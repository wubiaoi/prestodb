/*
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
package com.facebook.presto.parquet.cache;

import com.facebook.presto.parquet.ParquetCorruptionException;
import com.facebook.presto.parquet.ParquetDataSource;
import com.facebook.presto.parquet.ParquetDataSourceId;
import io.airlift.slice.BasicSliceInput;
import io.airlift.slice.Slice;
import org.apache.parquet.crypto.HiddenColumnChunkMetaData;
import org.apache.parquet.format.ColumnChunk;
import org.apache.parquet.format.ColumnCryptoMetaData;
import org.apache.parquet.format.ColumnMetaData;
import org.apache.parquet.format.ConvertedType;
import org.apache.parquet.format.Encoding;
import org.apache.parquet.format.EncryptionWithColumnKey;
import org.apache.parquet.format.FileCryptoMetaData;
import org.apache.parquet.format.FileMetaData;
import org.apache.parquet.format.KeyValue;
import org.apache.parquet.format.RowGroup;
import org.apache.parquet.format.SchemaElement;
import org.apache.parquet.format.Statistics;
import org.apache.parquet.format.Type;
import org.apache.parquet.format.Util;
import org.apache.parquet.format.converter.ParquetMetadataConverter;
import org.apache.parquet.hadoop.metadata.BlockMetaData;
import org.apache.parquet.hadoop.metadata.ColumnChunkMetaData;
import org.apache.parquet.hadoop.metadata.ColumnPath;
import org.apache.parquet.hadoop.metadata.CompressionCodecName;
import org.apache.parquet.hadoop.metadata.ParquetMetadata;
import org.apache.parquet.internal.hadoop.metadata.IndexReference;
import org.apache.parquet.schema.MessageType;
import org.apache.parquet.schema.OriginalType;
import org.apache.parquet.schema.PrimitiveType;
import org.apache.parquet.schema.PrimitiveType.PrimitiveTypeName;
import org.apache.parquet.schema.Type.Repetition;
import org.apache.parquet.schema.Types;

import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Locale;
import java.util.Map;
import java.util.Optional;
import java.util.Set;

import static com.facebook.presto.parquet.ParquetValidationUtils.validateParquet;
import static io.airlift.slice.Slices.wrappedBuffer;
import static java.lang.Math.min;
import static java.lang.Math.toIntExact;
import static java.lang.String.format;
import static java.nio.charset.StandardCharsets.US_ASCII;
import static org.apache.parquet.crypto.ParquetCryptoMetaDataUtils.removeColumnsInSchema;
import static org.apache.parquet.format.Util.readFileMetaData;
import static org.apache.parquet.hadoop.ParquetFileWriter.MAGIC_STR;

public final class MetadataReader
        implements ParquetMetadataSource
{
    private static final Slice MAGIC = wrappedBuffer(MAGIC_STR.getBytes(US_ASCII));
    private static final int POST_SCRIPT_SIZE = Integer.BYTES + MAGIC.length();
    private static final int EXPECTED_FOOTER_SIZE = 16 * 1024;
    private static final ParquetMetadataConverter PARQUET_METADATA_CONVERTER = new ParquetMetadataConverter();
    private static final long MODIFICATION_TIME_NOT_SET = 0L;

    public static ParquetFileMetadata readFooter(ParquetDataSource parquetDataSource, long fileSize, boolean readMaskedValue)
            throws IOException
    {
        return readFooter(parquetDataSource, fileSize, MODIFICATION_TIME_NOT_SET, readMaskedValue);
    }

    public static ParquetFileMetadata readFooter(ParquetDataSource parquetDataSource, long fileSize, long modificationTime, boolean readMaskedValue)
            throws IOException
    {
        // Parquet File Layout: https://github.com/apache/parquet-format/blob/master/Encryption.md
        validateParquet(fileSize >= MAGIC.length() + POST_SCRIPT_SIZE, "%s is not a valid Parquet File", parquetDataSource.getId());

        //  EXPECTED_FOOTER_SIZE is an int, so this will never fail
        byte[] buffer = new byte[toIntExact(min(fileSize, EXPECTED_FOOTER_SIZE))];
        parquetDataSource.readFully(fileSize - buffer.length, buffer);
        Slice tailSlice = wrappedBuffer(buffer);

        Slice magic = tailSlice.slice(tailSlice.length() - MAGIC.length(), MAGIC.length());

        int metadataLength = tailSlice.getInt(tailSlice.length() - POST_SCRIPT_SIZE);
        int completeFooterSize = metadataLength + POST_SCRIPT_SIZE;

        long metadataFileOffset = fileSize - completeFooterSize;
        validateParquet(metadataFileOffset >= MAGIC.length() && metadataFileOffset + POST_SCRIPT_SIZE < fileSize, "Corrupted Parquet file: %s metadata index: %s out of range", parquetDataSource.getId(), metadataFileOffset);
        //  Ensure the slice covers the entire metadata range
        if (tailSlice.length() < completeFooterSize) {
            byte[] footerBuffer = new byte[completeFooterSize];
            parquetDataSource.readFully(metadataFileOffset, footerBuffer, 0, footerBuffer.length - tailSlice.length());
            // Copy the previous slice contents into the new buffer
            tailSlice.getBytes(0, footerBuffer, footerBuffer.length - tailSlice.length(), tailSlice.length());
            tailSlice = wrappedBuffer(footerBuffer, 0, footerBuffer.length);
        }

        return readParquetMetadata(tailSlice.slice(tailSlice.length() - completeFooterSize, metadataLength).getInput(), metadataLength, modificationTime, parquetDataSource.getId(), readMaskedValue);
    }

    private static ParquetFileMetadata readParquetMetadata(BasicSliceInput input, int metadataLength, long modificationTime, ParquetDataSourceId id, boolean readMaskedValue)
            throws IOException
    {
        // additional authenticated data for AES cipher
        FileMetaData fileMetaData = readFileMetaData(input);
        return convertToParquetMetadata(input, fileMetaData, metadataLength, modificationTime, id, readMaskedValue);
    }

    private static ParquetFileMetadata convertToParquetMetadata(BasicSliceInput input, FileMetaData fileMetaData, int metadataLength, long modificationTime, ParquetDataSourceId id, boolean readMaskedValue)
            throws IOException
    {
        List<SchemaElement> schema = fileMetaData.getSchema();
        validateParquet(!schema.isEmpty(), "Empty Parquet schema in file: %s", id);

        // Reader attached fileDecryptor. The file could be encrypted with plaintext footer or the whole file is plaintext.
        MessageType messageType = readParquetSchema(schema);
        List<BlockMetaData> blocks = new ArrayList<>();
        List<RowGroup> rowGroups = fileMetaData.getRow_groups();
        Set<ColumnPath> maskedColumns = new HashSet<>();
        if (rowGroups != null) {
            for (RowGroup rowGroup : rowGroups) {
                BlockMetaData blockMetaData = new BlockMetaData();
                blockMetaData.setRowCount(rowGroup.getNum_rows());
                blockMetaData.setTotalByteSize(rowGroup.getTotal_byte_size());
                List<ColumnChunk> columns = rowGroup.getColumns();
                validateParquet(!columns.isEmpty(), "No columns in row group: %s", rowGroup);
                String filePath = columns.get(0).getFile_path();
                int columnOrdinal = -1;
                for (ColumnChunk columnChunk : columns) {
                    columnOrdinal++;
                    validateParquet(
                            (filePath == null && columnChunk.getFile_path() == null)
                                    || (filePath != null && filePath.equals(columnChunk.getFile_path())),
                            "all column chunks of the same row group must be in the same file");

                    ColumnMetaData metaData = columnChunk.meta_data;
                    ColumnCryptoMetaData cryptoMetaData = columnChunk.getCrypto_metadata();
                    ColumnPath columnPath = getPath(metaData);
                    ColumnChunkMetaData column = buildColumnChunkMetaData(metaData, columnPath, messageType.getType(columnPath.toArray()).asPrimitiveType());
                    column.setColumnIndexReference(toColumnIndexReference(columnChunk));
                    column.setOffsetIndexReference(toOffsetIndexReference(columnChunk));
                    blockMetaData.addColumn(column);
                }
                blockMetaData.setPath(filePath);
                blocks.add(blockMetaData);
            }
        }

        Map<String, String> keyValueMetaData = new HashMap<>();
        List<KeyValue> keyValueList = fileMetaData.getKey_value_metadata();
        if (keyValueList != null) {
            for (KeyValue keyValue : keyValueList) {
                keyValueMetaData.put(keyValue.key, keyValue.value);
            }
        }

        if (readMaskedValue) {
            messageType = removeColumnsInSchema(messageType, maskedColumns);
        }

        ParquetMetadata parquetMetadata = new ParquetMetadata(new org.apache.parquet.hadoop.metadata.FileMetaData(messageType, keyValueMetaData, fileMetaData.getCreated_by()), blocks);
        return new ParquetFileMetadata(parquetMetadata, toIntExact(metadataLength), modificationTime);
    }

    public static ColumnChunkMetaData buildColumnChunkMetaData(ColumnMetaData metaData, ColumnPath columnPath, PrimitiveType type)
    {
        return ColumnChunkMetaData.get(
                columnPath,
                type,
                CompressionCodecName.fromParquet(metaData.codec),
                PARQUET_METADATA_CONVERTER.convertEncodingStats(metaData.encoding_stats),
                readEncodings(metaData.encodings),
                readStats(metaData.statistics, type.getPrimitiveTypeName()),
                metaData.data_page_offset,
                metaData.dictionary_page_offset,
                metaData.num_values,
                metaData.total_compressed_size,
                metaData.total_uncompressed_size);
    }

    private static ColumnPath getPath(ColumnMetaData metaData)
    {
        String[] path = metaData.path_in_schema.stream()
                .map(value -> value.toLowerCase(Locale.ENGLISH))
                .toArray(String[]::new);
        return ColumnPath.get(path);
    }

    private static MessageType readParquetSchema(List<SchemaElement> schema)
    {
        Iterator<SchemaElement> schemaIterator = schema.iterator();
        SchemaElement rootSchema = schemaIterator.next();
        Types.MessageTypeBuilder builder = Types.buildMessage();
        readTypeSchema(builder, schemaIterator, rootSchema.getNum_children());
        return builder.named(rootSchema.name);
    }

    private static void readTypeSchema(Types.GroupBuilder<?> builder, Iterator<SchemaElement> schemaIterator, int typeCount)
    {
        for (int i = 0; i < typeCount; i++) {
            SchemaElement element = schemaIterator.next();
            Types.Builder<?, ?> typeBuilder;
            if (element.type == null) {
                typeBuilder = builder.group(Repetition.valueOf(element.repetition_type.name()));
                readTypeSchema((Types.GroupBuilder<?>) typeBuilder, schemaIterator, element.num_children);
            }
            else {
                Types.PrimitiveBuilder<?> primitiveBuilder = builder.primitive(getTypeName(element.type), Repetition.valueOf(element.repetition_type.name()));
                if (element.isSetType_length()) {
                    primitiveBuilder.length(element.type_length);
                }
                if (element.isSetPrecision()) {
                    primitiveBuilder.precision(element.precision);
                }
                if (element.isSetScale()) {
                    primitiveBuilder.scale(element.scale);
                }
                typeBuilder = primitiveBuilder;
            }

            if (element.isSetConverted_type()) {
                typeBuilder.as(getOriginalType(element.converted_type));
            }
            if (element.isSetField_id()) {
                typeBuilder.id(element.field_id);
            }
            typeBuilder.named(element.name.toLowerCase(Locale.ENGLISH));
        }
    }

    public static org.apache.parquet.column.statistics.Statistics<?> readStats(Statistics statistics, PrimitiveTypeName type)
    {
        org.apache.parquet.column.statistics.Statistics<?> stats = org.apache.parquet.column.statistics.Statistics.getStatsBasedOnType(type);
        stats.setNumNulls(-1);
        if (statistics != null) {
            if (statistics.isSetMax() && statistics.isSetMin()) {
                stats.setMinMaxFromBytes(statistics.min.array(), statistics.max.array());
            }
            if (statistics.isSetNull_count()) {
                stats.setNumNulls(statistics.null_count);
            }
        }
        return stats;
    }

    private static Set<org.apache.parquet.column.Encoding> readEncodings(List<Encoding> encodings)
    {
        Set<org.apache.parquet.column.Encoding> columnEncodings = new HashSet<>();
        for (Encoding encoding : encodings) {
            columnEncodings.add(org.apache.parquet.column.Encoding.valueOf(encoding.name()));
        }
        return Collections.unmodifiableSet(columnEncodings);
    }

    private static PrimitiveTypeName getTypeName(Type type)
    {
        switch (type) {
            case BYTE_ARRAY:
                return PrimitiveTypeName.BINARY;
            case INT64:
                return PrimitiveTypeName.INT64;
            case INT32:
                return PrimitiveTypeName.INT32;
            case BOOLEAN:
                return PrimitiveTypeName.BOOLEAN;
            case FLOAT:
                return PrimitiveTypeName.FLOAT;
            case DOUBLE:
                return PrimitiveTypeName.DOUBLE;
            case INT96:
                return PrimitiveTypeName.INT96;
            case FIXED_LEN_BYTE_ARRAY:
                return PrimitiveTypeName.FIXED_LEN_BYTE_ARRAY;
            default:
                throw new IllegalArgumentException("Unknown type " + type);
        }
    }

    private static OriginalType getOriginalType(ConvertedType type)
    {
        switch (type) {
            case UTF8:
                return OriginalType.UTF8;
            case MAP:
                return OriginalType.MAP;
            case MAP_KEY_VALUE:
                return OriginalType.MAP_KEY_VALUE;
            case LIST:
                return OriginalType.LIST;
            case ENUM:
                return OriginalType.ENUM;
            case DECIMAL:
                return OriginalType.DECIMAL;
            case DATE:
                return OriginalType.DATE;
            case TIME_MILLIS:
                return OriginalType.TIME_MILLIS;
            case TIMESTAMP_MICROS:
                return OriginalType.TIMESTAMP_MICROS;
            case TIMESTAMP_MILLIS:
                return OriginalType.TIMESTAMP_MILLIS;
            case INTERVAL:
                return OriginalType.INTERVAL;
            case INT_8:
                return OriginalType.INT_8;
            case INT_16:
                return OriginalType.INT_16;
            case INT_32:
                return OriginalType.INT_32;
            case INT_64:
                return OriginalType.INT_64;
            case UINT_8:
                return OriginalType.UINT_8;
            case UINT_16:
                return OriginalType.UINT_16;
            case UINT_32:
                return OriginalType.UINT_32;
            case UINT_64:
                return OriginalType.UINT_64;
            case JSON:
                return OriginalType.JSON;
            case BSON:
                return OriginalType.BSON;
            default:
                throw new IllegalArgumentException("Unknown converted type " + type);
        }
    }

    public ParquetFileMetadata getParquetMetadata(
            ParquetDataSource parquetDataSource,
            long fileSize,
            boolean cacheable,
            long modificationTime,
            boolean readMaskedValue)
            throws IOException
    {
        return readFooter(parquetDataSource, fileSize, modificationTime, readMaskedValue);
    }

    private static IndexReference toColumnIndexReference(ColumnChunk columnChunk)
    {
        if (columnChunk.isSetColumn_index_offset() && columnChunk.isSetColumn_index_length()) {
            return new IndexReference(columnChunk.getColumn_index_offset(), columnChunk.getColumn_index_length());
        }
        return null;
    }

    private static IndexReference toOffsetIndexReference(ColumnChunk columnChunk)
    {
        if (columnChunk.isSetOffset_index_offset() && columnChunk.isSetOffset_index_length()) {
            return new IndexReference(columnChunk.getOffset_index_offset(), columnChunk.getOffset_index_length());
        }
        return null;
    }

    public static Optional<Integer> findFirstNonHiddenColumnId(BlockMetaData block)
    {
        List<ColumnChunkMetaData> columns = block.getColumns();
        for (int i = 0; i < columns.size(); i++) {
            if (!HiddenColumnChunkMetaData.isHiddenColumn(columns.get(i))) {
                return Optional.of(i);
            }
        }
        // all columns are hidden (encrypted but not accessible to current user)
        return Optional.empty();
    }
}
