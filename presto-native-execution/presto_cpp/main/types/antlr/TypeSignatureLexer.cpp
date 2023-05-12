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


#include "TypeSignatureLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct TypeSignatureLexerStaticData final {
  TypeSignatureLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  TypeSignatureLexerStaticData(const TypeSignatureLexerStaticData&) = delete;
  TypeSignatureLexerStaticData(TypeSignatureLexerStaticData&&) = delete;
  TypeSignatureLexerStaticData& operator=(const TypeSignatureLexerStaticData&) = delete;
  TypeSignatureLexerStaticData& operator=(TypeSignatureLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag typesignaturelexerLexerOnceFlag;
TypeSignatureLexerStaticData *typesignaturelexerLexerStaticData = nullptr;

void typesignaturelexerLexerInitialize() {
  assert(typesignaturelexerLexerStaticData == nullptr);
  auto staticData = std::make_unique<TypeSignatureLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "TYPE_WITH_SPACES", "WORD", "QUOTED_ID", "NUMBER", 
      "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", 
      "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "WHITESPACE"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
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
  	4,0,8,263,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,1,0,1,0,1,1,1,
  	1,1,2,1,2,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,
  	1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,
  	3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,
  	1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,
  	3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,
  	1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,
  	3,1,3,1,3,1,3,1,3,1,3,3,3,184,8,3,1,4,1,4,5,4,188,8,4,10,4,12,4,191,9,
  	4,1,5,1,5,1,5,5,5,196,8,5,10,5,12,5,199,9,5,1,5,1,5,1,6,4,6,204,8,6,11,
  	6,12,6,205,1,7,1,7,1,8,1,8,1,9,1,9,1,10,1,10,1,11,1,11,1,12,1,12,1,13,
  	1,13,1,14,1,14,1,15,1,15,1,16,1,16,1,17,1,17,1,18,1,18,1,19,1,19,1,20,
  	1,20,1,21,1,21,1,22,1,22,1,23,1,23,1,24,1,24,1,25,1,25,1,26,1,26,1,27,
  	1,27,1,28,1,28,1,29,1,29,1,30,1,30,1,31,1,31,1,32,1,32,1,33,1,33,1,33,
  	1,33,0,0,34,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,0,17,0,19,0,21,0,23,0,25,
  	0,27,0,29,0,31,0,33,0,35,0,37,0,39,0,41,0,43,0,45,0,47,0,49,0,51,0,53,
  	0,55,0,57,0,59,0,61,0,63,0,65,0,67,8,1,0,31,3,0,65,90,95,95,97,122,4,
  	0,48,58,64,90,95,95,97,122,5,0,32,32,48,58,64,90,95,95,97,122,1,0,48,
  	57,2,0,65,65,97,97,2,0,66,66,98,98,2,0,67,67,99,99,2,0,68,68,100,100,
  	2,0,69,69,101,101,2,0,70,70,102,102,2,0,71,71,103,103,2,0,72,72,104,104,
  	2,0,73,73,105,105,2,0,74,74,106,106,2,0,75,75,107,107,2,0,76,76,108,108,
  	2,0,77,77,109,109,2,0,78,78,110,110,2,0,79,79,111,111,2,0,80,80,112,112,
  	2,0,81,81,113,113,2,0,82,82,114,114,2,0,83,83,115,115,2,0,84,84,116,116,
  	2,0,85,85,117,117,2,0,86,86,118,118,2,0,87,87,119,119,2,0,88,88,120,120,
  	2,0,89,89,121,121,2,0,90,90,122,122,2,0,9,10,32,32,243,0,1,1,0,0,0,0,
  	3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,
  	0,0,67,1,0,0,0,1,69,1,0,0,0,3,71,1,0,0,0,5,73,1,0,0,0,7,183,1,0,0,0,9,
  	185,1,0,0,0,11,192,1,0,0,0,13,203,1,0,0,0,15,207,1,0,0,0,17,209,1,0,0,
  	0,19,211,1,0,0,0,21,213,1,0,0,0,23,215,1,0,0,0,25,217,1,0,0,0,27,219,
  	1,0,0,0,29,221,1,0,0,0,31,223,1,0,0,0,33,225,1,0,0,0,35,227,1,0,0,0,37,
  	229,1,0,0,0,39,231,1,0,0,0,41,233,1,0,0,0,43,235,1,0,0,0,45,237,1,0,0,
  	0,47,239,1,0,0,0,49,241,1,0,0,0,51,243,1,0,0,0,53,245,1,0,0,0,55,247,
  	1,0,0,0,57,249,1,0,0,0,59,251,1,0,0,0,61,253,1,0,0,0,63,255,1,0,0,0,65,
  	257,1,0,0,0,67,259,1,0,0,0,69,70,5,40,0,0,70,2,1,0,0,0,71,72,5,41,0,0,
  	72,4,1,0,0,0,73,74,5,44,0,0,74,6,1,0,0,0,75,76,3,21,10,0,76,77,3,43,21,
  	0,77,78,3,55,27,0,78,79,3,17,8,0,79,80,3,37,18,0,80,81,3,23,11,0,81,82,
  	5,32,0,0,82,83,3,45,22,0,83,84,3,49,24,0,84,85,3,23,11,0,85,86,3,19,9,
  	0,86,87,3,31,15,0,87,88,3,51,25,0,88,89,3,31,15,0,89,90,3,43,21,0,90,
  	91,3,41,20,0,91,184,1,0,0,0,92,93,3,53,26,0,93,94,3,31,15,0,94,95,3,39,
  	19,0,95,96,3,23,11,0,96,97,5,32,0,0,97,98,3,59,29,0,98,99,3,31,15,0,99,
  	100,3,53,26,0,100,101,3,29,14,0,101,102,5,32,0,0,102,103,3,53,26,0,103,
  	104,3,31,15,0,104,105,3,39,19,0,105,106,3,23,11,0,106,107,5,32,0,0,107,
  	108,3,65,32,0,108,109,3,43,21,0,109,110,3,41,20,0,110,111,3,23,11,0,111,
  	184,1,0,0,0,112,113,3,53,26,0,113,114,3,31,15,0,114,115,3,39,19,0,115,
  	116,3,23,11,0,116,117,3,51,25,0,117,118,3,53,26,0,118,119,3,15,7,0,119,
  	120,3,39,19,0,120,121,3,45,22,0,121,122,5,32,0,0,122,123,3,59,29,0,123,
  	124,3,31,15,0,124,125,3,53,26,0,125,126,3,29,14,0,126,127,5,32,0,0,127,
  	128,3,53,26,0,128,129,3,31,15,0,129,130,3,39,19,0,130,131,3,23,11,0,131,
  	132,5,32,0,0,132,133,3,65,32,0,133,134,3,43,21,0,134,135,3,41,20,0,135,
  	136,3,23,11,0,136,184,1,0,0,0,137,138,3,31,15,0,138,139,3,41,20,0,139,
  	140,3,53,26,0,140,141,3,23,11,0,141,142,3,49,24,0,142,143,3,57,28,0,143,
  	144,3,15,7,0,144,145,3,37,18,0,145,146,5,32,0,0,146,147,3,63,31,0,147,
  	148,3,23,11,0,148,149,3,15,7,0,149,150,3,49,24,0,150,151,5,32,0,0,151,
  	152,3,53,26,0,152,153,3,43,21,0,153,154,5,32,0,0,154,155,3,39,19,0,155,
  	156,3,43,21,0,156,157,3,41,20,0,157,158,3,53,26,0,158,159,3,29,14,0,159,
  	184,1,0,0,0,160,161,3,31,15,0,161,162,3,41,20,0,162,163,3,53,26,0,163,
  	164,3,23,11,0,164,165,3,49,24,0,165,166,3,57,28,0,166,167,3,15,7,0,167,
  	168,3,37,18,0,168,169,5,32,0,0,169,170,3,21,10,0,170,171,3,15,7,0,171,
  	172,3,63,31,0,172,173,5,32,0,0,173,174,3,53,26,0,174,175,3,43,21,0,175,
  	176,5,32,0,0,176,177,3,51,25,0,177,178,3,23,11,0,178,179,3,19,9,0,179,
  	180,3,43,21,0,180,181,3,41,20,0,181,182,3,21,10,0,182,184,1,0,0,0,183,
  	75,1,0,0,0,183,92,1,0,0,0,183,112,1,0,0,0,183,137,1,0,0,0,183,160,1,0,
  	0,0,184,8,1,0,0,0,185,189,7,0,0,0,186,188,7,1,0,0,187,186,1,0,0,0,188,
  	191,1,0,0,0,189,187,1,0,0,0,189,190,1,0,0,0,190,10,1,0,0,0,191,189,1,
  	0,0,0,192,193,5,34,0,0,193,197,7,0,0,0,194,196,7,2,0,0,195,194,1,0,0,
  	0,196,199,1,0,0,0,197,195,1,0,0,0,197,198,1,0,0,0,198,200,1,0,0,0,199,
  	197,1,0,0,0,200,201,5,34,0,0,201,12,1,0,0,0,202,204,7,3,0,0,203,202,1,
  	0,0,0,204,205,1,0,0,0,205,203,1,0,0,0,205,206,1,0,0,0,206,14,1,0,0,0,
  	207,208,7,4,0,0,208,16,1,0,0,0,209,210,7,5,0,0,210,18,1,0,0,0,211,212,
  	7,6,0,0,212,20,1,0,0,0,213,214,7,7,0,0,214,22,1,0,0,0,215,216,7,8,0,0,
  	216,24,1,0,0,0,217,218,7,9,0,0,218,26,1,0,0,0,219,220,7,10,0,0,220,28,
  	1,0,0,0,221,222,7,11,0,0,222,30,1,0,0,0,223,224,7,12,0,0,224,32,1,0,0,
  	0,225,226,7,13,0,0,226,34,1,0,0,0,227,228,7,14,0,0,228,36,1,0,0,0,229,
  	230,7,15,0,0,230,38,1,0,0,0,231,232,7,16,0,0,232,40,1,0,0,0,233,234,7,
  	17,0,0,234,42,1,0,0,0,235,236,7,18,0,0,236,44,1,0,0,0,237,238,7,19,0,
  	0,238,46,1,0,0,0,239,240,7,20,0,0,240,48,1,0,0,0,241,242,7,21,0,0,242,
  	50,1,0,0,0,243,244,7,22,0,0,244,52,1,0,0,0,245,246,7,23,0,0,246,54,1,
  	0,0,0,247,248,7,24,0,0,248,56,1,0,0,0,249,250,7,25,0,0,250,58,1,0,0,0,
  	251,252,7,26,0,0,252,60,1,0,0,0,253,254,7,27,0,0,254,62,1,0,0,0,255,256,
  	7,28,0,0,256,64,1,0,0,0,257,258,7,29,0,0,258,66,1,0,0,0,259,260,7,30,
  	0,0,260,261,1,0,0,0,261,262,6,33,0,0,262,68,1,0,0,0,5,0,183,189,197,205,
  	1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  typesignaturelexerLexerStaticData = staticData.release();
}

}

TypeSignatureLexer::TypeSignatureLexer(CharStream *input) : Lexer(input) {
  TypeSignatureLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *typesignaturelexerLexerStaticData->atn, typesignaturelexerLexerStaticData->decisionToDFA, typesignaturelexerLexerStaticData->sharedContextCache);
}

TypeSignatureLexer::~TypeSignatureLexer() {
  delete _interpreter;
}

std::string TypeSignatureLexer::getGrammarFileName() const {
  return "TypeSignature.g4";
}

const std::vector<std::string>& TypeSignatureLexer::getRuleNames() const {
  return typesignaturelexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& TypeSignatureLexer::getChannelNames() const {
  return typesignaturelexerLexerStaticData->channelNames;
}

const std::vector<std::string>& TypeSignatureLexer::getModeNames() const {
  return typesignaturelexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& TypeSignatureLexer::getVocabulary() const {
  return typesignaturelexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView TypeSignatureLexer::getSerializedATN() const {
  return typesignaturelexerLexerStaticData->serializedATN;
}

const atn::ATN& TypeSignatureLexer::getATN() const {
  return *typesignaturelexerLexerStaticData->atn;
}




void TypeSignatureLexer::initialize() {
  ::antlr4::internal::call_once(typesignaturelexerLexerOnceFlag, typesignaturelexerLexerInitialize);
}
