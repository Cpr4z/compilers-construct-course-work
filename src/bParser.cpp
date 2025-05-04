
// Generated from b.g4 by ANTLR 4.13.0


#include "bListener.h"
#include "bVisitor.h"

#include "bParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct BParserStaticData final {
  BParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  BParserStaticData(const BParserStaticData&) = delete;
  BParserStaticData(BParserStaticData&&) = delete;
  BParserStaticData& operator=(const BParserStaticData&) = delete;
  BParserStaticData& operator=(BParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag bParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
BParserStaticData *bParserStaticData = nullptr;

void bParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (bParserStaticData != nullptr) {
    return;
  }
#else
  assert(bParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<BParserStaticData>(
    std::vector<std::string>{
      "program", "definition", "ival", "statement", "nullstmt", "expressionstmt", 
      "blockstmt", "returnstmt", "gotostmt", "switchstmt", "whilestmt", 
      "ifstmt", "casestmt", "externsmt", "autosmt", "rvalue", "ternary", 
      "comparison", "assignment", "expression", "functioninvocation", "functionparameters", 
      "assign", "incdec", "unary", "binary", "lvalue", "constant", "name"
    },
    std::vector<std::string>{
      "", "','", "';'", "'('", "')'", "':'", "'{'", "'}'", "'return'", "'goto'", 
      "'switch'", "'while'", "'if'", "'else'", "'case'", "'extrn'", "'auto'", 
      "'\\u003F'", "'&'", "'='", "'++'", "'--'", "'-'", "'!'", "'|'", "'=='", 
      "'!='", "'<'", "'<='", "'>'", "'>='", "'<<'", "'>>'", "'+'", "'%'", 
      "'*'", "'/'", "'['", "']'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "NAME", "INT", "STRING1", "STRING2", "BLOCKCOMMENT", 
      "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,44,282,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,1,0,5,0,60,8,0,10,0,12,0,63,9,0,1,0,1,0,1,1,1,1,3,1,69,8,1,1,1,1,1,
  	1,1,5,1,74,8,1,10,1,12,1,77,9,1,5,1,79,8,1,10,1,12,1,82,9,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,5,1,91,8,1,10,1,12,1,94,9,1,3,1,96,8,1,1,1,1,1,1,1,
  	3,1,101,8,1,1,2,1,2,3,2,105,8,2,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,
  	3,1,3,1,3,1,3,1,3,1,3,3,3,122,8,3,1,4,1,4,1,5,1,5,1,5,1,6,1,6,5,6,131,
  	8,6,10,6,12,6,134,9,6,1,6,1,6,1,7,1,7,1,7,1,7,1,7,3,7,143,8,7,1,7,1,7,
  	1,8,1,8,1,8,1,8,1,9,1,9,1,9,1,9,1,10,1,10,1,10,1,10,1,10,1,10,1,11,1,
  	11,1,11,1,11,1,11,1,11,1,11,3,11,168,8,11,1,12,1,12,1,12,1,12,1,12,1,
  	13,1,13,1,13,1,13,5,13,179,8,13,10,13,12,13,182,9,13,1,13,1,13,1,14,1,
  	14,1,14,3,14,189,8,14,1,14,1,14,1,14,3,14,194,8,14,5,14,196,8,14,10,14,
  	12,14,199,9,14,1,14,1,14,1,15,1,15,1,15,1,15,3,15,207,8,15,1,16,1,16,
  	1,16,1,16,1,16,1,16,1,17,1,17,1,17,1,17,1,18,1,18,1,18,1,18,1,19,1,19,
  	1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,
  	1,19,1,19,3,19,241,8,19,1,20,1,20,1,20,3,20,246,8,20,1,20,1,20,1,21,1,
  	21,1,21,5,21,253,8,21,10,21,12,21,256,9,21,1,22,1,22,3,22,260,8,22,1,
  	23,1,23,1,24,1,24,1,25,1,25,1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,3,
  	26,276,8,26,1,27,1,27,1,28,1,28,1,28,0,0,29,0,2,4,6,8,10,12,14,16,18,
  	20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,56,0,4,1,0,20,21,
  	1,0,22,23,3,0,18,18,22,22,24,36,1,0,40,42,293,0,61,1,0,0,0,2,100,1,0,
  	0,0,4,104,1,0,0,0,6,121,1,0,0,0,8,123,1,0,0,0,10,125,1,0,0,0,12,128,1,
  	0,0,0,14,137,1,0,0,0,16,146,1,0,0,0,18,150,1,0,0,0,20,154,1,0,0,0,22,
  	160,1,0,0,0,24,169,1,0,0,0,26,174,1,0,0,0,28,185,1,0,0,0,30,206,1,0,0,
  	0,32,208,1,0,0,0,34,214,1,0,0,0,36,218,1,0,0,0,38,240,1,0,0,0,40,242,
  	1,0,0,0,42,249,1,0,0,0,44,257,1,0,0,0,46,261,1,0,0,0,48,263,1,0,0,0,50,
  	265,1,0,0,0,52,275,1,0,0,0,54,277,1,0,0,0,56,279,1,0,0,0,58,60,3,2,1,
  	0,59,58,1,0,0,0,60,63,1,0,0,0,61,59,1,0,0,0,61,62,1,0,0,0,62,64,1,0,0,
  	0,63,61,1,0,0,0,64,65,5,0,0,1,65,1,1,0,0,0,66,68,3,56,28,0,67,69,3,54,
  	27,0,68,67,1,0,0,0,68,69,1,0,0,0,69,80,1,0,0,0,70,75,3,4,2,0,71,72,5,
  	1,0,0,72,74,3,4,2,0,73,71,1,0,0,0,74,77,1,0,0,0,75,73,1,0,0,0,75,76,1,
  	0,0,0,76,79,1,0,0,0,77,75,1,0,0,0,78,70,1,0,0,0,79,82,1,0,0,0,80,78,1,
  	0,0,0,80,81,1,0,0,0,81,83,1,0,0,0,82,80,1,0,0,0,83,84,5,2,0,0,84,101,
  	1,0,0,0,85,86,3,56,28,0,86,95,5,3,0,0,87,92,3,56,28,0,88,89,5,1,0,0,89,
  	91,3,56,28,0,90,88,1,0,0,0,91,94,1,0,0,0,92,90,1,0,0,0,92,93,1,0,0,0,
  	93,96,1,0,0,0,94,92,1,0,0,0,95,87,1,0,0,0,95,96,1,0,0,0,96,97,1,0,0,0,
  	97,98,5,4,0,0,98,99,3,6,3,0,99,101,1,0,0,0,100,66,1,0,0,0,100,85,1,0,
  	0,0,101,3,1,0,0,0,102,105,3,54,27,0,103,105,3,56,28,0,104,102,1,0,0,0,
  	104,103,1,0,0,0,105,5,1,0,0,0,106,122,3,26,13,0,107,122,3,28,14,0,108,
  	109,3,56,28,0,109,110,5,5,0,0,110,111,3,6,3,0,111,122,1,0,0,0,112,122,
  	3,24,12,0,113,122,3,12,6,0,114,122,3,22,11,0,115,122,3,20,10,0,116,122,
  	3,18,9,0,117,122,3,16,8,0,118,122,3,14,7,0,119,122,3,10,5,0,120,122,3,
  	8,4,0,121,106,1,0,0,0,121,107,1,0,0,0,121,108,1,0,0,0,121,112,1,0,0,0,
  	121,113,1,0,0,0,121,114,1,0,0,0,121,115,1,0,0,0,121,116,1,0,0,0,121,117,
  	1,0,0,0,121,118,1,0,0,0,121,119,1,0,0,0,121,120,1,0,0,0,122,7,1,0,0,0,
  	123,124,5,2,0,0,124,9,1,0,0,0,125,126,3,30,15,0,126,127,5,2,0,0,127,11,
  	1,0,0,0,128,132,5,6,0,0,129,131,3,6,3,0,130,129,1,0,0,0,131,134,1,0,0,
  	0,132,130,1,0,0,0,132,133,1,0,0,0,133,135,1,0,0,0,134,132,1,0,0,0,135,
  	136,5,7,0,0,136,13,1,0,0,0,137,142,5,8,0,0,138,139,5,3,0,0,139,140,3,
  	30,15,0,140,141,5,4,0,0,141,143,1,0,0,0,142,138,1,0,0,0,142,143,1,0,0,
  	0,143,144,1,0,0,0,144,145,5,2,0,0,145,15,1,0,0,0,146,147,5,9,0,0,147,
  	148,3,30,15,0,148,149,5,2,0,0,149,17,1,0,0,0,150,151,5,10,0,0,151,152,
  	3,30,15,0,152,153,3,6,3,0,153,19,1,0,0,0,154,155,5,11,0,0,155,156,5,3,
  	0,0,156,157,3,30,15,0,157,158,5,4,0,0,158,159,3,6,3,0,159,21,1,0,0,0,
  	160,161,5,12,0,0,161,162,5,3,0,0,162,163,3,30,15,0,163,164,5,4,0,0,164,
  	167,3,6,3,0,165,166,5,13,0,0,166,168,3,6,3,0,167,165,1,0,0,0,167,168,
  	1,0,0,0,168,23,1,0,0,0,169,170,5,14,0,0,170,171,3,54,27,0,171,172,5,5,
  	0,0,172,173,3,6,3,0,173,25,1,0,0,0,174,175,5,15,0,0,175,180,3,56,28,0,
  	176,177,5,1,0,0,177,179,3,56,28,0,178,176,1,0,0,0,179,182,1,0,0,0,180,
  	178,1,0,0,0,180,181,1,0,0,0,181,183,1,0,0,0,182,180,1,0,0,0,183,184,5,
  	2,0,0,184,27,1,0,0,0,185,186,5,16,0,0,186,188,3,56,28,0,187,189,3,54,
  	27,0,188,187,1,0,0,0,188,189,1,0,0,0,189,197,1,0,0,0,190,191,5,1,0,0,
  	191,193,3,56,28,0,192,194,3,54,27,0,193,192,1,0,0,0,193,194,1,0,0,0,194,
  	196,1,0,0,0,195,190,1,0,0,0,196,199,1,0,0,0,197,195,1,0,0,0,197,198,1,
  	0,0,0,198,200,1,0,0,0,199,197,1,0,0,0,200,201,5,2,0,0,201,29,1,0,0,0,
  	202,207,3,38,19,0,203,207,3,34,17,0,204,207,3,32,16,0,205,207,3,36,18,
  	0,206,202,1,0,0,0,206,203,1,0,0,0,206,204,1,0,0,0,206,205,1,0,0,0,207,
  	31,1,0,0,0,208,209,3,38,19,0,209,210,5,17,0,0,210,211,3,30,15,0,211,212,
  	5,5,0,0,212,213,3,30,15,0,213,33,1,0,0,0,214,215,3,38,19,0,215,216,3,
  	50,25,0,216,217,3,30,15,0,217,35,1,0,0,0,218,219,3,56,28,0,219,220,3,
  	44,22,0,220,221,3,30,15,0,221,37,1,0,0,0,222,223,5,3,0,0,223,224,3,30,
  	15,0,224,225,5,4,0,0,225,241,1,0,0,0,226,241,3,56,28,0,227,241,3,54,27,
  	0,228,229,3,46,23,0,229,230,3,56,28,0,230,241,1,0,0,0,231,232,3,56,28,
  	0,232,233,3,46,23,0,233,241,1,0,0,0,234,235,3,48,24,0,235,236,3,30,15,
  	0,236,241,1,0,0,0,237,238,5,18,0,0,238,241,3,56,28,0,239,241,3,40,20,
  	0,240,222,1,0,0,0,240,226,1,0,0,0,240,227,1,0,0,0,240,228,1,0,0,0,240,
  	231,1,0,0,0,240,234,1,0,0,0,240,237,1,0,0,0,240,239,1,0,0,0,241,39,1,
  	0,0,0,242,243,3,56,28,0,243,245,5,3,0,0,244,246,3,42,21,0,245,244,1,0,
  	0,0,245,246,1,0,0,0,246,247,1,0,0,0,247,248,5,4,0,0,248,41,1,0,0,0,249,
  	254,3,30,15,0,250,251,5,1,0,0,251,253,3,30,15,0,252,250,1,0,0,0,253,256,
  	1,0,0,0,254,252,1,0,0,0,254,255,1,0,0,0,255,43,1,0,0,0,256,254,1,0,0,
  	0,257,259,5,19,0,0,258,260,3,50,25,0,259,258,1,0,0,0,259,260,1,0,0,0,
  	260,45,1,0,0,0,261,262,7,0,0,0,262,47,1,0,0,0,263,264,7,1,0,0,264,49,
  	1,0,0,0,265,266,7,2,0,0,266,51,1,0,0,0,267,276,3,56,28,0,268,269,5,35,
  	0,0,269,276,3,30,15,0,270,271,3,30,15,0,271,272,5,37,0,0,272,273,3,30,
  	15,0,273,274,5,38,0,0,274,276,1,0,0,0,275,267,1,0,0,0,275,268,1,0,0,0,
  	275,270,1,0,0,0,276,53,1,0,0,0,277,278,7,3,0,0,278,55,1,0,0,0,279,280,
  	5,39,0,0,280,57,1,0,0,0,22,61,68,75,80,92,95,100,104,121,132,142,167,
  	180,188,193,197,206,240,245,254,259,275
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  bParserStaticData = staticData.release();
}

}

bParser::bParser(TokenStream *input) : bParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

bParser::bParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  bParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *bParserStaticData->atn, bParserStaticData->decisionToDFA, bParserStaticData->sharedContextCache, options);
}

bParser::~bParser() {
  delete _interpreter;
}

const atn::ATN& bParser::getATN() const {
  return *bParserStaticData->atn;
}

std::string bParser::getGrammarFileName() const {
  return "b.g4";
}

const std::vector<std::string>& bParser::getRuleNames() const {
  return bParserStaticData->ruleNames;
}

const dfa::Vocabulary& bParser::getVocabulary() const {
  return bParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView bParser::getSerializedATN() const {
  return bParserStaticData->serializedATN;
}


//----------------- ProgramContext ------------------------------------------------------------------

bParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* bParser::ProgramContext::EOF() {
  return getToken(bParser::EOF, 0);
}

std::vector<bParser::DefinitionContext *> bParser::ProgramContext::definition() {
  return getRuleContexts<bParser::DefinitionContext>();
}

bParser::DefinitionContext* bParser::ProgramContext::definition(size_t i) {
  return getRuleContext<bParser::DefinitionContext>(i);
}


size_t bParser::ProgramContext::getRuleIndex() const {
  return bParser::RuleProgram;
}

void bParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void bParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}


std::any bParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

bParser::ProgramContext* bParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, bParser::RuleProgram);
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
    setState(61);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == bParser::NAME) {
      setState(58);
      definition();
      setState(63);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(64);
    match(bParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DefinitionContext ------------------------------------------------------------------

bParser::DefinitionContext::DefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<bParser::NameContext *> bParser::DefinitionContext::name() {
  return getRuleContexts<bParser::NameContext>();
}

bParser::NameContext* bParser::DefinitionContext::name(size_t i) {
  return getRuleContext<bParser::NameContext>(i);
}

bParser::ConstantContext* bParser::DefinitionContext::constant() {
  return getRuleContext<bParser::ConstantContext>(0);
}

std::vector<bParser::IvalContext *> bParser::DefinitionContext::ival() {
  return getRuleContexts<bParser::IvalContext>();
}

bParser::IvalContext* bParser::DefinitionContext::ival(size_t i) {
  return getRuleContext<bParser::IvalContext>(i);
}

bParser::StatementContext* bParser::DefinitionContext::statement() {
  return getRuleContext<bParser::StatementContext>(0);
}


size_t bParser::DefinitionContext::getRuleIndex() const {
  return bParser::RuleDefinition;
}

void bParser::DefinitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDefinition(this);
}

void bParser::DefinitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDefinition(this);
}


std::any bParser::DefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bVisitor*>(visitor))
    return parserVisitor->visitDefinition(this);
  else
    return visitor->visitChildren(this);
}

bParser::DefinitionContext* bParser::definition() {
  DefinitionContext *_localctx = _tracker.createInstance<DefinitionContext>(_ctx, getState());
  enterRule(_localctx, 2, bParser::RuleDefinition);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(100);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(66);
      name();
      setState(68);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
      case 1: {
        setState(67);
        constant();
        break;
      }

      default:
        break;
      }
      setState(80);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 8246337208320) != 0)) {
        setState(70);
        ival();
        setState(75);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == bParser::T__0) {
          setState(71);
          match(bParser::T__0);
          setState(72);
          ival();
          setState(77);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(82);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(83);
      match(bParser::T__1);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(85);
      name();
      setState(86);
      match(bParser::T__2);
      setState(95);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == bParser::NAME) {
        setState(87);
        name();
        setState(92);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == bParser::T__0) {
          setState(88);
          match(bParser::T__0);
          setState(89);
          name();
          setState(94);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(97);
      match(bParser::T__3);
      setState(98);
      statement();
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

//----------------- IvalContext ------------------------------------------------------------------

bParser::IvalContext::IvalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

bParser::ConstantContext* bParser::IvalContext::constant() {
  return getRuleContext<bParser::ConstantContext>(0);
}

bParser::NameContext* bParser::IvalContext::name() {
  return getRuleContext<bParser::NameContext>(0);
}


size_t bParser::IvalContext::getRuleIndex() const {
  return bParser::RuleIval;
}

void bParser::IvalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIval(this);
}

void bParser::IvalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIval(this);
}


std::any bParser::IvalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bVisitor*>(visitor))
    return parserVisitor->visitIval(this);
  else
    return visitor->visitChildren(this);
}

bParser::IvalContext* bParser::ival() {
  IvalContext *_localctx = _tracker.createInstance<IvalContext>(_ctx, getState());
  enterRule(_localctx, 4, bParser::RuleIval);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(104);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case bParser::INT:
      case bParser::STRING1:
      case bParser::STRING2: {
        enterOuterAlt(_localctx, 1);
        setState(102);
        constant();
        break;
      }

      case bParser::NAME: {
        enterOuterAlt(_localctx, 2);
        setState(103);
        name();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

bParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

bParser::ExternsmtContext* bParser::StatementContext::externsmt() {
  return getRuleContext<bParser::ExternsmtContext>(0);
}

bParser::AutosmtContext* bParser::StatementContext::autosmt() {
  return getRuleContext<bParser::AutosmtContext>(0);
}

bParser::NameContext* bParser::StatementContext::name() {
  return getRuleContext<bParser::NameContext>(0);
}

bParser::StatementContext* bParser::StatementContext::statement() {
  return getRuleContext<bParser::StatementContext>(0);
}

bParser::CasestmtContext* bParser::StatementContext::casestmt() {
  return getRuleContext<bParser::CasestmtContext>(0);
}

bParser::BlockstmtContext* bParser::StatementContext::blockstmt() {
  return getRuleContext<bParser::BlockstmtContext>(0);
}

bParser::IfstmtContext* bParser::StatementContext::ifstmt() {
  return getRuleContext<bParser::IfstmtContext>(0);
}

bParser::WhilestmtContext* bParser::StatementContext::whilestmt() {
  return getRuleContext<bParser::WhilestmtContext>(0);
}

bParser::SwitchstmtContext* bParser::StatementContext::switchstmt() {
  return getRuleContext<bParser::SwitchstmtContext>(0);
}

bParser::GotostmtContext* bParser::StatementContext::gotostmt() {
  return getRuleContext<bParser::GotostmtContext>(0);
}

bParser::ReturnstmtContext* bParser::StatementContext::returnstmt() {
  return getRuleContext<bParser::ReturnstmtContext>(0);
}

bParser::ExpressionstmtContext* bParser::StatementContext::expressionstmt() {
  return getRuleContext<bParser::ExpressionstmtContext>(0);
}

bParser::NullstmtContext* bParser::StatementContext::nullstmt() {
  return getRuleContext<bParser::NullstmtContext>(0);
}


size_t bParser::StatementContext::getRuleIndex() const {
  return bParser::RuleStatement;
}

void bParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void bParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}


std::any bParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

bParser::StatementContext* bParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 6, bParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(121);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(106);
      externsmt();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(107);
      autosmt();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(108);
      name();
      setState(109);
      match(bParser::T__4);
      setState(110);
      statement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(112);
      casestmt();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(113);
      blockstmt();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(114);
      ifstmt();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(115);
      whilestmt();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(116);
      switchstmt();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(117);
      gotostmt();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(118);
      returnstmt();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(119);
      expressionstmt();
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(120);
      nullstmt();
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

//----------------- NullstmtContext ------------------------------------------------------------------

bParser::NullstmtContext::NullstmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t bParser::NullstmtContext::getRuleIndex() const {
  return bParser::RuleNullstmt;
}

void bParser::NullstmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNullstmt(this);
}

void bParser::NullstmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNullstmt(this);
}


std::any bParser::NullstmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bVisitor*>(visitor))
    return parserVisitor->visitNullstmt(this);
  else
    return visitor->visitChildren(this);
}

bParser::NullstmtContext* bParser::nullstmt() {
  NullstmtContext *_localctx = _tracker.createInstance<NullstmtContext>(_ctx, getState());
  enterRule(_localctx, 8, bParser::RuleNullstmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(123);
    match(bParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionstmtContext ------------------------------------------------------------------

bParser::ExpressionstmtContext::ExpressionstmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

bParser::RvalueContext* bParser::ExpressionstmtContext::rvalue() {
  return getRuleContext<bParser::RvalueContext>(0);
}


size_t bParser::ExpressionstmtContext::getRuleIndex() const {
  return bParser::RuleExpressionstmt;
}

void bParser::ExpressionstmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpressionstmt(this);
}

void bParser::ExpressionstmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpressionstmt(this);
}


std::any bParser::ExpressionstmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bVisitor*>(visitor))
    return parserVisitor->visitExpressionstmt(this);
  else
    return visitor->visitChildren(this);
}

bParser::ExpressionstmtContext* bParser::expressionstmt() {
  ExpressionstmtContext *_localctx = _tracker.createInstance<ExpressionstmtContext>(_ctx, getState());
  enterRule(_localctx, 10, bParser::RuleExpressionstmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(125);
    rvalue();
    setState(126);
    match(bParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockstmtContext ------------------------------------------------------------------

bParser::BlockstmtContext::BlockstmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<bParser::StatementContext *> bParser::BlockstmtContext::statement() {
  return getRuleContexts<bParser::StatementContext>();
}

bParser::StatementContext* bParser::BlockstmtContext::statement(size_t i) {
  return getRuleContext<bParser::StatementContext>(i);
}


size_t bParser::BlockstmtContext::getRuleIndex() const {
  return bParser::RuleBlockstmt;
}

void bParser::BlockstmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlockstmt(this);
}

void bParser::BlockstmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlockstmt(this);
}


std::any bParser::BlockstmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bVisitor*>(visitor))
    return parserVisitor->visitBlockstmt(this);
  else
    return visitor->visitChildren(this);
}

bParser::BlockstmtContext* bParser::blockstmt() {
  BlockstmtContext *_localctx = _tracker.createInstance<BlockstmtContext>(_ctx, getState());
  enterRule(_localctx, 12, bParser::RuleBlockstmt);
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
    setState(128);
    match(bParser::T__5);
    setState(132);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 8246353321804) != 0)) {
      setState(129);
      statement();
      setState(134);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(135);
    match(bParser::T__6);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnstmtContext ------------------------------------------------------------------

bParser::ReturnstmtContext::ReturnstmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

bParser::RvalueContext* bParser::ReturnstmtContext::rvalue() {
  return getRuleContext<bParser::RvalueContext>(0);
}


size_t bParser::ReturnstmtContext::getRuleIndex() const {
  return bParser::RuleReturnstmt;
}

void bParser::ReturnstmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturnstmt(this);
}

void bParser::ReturnstmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturnstmt(this);
}


std::any bParser::ReturnstmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bVisitor*>(visitor))
    return parserVisitor->visitReturnstmt(this);
  else
    return visitor->visitChildren(this);
}

bParser::ReturnstmtContext* bParser::returnstmt() {
  ReturnstmtContext *_localctx = _tracker.createInstance<ReturnstmtContext>(_ctx, getState());
  enterRule(_localctx, 14, bParser::RuleReturnstmt);
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
    setState(137);
    match(bParser::T__7);
    setState(142);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == bParser::T__2) {
      setState(138);
      match(bParser::T__2);
      setState(139);
      rvalue();
      setState(140);
      match(bParser::T__3);
    }
    setState(144);
    match(bParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GotostmtContext ------------------------------------------------------------------

bParser::GotostmtContext::GotostmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

bParser::RvalueContext* bParser::GotostmtContext::rvalue() {
  return getRuleContext<bParser::RvalueContext>(0);
}


size_t bParser::GotostmtContext::getRuleIndex() const {
  return bParser::RuleGotostmt;
}

void bParser::GotostmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGotostmt(this);
}

void bParser::GotostmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGotostmt(this);
}


std::any bParser::GotostmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bVisitor*>(visitor))
    return parserVisitor->visitGotostmt(this);
  else
    return visitor->visitChildren(this);
}

bParser::GotostmtContext* bParser::gotostmt() {
  GotostmtContext *_localctx = _tracker.createInstance<GotostmtContext>(_ctx, getState());
  enterRule(_localctx, 16, bParser::RuleGotostmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(146);
    match(bParser::T__8);
    setState(147);
    rvalue();
    setState(148);
    match(bParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SwitchstmtContext ------------------------------------------------------------------

bParser::SwitchstmtContext::SwitchstmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

bParser::RvalueContext* bParser::SwitchstmtContext::rvalue() {
  return getRuleContext<bParser::RvalueContext>(0);
}

bParser::StatementContext* bParser::SwitchstmtContext::statement() {
  return getRuleContext<bParser::StatementContext>(0);
}


size_t bParser::SwitchstmtContext::getRuleIndex() const {
  return bParser::RuleSwitchstmt;
}

void bParser::SwitchstmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSwitchstmt(this);
}

void bParser::SwitchstmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSwitchstmt(this);
}


std::any bParser::SwitchstmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bVisitor*>(visitor))
    return parserVisitor->visitSwitchstmt(this);
  else
    return visitor->visitChildren(this);
}

bParser::SwitchstmtContext* bParser::switchstmt() {
  SwitchstmtContext *_localctx = _tracker.createInstance<SwitchstmtContext>(_ctx, getState());
  enterRule(_localctx, 18, bParser::RuleSwitchstmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(150);
    match(bParser::T__9);
    setState(151);
    rvalue();
    setState(152);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhilestmtContext ------------------------------------------------------------------

bParser::WhilestmtContext::WhilestmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

bParser::RvalueContext* bParser::WhilestmtContext::rvalue() {
  return getRuleContext<bParser::RvalueContext>(0);
}

bParser::StatementContext* bParser::WhilestmtContext::statement() {
  return getRuleContext<bParser::StatementContext>(0);
}


size_t bParser::WhilestmtContext::getRuleIndex() const {
  return bParser::RuleWhilestmt;
}

void bParser::WhilestmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhilestmt(this);
}

void bParser::WhilestmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhilestmt(this);
}


std::any bParser::WhilestmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bVisitor*>(visitor))
    return parserVisitor->visitWhilestmt(this);
  else
    return visitor->visitChildren(this);
}

bParser::WhilestmtContext* bParser::whilestmt() {
  WhilestmtContext *_localctx = _tracker.createInstance<WhilestmtContext>(_ctx, getState());
  enterRule(_localctx, 20, bParser::RuleWhilestmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(154);
    match(bParser::T__10);
    setState(155);
    match(bParser::T__2);
    setState(156);
    rvalue();
    setState(157);
    match(bParser::T__3);
    setState(158);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfstmtContext ------------------------------------------------------------------

bParser::IfstmtContext::IfstmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

bParser::RvalueContext* bParser::IfstmtContext::rvalue() {
  return getRuleContext<bParser::RvalueContext>(0);
}

std::vector<bParser::StatementContext *> bParser::IfstmtContext::statement() {
  return getRuleContexts<bParser::StatementContext>();
}

bParser::StatementContext* bParser::IfstmtContext::statement(size_t i) {
  return getRuleContext<bParser::StatementContext>(i);
}


size_t bParser::IfstmtContext::getRuleIndex() const {
  return bParser::RuleIfstmt;
}

void bParser::IfstmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfstmt(this);
}

void bParser::IfstmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfstmt(this);
}


std::any bParser::IfstmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bVisitor*>(visitor))
    return parserVisitor->visitIfstmt(this);
  else
    return visitor->visitChildren(this);
}

bParser::IfstmtContext* bParser::ifstmt() {
  IfstmtContext *_localctx = _tracker.createInstance<IfstmtContext>(_ctx, getState());
  enterRule(_localctx, 22, bParser::RuleIfstmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(160);
    match(bParser::T__11);
    setState(161);
    match(bParser::T__2);
    setState(162);
    rvalue();
    setState(163);
    match(bParser::T__3);
    setState(164);
    statement();
    setState(167);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      setState(165);
      match(bParser::T__12);
      setState(166);
      statement();
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

//----------------- CasestmtContext ------------------------------------------------------------------

bParser::CasestmtContext::CasestmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

bParser::ConstantContext* bParser::CasestmtContext::constant() {
  return getRuleContext<bParser::ConstantContext>(0);
}

bParser::StatementContext* bParser::CasestmtContext::statement() {
  return getRuleContext<bParser::StatementContext>(0);
}


size_t bParser::CasestmtContext::getRuleIndex() const {
  return bParser::RuleCasestmt;
}

void bParser::CasestmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCasestmt(this);
}

void bParser::CasestmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCasestmt(this);
}


std::any bParser::CasestmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bVisitor*>(visitor))
    return parserVisitor->visitCasestmt(this);
  else
    return visitor->visitChildren(this);
}

bParser::CasestmtContext* bParser::casestmt() {
  CasestmtContext *_localctx = _tracker.createInstance<CasestmtContext>(_ctx, getState());
  enterRule(_localctx, 24, bParser::RuleCasestmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(169);
    match(bParser::T__13);
    setState(170);
    constant();
    setState(171);
    match(bParser::T__4);
    setState(172);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExternsmtContext ------------------------------------------------------------------

bParser::ExternsmtContext::ExternsmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<bParser::NameContext *> bParser::ExternsmtContext::name() {
  return getRuleContexts<bParser::NameContext>();
}

bParser::NameContext* bParser::ExternsmtContext::name(size_t i) {
  return getRuleContext<bParser::NameContext>(i);
}


size_t bParser::ExternsmtContext::getRuleIndex() const {
  return bParser::RuleExternsmt;
}

void bParser::ExternsmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExternsmt(this);
}

void bParser::ExternsmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExternsmt(this);
}


std::any bParser::ExternsmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bVisitor*>(visitor))
    return parserVisitor->visitExternsmt(this);
  else
    return visitor->visitChildren(this);
}

bParser::ExternsmtContext* bParser::externsmt() {
  ExternsmtContext *_localctx = _tracker.createInstance<ExternsmtContext>(_ctx, getState());
  enterRule(_localctx, 26, bParser::RuleExternsmt);
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
    setState(174);
    match(bParser::T__14);
    setState(175);
    name();
    setState(180);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == bParser::T__0) {
      setState(176);
      match(bParser::T__0);
      setState(177);
      name();
      setState(182);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(183);
    match(bParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AutosmtContext ------------------------------------------------------------------

bParser::AutosmtContext::AutosmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<bParser::NameContext *> bParser::AutosmtContext::name() {
  return getRuleContexts<bParser::NameContext>();
}

bParser::NameContext* bParser::AutosmtContext::name(size_t i) {
  return getRuleContext<bParser::NameContext>(i);
}

std::vector<bParser::ConstantContext *> bParser::AutosmtContext::constant() {
  return getRuleContexts<bParser::ConstantContext>();
}

bParser::ConstantContext* bParser::AutosmtContext::constant(size_t i) {
  return getRuleContext<bParser::ConstantContext>(i);
}


size_t bParser::AutosmtContext::getRuleIndex() const {
  return bParser::RuleAutosmt;
}

void bParser::AutosmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAutosmt(this);
}

void bParser::AutosmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAutosmt(this);
}


std::any bParser::AutosmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bVisitor*>(visitor))
    return parserVisitor->visitAutosmt(this);
  else
    return visitor->visitChildren(this);
}

bParser::AutosmtContext* bParser::autosmt() {
  AutosmtContext *_localctx = _tracker.createInstance<AutosmtContext>(_ctx, getState());
  enterRule(_localctx, 28, bParser::RuleAutosmt);
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
    setState(185);
    match(bParser::T__15);
    setState(186);
    name();
    setState(188);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 7696581394432) != 0)) {
      setState(187);
      constant();
    }
    setState(197);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == bParser::T__0) {
      setState(190);
      match(bParser::T__0);
      setState(191);
      name();
      setState(193);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 7696581394432) != 0)) {
        setState(192);
        constant();
      }
      setState(199);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(200);
    match(bParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RvalueContext ------------------------------------------------------------------

bParser::RvalueContext::RvalueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

bParser::ExpressionContext* bParser::RvalueContext::expression() {
  return getRuleContext<bParser::ExpressionContext>(0);
}

bParser::ComparisonContext* bParser::RvalueContext::comparison() {
  return getRuleContext<bParser::ComparisonContext>(0);
}

bParser::TernaryContext* bParser::RvalueContext::ternary() {
  return getRuleContext<bParser::TernaryContext>(0);
}

bParser::AssignmentContext* bParser::RvalueContext::assignment() {
  return getRuleContext<bParser::AssignmentContext>(0);
}

bParser::ExpressionListContext* bParser::RvalueContext::expressionList() {
    return getRuleContext<bParser::ExpressionListContext>(0);
}


size_t bParser::RvalueContext::getRuleIndex() const {
  return bParser::RuleRvalue;
}

void bParser::RvalueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRvalue(this);
}

void bParser::RvalueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRvalue(this);
}


std::any bParser::RvalueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bVisitor*>(visitor))
    return parserVisitor->visitRvalue(this);
  else
    return visitor->visitChildren(this);
}

bParser::RvalueContext* bParser::rvalue() {
  RvalueContext *_localctx = _tracker.createInstance<RvalueContext>(_ctx, getState());
  enterRule(_localctx, 30, bParser::RuleRvalue);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(206);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(202);
      expression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(203);
      comparison();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(204);
      ternary();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(205);
      assignment();
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

//----------------- TernaryContext ------------------------------------------------------------------

bParser::TernaryContext::TernaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

bParser::ExpressionContext* bParser::TernaryContext::expression() {
  return getRuleContext<bParser::ExpressionContext>(0);
}

std::vector<bParser::RvalueContext *> bParser::TernaryContext::rvalue() {
  return getRuleContexts<bParser::RvalueContext>();
}

bParser::RvalueContext* bParser::TernaryContext::rvalue(size_t i) {
  return getRuleContext<bParser::RvalueContext>(i);
}


size_t bParser::TernaryContext::getRuleIndex() const {
  return bParser::RuleTernary;
}

void bParser::TernaryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTernary(this);
}

void bParser::TernaryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTernary(this);
}


std::any bParser::TernaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bVisitor*>(visitor))
    return parserVisitor->visitTernary(this);
  else
    return visitor->visitChildren(this);
}

bParser::TernaryContext* bParser::ternary() {
  TernaryContext *_localctx = _tracker.createInstance<TernaryContext>(_ctx, getState());
  enterRule(_localctx, 32, bParser::RuleTernary);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(208);
    expression();
    setState(209);
    match(bParser::T__16);
    setState(210);
    rvalue();
    setState(211);
    match(bParser::T__4);
    setState(212);
    rvalue();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ComparisonContext ------------------------------------------------------------------

bParser::ComparisonContext::ComparisonContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

bParser::ExpressionContext* bParser::ComparisonContext::expression() {
  return getRuleContext<bParser::ExpressionContext>(0);
}

bParser::BinaryContext* bParser::ComparisonContext::binary() {
  return getRuleContext<bParser::BinaryContext>(0);
}

bParser::RvalueContext* bParser::ComparisonContext::rvalue() {
  return getRuleContext<bParser::RvalueContext>(0);
}


size_t bParser::ComparisonContext::getRuleIndex() const {
  return bParser::RuleComparison;
}

void bParser::ComparisonContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComparison(this);
}

void bParser::ComparisonContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComparison(this);
}


std::any bParser::ComparisonContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bVisitor*>(visitor))
    return parserVisitor->visitComparison(this);
  else
    return visitor->visitChildren(this);
}

bParser::ComparisonContext* bParser::comparison() {
  ComparisonContext *_localctx = _tracker.createInstance<ComparisonContext>(_ctx, getState());
  enterRule(_localctx, 34, bParser::RuleComparison);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(214);
    expression();
    setState(215);
    binary();
    setState(216);
    rvalue();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentContext ------------------------------------------------------------------

bParser::AssignmentContext::AssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

bParser::NameContext* bParser::AssignmentContext::name() {
  return getRuleContext<bParser::NameContext>(0);
}

bParser::AssignContext* bParser::AssignmentContext::assign() {
  return getRuleContext<bParser::AssignContext>(0);
}

bParser::RvalueContext* bParser::AssignmentContext::rvalue() {
  return getRuleContext<bParser::RvalueContext>(0);
}


size_t bParser::AssignmentContext::getRuleIndex() const {
  return bParser::RuleAssignment;
}

void bParser::AssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignment(this);
}

void bParser::AssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignment(this);
}


std::any bParser::AssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bVisitor*>(visitor))
    return parserVisitor->visitAssignment(this);
  else
    return visitor->visitChildren(this);
}

bParser::AssignmentContext* bParser::assignment() {
  AssignmentContext *_localctx = _tracker.createInstance<AssignmentContext>(_ctx, getState());
  enterRule(_localctx, 36, bParser::RuleAssignment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(218);
    name();
    setState(219);
    assign();
    setState(220);
    rvalue();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

bParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

bParser::RvalueContext* bParser::ExpressionContext::rvalue() {
  return getRuleContext<bParser::RvalueContext>(0);
}

bParser::NameContext* bParser::ExpressionContext::name() {
  return getRuleContext<bParser::NameContext>(0);
}

bParser::ConstantContext* bParser::ExpressionContext::constant() {
  return getRuleContext<bParser::ConstantContext>(0);
}

bParser::IncdecContext* bParser::ExpressionContext::incdec() {
  return getRuleContext<bParser::IncdecContext>(0);
}

bParser::UnaryContext* bParser::ExpressionContext::unary() {
  return getRuleContext<bParser::UnaryContext>(0);
}

bParser::FunctioninvocationContext* bParser::ExpressionContext::functioninvocation() {
  return getRuleContext<bParser::FunctioninvocationContext>(0);
}


size_t bParser::ExpressionContext::getRuleIndex() const {
  return bParser::RuleExpression;
}

void bParser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void bParser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}


std::any bParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}

bParser::ExpressionContext* bParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 38, bParser::RuleExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(240);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(222);
      match(bParser::T__2);
      setState(223);
      rvalue();
      setState(224);
      match(bParser::T__3);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(226);
      name();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(227);
      constant();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(228);
      incdec();
      setState(229);
      name();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(231);
      name();
      setState(232);
      incdec();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(234);
      unary();
      setState(235);
      rvalue();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(237);
      match(bParser::T__17);
      setState(238);
      name();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(239);
      functioninvocation();
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

//----------------- ExpressionListContext ------------------------------------------------------------------

bParser::ExpressionListContext::ExpressionListContext(ParserRuleContext *parent, size_t invokingState)
        : ParserRuleContext(parent, invokingState) {
}

std::vector<bParser::RvalueContext *> bParser::ExpressionListContext::rvalue() {
    return getRuleContexts<bParser::RvalueContext>();
}

bParser::RvalueContext* bParser::ExpressionListContext::rvalue(size_t i) {
    return getRuleContext<bParser::RvalueContext>(i);
}

size_t bParser::ExpressionListContext::getRuleIndex() const {
    return bParser::RuleExpressionList;
}

void bParser::ExpressionListContext::enterRule(tree::ParseTreeListener *listener) {
    auto parserListener = dynamic_cast<bListener *>(listener);
    if (parserListener != nullptr)
        parserListener->enterExpressionList(this);
}

void bParser::ExpressionListContext::exitRule(tree::ParseTreeListener *listener) {
    auto parserListener = dynamic_cast<bListener *>(listener);
    if (parserListener != nullptr)
        parserListener->exitExpressionList(this);
}


std::any bParser::ExpressionListContext::accept(tree::ParseTreeVisitor *visitor) {
    if (auto parserVisitor = dynamic_cast<bVisitor*>(visitor))
        return parserVisitor->visitExpressionList(this);
    else
        return visitor->visitChildren(this);
}

bParser::ExpressionListContext* bParser::expressionList() {
    ExpressionListContext *_localctx = _tracker.createInstance<ExpressionListContext>(_ctx, getState());
    enterRule(_localctx, 40, bParser::RuleExpressionList);
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
        setState(249);
        rvalue();
        setState(254);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == bParser::T__0) {
            setState(250);
            match(bParser::T__0);
            setState(251);
            rvalue();
            setState(256);
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

//----------------- FunctioninvocationContext ------------------------------------------------------------------

bParser::FunctioninvocationContext::FunctioninvocationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

bParser::NameContext* bParser::FunctioninvocationContext::name() {
  return getRuleContext<bParser::NameContext>(0);
}

bParser::FunctionparametersContext* bParser::FunctioninvocationContext::functionparameters() {
  return getRuleContext<bParser::FunctionparametersContext>(0);
}


size_t bParser::FunctioninvocationContext::getRuleIndex() const {
  return bParser::RuleFunctioninvocation;
}

void bParser::FunctioninvocationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctioninvocation(this);
}

void bParser::FunctioninvocationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctioninvocation(this);
}


std::any bParser::FunctioninvocationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bVisitor*>(visitor))
    return parserVisitor->visitFunctioninvocation(this);
  else
    return visitor->visitChildren(this);
}

bParser::FunctioninvocationContext* bParser::functioninvocation() {
  FunctioninvocationContext *_localctx = _tracker.createInstance<FunctioninvocationContext>(_ctx, getState());
  enterRule(_localctx, 40, bParser::RuleFunctioninvocation);
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
    setState(242);
    name();
    setState(243);
    match(bParser::T__2);
    setState(245);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 8246353199112) != 0)) {
      setState(244);
      functionparameters();
    }
    setState(247);
    match(bParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionparametersContext ------------------------------------------------------------------

bParser::FunctionparametersContext::FunctionparametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<bParser::RvalueContext *> bParser::FunctionparametersContext::rvalue() {
  return getRuleContexts<bParser::RvalueContext>();
}

bParser::RvalueContext* bParser::FunctionparametersContext::rvalue(size_t i) {
  return getRuleContext<bParser::RvalueContext>(i);
}


size_t bParser::FunctionparametersContext::getRuleIndex() const {
  return bParser::RuleFunctionparameters;
}

void bParser::FunctionparametersContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionparameters(this);
}

void bParser::FunctionparametersContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionparameters(this);
}


std::any bParser::FunctionparametersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bVisitor*>(visitor))
    return parserVisitor->visitFunctionparameters(this);
  else
    return visitor->visitChildren(this);
}

bParser::FunctionparametersContext* bParser::functionparameters() {
  FunctionparametersContext *_localctx = _tracker.createInstance<FunctionparametersContext>(_ctx, getState());
  enterRule(_localctx, 42, bParser::RuleFunctionparameters);
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
    setState(249);
    rvalue();
    setState(254);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == bParser::T__0) {
      setState(250);
      match(bParser::T__0);
      setState(251);
      rvalue();
      setState(256);
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

//----------------- AssignContext ------------------------------------------------------------------

bParser::AssignContext::AssignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

bParser::BinaryContext* bParser::AssignContext::binary() {
  return getRuleContext<bParser::BinaryContext>(0);
}


size_t bParser::AssignContext::getRuleIndex() const {
  return bParser::RuleAssign;
}

void bParser::AssignContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssign(this);
}

void bParser::AssignContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssign(this);
}


std::any bParser::AssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bVisitor*>(visitor))
    return parserVisitor->visitAssign(this);
  else
    return visitor->visitChildren(this);
}

bParser::AssignContext* bParser::assign() {
  AssignContext *_localctx = _tracker.createInstance<AssignContext>(_ctx, getState());
  enterRule(_localctx, 44, bParser::RuleAssign);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(257);
    match(bParser::T__18);
    setState(259);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      setState(258);
      binary();
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

//----------------- IncdecContext ------------------------------------------------------------------

bParser::IncdecContext::IncdecContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t bParser::IncdecContext::getRuleIndex() const {
  return bParser::RuleIncdec;
}

void bParser::IncdecContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIncdec(this);
}

void bParser::IncdecContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIncdec(this);
}


std::any bParser::IncdecContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bVisitor*>(visitor))
    return parserVisitor->visitIncdec(this);
  else
    return visitor->visitChildren(this);
}

bParser::IncdecContext* bParser::incdec() {
  IncdecContext *_localctx = _tracker.createInstance<IncdecContext>(_ctx, getState());
  enterRule(_localctx, 46, bParser::RuleIncdec);
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
    setState(261);
    _la = _input->LA(1);
    if (!(_la == bParser::T__19

    || _la == bParser::T__20)) {
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

//----------------- UnaryContext ------------------------------------------------------------------

bParser::UnaryContext::UnaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t bParser::UnaryContext::getRuleIndex() const {
  return bParser::RuleUnary;
}

void bParser::UnaryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnary(this);
}

void bParser::UnaryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnary(this);
}


std::any bParser::UnaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bVisitor*>(visitor))
    return parserVisitor->visitUnary(this);
  else
    return visitor->visitChildren(this);
}

bParser::UnaryContext* bParser::unary() {
  UnaryContext *_localctx = _tracker.createInstance<UnaryContext>(_ctx, getState());
  enterRule(_localctx, 48, bParser::RuleUnary);
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
    setState(263);
    _la = _input->LA(1);
    if (!(_la == bParser::T__21

    || _la == bParser::T__22)) {
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

//----------------- BinaryContext ------------------------------------------------------------------

bParser::BinaryContext::BinaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t bParser::BinaryContext::getRuleIndex() const {
  return bParser::RuleBinary;
}

void bParser::BinaryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinary(this);
}

void bParser::BinaryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinary(this);
}


std::any bParser::BinaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bVisitor*>(visitor))
    return parserVisitor->visitBinary(this);
  else
    return visitor->visitChildren(this);
}

bParser::BinaryContext* bParser::binary() {
  BinaryContext *_localctx = _tracker.createInstance<BinaryContext>(_ctx, getState());
  enterRule(_localctx, 50, bParser::RuleBinary);
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
    setState(265);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 137426632704) != 0))) {
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

//----------------- LvalueContext ------------------------------------------------------------------

bParser::LvalueContext::LvalueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

bParser::NameContext* bParser::LvalueContext::name() {
  return getRuleContext<bParser::NameContext>(0);
}

std::vector<bParser::RvalueContext *> bParser::LvalueContext::rvalue() {
  return getRuleContexts<bParser::RvalueContext>();
}

bParser::RvalueContext* bParser::LvalueContext::rvalue(size_t i) {
  return getRuleContext<bParser::RvalueContext>(i);
}


size_t bParser::LvalueContext::getRuleIndex() const {
  return bParser::RuleLvalue;
}

void bParser::LvalueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLvalue(this);
}

void bParser::LvalueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLvalue(this);
}


std::any bParser::LvalueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bVisitor*>(visitor))
    return parserVisitor->visitLvalue(this);
  else
    return visitor->visitChildren(this);
}

bParser::LvalueContext* bParser::lvalue() {
  LvalueContext *_localctx = _tracker.createInstance<LvalueContext>(_ctx, getState());
  enterRule(_localctx, 52, bParser::RuleLvalue);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(275);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(267);
      name();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(268);
      match(bParser::T__34);
      setState(269);
      rvalue();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(270);
      rvalue();
      setState(271);
      match(bParser::T__36);
      setState(272);
      rvalue();
      setState(273);
      match(bParser::T__37);
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

//----------------- ConstantContext ------------------------------------------------------------------

bParser::ConstantContext::ConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* bParser::ConstantContext::INT() {
  return getToken(bParser::INT, 0);
}

tree::TerminalNode* bParser::ConstantContext::STRING1() {
  return getToken(bParser::STRING1, 0);
}

tree::TerminalNode* bParser::ConstantContext::STRING2() {
  return getToken(bParser::STRING2, 0);
}


size_t bParser::ConstantContext::getRuleIndex() const {
  return bParser::RuleConstant;
}

void bParser::ConstantContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstant(this);
}

void bParser::ConstantContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstant(this);
}


std::any bParser::ConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bVisitor*>(visitor))
    return parserVisitor->visitConstant(this);
  else
    return visitor->visitChildren(this);
}

bParser::ConstantContext* bParser::constant() {
  ConstantContext *_localctx = _tracker.createInstance<ConstantContext>(_ctx, getState());
  enterRule(_localctx, 54, bParser::RuleConstant);
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
    setState(277);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 7696581394432) != 0))) {
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

//----------------- NameContext ------------------------------------------------------------------

bParser::NameContext::NameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* bParser::NameContext::NAME() {
  return getToken(bParser::NAME, 0);
}


size_t bParser::NameContext::getRuleIndex() const {
  return bParser::RuleName;
}

void bParser::NameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterName(this);
}

void bParser::NameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitName(this);
}


std::any bParser::NameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bVisitor*>(visitor))
    return parserVisitor->visitName(this);
  else
    return visitor->visitChildren(this);
}

bParser::NameContext* bParser::name() {
  NameContext *_localctx = _tracker.createInstance<NameContext>(_ctx, getState());
  enterRule(_localctx, 56, bParser::RuleName);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(279);
    match(bParser::NAME);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void bParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  bParserInitialize();
#else
  ::antlr4::internal::call_once(bParserOnceFlag, bParserInitialize);
#endif
}
