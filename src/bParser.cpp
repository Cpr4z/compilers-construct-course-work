
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
      "ifstmt", "casestmt", "externsmt", "autosmt", "autoarraysmt", "rvalue", 
      "ternary", "comparison", "assignment", "expression", "functioninvocation", 
      "functionparameters", "assign", "incdec", "unary", "binary", "lvalue", 
      "constant", "name"
    },
    std::vector<std::string>{
      "", "','", "';'", "'('", "')'", "':'", "'{'", "'}'", "'return'", "'goto'", 
      "'switch'", "'while'", "'if'", "'else'", "'case'", "'extrn'", "'auto'", 
      "'\\u003F'", "'&'", "'='", "'++'", "'--'", "'-'", "'!'", "'|'", "'=='", 
      "'!='", "'<'", "'<='", "'>'", "'>='", "'<<'", "'>>'", "'+'", "'%'", 
      "'*'", "'/'", "", "", "", "", "", "", "'['", "']'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "NAME", "INT", "STRING1", "STRING2", "BLOCKCOMMENT", "WS", 
      "LBRACK", "RBRACK"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,44,311,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,1,0,5,0,62,8,0,10,0,12,0,65,9,0,1,0,1,0,1,1,1,1,3,1,71,8,
  	1,1,1,1,1,1,1,5,1,76,8,1,10,1,12,1,79,9,1,5,1,81,8,1,10,1,12,1,84,9,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,1,93,8,1,10,1,12,1,96,9,1,3,1,98,8,1,1,
  	1,1,1,1,1,3,1,103,8,1,1,2,1,2,3,2,107,8,2,1,3,1,3,1,3,1,3,1,3,1,3,1,3,
  	1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,3,3,125,8,3,1,4,1,4,1,5,1,5,1,5,1,
  	6,1,6,5,6,134,8,6,10,6,12,6,137,9,6,1,6,1,6,1,7,1,7,1,7,1,7,1,7,3,7,146,
  	8,7,1,7,1,7,1,8,1,8,1,8,1,8,1,9,1,9,1,9,1,9,1,10,1,10,1,10,1,10,1,10,
  	1,10,1,11,1,11,1,11,1,11,1,11,1,11,1,11,3,11,171,8,11,1,12,1,12,1,12,
  	1,12,1,12,1,13,1,13,1,13,1,13,5,13,182,8,13,10,13,12,13,185,9,13,1,13,
  	1,13,1,14,1,14,1,14,3,14,192,8,14,1,14,1,14,1,14,3,14,197,8,14,5,14,199,
  	8,14,10,14,12,14,202,9,14,1,14,1,14,1,15,1,15,1,15,1,15,1,15,1,15,1,15,
  	1,16,1,16,1,16,1,16,3,16,217,8,16,1,17,1,17,1,17,1,17,1,17,1,17,1,18,
  	1,18,1,18,1,18,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,
  	3,19,240,8,19,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,
  	1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,3,20,265,
  	8,20,1,21,1,21,1,21,3,21,270,8,21,1,21,1,21,1,22,1,22,1,22,5,22,277,8,
  	22,10,22,12,22,280,9,22,1,23,1,23,3,23,284,8,23,1,24,1,24,1,25,1,25,1,
  	26,1,26,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,
  	27,3,27,305,8,27,1,28,1,28,1,29,1,29,1,29,0,0,30,0,2,4,6,8,10,12,14,16,
  	18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,56,58,0,4,1,
  	0,20,21,1,0,22,23,3,0,18,18,22,22,24,36,1,0,38,40,325,0,63,1,0,0,0,2,
  	102,1,0,0,0,4,106,1,0,0,0,6,124,1,0,0,0,8,126,1,0,0,0,10,128,1,0,0,0,
  	12,131,1,0,0,0,14,140,1,0,0,0,16,149,1,0,0,0,18,153,1,0,0,0,20,157,1,
  	0,0,0,22,163,1,0,0,0,24,172,1,0,0,0,26,177,1,0,0,0,28,188,1,0,0,0,30,
  	205,1,0,0,0,32,216,1,0,0,0,34,218,1,0,0,0,36,224,1,0,0,0,38,239,1,0,0,
  	0,40,264,1,0,0,0,42,266,1,0,0,0,44,273,1,0,0,0,46,281,1,0,0,0,48,285,
  	1,0,0,0,50,287,1,0,0,0,52,289,1,0,0,0,54,304,1,0,0,0,56,306,1,0,0,0,58,
  	308,1,0,0,0,60,62,3,2,1,0,61,60,1,0,0,0,62,65,1,0,0,0,63,61,1,0,0,0,63,
  	64,1,0,0,0,64,66,1,0,0,0,65,63,1,0,0,0,66,67,5,0,0,1,67,1,1,0,0,0,68,
  	70,3,58,29,0,69,71,3,56,28,0,70,69,1,0,0,0,70,71,1,0,0,0,71,82,1,0,0,
  	0,72,77,3,4,2,0,73,74,5,1,0,0,74,76,3,4,2,0,75,73,1,0,0,0,76,79,1,0,0,
  	0,77,75,1,0,0,0,77,78,1,0,0,0,78,81,1,0,0,0,79,77,1,0,0,0,80,72,1,0,0,
  	0,81,84,1,0,0,0,82,80,1,0,0,0,82,83,1,0,0,0,83,85,1,0,0,0,84,82,1,0,0,
  	0,85,86,5,2,0,0,86,103,1,0,0,0,87,88,3,58,29,0,88,97,5,3,0,0,89,94,3,
  	58,29,0,90,91,5,1,0,0,91,93,3,58,29,0,92,90,1,0,0,0,93,96,1,0,0,0,94,
  	92,1,0,0,0,94,95,1,0,0,0,95,98,1,0,0,0,96,94,1,0,0,0,97,89,1,0,0,0,97,
  	98,1,0,0,0,98,99,1,0,0,0,99,100,5,4,0,0,100,101,3,6,3,0,101,103,1,0,0,
  	0,102,68,1,0,0,0,102,87,1,0,0,0,103,3,1,0,0,0,104,107,3,56,28,0,105,107,
  	3,58,29,0,106,104,1,0,0,0,106,105,1,0,0,0,107,5,1,0,0,0,108,125,3,26,
  	13,0,109,125,3,28,14,0,110,125,3,30,15,0,111,112,3,58,29,0,112,113,5,
  	5,0,0,113,114,3,6,3,0,114,125,1,0,0,0,115,125,3,24,12,0,116,125,3,12,
  	6,0,117,125,3,22,11,0,118,125,3,20,10,0,119,125,3,18,9,0,120,125,3,16,
  	8,0,121,125,3,14,7,0,122,125,3,10,5,0,123,125,3,8,4,0,124,108,1,0,0,0,
  	124,109,1,0,0,0,124,110,1,0,0,0,124,111,1,0,0,0,124,115,1,0,0,0,124,116,
  	1,0,0,0,124,117,1,0,0,0,124,118,1,0,0,0,124,119,1,0,0,0,124,120,1,0,0,
  	0,124,121,1,0,0,0,124,122,1,0,0,0,124,123,1,0,0,0,125,7,1,0,0,0,126,127,
  	5,2,0,0,127,9,1,0,0,0,128,129,3,32,16,0,129,130,5,2,0,0,130,11,1,0,0,
  	0,131,135,5,6,0,0,132,134,3,6,3,0,133,132,1,0,0,0,134,137,1,0,0,0,135,
  	133,1,0,0,0,135,136,1,0,0,0,136,138,1,0,0,0,137,135,1,0,0,0,138,139,5,
  	7,0,0,139,13,1,0,0,0,140,145,5,8,0,0,141,142,5,3,0,0,142,143,3,32,16,
  	0,143,144,5,4,0,0,144,146,1,0,0,0,145,141,1,0,0,0,145,146,1,0,0,0,146,
  	147,1,0,0,0,147,148,5,2,0,0,148,15,1,0,0,0,149,150,5,9,0,0,150,151,3,
  	32,16,0,151,152,5,2,0,0,152,17,1,0,0,0,153,154,5,10,0,0,154,155,3,32,
  	16,0,155,156,3,6,3,0,156,19,1,0,0,0,157,158,5,11,0,0,158,159,5,3,0,0,
  	159,160,3,32,16,0,160,161,5,4,0,0,161,162,3,6,3,0,162,21,1,0,0,0,163,
  	164,5,12,0,0,164,165,5,3,0,0,165,166,3,32,16,0,166,167,5,4,0,0,167,170,
  	3,6,3,0,168,169,5,13,0,0,169,171,3,6,3,0,170,168,1,0,0,0,170,171,1,0,
  	0,0,171,23,1,0,0,0,172,173,5,14,0,0,173,174,3,56,28,0,174,175,5,5,0,0,
  	175,176,3,6,3,0,176,25,1,0,0,0,177,178,5,15,0,0,178,183,3,58,29,0,179,
  	180,5,1,0,0,180,182,3,58,29,0,181,179,1,0,0,0,182,185,1,0,0,0,183,181,
  	1,0,0,0,183,184,1,0,0,0,184,186,1,0,0,0,185,183,1,0,0,0,186,187,5,2,0,
  	0,187,27,1,0,0,0,188,189,5,16,0,0,189,191,3,58,29,0,190,192,3,56,28,0,
  	191,190,1,0,0,0,191,192,1,0,0,0,192,200,1,0,0,0,193,194,5,1,0,0,194,196,
  	3,58,29,0,195,197,3,56,28,0,196,195,1,0,0,0,196,197,1,0,0,0,197,199,1,
  	0,0,0,198,193,1,0,0,0,199,202,1,0,0,0,200,198,1,0,0,0,200,201,1,0,0,0,
  	201,203,1,0,0,0,202,200,1,0,0,0,203,204,5,2,0,0,204,29,1,0,0,0,205,206,
  	5,16,0,0,206,207,3,58,29,0,207,208,5,43,0,0,208,209,5,38,0,0,209,210,
  	5,44,0,0,210,211,5,2,0,0,211,31,1,0,0,0,212,217,3,40,20,0,213,217,3,36,
  	18,0,214,217,3,34,17,0,215,217,3,38,19,0,216,212,1,0,0,0,216,213,1,0,
  	0,0,216,214,1,0,0,0,216,215,1,0,0,0,217,33,1,0,0,0,218,219,3,40,20,0,
  	219,220,5,17,0,0,220,221,3,32,16,0,221,222,5,5,0,0,222,223,3,32,16,0,
  	223,35,1,0,0,0,224,225,3,40,20,0,225,226,3,52,26,0,226,227,3,32,16,0,
  	227,37,1,0,0,0,228,229,3,58,29,0,229,230,3,46,23,0,230,231,3,32,16,0,
  	231,240,1,0,0,0,232,233,3,58,29,0,233,234,5,43,0,0,234,235,3,32,16,0,
  	235,236,5,44,0,0,236,237,3,46,23,0,237,238,3,32,16,0,238,240,1,0,0,0,
  	239,228,1,0,0,0,239,232,1,0,0,0,240,39,1,0,0,0,241,242,5,3,0,0,242,243,
  	3,32,16,0,243,244,5,4,0,0,244,265,1,0,0,0,245,265,3,58,29,0,246,265,3,
  	56,28,0,247,248,3,48,24,0,248,249,3,58,29,0,249,265,1,0,0,0,250,251,3,
  	58,29,0,251,252,3,48,24,0,252,265,1,0,0,0,253,254,3,50,25,0,254,255,3,
  	32,16,0,255,265,1,0,0,0,256,257,5,18,0,0,257,265,3,58,29,0,258,265,3,
  	42,21,0,259,260,3,58,29,0,260,261,5,43,0,0,261,262,3,32,16,0,262,263,
  	5,44,0,0,263,265,1,0,0,0,264,241,1,0,0,0,264,245,1,0,0,0,264,246,1,0,
  	0,0,264,247,1,0,0,0,264,250,1,0,0,0,264,253,1,0,0,0,264,256,1,0,0,0,264,
  	258,1,0,0,0,264,259,1,0,0,0,265,41,1,0,0,0,266,267,3,58,29,0,267,269,
  	5,3,0,0,268,270,3,44,22,0,269,268,1,0,0,0,269,270,1,0,0,0,270,271,1,0,
  	0,0,271,272,5,4,0,0,272,43,1,0,0,0,273,278,3,32,16,0,274,275,5,1,0,0,
  	275,277,3,32,16,0,276,274,1,0,0,0,277,280,1,0,0,0,278,276,1,0,0,0,278,
  	279,1,0,0,0,279,45,1,0,0,0,280,278,1,0,0,0,281,283,5,19,0,0,282,284,3,
  	52,26,0,283,282,1,0,0,0,283,284,1,0,0,0,284,47,1,0,0,0,285,286,7,0,0,
  	0,286,49,1,0,0,0,287,288,7,1,0,0,288,51,1,0,0,0,289,290,7,2,0,0,290,53,
  	1,0,0,0,291,305,3,58,29,0,292,293,5,35,0,0,293,305,3,32,16,0,294,295,
  	3,58,29,0,295,296,5,43,0,0,296,297,5,38,0,0,297,298,5,44,0,0,298,305,
  	1,0,0,0,299,300,3,32,16,0,300,301,5,43,0,0,301,302,3,32,16,0,302,303,
  	5,44,0,0,303,305,1,0,0,0,304,291,1,0,0,0,304,292,1,0,0,0,304,294,1,0,
  	0,0,304,299,1,0,0,0,305,55,1,0,0,0,306,307,7,3,0,0,307,57,1,0,0,0,308,
  	309,5,37,0,0,309,59,1,0,0,0,23,63,70,77,82,94,97,102,106,124,135,145,
  	170,183,191,196,200,216,239,264,269,278,283,304
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
    setState(63);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == bParser::NAME) {
      setState(60);
      definition();
      setState(65);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(66);
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
    setState(102);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(68);
      name();
      setState(70);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
      case 1: {
        setState(69);
        constant();
        break;
      }

      default:
        break;
      }
      setState(82);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 2061584302080) != 0)) {
        setState(72);
        ival();
        setState(77);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == bParser::T__0) {
          setState(73);
          match(bParser::T__0);
          setState(74);
          ival();
          setState(79);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(84);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(85);
      match(bParser::T__1);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(87);
      name();
      setState(88);
      match(bParser::T__2);
      setState(97);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == bParser::NAME) {
        setState(89);
        name();
        setState(94);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == bParser::T__0) {
          setState(90);
          match(bParser::T__0);
          setState(91);
          name();
          setState(96);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(99);
      match(bParser::T__3);
      setState(100);
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
    setState(106);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case bParser::INT:
      case bParser::STRING1:
      case bParser::STRING2: {
        enterOuterAlt(_localctx, 1);
        setState(104);
        constant();
        break;
      }

      case bParser::NAME: {
        enterOuterAlt(_localctx, 2);
        setState(105);
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

bParser::AutoarraysmtContext* bParser::StatementContext::autoarraysmt() {
  return getRuleContext<bParser::AutoarraysmtContext>(0);
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
    setState(124);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(108);
      externsmt();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(109);
      autosmt();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(110);
      autoarraysmt();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(111);
      name();
      setState(112);
      match(bParser::T__4);
      setState(113);
      statement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(115);
      casestmt();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(116);
      blockstmt();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(117);
      ifstmt();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(118);
      whilestmt();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(119);
      switchstmt();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(120);
      gotostmt();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(121);
      returnstmt();
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(122);
      expressionstmt();
      break;
    }

    case 13: {
      enterOuterAlt(_localctx, 13);
      setState(123);
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
    setState(128);
    rvalue();
    setState(129);
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
    setState(131);
    match(bParser::T__5);
    setState(135);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2061600415564) != 0)) {
      setState(132);
      statement();
      setState(137);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(138);
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
    setState(140);
    match(bParser::T__7);
    setState(145);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == bParser::T__2) {
      setState(141);
      match(bParser::T__2);
      setState(142);
      rvalue();
      setState(143);
      match(bParser::T__3);
    }
    setState(147);
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
    setState(149);
    match(bParser::T__8);
    setState(150);
    rvalue();
    setState(151);
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
    setState(153);
    match(bParser::T__9);
    setState(154);
    rvalue();
    setState(155);
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
    setState(157);
    match(bParser::T__10);
    setState(158);
    match(bParser::T__2);
    setState(159);
    rvalue();
    setState(160);
    match(bParser::T__3);
    setState(161);
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
    setState(163);
    match(bParser::T__11);
    setState(164);
    match(bParser::T__2);
    setState(165);
    rvalue();
    setState(166);
    match(bParser::T__3);
    setState(167);
    statement();
    setState(170);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      setState(168);
      match(bParser::T__12);
      setState(169);
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
    setState(172);
    match(bParser::T__13);
    setState(173);
    constant();
    setState(174);
    match(bParser::T__4);
    setState(175);
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
    setState(177);
    match(bParser::T__14);
    setState(178);
    name();
    setState(183);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == bParser::T__0) {
      setState(179);
      match(bParser::T__0);
      setState(180);
      name();
      setState(185);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(186);
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
    setState(188);
    match(bParser::T__15);
    setState(189);
    name();
    setState(191);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1924145348608) != 0)) {
      setState(190);
      constant();
    }
    setState(200);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == bParser::T__0) {
      setState(193);
      match(bParser::T__0);
      setState(194);
      name();
      setState(196);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 1924145348608) != 0)) {
        setState(195);
        constant();
      }
      setState(202);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(203);
    match(bParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AutoarraysmtContext ------------------------------------------------------------------

bParser::AutoarraysmtContext::AutoarraysmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

bParser::NameContext* bParser::AutoarraysmtContext::name() {
  return getRuleContext<bParser::NameContext>(0);
}

tree::TerminalNode* bParser::AutoarraysmtContext::LBRACK() {
  return getToken(bParser::LBRACK, 0);
}

tree::TerminalNode* bParser::AutoarraysmtContext::INT() {
  return getToken(bParser::INT, 0);
}

tree::TerminalNode* bParser::AutoarraysmtContext::RBRACK() {
  return getToken(bParser::RBRACK, 0);
}


size_t bParser::AutoarraysmtContext::getRuleIndex() const {
  return bParser::RuleAutoarraysmt;
}

void bParser::AutoarraysmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAutoarraysmt(this);
}

void bParser::AutoarraysmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<bListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAutoarraysmt(this);
}


std::any bParser::AutoarraysmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<bVisitor*>(visitor))
    return parserVisitor->visitAutoarraysmt(this);
  else
    return visitor->visitChildren(this);
}

bParser::AutoarraysmtContext* bParser::autoarraysmt() {
  AutoarraysmtContext *_localctx = _tracker.createInstance<AutoarraysmtContext>(_ctx, getState());
  enterRule(_localctx, 30, bParser::RuleAutoarraysmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(205);
    match(bParser::T__15);
    setState(206);
    name();
    setState(207);
    match(bParser::LBRACK);
    setState(208);
    match(bParser::INT);
    setState(209);
    match(bParser::RBRACK);
    setState(210);
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
  enterRule(_localctx, 32, bParser::RuleRvalue);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(216);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(212);
      expression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(213);
      comparison();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(214);
      ternary();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(215);
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
  enterRule(_localctx, 34, bParser::RuleTernary);

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
    expression();
    setState(219);
    match(bParser::T__16);
    setState(220);
    rvalue();
    setState(221);
    match(bParser::T__4);
    setState(222);
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
  enterRule(_localctx, 36, bParser::RuleComparison);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(224);
    expression();
    setState(225);
    binary();
    setState(226);
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

std::vector<bParser::RvalueContext *> bParser::AssignmentContext::rvalue() {
  return getRuleContexts<bParser::RvalueContext>();
}

bParser::RvalueContext* bParser::AssignmentContext::rvalue(size_t i) {
  return getRuleContext<bParser::RvalueContext>(i);
}

tree::TerminalNode* bParser::AssignmentContext::LBRACK() {
  return getToken(bParser::LBRACK, 0);
}

tree::TerminalNode* bParser::AssignmentContext::RBRACK() {
  return getToken(bParser::RBRACK, 0);
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
  enterRule(_localctx, 38, bParser::RuleAssignment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(239);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(228);
      name();
      setState(229);
      assign();
      setState(230);
      rvalue();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(232);
      name();
      setState(233);
      match(bParser::LBRACK);
      setState(234);
      rvalue();
      setState(235);
      match(bParser::RBRACK);
      setState(236);
      assign();
      setState(237);
      rvalue();
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

tree::TerminalNode* bParser::ExpressionContext::LBRACK() {
  return getToken(bParser::LBRACK, 0);
}

tree::TerminalNode* bParser::ExpressionContext::RBRACK() {
  return getToken(bParser::RBRACK, 0);
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
  enterRule(_localctx, 40, bParser::RuleExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(264);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(241);
      match(bParser::T__2);
      setState(242);
      rvalue();
      setState(243);
      match(bParser::T__3);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(245);
      name();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(246);
      constant();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(247);
      incdec();
      setState(248);
      name();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(250);
      name();
      setState(251);
      incdec();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(253);
      unary();
      setState(254);
      rvalue();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(256);
      match(bParser::T__17);
      setState(257);
      name();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(258);
      functioninvocation();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(259);
      name();
      setState(260);
      match(bParser::LBRACK);
      setState(261);
      rvalue();
      setState(262);
      match(bParser::RBRACK);
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
  enterRule(_localctx, 42, bParser::RuleFunctioninvocation);
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
    setState(266);
    name();
    setState(267);
    match(bParser::T__2);
    setState(269);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2061600292872) != 0)) {
      setState(268);
      functionparameters();
    }
    setState(271);
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
  enterRule(_localctx, 44, bParser::RuleFunctionparameters);
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
    setState(273);
    rvalue();
    setState(278);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == bParser::T__0) {
      setState(274);
      match(bParser::T__0);
      setState(275);
      rvalue();
      setState(280);
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
  enterRule(_localctx, 46, bParser::RuleAssign);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(281);
    match(bParser::T__18);
    setState(283);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
    case 1: {
      setState(282);
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
  enterRule(_localctx, 48, bParser::RuleIncdec);
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
    setState(285);
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
  enterRule(_localctx, 50, bParser::RuleUnary);
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
    setState(287);
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
  enterRule(_localctx, 52, bParser::RuleBinary);
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
    setState(289);
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

tree::TerminalNode* bParser::LvalueContext::LBRACK() {
  return getToken(bParser::LBRACK, 0);
}

tree::TerminalNode* bParser::LvalueContext::INT() {
  return getToken(bParser::INT, 0);
}

tree::TerminalNode* bParser::LvalueContext::RBRACK() {
  return getToken(bParser::RBRACK, 0);
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
  enterRule(_localctx, 54, bParser::RuleLvalue);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(304);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(291);
      name();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(292);
      match(bParser::T__34);
      setState(293);
      rvalue();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(294);
      name();
      setState(295);
      match(bParser::LBRACK);
      setState(296);
      match(bParser::INT);
      setState(297);
      match(bParser::RBRACK);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(299);
      rvalue();
      setState(300);
      match(bParser::LBRACK);
      setState(301);
      rvalue();
      setState(302);
      match(bParser::RBRACK);
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
  enterRule(_localctx, 56, bParser::RuleConstant);
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
    setState(306);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1924145348608) != 0))) {
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
  enterRule(_localctx, 58, bParser::RuleName);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(308);
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
