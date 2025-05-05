
// Generated from b.g4 by ANTLR 4.13.0

#pragma once

#include "antlr4-runtime.h"
#include "bVisitor.h"

#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Function.h>
#include <llvm/ExecutionEngine/ExecutionEngine.h>
#include <llvm/Support/TargetSelect.h>
#include "llvm/IR/Type.h"
#include "llvm/IR/DerivedTypes.h"


/**
 * This class provides an empty implementation of bVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */

class  bBaseVisitor : public bVisitor {
private:
    struct variableWrapper
    {
        llvm::Value* value = nullptr;
        bool is_int = true;
    };

    // RAII Object to switch IR context
    struct ScopedContext
    {
        llvm::Function*& m_functionRef;
        llvm::Function* m_savedFunction;
        llvm::IRBuilder<>& m_builder;
        llvm::BasicBlock* m_savedInsertPoint;

        ScopedContext(llvm::Function*& functionRef, llvm::IRBuilder<>& builder)
                : m_functionRef(functionRef), m_savedFunction(functionRef), m_builder(builder),
                  m_savedInsertPoint(builder.GetInsertBlock()) {}

        ~ScopedContext() {
            m_functionRef = m_savedFunction;
            if (m_savedInsertPoint)
                m_builder.SetInsertPoint(m_savedInsertPoint);
        }
    };

    llvm::Value* handleIncDec(bParser::IncdecContext* opCtx, bParser::NameContext* nameCtx)
    {
        std::string name = nameCtx->getText();
        variableWrapper wrapper = getOrCreateVariable(name);
        auto* alloca = llvm::cast<llvm::AllocaInst>(wrapper.value);
        llvm::Type* type = alloca->getAllocatedType();

        llvm::Value* val = m_builder.CreateLoad(type, alloca, "loadtmp");
        llvm::Value* one = llvm::ConstantInt::get(type, 1);
        llvm::Value* result = nullptr;

        if (opCtx->getText() == "++")
            result = m_builder.CreateAdd(val, one, "inctmp");
        else if (opCtx->getText() == "--")
            result = m_builder.CreateSub(val, one, "dectmp");
        else {
            std::cerr << "Неизвестный оператор " << opCtx->getText() << "\n";
            return nullptr;
        }
        m_builder.CreateStore(result, alloca);
        return result;
    }

public:
    static llvm::LLVMContext m_context;
    static llvm::Module* m_module;
    static llvm::IRBuilder<> m_builder;
    static llvm::Function* m_function;

    std::optional<std::string> m_pendingVariableName;

    static std::vector<llvm::BasicBlock*> m_blocks;
    static std::unordered_map<std::string, variableWrapper> m_namedValues;
    static std::unordered_map<std::string, llvm::BasicBlock*> m_labelMap;
    static std::stack<std::pair<llvm::SwitchInst*, llvm::BasicBlock*>> m_switchStack;

    static std::unordered_map<std::string, llvm::Function*> m_namedFunctions;
    static std::unordered_map<std::string, bParser::DefinitionContext*> m_functionBodies;

public:

    bBaseVisitor() = default;

    inline void printInfo(const std::string& func_name, antlr4::ParserRuleContext* ctx)
    {
        std::string result;
        int depth = ctx->depth();
        while(--depth)
        {
            result+= "\t";
        }
        std::cout << result + " " + func_name << " " << ctx->getText() + " " + currentScope() << std::endl;
    }

    static std::string currentScope()
    {
        llvm::BasicBlock* currentBlock = m_builder.GetInsertBlock();
        if (currentBlock)
        {
            llvm::Function* currentFunction = m_builder.GetInsertBlock()->getParent();
            if (currentFunction)
            {
                return "Current function name: " + currentFunction->getName().str();
            }
            else
            {
                return "Current block name: " + currentBlock->getName().str();
            }
        }
        return {};
    }

    variableWrapper getOrCreateVariable(const std::string& name)
    {
        if (m_namedValues.contains(name))
        {
            return m_namedValues[name];
        }
        m_namedValues[name] = variableWrapper{};
        return m_namedValues[name];

    }

    llvm::Function* getOrCreatePrint()
    {
        static llvm::Function* printFunc = m_module->getFunction("printf");
        if (!printFunc)
        {
            llvm::FunctionType* printType = llvm::FunctionType::get(
                    llvm::Type::getVoidTy(m_context),
                    { llvm::PointerType::getUnqual(llvm::Type::getInt8Ty(m_context)) },
                    true
            );

            printFunc = llvm::Function::Create(
                    printType,
                    llvm::Function::ExternalLinkage,
                    0,
                    "printf",
                    m_module
            );
        }
        return printFunc;
    }

  virtual std::any visitProgram(bParser::ProgramContext *ctx) override
  {
      printInfo(__FUNCTION__, ctx);
      for (auto def : ctx->definition())
      {
          std::string functionName = def->name(0)->getText();
          if (def->statement())
          {
              m_functionBodies[functionName] = def;

              std::vector<llvm::Type*> paramTypes;
              for (size_t i = 1; i < def->name().size(); ++i)
                  paramTypes.push_back(llvm::Type::getInt32Ty(m_context));

              if (!m_namedFunctions.contains(functionName))
              {
                  llvm::FunctionType* funcType = llvm::FunctionType::get(
                          llvm::Type::getInt32Ty(m_context), paramTypes, false);

                  llvm::Function* func = llvm::Function::Create(
                          funcType,
                          llvm::Function::ExternalLinkage,
                          functionName,
                          m_module);

                  size_t idx = 1;
                  for (auto& arg : func->args())
                      arg.setName(def->name(idx++)->getText());

                  m_namedFunctions[functionName] = func;
              }
          }
      }

      if (m_functionBodies.contains("main"))
      {
          visitDefinition(m_functionBodies["main"]);
      }
      return nullptr;
  }

  virtual std::any visitDefinition(bParser::DefinitionContext *ctx) override
  {
      printInfo(__FUNCTION__, ctx);
      std::string functionName = ctx->name(0)->getText();
      llvm::Function* function = m_namedFunctions[functionName];
      if (!function)
      {
          std::cerr << "Ошибка: функция " << functionName << " не найдена\n";
          return nullptr;
      }

      ScopedContext scoped(m_function, m_builder); // save context
      m_function = function;

      llvm::BasicBlock* entry = llvm::BasicBlock::Create(m_context, "entry", function);
      m_blocks.push_back(entry);
      m_builder.SetInsertPoint(entry);

      m_namedValues.clear();
      for (auto& arg : function->args()) {
          llvm::AllocaInst* alloca = m_builder.CreateAlloca(arg.getType(), nullptr, arg.getName());
          m_builder.CreateStore(&arg, alloca);
          m_namedValues[arg.getName().str()] = variableWrapper{alloca, true};
      }

      bool returnsInt = function->getReturnType()->isIntegerTy(32);
      llvm::AllocaInst* returnValue = nullptr;
      if (returnsInt) {
          returnValue = m_builder.CreateAlloca(llvm::Type::getInt32Ty(m_context), nullptr, "retval");
          m_namedValues["return"] = variableWrapper{returnValue, true};
      }

      visit(ctx->statement());

      if (!m_builder.GetInsertBlock()->getTerminator()) {
          if (returnsInt) {
              llvm::Value* retVal = m_builder.CreateLoad(
                      llvm::Type::getInt32Ty(m_context),
                      returnValue,
                      "ret");
              m_builder.CreateRet(retVal);
          } else {
              m_builder.CreateRetVoid();
          }
      }

      m_blocks.pop_back();
      return nullptr;
  }

  virtual std::any visitIval(bParser::IvalContext *ctx) override
  {
      printInfo(__FUNCTION__, ctx);
      if (ctx->constant())
      {
          auto wrapper = std::any_cast<variableWrapper>(visit(ctx->constant()));
          return wrapper.value;
      }
      else if (ctx->name())
      {
          variableWrapper wrapper = getOrCreateVariable(ctx->name()->getText());
          auto* alloca = llvm::cast<llvm::AllocaInst>(wrapper.value);
          llvm::Type* elementType = alloca->getAllocatedType();
          return m_builder.CreateLoad(elementType, wrapper.value, "loadtmp");
      }
      return nullptr;
  }

  virtual std::any visitStatement(bParser::StatementContext *ctx) override
  {
      printInfo(__FUNCTION__, ctx);
      if (ctx->externsmt())
      {
          return visit(ctx->externsmt());
      }
      else if (ctx->autosmt())
      {
          return visit(ctx->autosmt());
      }
      else if (ctx->name() && ctx->statement())
      {
          return visit(ctx->statement());
      }
      else if (ctx->casestmt())
      {
          return visit(ctx->casestmt());
      }
      else if (ctx->blockstmt())
      {
          return visit(ctx->blockstmt());
      }
      else if (ctx->ifstmt())
      {
          return visit(ctx->ifstmt());
      }
      else if (ctx->whilestmt())
      {
          return visit(ctx->whilestmt());
      }
      else if (ctx->switchstmt())
      {
          return visit(ctx->switchstmt());
      }
      else if (ctx->gotostmt())
      {
          return visit(ctx->gotostmt());
      }
      else if (ctx->returnstmt())
      {
          return visit(ctx->returnstmt());
      }
      else if (ctx->expressionstmt())
      {
          return visit(ctx->expressionstmt());
      }
      else if (ctx->nullstmt())
      {
          return visit(ctx->nullstmt());
      }
      return nullptr;
  }

  virtual std::any visitNullstmt(bParser::NullstmtContext *ctx) override
  {
      printInfo(__FUNCTION__, ctx);
      return nullptr;
  }

  virtual std::any visitExpressionstmt(bParser::ExpressionstmtContext *ctx) override
  {
      printInfo(__FUNCTION__, ctx);
      if (auto* rvalue = ctx->rvalue())
      {
          return visit(rvalue);
      }
      return nullptr;
  }

  virtual std::any visitBlockstmt(bParser::BlockstmtContext *ctx) override
  {
      printInfo(__FUNCTION__, ctx);
      for (auto* stmt : ctx->statement())
      {
          visit(stmt);
      }
      return nullptr;
  }

  virtual std::any visitReturnstmt(bParser::ReturnstmtContext *ctx) override
  {
      printInfo(__FUNCTION__, ctx);
      if (auto* rvalue = ctx->rvalue())
      {
          llvm::Value* value = nullptr;
          auto anyValue = visit(rvalue);

          if (anyValue.type() == typeid(llvm::Value*)) {
              value = std::any_cast<llvm::Value*>(anyValue);
          }
          else if (anyValue.type() == typeid(variableWrapper)) {
              auto wrapper = std::any_cast<variableWrapper>(anyValue);
              value = wrapper.value;
          }

          if (!value) {
              std::cerr << "Ошибка: значение для return не получено\n";
              return nullptr;
          }

          if (value->getType()->isPointerTy()) {
              value = m_builder.CreateLoad(
                      llvm::Type::getInt32Ty(m_context),
                      value,
                      "ret_val"
              );
          }

          return m_builder.CreateRet(value);
      }
      else
      {
          return m_builder.CreateRetVoid();
      }
  }

  virtual std::any visitGotostmt(bParser::GotostmtContext *ctx) override
  {
      printInfo(__FUNCTION__, ctx);
        std::string label = ctx->rvalue()->getText();
        llvm::BasicBlock* targetBlock = m_labelMap[label];
        m_builder.CreateBr(targetBlock);
        llvm::BasicBlock* unreachable = llvm::BasicBlock::Create(m_context, "after_goto", m_function);
        m_blocks.push_back(unreachable);
        m_builder.SetInsertPoint(unreachable);
        return nullptr;
  }

  virtual std::any visitSwitchstmt(bParser::SwitchstmtContext *ctx) override
  {
      printInfo(__FUNCTION__, ctx);
      auto* cond = std::any_cast<llvm::Value*>(visit(ctx->rvalue()));
      llvm::Function* function = m_builder.GetInsertBlock()->getParent();
      llvm::BasicBlock* endBlock = llvm::BasicBlock::Create(m_context, "switch.end", function);
      m_blocks.push_back(endBlock);
      llvm::SwitchInst* switchInst = m_builder.CreateSwitch(cond, endBlock);
      m_switchStack.push({switchInst, endBlock});
      visit(ctx->statement());
      if (!m_builder.GetInsertBlock()->getTerminator())
      {
          m_builder.CreateBr(endBlock);
      }

      m_builder.SetInsertPoint(endBlock);
      m_switchStack.pop();
      return nullptr;
  }

  virtual std::any visitWhilestmt(bParser::WhilestmtContext *ctx) override
  {
      printInfo(__FUNCTION__, ctx);
      llvm::Function* function = m_builder.GetInsertBlock()->getParent();

      llvm::BasicBlock* condBlock = llvm::BasicBlock::Create(m_context, "while.cond", function);
      llvm::BasicBlock* bodyBlock = llvm::BasicBlock::Create(m_context, "while.body", function);
      llvm::BasicBlock* endBlock  = llvm::BasicBlock::Create(m_context, "while.end", function);

      m_builder.CreateBr(condBlock);

      m_builder.SetInsertPoint(condBlock);
      auto* cond = std::any_cast<llvm::Value*>(visit(ctx->rvalue()));
      cond = m_builder.CreateICmpNE(cond, llvm::ConstantInt::get(cond->getType(), 0), "whilecond");
      m_builder.CreateCondBr(cond, bodyBlock, endBlock);

      m_builder.SetInsertPoint(bodyBlock);
      visit(ctx->statement());
      if (!m_builder.GetInsertBlock()->getTerminator())
      {
          m_builder.CreateBr(condBlock);
      }

      m_builder.SetInsertPoint(endBlock);
      return nullptr;
  }

  virtual std::any visitIfstmt(bParser::IfstmtContext *ctx) override
  {
      printInfo(__FUNCTION__, ctx);
      auto anyValue = visit(ctx->rvalue());
      auto* cond = std::any_cast<llvm::Value*>(anyValue);
      cond = m_builder.CreateICmpNE(cond, llvm::ConstantInt::get(cond->getType(), 0), "ifcond");

      llvm::Function* function = m_builder.GetInsertBlock()->getParent();
      llvm::BasicBlock* thenBlock = llvm::BasicBlock::Create(m_context, "if.then", function);
      llvm::BasicBlock* mergeBlock = llvm::BasicBlock::Create(m_context, "if.end", function);

      llvm::BasicBlock* elseBlock = nullptr;
      if (ctx->statement().size() > 1)
      {
          elseBlock = llvm::BasicBlock::Create(m_context, "if.else", function);
      }
      m_builder.CreateCondBr(cond, thenBlock, elseBlock ? elseBlock : mergeBlock);
      m_builder.SetInsertPoint(thenBlock);
      visit(ctx->statement(0));
      if (!m_builder.GetInsertBlock()->getTerminator())
      {
          m_builder.CreateBr(mergeBlock);
      }

      if (elseBlock)
      {
          m_builder.SetInsertPoint(elseBlock);
          visit(ctx->statement(1));
          if (!m_builder.GetInsertBlock()->getTerminator())
          {
              m_builder.CreateBr(mergeBlock);
          }
      }
      m_builder.SetInsertPoint(mergeBlock);
      return nullptr;
  }

  virtual std::any visitCasestmt(bParser::CasestmtContext *ctx) override
  {
      printInfo(__FUNCTION__, ctx);
      if (m_switchStack.empty())
      {
          std::cerr << "Ошибка: case вне switch\n";
          return nullptr;
      }

      auto& [switchInst, endBlock] = m_switchStack.top();
      llvm::Function* function = m_builder.GetInsertBlock()->getParent();

      auto wrapper = std::any_cast<variableWrapper>(visit(ctx->constant()));
      auto* constInt = llvm::dyn_cast<llvm::ConstantInt>(wrapper.value);
      if (!constInt)
      {
          std::cerr << "Ошибка: значение case не является целым числом\n";
          return nullptr;
      }

      llvm::BasicBlock* caseBlock = llvm::BasicBlock::Create(m_context, "case", function);
      switchInst->addCase(constInt, caseBlock);
      if (!m_builder.GetInsertBlock()->getTerminator())
      {
          m_builder.CreateBr(caseBlock);
      }
      m_builder.SetInsertPoint(caseBlock);
      visit(ctx->statement());
      return nullptr;
  }

  virtual std::any visitExternsmt(bParser::ExternsmtContext *ctx) override
  {
      printInfo(__FUNCTION__, ctx);
        for (auto* nameCtx : ctx->name())
        {
            std::string name = nameCtx->getText();
            auto* var = new llvm::GlobalVariable(
                    *m_module,
                    llvm::Type::getInt32Ty(m_context),
                    false,
                    llvm::GlobalValue::ExternalLinkage,
                    nullptr,
                    name
                    );
            m_namedValues[name] = {var};
        }
        return nullptr;
  }

  virtual std::any visitAutosmt(bParser::AutosmtContext *ctx) override
  {
      printInfo(__FUNCTION__, ctx);
      auto names = ctx->name();
      auto constants = ctx->constant();
      for (size_t i = 0; i < names.size(); ++i)
      {
          std::string name = names[i]->getText();
          if (i < constants.size() && constants[i])
          {
              m_pendingVariableName = name;
              auto result = visit(constants[i]);
              m_pendingVariableName.reset();

              variableWrapper wrapper = std::any_cast<variableWrapper>(result);
              llvm::AllocaInst* alloca = llvm::cast<llvm::AllocaInst>(m_namedValues[name].value);
              m_builder.CreateStore(wrapper.value, alloca);
          }
          else
          {
              m_pendingVariableName = name;
          }
      }
      return nullptr;
  }

  virtual std::any visitRvalue(bParser::RvalueContext *ctx) override
  {
      printInfo(__FUNCTION__, ctx);
      if (ctx->expression()) {
          return visit(ctx->expression());
      }

      if (ctx->comparison()) {
          return visit(ctx->comparison());
      }

      if (ctx->ternary()) {
          return visit(ctx->ternary());
      }

      if (ctx->assignment()) {
          return visit(ctx->assignment());
      }

      // массив
      if (ctx->expressionList())
      {
          auto raw = visit(ctx->expressionList());
          return std::any_cast<std::vector<int>>(raw);
      }
      return std::vector<int>{};
  }

  virtual std::any visitTernary(bParser::TernaryContext *ctx) override
  {
      printInfo(__FUNCTION__, ctx);
      std::string value = ctx->getText();
      std::string expression = ctx->expression()->getText();
      std::cout << expression << std::endl;
      std::vector<bParser::RvalueContext*> rvalues = ctx->rvalue();
      for (auto rvalue : rvalues)
      {
          std::cout << rvalue->getText() << std::endl;
      }
      auto* cond = std::any_cast<llvm::Value*>(visit(ctx->expression()));
      if (!cond) return nullptr;

      if (cond->getType()->isPointerTy())
      {
          auto* allocaInst = llvm::cast<llvm::AllocaInst>(cond);
          llvm::Type* elemType = allocaInst->getAllocatedType();
          cond = m_builder.CreateLoad(elemType, cond, "loaded_cond");
      }

      cond = m_builder.CreateICmpNE(cond, llvm::ConstantInt::get(cond->getType(), 0), "cond");

      llvm::Function* function = m_builder.GetInsertBlock()->getParent();

      llvm::BasicBlock* ifTrueBlock = llvm::BasicBlock::Create(m_context, "ternary.true", function);
      llvm::BasicBlock* ifFalseBlock = llvm::BasicBlock::Create(m_context, "ternary.false");
      llvm::BasicBlock* mergeBlock  = llvm::BasicBlock::Create(m_context, "ternary.merge");

      m_builder.CreateCondBr(cond, ifTrueBlock, ifFalseBlock);

      m_builder.SetInsertPoint(ifTrueBlock);
      auto* trueVal = std::any_cast<llvm::Value*>(visit(ctx->rvalue(0)));
      std::cout << trueVal->getName().str() << std::endl;
      if (!m_builder.GetInsertBlock()->getTerminator())
      {
          m_builder.CreateBr(mergeBlock);
      }

      ifTrueBlock = m_builder.GetInsertBlock();

      function->insert(function->end(), ifFalseBlock);
      m_builder.SetInsertPoint(ifFalseBlock);
      auto* falseVal = std::any_cast<llvm::Value*>(visit(ctx->rvalue(1)));
      std::cout << falseVal->getName().str() << std::endl;
      if (!m_builder.GetInsertBlock()->getTerminator())
      {
          m_builder.CreateBr(mergeBlock);
      }

      ifFalseBlock = m_builder.GetInsertBlock();

      function->insert(function->end(), mergeBlock);
      m_builder.SetInsertPoint(mergeBlock);

      llvm::PHINode* phi = m_builder.CreatePHI(trueVal->getType(), 2, "ternarytmp");
      phi->addIncoming(trueVal, ifTrueBlock);
      phi->addIncoming(falseVal, ifFalseBlock);

      return phi;
  }

  virtual std::any visitComparison(bParser::ComparisonContext *ctx) override
  {
      printInfo(__FUNCTION__, ctx);
      std::string expression = ctx->getText();
      std::string value = ctx->expression()->getText();
      std::string op = ctx->binary()->getText();
      std::string rvalue = ctx->rvalue()->getText();

      auto anyValue = visit(ctx->expression());

      llvm::Value* rhs = nullptr;
      llvm::Value* lhs = nullptr;

      if (anyValue.type() == typeid(variableWrapper))
      {
          lhs = std::any_cast<variableWrapper>(anyValue).value;
      }
      else if (anyValue.type() == typeid(llvm::Value*))
      {
          lhs = std::any_cast<llvm::Value*>(anyValue);
      }
      else if (anyValue.type() == typeid(llvm::PHINode*))
      {
          lhs = std::any_cast<llvm::PHINode*>(anyValue);
      }
      else
      {
          std::cerr << "Ошибка: неподдерживаемый тип lhs\n";
          return nullptr;
      }

      std::any anyResult = visit(ctx->rvalue());
      if (anyResult.type() == typeid(llvm::Value*))
      {
          rhs = std::any_cast<llvm::Value*>(anyResult);
      }
      else if (anyResult.type() == typeid(llvm::PHINode*))
      {
          rhs = std::any_cast<llvm::PHINode*>(anyResult);
      }
      else if (anyResult.type() == typeid(variableWrapper))
      {
          auto wrapper = std::any_cast<variableWrapper>(anyResult);
          rhs = wrapper.value;
      }
      else
      {
          std::cerr << "Ошибка: неподдерживаемый тип в anyResult для rvalue\n";
          return nullptr;
      }

        auto tryLoad = [&](llvm::Value* value, const std::string& name)-> llvm::Value*
        {
          if (value->getType()->isPointerTy())
          {
              if (llvm::isa<llvm::AllocaInst>(value))
              {
                  auto* allocaInst = llvm::cast<llvm::AllocaInst>(value);
                  llvm::Type* elemType = allocaInst->getAllocatedType();
                  return m_builder.CreateLoad(elemType, value, name);
              }
              return value;
          }
          return value;
      };

      lhs = tryLoad(lhs, "loaded_lhs");
      rhs = tryLoad(rhs, "loaded_rhs");

      if (auto* phi = llvm::dyn_cast<llvm::PHINode>(rhs))
      {
          std::string lhsName = lhs->getName().str();

          llvm::Value* first  = phi->getIncomingValue(0);
          llvm::Value* second = phi->getIncomingValue(1);

//          std::string firstName  = first->getName().str();
//          std::string secondName = second->getName().str();

          llvm::Value* actualRhs = nullptr;

          if (lhs == first) {
              actualRhs = first;
          } else if (lhs == second) {
              actualRhs = second;
          } else {
              std::cerr << "Ошибка: имя переменной в lhs не совпадает ни с одним из вариантов PHI\n";
              return nullptr;
          }

          if (op == ">")
              return m_builder.CreateICmpSGT(lhs, actualRhs, "gttmp");
          else if (op == ">=")
              return m_builder.CreateICmpSGE(lhs, actualRhs, "getmp");
          else if (op == "==")
              return m_builder.CreateICmpEQ(lhs, actualRhs, "eqtmp");
          else if (op == "!=")
              return m_builder.CreateICmpNE(lhs, actualRhs, "netmp");
          else if (op == "<")
              return m_builder.CreateICmpSLT(lhs, actualRhs, "lttmp");
          else if (op == "<=")
              return m_builder.CreateICmpSLE(lhs, actualRhs, "letmp");
      }
      else
      {
          llvm::Value* result = nullptr;
          if (op == "==")
          {
              result = m_builder.CreateICmpEQ(lhs, rhs, "eqtmp");
          }
          else if (op == "!=")
          {
              result = m_builder.CreateICmpNE(lhs, rhs, "netmp");
          }
          else if (op == "<")
          {
              result = m_builder.CreateICmpSLT(lhs, rhs, "lttmp");
          }
          else if (op == "<=")
          {
              result = m_builder.CreateICmpSLE(lhs, rhs, "letmp");
          }
          else if (op == ">")
          {
              std::cout << lhs->getType()->getTypeID() << std::endl;
              std::cout << rhs->getType()->getTypeID() << std::endl;
              std::cout << lhs->getName().str() << std::endl;
              std::cout << rhs->getName().str() << std::endl;

              result = m_builder.CreateICmpSGT(lhs, rhs, "gttmp");
          }
          else if (op == ">=")
          {
              result = m_builder.CreateICmpSGE(lhs, rhs, "getmp");
          }
          else
          {
              std::cerr << "Unknown comparison operator: " << op << "\n";
              return nullptr;
          }
          return result;
      }
      return {};
  }

  virtual std::any visitAssignment(bParser::AssignmentContext *ctx) override
  {
      printInfo(__FUNCTION__, ctx);

      std::string varName = ctx->name()->getText();
      m_pendingVariableName = varName;

      std::any anyValue = visit(ctx->rvalue());
      llvm::Value* rawValue = nullptr;

      if (anyValue.type() == typeid(variableWrapper))
      {
          variableWrapper wrapper = std::any_cast<variableWrapper>(anyValue);
          llvm::Value* ptr = wrapper.value;

          if (auto* alloca = llvm::dyn_cast<llvm::AllocaInst>(ptr)) {
              rawValue = m_builder.CreateLoad(alloca->getAllocatedType(), alloca, "loaded_from_var");
          } else {
              rawValue = ptr;
          }
      }
      else if (anyValue.type() == typeid(llvm::Value*)) {
          rawValue = std::any_cast<llvm::Value*>(anyValue);
      }
      else if (anyValue.type() == typeid(llvm::CallInst*)) {
          rawValue = std::any_cast<llvm::CallInst*>(anyValue);
      }
      else {
          std::cerr << "Ошибка: неизвестный тип rvalue в присваивании\n";
          return nullptr;
      }

      m_pendingVariableName.reset();

      if (!rawValue) {
          std::cerr << "Ошибка: значение присваивания не определено\n";
          return nullptr;
      }

      if (!m_namedValues.contains(varName))
      {
          llvm::AllocaInst* newAlloca = nullptr;
          if (llvm::isa<llvm::AllocaInst>(rawValue))
          {
              llvm::AllocaInst* oldAlloca = llvm::cast<llvm::AllocaInst>(rawValue);
                llvm::Type* oldType = oldAlloca->getAllocatedType();
                newAlloca = m_builder.CreateAlloca(oldType, nullptr, varName);
              m_namedValues[varName] = variableWrapper{newAlloca, true};
          }
          else
          {
              newAlloca = m_builder.CreateAlloca(rawValue->getType(), nullptr, varName);
          }
          m_namedValues[varName] = variableWrapper{newAlloca, true};
      }

      llvm::Value* target = m_namedValues[varName].value;
      if (auto* destAlloca = llvm::dyn_cast<llvm::AllocaInst>(target))
      {
          llvm::Value* valueToStore = rawValue;
          if (rawValue->getType()->isPointerTy() &&
              llvm::isa<llvm::AllocaInst>(rawValue))
          {
              llvm::Type* storedType = llvm::cast<llvm::AllocaInst>(rawValue)->getAllocatedType();
              valueToStore = m_builder.CreateLoad(storedType, rawValue, "loaded_rhs");
          }
          m_builder.CreateStore(valueToStore, destAlloca);
      }
      else {
          std::cerr << "Ошибка: переменная " << varName << " не является допустимой alloca\n";
          return nullptr;
      }

      return rawValue;
  }

  virtual std::any visitExpression(bParser::ExpressionContext *ctx) override
  {
      printInfo(__FUNCTION__, ctx);
      if (ctx->rvalue() && ctx->getStart()->getText() == "(")
      {
          if (ctx->rvalue()->comparison())
          {
              return visit(ctx->rvalue()->comparison());
          }
          return visit(ctx->rvalue());
      }

      if (ctx->name() && !ctx->incdec() && ctx->children.size() == 1)
      {
          return visit(ctx->name());
      }

      if (ctx->constant())
      {
          auto wrapper = std::any_cast<variableWrapper>(visit(ctx->constant()));
          return wrapper;
      }

      if (ctx->incdec() && ctx->name())
      {
          return handleIncDec(ctx->incdec(), ctx->name());
      }

      if (ctx->name() && ctx->incdec())
      {
          return handleIncDec(ctx->incdec(), ctx->name());
      }

      if (ctx->unary() && ctx->rvalue())
      {
          return visit(ctx->unary());
      }

      if (ctx->getStart()->getText() == "&" && ctx->name())
      {
          variableWrapper wrapper = getOrCreateVariable(ctx->name()->getText());
          return wrapper.value;
      }

      if (ctx->functioninvocation())
      {
          return visit(ctx->functioninvocation());
      }

      std::cerr << "Не удалось распознать выражение\n";
      return nullptr;
  }

 virtual std::any visitExpressionList(bParser::ExpressionListContext *ctx) override
 {
     std::vector<std::any> values;
     for (auto child : ctx->rvalue())
     {
         auto val = visit(child);
         values.push_back(val);
     }
     return values;
 }

  virtual std::any visitFunctioninvocation(bParser::FunctioninvocationContext *ctx) override
  {
      printInfo(__FUNCTION__, ctx);
      std::string funcName = ctx->name()->getText();
      if (funcName == "print")
      {
          std::vector<llvm::Value*> args;

          if (ctx->functionparameters())
          {
              args = std::any_cast<std::vector<llvm::Value*>>(visit(ctx->functionparameters()));
          }

          if (args.empty())
          {
              std::cerr << "Ошибка: print() должен принимать хотя бы один аргумент\n";
              return nullptr;
          }
          llvm::Value* value = args[0];
          if (!value)
          {
              return nullptr;
          }
          llvm::Type* valueType = value->getType();
          llvm::Value* finalValue = value;
          const char* format = nullptr;
          if (valueType->isPointerTy())
          {
              if (llvm::isa<llvm::ConstantExpr>(value) || llvm::isa<llvm::GlobalVariable>(value))
              {
                  finalValue = value;
                  format = "%s\n";
              }
              else if (llvm::isa<llvm::AllocaInst>(value))
              {
                  auto allocaInst = llvm::cast<llvm::AllocaInst>(value);
                  llvm::Type* elementType = allocaInst->getAllocatedType();
                  finalValue = m_builder.CreateLoad(elementType, value, "loaded_int");
                  format = "%d\n";
              }
              else
              {
                  std::cerr << "Ошибка: неизвестный pointer type\n";
                  return nullptr;
              }
          }
          else
          {
              if (valueType->isIntegerTy(32))
              {
                  format = "%d\n";
                  finalValue = value;
              }
              else if (valueType->isFloatTy())
              {
                  format = "%f\n";
                  finalValue = value;
              }
              else
              {
                  std::cerr << "Ошибка: неподдерживаемый тип литерала\n";
                  return nullptr;
              }
          }

          llvm::GlobalVariable* formatStr = m_builder.CreateGlobalString(format);
          llvm::Function* printFunc = getOrCreatePrint();
          if (!printFunc)
          {
              std::cerr << "Ошибка: print не добавлен в модуль\n";
              return nullptr;
          }

          llvm::Value* castedStr = m_builder.CreatePointerCast(
                  formatStr,
                  llvm::PointerType::get(llvm::Type::getInt8Ty(m_context), 0)
          );
          return m_builder.CreateCall(printFunc, {castedStr, finalValue});
      }

      llvm::Function* callee = m_namedFunctions[funcName];
      if (!callee) {
          std::cerr << "Ошибка: функция \"" << funcName << "\" не найдена\n";
          return nullptr;
      }

      std::vector<llvm::Value*> args;
      if (ctx->functionparameters())
      {
          args = std::any_cast<std::vector<llvm::Value*>>(visit(ctx->functionparameters()));
      }

      if (callee->arg_size() != args.size())
      {
          std::cerr << "Ошибка: количество аргументов не совпадает для функции \"" << funcName << "\"\n";
          return nullptr;
      }


      if (m_functionBodies.contains(funcName))
      {
          auto oldNamedValues = m_namedValues;
          size_t idx = 0;
          for (auto& arg : callee->args())
          {
              m_namedValues[arg.getName().str()] = variableWrapper{args[idx++], false};
          }
          visitDefinition(m_functionBodies[funcName]);
          m_namedValues = oldNamedValues;
      }
      return m_builder.CreateCall(callee, args, "calltmp");
  }

  virtual std::any visitFunctionparameters(bParser::FunctionparametersContext *ctx) override
  {
      printInfo(__FUNCTION__, ctx);
      std::vector<llvm::Value*> args;
      for (auto* expr : ctx->rvalue())
      {
          auto anyVal = visit(expr);
          llvm::Value* val = nullptr;

          if (anyVal.type() == typeid(llvm::Value*)) {
              val = std::any_cast<llvm::Value*>(anyVal);
          }
          else if (anyVal.type() == typeid(variableWrapper)) {
              val = std::any_cast<variableWrapper>(anyVal).value;
          }
          else if (auto* funcCall = dynamic_cast<bParser::FunctioninvocationContext*>(expr))
          {
              std::any result = visitFunctioninvocation(funcCall);
              if (result.has_value()) {
                  val = std::any_cast<llvm::Value*>(result);
              }
          }
          args.push_back(val);
      }
      return args;
  }

  virtual std::any visitAssign(bParser::AssignContext *ctx) override
  {
      printInfo(__FUNCTION__, ctx);
      if (!ctx->binary())
      {
          std::cerr << "Предупреждение: пустое присваивание\n";
          return nullptr;
      }

      auto* value = std::any_cast<llvm::Value*>(visit(ctx->binary()));
      auto* parent = ctx->parent;
      auto* lvalueCtx = dynamic_cast<bParser::LvalueContext*>(parent);
      if (!lvalueCtx || !lvalueCtx->name())
      {
          std::cerr << "Ошибка: присваивание без имени слева\n";
          return nullptr;
      }

      std::string name = lvalueCtx->name()->getText();
      variableWrapper ptr = getOrCreateVariable(name);
      auto* alloca = llvm::cast<llvm::AllocaInst>(ptr.value);
      return m_builder.CreateStore(value, alloca);
  }

  virtual std::any visitIncdec(bParser::IncdecContext *ctx) override
  {
      printInfo(__FUNCTION__, ctx);
      auto* lvalueCtx = dynamic_cast<bParser::LvalueContext*>(ctx->parent);
      if (!lvalueCtx || !lvalueCtx->name())
      {
          std::cerr << "Ошибка: incdec без имени переменной\n";
          return nullptr;
      }

      std::string name = lvalueCtx->name()->getText();
      variableWrapper wrapper = getOrCreateVariable(name);
      auto* alloca = llvm::cast<llvm::AllocaInst>(wrapper.value);
      llvm::Type* elementType = alloca->getAllocatedType();
      llvm::Value* val = m_builder.CreateLoad(elementType, alloca, "loadtmp");

      llvm::Value* one = llvm::ConstantInt::get(val->getType(), 1);
      llvm::Value* result = nullptr;

      if (ctx->getText() == "++")
      {
          result = m_builder.CreateAdd(val, one, "inctmp");
      }
      else if (ctx->getText() == "--")
      {
          result = m_builder.CreateSub(val, one, "dectmp");
      }
      else
      {
          std::cerr << "Ошибка: неизвестный оператор incdec\n";
          return nullptr;
      }
      m_builder.CreateStore(result, alloca);
      return result;
  }

  virtual std::any visitUnary(bParser::UnaryContext *ctx) override
  {
      printInfo(__FUNCTION__, ctx);
      auto parent = ctx->parent;
      auto rvalueCtx = dynamic_cast<bParser::RvalueContext*>(parent);

      if (!rvalueCtx) {
          std::cerr << "Ошибка: унарный оператор без rvalue\n";
          return nullptr;
      }

      auto* val = std::any_cast<llvm::Value*>(visit(rvalueCtx));
      if (!val) return nullptr;

      std::string op = ctx->getStart()->getText();

      if (op == "-")
      {
          llvm::Value* zero = llvm::ConstantInt::get(val->getType(), 0);
          return m_builder.CreateSub(zero, val, "negtmp");
      } else if (op == "!")
      {
          llvm::Value* zero = llvm::ConstantInt::get(val->getType(), 0);
          return m_builder.CreateICmpEQ(val, zero, "nottmp");
      }
      return nullptr;
  }

  virtual std::any visitBinary(bParser::BinaryContext *ctx) override
  {
      printInfo(__FUNCTION__, ctx);
      if (ctx->children.size() == 3) {
          auto lhs = std::any_cast<llvm::Value*>(visit(ctx->children[0]));
          auto op = ctx->children[1]->getText();
          auto rhs = std::any_cast<llvm::Value*>(visit(ctx->children[2]));

          if (!lhs || !rhs) return nullptr;

          if (op == "+")
          {
              return m_builder.CreateAdd(lhs, rhs, "addtmp");
          }
          else if (op == "-")
          {
              return m_builder.CreateSub(lhs, rhs, "subtmp");
          }
          else if (op == "*")
          {
              return m_builder.CreateMul(lhs, rhs, "multmp");
          }
          else if (op == "/")
          {
              return m_builder.CreateSDiv(lhs, rhs, "divtmp");
          }
          else if (op == "%")
          {
              return m_builder.CreateSRem(lhs, rhs, "modtmp");
          }
          else if (op == "==")
          {
              return m_builder.CreateICmpEQ(lhs, rhs, "eqtmp");
          }
          else if (op == "!=")
          {
              return m_builder.CreateICmpNE(lhs, rhs, "netmp");
          }
          else if (op == "<")
          {
              return m_builder.CreateICmpSLT(lhs, rhs, "lttmp");
          }
          else if (op == "<=")
          {
              return m_builder.CreateICmpSLE(lhs, rhs, "letmp");
          }
          else if (op == ">")
          {
              return m_builder.CreateICmpSGT(lhs, rhs, "gttmp");
          }
          else if (op == ">=")
          {
              return m_builder.CreateICmpSGE(lhs, rhs, "getmp");
          }
          else if (op == "&")
          {
              return m_builder.CreateAnd(lhs, rhs, "andtmp");
          }
          else if (op == "|")
          {
              return m_builder.CreateOr(lhs, rhs, "ortmp");
          }
          else if (op == "<<")
          {
              return m_builder.CreateShl(lhs, rhs, "shltmp");
          }
          else if (op == ">>")
          {
              return m_builder.CreateAShr(lhs, rhs, "shrtmp");
          }
          else
          {
              std::cerr << "Неизвестный бинарный оператор: " << op << std::endl;
              return nullptr;
          }
      }
      std::cerr << "Кол-во аргументов не соответствует данной операции" << std::endl;
      return nullptr;
  }

  virtual std::any visitLvalue(bParser::LvalueContext *ctx) override
  {
      printInfo(__FUNCTION__, ctx);
    return visitChildren(ctx);
  }

  virtual std::any visitConstant(bParser::ConstantContext *ctx) override
  {
      printInfo(__FUNCTION__, ctx);
      if (m_pendingVariableName)
      {
          llvm::Type* type;
          llvm::Value* value;
          if (ctx->INT())
          {
              int v = std::stoi(ctx->getText());
              value = llvm::ConstantInt::get(llvm::Type::getInt32Ty(m_context), v);
              llvm::AllocaInst* alloc = m_builder.CreateAlloca(llvm::Type::getInt32Ty(m_context), nullptr, *m_pendingVariableName);
              m_namedValues[*m_pendingVariableName] = variableWrapper{alloc, true};
              m_builder.CreateStore(value, alloc);
          }
          else if (ctx->STRING1() || ctx->STRING2())
          {
              std::string raw = ctx->getText();
              std::string stripped = raw.substr(1, raw.length() - 2);
              value = m_builder.CreateGlobalString(stripped);
              m_namedValues[*m_pendingVariableName] = variableWrapper{value, false};
          }
          return getOrCreateVariable(*m_pendingVariableName);
      }
      else
      {
          if (ctx->INT())
          {
              int value = std::stoi(ctx->getText());
              llvm::Value* constVal = llvm::ConstantInt::get(llvm::Type::getInt32Ty(m_context), value);
              return variableWrapper{constVal, true};
          }
          else if (ctx->STRING1() || ctx->STRING2())
          {
              std::string raw = ctx->getText();
              std::string stripped = raw.substr(1, raw.length() - 2);
              llvm::Value* str = m_builder.CreateGlobalString(stripped);
              return variableWrapper{str, false};
          }
      }
      return variableWrapper{};
  }

  virtual std::any visitName(bParser::NameContext *ctx) override
  {
      printInfo(__FUNCTION__, ctx);
      std::string name = ctx->getText();
      variableWrapper wrapper = getOrCreateVariable(name);
      if (wrapper.value)
      {
          if (name != wrapper.value->getName().str())
          {
              std::cerr << "Name is not suite" << std::endl;
          }
          std::cout << name << " == " << wrapper.value->getName().str() << std::endl;
      }
      return wrapper.value;
  }


};

