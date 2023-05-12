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

// Generated from TypeSignature.g4 by ANTLR 4.12.0

#pragma once


#include "antlr4-runtime.h"
#include "TypeSignatureParser.h"

namespace facebook::presto::type {

/**
 * This class defines an abstract visitor for a parse tree
 * produced by TypeSignatureParser.
 */
class  TypeSignatureVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by TypeSignatureParser.
   */
    virtual std::any visitStart(TypeSignatureParser::StartContext *context) = 0;

    virtual std::any visitType_spec(TypeSignatureParser::Type_specContext *context) = 0;

    virtual std::any visitNamed_type(TypeSignatureParser::Named_typeContext *context) = 0;

    virtual std::any visitType(TypeSignatureParser::TypeContext *context) = 0;

    virtual std::any visitSimple_type(TypeSignatureParser::Simple_typeContext *context) = 0;

    virtual std::any visitVariable_type(TypeSignatureParser::Variable_typeContext *context) = 0;

    virtual std::any visitDecimal_type(TypeSignatureParser::Decimal_typeContext *context) = 0;

    virtual std::any visitType_list(TypeSignatureParser::Type_listContext *context) = 0;

    virtual std::any visitRow_type(TypeSignatureParser::Row_typeContext *context) = 0;

    virtual std::any visitMap_type(TypeSignatureParser::Map_typeContext *context) = 0;

    virtual std::any visitArray_type(TypeSignatureParser::Array_typeContext *context) = 0;

    virtual std::any visitIdentifier(TypeSignatureParser::IdentifierContext *context) = 0;


};

} // namespace facebook::presto::type