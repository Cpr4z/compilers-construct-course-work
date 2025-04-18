
// Generated from b.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "bListener.h"


/**
 * This class provides an empty implementation of bListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  bBaseListener : public bListener {
public:

  virtual void enterProgram(bParser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(bParser::ProgramContext * /*ctx*/) override { }

  virtual void enterDefinition(bParser::DefinitionContext * /*ctx*/) override { }
  virtual void exitDefinition(bParser::DefinitionContext * /*ctx*/) override { }

  virtual void enterIval(bParser::IvalContext * /*ctx*/) override { }
  virtual void exitIval(bParser::IvalContext * /*ctx*/) override { }

  virtual void enterStatement(bParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(bParser::StatementContext * /*ctx*/) override { }

  virtual void enterNullstmt(bParser::NullstmtContext * /*ctx*/) override { }
  virtual void exitNullstmt(bParser::NullstmtContext * /*ctx*/) override { }

  virtual void enterExpressionstmt(bParser::ExpressionstmtContext * /*ctx*/) override { }
  virtual void exitExpressionstmt(bParser::ExpressionstmtContext * /*ctx*/) override { }

  virtual void enterBlockstmt(bParser::BlockstmtContext * /*ctx*/) override { }
  virtual void exitBlockstmt(bParser::BlockstmtContext * /*ctx*/) override { }

  virtual void enterReturnstmt(bParser::ReturnstmtContext * /*ctx*/) override { }
  virtual void exitReturnstmt(bParser::ReturnstmtContext * /*ctx*/) override { }

  virtual void enterGotostmt(bParser::GotostmtContext * /*ctx*/) override { }
  virtual void exitGotostmt(bParser::GotostmtContext * /*ctx*/) override { }

  virtual void enterSwitchstmt(bParser::SwitchstmtContext * /*ctx*/) override { }
  virtual void exitSwitchstmt(bParser::SwitchstmtContext * /*ctx*/) override { }

  virtual void enterWhilestmt(bParser::WhilestmtContext * /*ctx*/) override { }
  virtual void exitWhilestmt(bParser::WhilestmtContext * /*ctx*/) override { }

  virtual void enterIfstmt(bParser::IfstmtContext * /*ctx*/) override { }
  virtual void exitIfstmt(bParser::IfstmtContext * /*ctx*/) override { }

  virtual void enterCasestmt(bParser::CasestmtContext * /*ctx*/) override { }
  virtual void exitCasestmt(bParser::CasestmtContext * /*ctx*/) override { }

  virtual void enterExternsmt(bParser::ExternsmtContext * /*ctx*/) override { }
  virtual void exitExternsmt(bParser::ExternsmtContext * /*ctx*/) override { }

  virtual void enterAutosmt(bParser::AutosmtContext * /*ctx*/) override { }
  virtual void exitAutosmt(bParser::AutosmtContext * /*ctx*/) override { }

  virtual void enterRvalue(bParser::RvalueContext * /*ctx*/) override { }
  virtual void exitRvalue(bParser::RvalueContext * /*ctx*/) override { }

  virtual void enterTernary(bParser::TernaryContext * /*ctx*/) override { }
  virtual void exitTernary(bParser::TernaryContext * /*ctx*/) override { }

  virtual void enterComparison(bParser::ComparisonContext * /*ctx*/) override { }
  virtual void exitComparison(bParser::ComparisonContext * /*ctx*/) override { }

  virtual void enterAssignment(bParser::AssignmentContext * /*ctx*/) override { }
  virtual void exitAssignment(bParser::AssignmentContext * /*ctx*/) override { }

  virtual void enterExpression(bParser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(bParser::ExpressionContext * /*ctx*/) override { }

  virtual void enterFunctioninvocation(bParser::FunctioninvocationContext * /*ctx*/) override { }
  virtual void exitFunctioninvocation(bParser::FunctioninvocationContext * /*ctx*/) override { }

  virtual void enterFunctionparameters(bParser::FunctionparametersContext * /*ctx*/) override { }
  virtual void exitFunctionparameters(bParser::FunctionparametersContext * /*ctx*/) override { }

  virtual void enterAssign(bParser::AssignContext * /*ctx*/) override { }
  virtual void exitAssign(bParser::AssignContext * /*ctx*/) override { }

  virtual void enterIncdec(bParser::IncdecContext * /*ctx*/) override { }
  virtual void exitIncdec(bParser::IncdecContext * /*ctx*/) override { }

  virtual void enterUnary(bParser::UnaryContext * /*ctx*/) override { }
  virtual void exitUnary(bParser::UnaryContext * /*ctx*/) override { }

  virtual void enterBinary(bParser::BinaryContext * /*ctx*/) override { }
  virtual void exitBinary(bParser::BinaryContext * /*ctx*/) override { }

  virtual void enterLvalue(bParser::LvalueContext * /*ctx*/) override { }
  virtual void exitLvalue(bParser::LvalueContext * /*ctx*/) override { }

  virtual void enterConstant(bParser::ConstantContext * /*ctx*/) override { }
  virtual void exitConstant(bParser::ConstantContext * /*ctx*/) override { }

  virtual void enterName(bParser::NameContext * /*ctx*/) override { }
  virtual void exitName(bParser::NameContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

