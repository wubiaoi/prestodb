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
#include "TypeSignatureVisitor.h"

namespace facebook::presto::type {
/**
 * This class provides an empty implementation of TypeSignatureVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  TypeSignatureBaseVisitor : public TypeSignatureVisitor {
public:

  virtual std::any visitStart(TypeSignatureParser::StartContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType_spec(TypeSignatureParser::Type_specContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNamed_type(TypeSignatureParser::Named_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType(TypeSignatureParser::TypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimple_type(TypeSignatureParser::Simple_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVariable_type(TypeSignatureParser::Variable_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDecimal_type(TypeSignatureParser::Decimal_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType_list(TypeSignatureParser::Type_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRow_type(TypeSignatureParser::Row_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMap_type(TypeSignatureParser::Map_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArray_type(TypeSignatureParser::Array_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIdentifier(TypeSignatureParser::IdentifierContext *ctx) override {
    return visitChildren(ctx);
  }


};

} // namespace facebook::presto::type