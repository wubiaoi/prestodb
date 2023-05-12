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

#include <boost/algorithm/string.hpp>
#include "presto_cpp/main/types/TypeSignatureTypeConverter.h"


// Generated from TypeSignature.g4 by ANTLR 4.12.0


#include "TypeSignatureVisitor.h"

#include "TypeSignatureParser.h"


using namespace antlrcpp;
using namespace facebook::presto::type;

using namespace antlr4;

namespace {

struct TypeSignatureParserStaticData final {
  TypeSignatureParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  TypeSignatureParserStaticData(const TypeSignatureParserStaticData&) = delete;
  TypeSignatureParserStaticData(TypeSignatureParserStaticData&&) = delete;
  TypeSignatureParserStaticData& operator=(const TypeSignatureParserStaticData&) = delete;
  TypeSignatureParserStaticData& operator=(TypeSignatureParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag typesignatureParserOnceFlag;
TypeSignatureParserStaticData *typesignatureParserStaticData = nullptr;

void typesignatureParserInitialize() {
  assert(typesignatureParserStaticData == nullptr);
  auto staticData = std::make_unique<TypeSignatureParserStaticData>(
    std::vector<std::string>{
      "start", "type_spec", "named_type", "type", "simple_type", "variable_type", 
      "decimal_type", "type_list", "row_type", "map_type", "array_type", 
      "identifier"
    },
    std::vector<std::string>{
      "", "'('", "')'", "','"
    },
    std::vector<std::string>{
      "", "", "", "", "TYPE_WITH_SPACES", "WORD", "QUOTED_ID", "NUMBER", 
      "WHITESPACE"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,8,107,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,7,
  	7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,1,0,1,0,1,0,1,1,1,1,3,1,30,8,
  	1,1,2,1,2,1,2,1,3,1,3,1,3,1,3,1,3,1,3,3,3,41,8,3,1,4,1,4,1,5,1,5,1,5,
  	1,5,1,5,1,5,5,5,51,8,5,10,5,12,5,54,9,5,1,5,3,5,57,8,5,1,6,1,6,1,6,1,
  	6,5,6,63,8,6,10,6,12,6,66,9,6,1,6,1,6,5,6,70,8,6,10,6,12,6,73,9,6,1,6,
  	1,6,1,7,1,7,1,7,5,7,80,8,7,10,7,12,7,83,9,7,1,8,1,8,1,8,1,8,1,8,1,8,1,
  	9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,10,1,10,1,10,1,10,1,10,1,10,1,11,1,11,
  	1,11,0,0,12,0,2,4,6,8,10,12,14,16,18,20,22,0,2,1,0,4,5,1,0,5,6,105,0,
  	24,1,0,0,0,2,29,1,0,0,0,4,31,1,0,0,0,6,40,1,0,0,0,8,42,1,0,0,0,10,56,
  	1,0,0,0,12,58,1,0,0,0,14,76,1,0,0,0,16,84,1,0,0,0,18,90,1,0,0,0,20,98,
  	1,0,0,0,22,104,1,0,0,0,24,25,3,2,1,0,25,26,5,0,0,1,26,1,1,0,0,0,27,30,
  	3,4,2,0,28,30,3,6,3,0,29,27,1,0,0,0,29,28,1,0,0,0,30,3,1,0,0,0,31,32,
  	3,22,11,0,32,33,3,6,3,0,33,5,1,0,0,0,34,41,3,8,4,0,35,41,3,12,6,0,36,
  	41,3,10,5,0,37,41,3,20,10,0,38,41,3,18,9,0,39,41,3,16,8,0,40,34,1,0,0,
  	0,40,35,1,0,0,0,40,36,1,0,0,0,40,37,1,0,0,0,40,38,1,0,0,0,40,39,1,0,0,
  	0,41,7,1,0,0,0,42,43,7,0,0,0,43,9,1,0,0,0,44,45,4,5,0,0,45,57,5,5,0,0,
  	46,47,4,5,1,0,47,48,5,5,0,0,48,52,5,1,0,0,49,51,5,7,0,0,50,49,1,0,0,0,
  	51,54,1,0,0,0,52,50,1,0,0,0,52,53,1,0,0,0,53,55,1,0,0,0,54,52,1,0,0,0,
  	55,57,5,2,0,0,56,44,1,0,0,0,56,46,1,0,0,0,57,11,1,0,0,0,58,59,4,6,2,0,
  	59,60,5,5,0,0,60,64,5,1,0,0,61,63,5,7,0,0,62,61,1,0,0,0,63,66,1,0,0,0,
  	64,62,1,0,0,0,64,65,1,0,0,0,65,67,1,0,0,0,66,64,1,0,0,0,67,71,5,3,0,0,
  	68,70,5,7,0,0,69,68,1,0,0,0,70,73,1,0,0,0,71,69,1,0,0,0,71,72,1,0,0,0,
  	72,74,1,0,0,0,73,71,1,0,0,0,74,75,5,2,0,0,75,13,1,0,0,0,76,81,3,2,1,0,
  	77,78,5,3,0,0,78,80,3,2,1,0,79,77,1,0,0,0,80,83,1,0,0,0,81,79,1,0,0,0,
  	81,82,1,0,0,0,82,15,1,0,0,0,83,81,1,0,0,0,84,85,4,8,3,0,85,86,5,5,0,0,
  	86,87,5,1,0,0,87,88,3,14,7,0,88,89,5,2,0,0,89,17,1,0,0,0,90,91,4,9,4,
  	0,91,92,5,5,0,0,92,93,5,1,0,0,93,94,3,6,3,0,94,95,5,3,0,0,95,96,3,6,3,
  	0,96,97,5,2,0,0,97,19,1,0,0,0,98,99,4,10,5,0,99,100,5,5,0,0,100,101,5,
  	1,0,0,101,102,3,6,3,0,102,103,5,2,0,0,103,21,1,0,0,0,104,105,7,1,0,0,
  	105,23,1,0,0,0,7,29,40,52,56,64,71,81
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  typesignatureParserStaticData = staticData.release();
}

}

TypeSignatureParser::TypeSignatureParser(TokenStream *input) : TypeSignatureParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

TypeSignatureParser::TypeSignatureParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  TypeSignatureParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *typesignatureParserStaticData->atn, typesignatureParserStaticData->decisionToDFA, typesignatureParserStaticData->sharedContextCache, options);
}

TypeSignatureParser::~TypeSignatureParser() {
  delete _interpreter;
}

const atn::ATN& TypeSignatureParser::getATN() const {
  return *typesignatureParserStaticData->atn;
}

std::string TypeSignatureParser::getGrammarFileName() const {
  return "TypeSignature.g4";
}

const std::vector<std::string>& TypeSignatureParser::getRuleNames() const {
  return typesignatureParserStaticData->ruleNames;
}

const dfa::Vocabulary& TypeSignatureParser::getVocabulary() const {
  return typesignatureParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView TypeSignatureParser::getSerializedATN() const {
  return typesignatureParserStaticData->serializedATN;
}


//----------------- StartContext ------------------------------------------------------------------

TypeSignatureParser::StartContext::StartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TypeSignatureParser::Type_specContext* TypeSignatureParser::StartContext::type_spec() {
  return getRuleContext<TypeSignatureParser::Type_specContext>(0);
}

tree::TerminalNode* TypeSignatureParser::StartContext::EOF() {
  return getToken(TypeSignatureParser::EOF, 0);
}


size_t TypeSignatureParser::StartContext::getRuleIndex() const {
  return TypeSignatureParser::RuleStart;
}


std::any TypeSignatureParser::StartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeSignatureVisitor*>(visitor))
    return parserVisitor->visitStart(this);
  else
    return visitor->visitChildren(this);
}

TypeSignatureParser::StartContext* TypeSignatureParser::start() {
  StartContext *_localctx = _tracker.createInstance<StartContext>(_ctx, getState());
  enterRule(_localctx, 0, TypeSignatureParser::RuleStart);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(24);
    type_spec();
    setState(25);
    match(TypeSignatureParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_specContext ------------------------------------------------------------------

TypeSignatureParser::Type_specContext::Type_specContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TypeSignatureParser::Named_typeContext* TypeSignatureParser::Type_specContext::named_type() {
  return getRuleContext<TypeSignatureParser::Named_typeContext>(0);
}

TypeSignatureParser::TypeContext* TypeSignatureParser::Type_specContext::type() {
  return getRuleContext<TypeSignatureParser::TypeContext>(0);
}


size_t TypeSignatureParser::Type_specContext::getRuleIndex() const {
  return TypeSignatureParser::RuleType_spec;
}


std::any TypeSignatureParser::Type_specContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeSignatureVisitor*>(visitor))
    return parserVisitor->visitType_spec(this);
  else
    return visitor->visitChildren(this);
}

TypeSignatureParser::Type_specContext* TypeSignatureParser::type_spec() {
  Type_specContext *_localctx = _tracker.createInstance<Type_specContext>(_ctx, getState());
  enterRule(_localctx, 2, TypeSignatureParser::RuleType_spec);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(29);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(27);
      named_type();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(28);
      type();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Named_typeContext ------------------------------------------------------------------

TypeSignatureParser::Named_typeContext::Named_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TypeSignatureParser::IdentifierContext* TypeSignatureParser::Named_typeContext::identifier() {
  return getRuleContext<TypeSignatureParser::IdentifierContext>(0);
}

TypeSignatureParser::TypeContext* TypeSignatureParser::Named_typeContext::type() {
  return getRuleContext<TypeSignatureParser::TypeContext>(0);
}


size_t TypeSignatureParser::Named_typeContext::getRuleIndex() const {
  return TypeSignatureParser::RuleNamed_type;
}


std::any TypeSignatureParser::Named_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeSignatureVisitor*>(visitor))
    return parserVisitor->visitNamed_type(this);
  else
    return visitor->visitChildren(this);
}

TypeSignatureParser::Named_typeContext* TypeSignatureParser::named_type() {
  Named_typeContext *_localctx = _tracker.createInstance<Named_typeContext>(_ctx, getState());
  enterRule(_localctx, 4, TypeSignatureParser::RuleNamed_type);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(31);
    identifier();
    setState(32);
    type();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

TypeSignatureParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TypeSignatureParser::Simple_typeContext* TypeSignatureParser::TypeContext::simple_type() {
  return getRuleContext<TypeSignatureParser::Simple_typeContext>(0);
}

TypeSignatureParser::Decimal_typeContext* TypeSignatureParser::TypeContext::decimal_type() {
  return getRuleContext<TypeSignatureParser::Decimal_typeContext>(0);
}

TypeSignatureParser::Variable_typeContext* TypeSignatureParser::TypeContext::variable_type() {
  return getRuleContext<TypeSignatureParser::Variable_typeContext>(0);
}

TypeSignatureParser::Array_typeContext* TypeSignatureParser::TypeContext::array_type() {
  return getRuleContext<TypeSignatureParser::Array_typeContext>(0);
}

TypeSignatureParser::Map_typeContext* TypeSignatureParser::TypeContext::map_type() {
  return getRuleContext<TypeSignatureParser::Map_typeContext>(0);
}

TypeSignatureParser::Row_typeContext* TypeSignatureParser::TypeContext::row_type() {
  return getRuleContext<TypeSignatureParser::Row_typeContext>(0);
}


size_t TypeSignatureParser::TypeContext::getRuleIndex() const {
  return TypeSignatureParser::RuleType;
}


std::any TypeSignatureParser::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeSignatureVisitor*>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}

TypeSignatureParser::TypeContext* TypeSignatureParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 6, TypeSignatureParser::RuleType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(40);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(34);
      simple_type();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(35);
      decimal_type();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(36);
      variable_type();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(37);
      array_type();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(38);
      map_type();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(39);
      row_type();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Simple_typeContext ------------------------------------------------------------------

TypeSignatureParser::Simple_typeContext::Simple_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TypeSignatureParser::Simple_typeContext::WORD() {
  return getToken(TypeSignatureParser::WORD, 0);
}

tree::TerminalNode* TypeSignatureParser::Simple_typeContext::TYPE_WITH_SPACES() {
  return getToken(TypeSignatureParser::TYPE_WITH_SPACES, 0);
}


size_t TypeSignatureParser::Simple_typeContext::getRuleIndex() const {
  return TypeSignatureParser::RuleSimple_type;
}


std::any TypeSignatureParser::Simple_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeSignatureVisitor*>(visitor))
    return parserVisitor->visitSimple_type(this);
  else
    return visitor->visitChildren(this);
}

TypeSignatureParser::Simple_typeContext* TypeSignatureParser::simple_type() {
  Simple_typeContext *_localctx = _tracker.createInstance<Simple_typeContext>(_ctx, getState());
  enterRule(_localctx, 8, TypeSignatureParser::RuleSimple_type);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(42);
    _la = _input->LA(1);
    if (!(_la == TypeSignatureParser::TYPE_WITH_SPACES

    || _la == TypeSignatureParser::WORD)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Variable_typeContext ------------------------------------------------------------------

TypeSignatureParser::Variable_typeContext::Variable_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TypeSignatureParser::Variable_typeContext::WORD() {
  return getToken(TypeSignatureParser::WORD, 0);
}

std::vector<tree::TerminalNode *> TypeSignatureParser::Variable_typeContext::NUMBER() {
  return getTokens(TypeSignatureParser::NUMBER);
}

tree::TerminalNode* TypeSignatureParser::Variable_typeContext::NUMBER(size_t i) {
  return getToken(TypeSignatureParser::NUMBER, i);
}


size_t TypeSignatureParser::Variable_typeContext::getRuleIndex() const {
  return TypeSignatureParser::RuleVariable_type;
}


std::any TypeSignatureParser::Variable_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeSignatureVisitor*>(visitor))
    return parserVisitor->visitVariable_type(this);
  else
    return visitor->visitChildren(this);
}

TypeSignatureParser::Variable_typeContext* TypeSignatureParser::variable_type() {
  Variable_typeContext *_localctx = _tracker.createInstance<Variable_typeContext>(_ctx, getState());
  enterRule(_localctx, 10, TypeSignatureParser::RuleVariable_type);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(56);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(44);

      if (!( isVarToken() )) throw FailedPredicateException(this, " isVarToken() ");
      setState(45);
      match(TypeSignatureParser::WORD);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(46);

      if (!( isVarToken() )) throw FailedPredicateException(this, " isVarToken() ");
      setState(47);
      match(TypeSignatureParser::WORD);
      setState(48);
      match(TypeSignatureParser::T__0);
      setState(52);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TypeSignatureParser::NUMBER) {
        setState(49);
        match(TypeSignatureParser::NUMBER);
        setState(54);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(55);
      match(TypeSignatureParser::T__1);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Decimal_typeContext ------------------------------------------------------------------

TypeSignatureParser::Decimal_typeContext::Decimal_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TypeSignatureParser::Decimal_typeContext::WORD() {
  return getToken(TypeSignatureParser::WORD, 0);
}

std::vector<tree::TerminalNode *> TypeSignatureParser::Decimal_typeContext::NUMBER() {
  return getTokens(TypeSignatureParser::NUMBER);
}

tree::TerminalNode* TypeSignatureParser::Decimal_typeContext::NUMBER(size_t i) {
  return getToken(TypeSignatureParser::NUMBER, i);
}


size_t TypeSignatureParser::Decimal_typeContext::getRuleIndex() const {
  return TypeSignatureParser::RuleDecimal_type;
}


std::any TypeSignatureParser::Decimal_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeSignatureVisitor*>(visitor))
    return parserVisitor->visitDecimal_type(this);
  else
    return visitor->visitChildren(this);
}

TypeSignatureParser::Decimal_typeContext* TypeSignatureParser::decimal_type() {
  Decimal_typeContext *_localctx = _tracker.createInstance<Decimal_typeContext>(_ctx, getState());
  enterRule(_localctx, 12, TypeSignatureParser::RuleDecimal_type);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(58);

    if (!( isDecimalToken() )) throw FailedPredicateException(this, " isDecimalToken() ");
    setState(59);
    match(TypeSignatureParser::WORD);
    setState(60);
    match(TypeSignatureParser::T__0);
    setState(64);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TypeSignatureParser::NUMBER) {
      setState(61);
      match(TypeSignatureParser::NUMBER);
      setState(66);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(67);
    match(TypeSignatureParser::T__2);
    setState(71);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TypeSignatureParser::NUMBER) {
      setState(68);
      match(TypeSignatureParser::NUMBER);
      setState(73);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(74);
    match(TypeSignatureParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_listContext ------------------------------------------------------------------

TypeSignatureParser::Type_listContext::Type_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<TypeSignatureParser::Type_specContext *> TypeSignatureParser::Type_listContext::type_spec() {
  return getRuleContexts<TypeSignatureParser::Type_specContext>();
}

TypeSignatureParser::Type_specContext* TypeSignatureParser::Type_listContext::type_spec(size_t i) {
  return getRuleContext<TypeSignatureParser::Type_specContext>(i);
}


size_t TypeSignatureParser::Type_listContext::getRuleIndex() const {
  return TypeSignatureParser::RuleType_list;
}


std::any TypeSignatureParser::Type_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeSignatureVisitor*>(visitor))
    return parserVisitor->visitType_list(this);
  else
    return visitor->visitChildren(this);
}

TypeSignatureParser::Type_listContext* TypeSignatureParser::type_list() {
  Type_listContext *_localctx = _tracker.createInstance<Type_listContext>(_ctx, getState());
  enterRule(_localctx, 14, TypeSignatureParser::RuleType_list);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(76);
    type_spec();
    setState(81);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TypeSignatureParser::T__2) {
      setState(77);
      match(TypeSignatureParser::T__2);
      setState(78);
      type_spec();
      setState(83);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Row_typeContext ------------------------------------------------------------------

TypeSignatureParser::Row_typeContext::Row_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TypeSignatureParser::Row_typeContext::WORD() {
  return getToken(TypeSignatureParser::WORD, 0);
}

TypeSignatureParser::Type_listContext* TypeSignatureParser::Row_typeContext::type_list() {
  return getRuleContext<TypeSignatureParser::Type_listContext>(0);
}


size_t TypeSignatureParser::Row_typeContext::getRuleIndex() const {
  return TypeSignatureParser::RuleRow_type;
}


std::any TypeSignatureParser::Row_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeSignatureVisitor*>(visitor))
    return parserVisitor->visitRow_type(this);
  else
    return visitor->visitChildren(this);
}

TypeSignatureParser::Row_typeContext* TypeSignatureParser::row_type() {
  Row_typeContext *_localctx = _tracker.createInstance<Row_typeContext>(_ctx, getState());
  enterRule(_localctx, 16, TypeSignatureParser::RuleRow_type);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(84);

    if (!( isRowToken() )) throw FailedPredicateException(this, " isRowToken() ");
    setState(85);
    match(TypeSignatureParser::WORD);
    setState(86);
    match(TypeSignatureParser::T__0);
    setState(87);
    type_list();
    setState(88);
    match(TypeSignatureParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Map_typeContext ------------------------------------------------------------------

TypeSignatureParser::Map_typeContext::Map_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TypeSignatureParser::Map_typeContext::WORD() {
  return getToken(TypeSignatureParser::WORD, 0);
}

std::vector<TypeSignatureParser::TypeContext *> TypeSignatureParser::Map_typeContext::type() {
  return getRuleContexts<TypeSignatureParser::TypeContext>();
}

TypeSignatureParser::TypeContext* TypeSignatureParser::Map_typeContext::type(size_t i) {
  return getRuleContext<TypeSignatureParser::TypeContext>(i);
}


size_t TypeSignatureParser::Map_typeContext::getRuleIndex() const {
  return TypeSignatureParser::RuleMap_type;
}


std::any TypeSignatureParser::Map_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeSignatureVisitor*>(visitor))
    return parserVisitor->visitMap_type(this);
  else
    return visitor->visitChildren(this);
}

TypeSignatureParser::Map_typeContext* TypeSignatureParser::map_type() {
  Map_typeContext *_localctx = _tracker.createInstance<Map_typeContext>(_ctx, getState());
  enterRule(_localctx, 18, TypeSignatureParser::RuleMap_type);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(90);

    if (!( isMapToken() )) throw FailedPredicateException(this, " isMapToken() ");
    setState(91);
    match(TypeSignatureParser::WORD);
    setState(92);
    match(TypeSignatureParser::T__0);
    setState(93);
    type();
    setState(94);
    match(TypeSignatureParser::T__2);
    setState(95);
    type();
    setState(96);
    match(TypeSignatureParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Array_typeContext ------------------------------------------------------------------

TypeSignatureParser::Array_typeContext::Array_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TypeSignatureParser::Array_typeContext::WORD() {
  return getToken(TypeSignatureParser::WORD, 0);
}

TypeSignatureParser::TypeContext* TypeSignatureParser::Array_typeContext::type() {
  return getRuleContext<TypeSignatureParser::TypeContext>(0);
}


size_t TypeSignatureParser::Array_typeContext::getRuleIndex() const {
  return TypeSignatureParser::RuleArray_type;
}


std::any TypeSignatureParser::Array_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeSignatureVisitor*>(visitor))
    return parserVisitor->visitArray_type(this);
  else
    return visitor->visitChildren(this);
}

TypeSignatureParser::Array_typeContext* TypeSignatureParser::array_type() {
  Array_typeContext *_localctx = _tracker.createInstance<Array_typeContext>(_ctx, getState());
  enterRule(_localctx, 20, TypeSignatureParser::RuleArray_type);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(98);

    if (!( isArrayToken() )) throw FailedPredicateException(this, " isArrayToken() ");
    setState(99);
    match(TypeSignatureParser::WORD);
    setState(100);
    match(TypeSignatureParser::T__0);
    setState(101);
    type();
    setState(102);
    match(TypeSignatureParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdentifierContext ------------------------------------------------------------------

TypeSignatureParser::IdentifierContext::IdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TypeSignatureParser::IdentifierContext::QUOTED_ID() {
  return getToken(TypeSignatureParser::QUOTED_ID, 0);
}

tree::TerminalNode* TypeSignatureParser::IdentifierContext::WORD() {
  return getToken(TypeSignatureParser::WORD, 0);
}


size_t TypeSignatureParser::IdentifierContext::getRuleIndex() const {
  return TypeSignatureParser::RuleIdentifier;
}


std::any TypeSignatureParser::IdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TypeSignatureVisitor*>(visitor))
    return parserVisitor->visitIdentifier(this);
  else
    return visitor->visitChildren(this);
}

TypeSignatureParser::IdentifierContext* TypeSignatureParser::identifier() {
  IdentifierContext *_localctx = _tracker.createInstance<IdentifierContext>(_ctx, getState());
  enterRule(_localctx, 22, TypeSignatureParser::RuleIdentifier);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(104);
    _la = _input->LA(1);
    if (!(_la == TypeSignatureParser::WORD

    || _la == TypeSignatureParser::QUOTED_ID)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool TypeSignatureParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 5: return variable_typeSempred(antlrcpp::downCast<Variable_typeContext *>(context), predicateIndex);
    case 6: return decimal_typeSempred(antlrcpp::downCast<Decimal_typeContext *>(context), predicateIndex);
    case 8: return row_typeSempred(antlrcpp::downCast<Row_typeContext *>(context), predicateIndex);
    case 9: return map_typeSempred(antlrcpp::downCast<Map_typeContext *>(context), predicateIndex);
    case 10: return array_typeSempred(antlrcpp::downCast<Array_typeContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool TypeSignatureParser::variable_typeSempred(Variable_typeContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return  isVarToken() ;
    case 1: return  isVarToken() ;

  default:
    break;
  }
  return true;
}

bool TypeSignatureParser::decimal_typeSempred(Decimal_typeContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 2: return  isDecimalToken() ;

  default:
    break;
  }
  return true;
}

bool TypeSignatureParser::row_typeSempred(Row_typeContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 3: return  isRowToken() ;

  default:
    break;
  }
  return true;
}

bool TypeSignatureParser::map_typeSempred(Map_typeContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 4: return  isMapToken() ;

  default:
    break;
  }
  return true;
}

bool TypeSignatureParser::array_typeSempred(Array_typeContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 5: return  isArrayToken() ;

  default:
    break;
  }
  return true;
}

void TypeSignatureParser::initialize() {
  ::antlr4::internal::call_once(typesignatureParserOnceFlag, typesignatureParserInitialize);
}
