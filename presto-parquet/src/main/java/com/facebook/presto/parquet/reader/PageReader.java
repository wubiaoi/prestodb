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
package com.facebook.presto.parquet.reader;

import com.facebook.presto.parquet.DataPage;
import com.facebook.presto.parquet.DataPageV1;
import com.facebook.presto.parquet.DataPageV2;
import com.facebook.presto.parquet.DictionaryPage;
import io.airlift.slice.Slice;
import org.apache.parquet.hadoop.metadata.CompressionCodecName;
import org.apache.parquet.internal.column.columnindex.OffsetIndex;
import org.openjdk.jol.info.ClassLayout;

import java.io.IOException;
import java.util.Iterator;

import static com.facebook.presto.parquet.ParquetCompressionUtils.decompress;
import static java.lang.Math.toIntExact;

public class PageReader
{
    private static final int INSTANCE_SIZE = ClassLayout.parseClass(PageReader.class).instanceSize();

    private final long valueCountInColumnChunk;
    private final Iterator<DataPage> dataPageIterator;
    private final CompressionCodecName codec;
    private final DictionaryPage compressedDictionaryPage;
    private final OffsetIndex offsetIndex;
    private int pageIndex;
    public PageReader(CompressionCodecName codec,
            Iterator<DataPage> dataPageIterator,
            long valueCountInColumnChunk,
            DictionaryPage compressedDictionaryPage,
            OffsetIndex offsetIndex)
    {
        this.codec = codec;
        this.dataPageIterator = dataPageIterator;
        this.valueCountInColumnChunk = valueCountInColumnChunk;
        this.compressedDictionaryPage = compressedDictionaryPage;
        this.offsetIndex = offsetIndex;
        this.pageIndex = 0;
    }

    public static long getFirstRowIndex(int pageIndex, OffsetIndex offsetIndex)
    {
        return offsetIndex == null ? -1 : offsetIndex.getFirstRowIndex(pageIndex);
    }

    public long getValueCountInColumnChunk()
    {
        return valueCountInColumnChunk;
    }

    public DataPage readPage()
    {
        if (!dataPageIterator.hasNext()) {
            return null;
        }
        DataPage compressedPage = dataPageIterator.next();
        try {
            Slice slice = compressedPage.getSlice();
            long firstRowIndex = getFirstRowIndex(pageIndex, offsetIndex);
            pageIndex = pageIndex + 1;
            if (compressedPage instanceof DataPageV1) {
                DataPageV1 dataPageV1 = (DataPageV1) compressedPage;
                slice = decompress(codec, slice, dataPageV1.getUncompressedSize());
                return new DataPageV1(
                        slice,
                        dataPageV1.getValueCount(),
                        dataPageV1.getUncompressedSize(),
                        firstRowIndex,
                        dataPageV1.getStatistics(),
                        dataPageV1.getRepetitionLevelEncoding(),
                        dataPageV1.getDefinitionLevelEncoding(),
                        dataPageV1.getValueEncoding());
            }
            else {
                DataPageV2 dataPageV2 = (DataPageV2) compressedPage;
                if (!dataPageV2.isCompressed()) {
                    return dataPageV2;
                }
                int uncompressedSize = toIntExact(dataPageV2.getUncompressedSize()
                        - dataPageV2.getDefinitionLevels().length()
                        - dataPageV2.getRepetitionLevels().length());
                slice = decompress(codec, slice, uncompressedSize);
                return new DataPageV2(
                        dataPageV2.getRowCount(),
                        dataPageV2.getNullCount(),
                        dataPageV2.getValueCount(),
                        firstRowIndex,
                        dataPageV2.getRepetitionLevels(),
                        dataPageV2.getDefinitionLevels(),
                        dataPageV2.getDataEncoding(),
                        slice,
                        dataPageV2.getUncompressedSize(),
                        dataPageV2.getStatistics(),
                        false);
            }
        }
        catch (IOException e) {
            throw new RuntimeException("Could not decompress page", e);
        }
    }

    public DictionaryPage readDictionaryPage()
    {
        if (compressedDictionaryPage == null) {
            return null;
        }
        try {
            Slice slice = compressedDictionaryPage.getSlice();
            return new DictionaryPage(
                    decompress(codec, slice, compressedDictionaryPage.getUncompressedSize()),
                    compressedDictionaryPage.getDictionarySize(),
                    compressedDictionaryPage.getEncoding());
        }
        catch (IOException e) {
            throw new RuntimeException("Error reading dictionary page", e);
        }
    }

    public long getRetainedSizeInBytes()
    {
        return INSTANCE_SIZE +
                (compressedDictionaryPage == null ? 0 : compressedDictionaryPage.getRetainedSizeInBytes());
    }
}
