
// Generated from b.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "bParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by bParser.
 */
class  bVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by bParser.
   */
    virtual std::any visitProgram(bParser::ProgramContext *context) = 0;

    virtual std::any visitDefinition(bParser::DefinitionContext *context) = 0;

    virtual std::any visitIval(bParser::IvalContext *context) = 0;

    virtual std::any visitStatement(bParser::StatementContext *context) = 0;

    virtual std::any visitNullstmt(bParser::NullstmtContext *context) = 0;

    virtual std::any visitExpressionstmt(bParser::ExpressionstmtContext *context) = 0;

    virtual std::any visitBlockstmt(bParser::BlockstmtContext *context) = 0;

    virtual std::any visitReturnstmt(bParser::ReturnstmtContext *context) = 0;

    virtual std::any visitGotostmt(bParser::GotostmtContext *context) = 0;

    virtual std::any visitSwitchstmt(bParser::SwitchstmtContext *context) = 0;

    virtual std::any visitWhilestmt(bParser::WhilestmtContext *context) = 0;

    virtual std::any visitIfstmt(bParser::IfstmtContext *context) = 0;

    virtual std::any visitCasestmt(bParser::CasestmtContext *context) = 0;

    virtual std::any visitExternsmt(bParser::ExternsmtContext *context) = 0;

    virtual std::any visitAutosmt(bParser::AutosmtContext *context) = 0;

    virtual std::any visitRvalue(bParser::RvalueContext *context) = 0;

    virtual std::any visitTernary(bParser::TernaryContext *context) = 0;

    virtual std::any visitComparison(bParser::ComparisonContext *context) = 0;

    virtual std::any visitAssignment(bParser::AssignmentContext *context) = 0;

    virtual std::any visitExpression(bParser::ExpressionContext *context) = 0;

    virtual std::any visitExpressionList(bParser::ExpressionListContext *context) = 0;

    virtual std::any visitFunctioninvocation(bParser::FunctioninvocationContext *context) = 0;

    virtual std::any visitFunctionparameters(bParser::FunctionparametersContext *context) = 0;

    virtual std::any visitAssign(bParser::AssignContext *context) = 0;

    virtual std::any visitIncdec(bParser::IncdecContext *context) = 0;

    virtual std::any visitUnary(bParser::UnaryContext *context) = 0;

    virtual std::any visitBinary(bParser::BinaryContext *context) = 0;

    virtual std::any visitLvalue(bParser::LvalueContext *context) = 0;

    virtual std::any visitConstant(bParser::ConstantContext *context) = 0;

    virtual std::any visitName(bParser::NameContext *context) = 0;


};

