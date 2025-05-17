
// Generated from b.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "bParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by bParser.
 */
class  bListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(bParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(bParser::ProgramContext *ctx) = 0;

  virtual void enterDefinition(bParser::DefinitionContext *ctx) = 0;
  virtual void exitDefinition(bParser::DefinitionContext *ctx) = 0;

  virtual void enterIval(bParser::IvalContext *ctx) = 0;
  virtual void exitIval(bParser::IvalContext *ctx) = 0;

  virtual void enterStatement(bParser::StatementContext *ctx) = 0;
  virtual void exitStatement(bParser::StatementContext *ctx) = 0;

  virtual void enterNullstmt(bParser::NullstmtContext *ctx) = 0;
  virtual void exitNullstmt(bParser::NullstmtContext *ctx) = 0;

  virtual void enterExpressionstmt(bParser::ExpressionstmtContext *ctx) = 0;
  virtual void exitExpressionstmt(bParser::ExpressionstmtContext *ctx) = 0;

  virtual void enterBlockstmt(bParser::BlockstmtContext *ctx) = 0;
  virtual void exitBlockstmt(bParser::BlockstmtContext *ctx) = 0;

  virtual void enterReturnstmt(bParser::ReturnstmtContext *ctx) = 0;
  virtual void exitReturnstmt(bParser::ReturnstmtContext *ctx) = 0;

  virtual void enterGotostmt(bParser::GotostmtContext *ctx) = 0;
  virtual void exitGotostmt(bParser::GotostmtContext *ctx) = 0;

  virtual void enterSwitchstmt(bParser::SwitchstmtContext *ctx) = 0;
  virtual void exitSwitchstmt(bParser::SwitchstmtContext *ctx) = 0;

  virtual void enterWhilestmt(bParser::WhilestmtContext *ctx) = 0;
  virtual void exitWhilestmt(bParser::WhilestmtContext *ctx) = 0;

  virtual void enterIfstmt(bParser::IfstmtContext *ctx) = 0;
  virtual void exitIfstmt(bParser::IfstmtContext *ctx) = 0;

  virtual void enterCasestmt(bParser::CasestmtContext *ctx) = 0;
  virtual void exitCasestmt(bParser::CasestmtContext *ctx) = 0;

  virtual void enterExternsmt(bParser::ExternsmtContext *ctx) = 0;
  virtual void exitExternsmt(bParser::ExternsmtContext *ctx) = 0;

  virtual void enterAutosmt(bParser::AutosmtContext *ctx) = 0;
  virtual void exitAutosmt(bParser::AutosmtContext *ctx) = 0;

  virtual void enterAutoarraysmt(bParser::AutoarraysmtContext *ctx) = 0;
  virtual void exitAutoarraysmt(bParser::AutoarraysmtContext *ctx) = 0;

  virtual void enterRvalue(bParser::RvalueContext *ctx) = 0;
  virtual void exitRvalue(bParser::RvalueContext *ctx) = 0;

  virtual void enterTernary(bParser::TernaryContext *ctx) = 0;
  virtual void exitTernary(bParser::TernaryContext *ctx) = 0;

  virtual void enterComparison(bParser::ComparisonContext *ctx) = 0;
  virtual void exitComparison(bParser::ComparisonContext *ctx) = 0;

  virtual void enterAssignment(bParser::AssignmentContext *ctx) = 0;
  virtual void exitAssignment(bParser::AssignmentContext *ctx) = 0;

  virtual void enterExpression(bParser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(bParser::ExpressionContext *ctx) = 0;

  virtual void enterFunctioninvocation(bParser::FunctioninvocationContext *ctx) = 0;
  virtual void exitFunctioninvocation(bParser::FunctioninvocationContext *ctx) = 0;

  virtual void enterFunctionparameters(bParser::FunctionparametersContext *ctx) = 0;
  virtual void exitFunctionparameters(bParser::FunctionparametersContext *ctx) = 0;

  virtual void enterAssign(bParser::AssignContext *ctx) = 0;
  virtual void exitAssign(bParser::AssignContext *ctx) = 0;

  virtual void enterIncdec(bParser::IncdecContext *ctx) = 0;
  virtual void exitIncdec(bParser::IncdecContext *ctx) = 0;

  virtual void enterUnary(bParser::UnaryContext *ctx) = 0;
  virtual void exitUnary(bParser::UnaryContext *ctx) = 0;

  virtual void enterBinary(bParser::BinaryContext *ctx) = 0;
  virtual void exitBinary(bParser::BinaryContext *ctx) = 0;

  virtual void enterLvalue(bParser::LvalueContext *ctx) = 0;
  virtual void exitLvalue(bParser::LvalueContext *ctx) = 0;

  virtual void enterConstant(bParser::ConstantContext *ctx) = 0;
  virtual void exitConstant(bParser::ConstantContext *ctx) = 0;

  virtual void enterName(bParser::NameContext *ctx) = 0;
  virtual void exitName(bParser::NameContext *ctx) = 0;


};

