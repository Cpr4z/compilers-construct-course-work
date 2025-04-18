
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

inline void printInfo(std::string func_name, antlr4::ParserRuleContext* ctx)
{
    std::string result;
    int depth = ctx->depth();
    while(--depth)
    {
        result+= "\t";
    }
    std::cout << result + " " + func_name << " " << ctx->getText() << std::endl;
}


class  bBaseVisitor : public bVisitor {
public:
    static llvm::LLVMContext m_context;
    static std::unique_ptr<llvm::Module> m_module;
    static llvm::IRBuilder<> m_builder;
    static llvm::Function* m_function;

    static std::vector<llvm::BasicBlock*> m_blocks;
    static std::unordered_map<std::string, llvm::Value*> m_namedValues;
    static std::unordered_map<std::string, llvm::BasicBlock*> m_labelMap;
    static std::stack<std::pair<llvm::SwitchInst*, llvm::BasicBlock*>> m_switchStack;


public:

    llvm::AllocaInst* getOrCreateVariable(const std::string& name)
    {
        if (m_namedValues.contains(name))
        {
            return llvm::cast<llvm::AllocaInst>(m_namedValues[name]);;
        }
        else
        {
            // можно создать alloca и записать в таблицу
            llvm::AllocaInst* alloca = m_builder.CreateAlloca(llvm::Type::getInt32Ty(m_context), nullptr, name);
            m_namedValues[name] = alloca;
            return alloca;
        }
    }

    llvm::Function* getOrCreatePrintf()
    {
        llvm::Function* printfFunc = m_module->getFunction("printf");
        if (!printfFunc)
        {
            llvm::FunctionType* printfType = llvm::FunctionType::get(
                    llvm::Type::getInt32Ty(m_context),                       // возвращаемый тип
                    { llvm::PointerType::getUnqual(llvm::Type::getInt8Ty(m_context)) }, // аргумент: const char*
                    true                                                     // isVarArg
            );

            llvm::Function *printfFunc = llvm::Function::Create(
                    printfType,
                    llvm::Function::ExternalLinkage,
                    0,                   // AddrSpace
                    "printf",
                    m_module.get()
            );
        }
        return printfFunc;
    }

  virtual std::any visitProgram(bParser::ProgramContext *ctx) override
  {
      printInfo(__FUNCTION__, ctx);
      for (auto def : ctx->definition())
      {
          visit(def);
      }
    return visitChildren(ctx);
  }

  virtual std::any visitDefinition(bParser::DefinitionContext *ctx) override
  {
      printInfo(__FUNCTION__, ctx);
      if (ctx->statement())
      {
            std::string functionName = ctx->name(0)->getText();
            std::vector<llvm::Type*> paramTypes;
            std::vector<std::string> paramNames;
            for (size_t i = 1; i < ctx->name().size(); ++i)
            {
                paramTypes.push_back(llvm::Type::getInt32Ty(m_context));
                paramNames.push_back(ctx->name(i)->getText());
            }

            llvm::FunctionType* funcType = llvm::FunctionType::get(
                    llvm::Type::getVoidTy(m_context),
                    paramTypes,
                    false
                    );

            llvm::Function* function = llvm::Function::Create(
                    funcType,
                    llvm::Function::ExternalLinkage,
                    functionName,
                    m_module.get()
                    );

            m_function = function;
            size_t idx = 0;
            for (auto& arg : function->args())
            {
                arg.setName(paramNames[idx++]);
            }
            llvm::BasicBlock* entry = llvm::BasicBlock::Create(m_context, "entry", function);
            m_blocks.push_back(entry);//
            m_builder.SetInsertPoint(entry);
            visit(ctx->statement());
            m_builder.CreateRetVoid();
            m_blocks.pop_back();//
      }
      else
      {
            std::string varName = ctx->name(0)->getText();
            llvm::Type* type = llvm::Type::getInt32Ty(m_context);
            llvm::AllocaInst* alloc = m_builder.CreateAlloca(type, nullptr, varName);
            auto ivals = ctx->ival();
            for (size_t i = 0; i < ivals.size(); ++i)
            {
                auto* value = std::any_cast<llvm::Value*>(visit(ivals[i]));
                // пока просто store первого
                m_builder.CreateStore(value, alloc);
                break; // TODO: поддержка массивов позже
            }
      }
      return nullptr;
//    return visitChildren(ctx);
  }

  virtual std::any visitIval(bParser::IvalContext *ctx) override
  {
      printInfo(__FUNCTION__, ctx);
      if (ctx->constant())
      {
          // Если это константа — генерируем llvm::Constant
            return visit(ctx->constant()); // вернёт llvm::Value*
      }
      else if (ctx->name())
      {
            // Если это имя — читаем переменную
          llvm::AllocaInst* ptr = getOrCreateVariable(ctx->name()->getText());
          llvm::Type* elementType = ptr->getAllocatedType();
          return m_builder.CreateLoad(elementType, ptr, "loadtmp");
      }
      return nullptr;
//    return visitChildren(ctx);
  }

  virtual std::any visitStatement(bParser::StatementContext *ctx) override
  {
      printInfo(__FUNCTION__, ctx);
      if (ctx->externsmt()) {
          return visit(ctx->externsmt());
      } else if (ctx->autosmt()) {
          return visit(ctx->autosmt());
      } else if (ctx->name() && ctx->statement()) {
          // Это метка: `name ':' statement`
          return visit(ctx->statement());
      } else if (ctx->casestmt()) {
          return visit(ctx->casestmt());
      } else if (ctx->blockstmt()) {
          return visit(ctx->blockstmt());
      } else if (ctx->ifstmt()) {
          return visit(ctx->ifstmt());
      } else if (ctx->whilestmt()) {
          return visit(ctx->whilestmt());
      } else if (ctx->switchstmt()) {
          return visit(ctx->switchstmt());
      } else if (ctx->gotostmt()) {
          return visit(ctx->gotostmt());
      } else if (ctx->returnstmt()) {
          return visit(ctx->returnstmt());
      } else if (ctx->expressionstmt()) {
          return visit(ctx->expressionstmt());
      } else if (ctx->nullstmt()) {
          return visit(ctx->nullstmt());
      }

      return nullptr;
//    return visitChildren(ctx);
  }

  virtual std::any visitNullstmt(bParser::NullstmtContext *ctx) override
  {
      printInfo(__FUNCTION__, ctx);
        return nullptr;
//    return visitChildren(ctx);
  }

  virtual std::any visitExpressionstmt(bParser::ExpressionstmtContext *ctx) override
  {
      printInfo(__FUNCTION__, ctx);
        if (auto* rvalue = ctx->rvalue())
        {
            return visit(rvalue);
        }
        return nullptr;
//    return visitChildren(ctx);
  }

  virtual std::any visitBlockstmt(bParser::BlockstmtContext *ctx) override
  {
      printInfo(__FUNCTION__, ctx);
    return visitChildren(ctx);
  }

  virtual std::any visitReturnstmt(bParser::ReturnstmtContext *ctx) override
  {
      printInfo(__FUNCTION__, ctx);
        if (auto* rvalue = ctx->rvalue())
        {
            auto* value = std::any_cast<llvm::Value*>(visit(rvalue));
            return m_builder.CreateRet(value);
        }
        else
        {
            return m_builder.CreateRetVoid();
        }
//    return visitChildren(ctx);
  }

  virtual std::any visitGotostmt(bParser::GotostmtContext *ctx) override
  {
      printInfo(__FUNCTION__, ctx);
        std::string label = ctx->rvalue()->getText();
        llvm::BasicBlock* targetBlock = m_labelMap[label];
        m_builder.CreateBr(targetBlock);
        // После br нельзя вставлять код, создаём "пустой" блок на всякий случай
        llvm::BasicBlock* unreachable = llvm::BasicBlock::Create(m_context, "after_goto", m_function);
        m_blocks.push_back(unreachable);
        m_builder.SetInsertPoint(unreachable);
        return nullptr;
//      return visitChildren(ctx);
  }

  virtual std::any visitSwitchstmt(bParser::SwitchstmtContext *ctx) override
  {
      printInfo(__FUNCTION__, ctx);
      llvm::Value* cond = std::any_cast<llvm::Value*>(visit(ctx->rvalue()));
      llvm::Function* function = m_builder.GetInsertBlock()->getParent();

      // Блок выхода из switch (если ни один case не сработал)
      llvm::BasicBlock* endBlock = llvm::BasicBlock::Create(m_context, "switch.end", function);
      m_blocks.push_back(endBlock);
      // Инструкция switch
      llvm::SwitchInst* switchInst = m_builder.CreateSwitch(cond, endBlock);

      // Сохраняем текущий switch в стек
      m_switchStack.push({switchInst, endBlock});

      // Внутренние case-операторы
      visit(ctx->statement());

      // Выход из switch
      if (!m_builder.GetInsertBlock()->getTerminator()) {
          m_builder.CreateBr(endBlock);
      }

      m_builder.SetInsertPoint(endBlock);
      m_switchStack.pop();
      return nullptr;
//    return visitChildren(ctx);
  }

  virtual std::any visitWhilestmt(bParser::WhilestmtContext *ctx) override
  {
      printInfo(__FUNCTION__, ctx);
      llvm::Function* function = m_builder.GetInsertBlock()->getParent();

      // Блоки цикла
      llvm::BasicBlock* condBlock = llvm::BasicBlock::Create(m_context, "while.cond", function);
      llvm::BasicBlock* bodyBlock = llvm::BasicBlock::Create(m_context, "while.body", function);
      llvm::BasicBlock* endBlock  = llvm::BasicBlock::Create(m_context, "while.end", function);

      // Безусловный переход в проверку условия
      m_builder.CreateBr(condBlock);

      // Условие
      m_builder.SetInsertPoint(condBlock);
      llvm::Value* cond = std::any_cast<llvm::Value*>(visit(ctx->rvalue()));
      cond = m_builder.CreateICmpNE(cond, llvm::ConstantInt::get(cond->getType(), 0), "whilecond");
      m_builder.CreateCondBr(cond, bodyBlock, endBlock);

      // Тело цикла
      m_builder.SetInsertPoint(bodyBlock);
      visit(ctx->statement());
      if (!m_builder.GetInsertBlock()->getTerminator())
          m_builder.CreateBr(condBlock); // Переход к следующей проверке

      // Блок выхода
      m_builder.SetInsertPoint(endBlock);
      return nullptr;
//    return visitChildren(ctx);
  }

  virtual std::any visitIfstmt(bParser::IfstmtContext *ctx) override
  {
      printInfo(__FUNCTION__, ctx);
      llvm::Value* cond = std::any_cast<llvm::Value*>(visit(ctx->rvalue()));
      cond = m_builder.CreateICmpNE(cond, llvm::ConstantInt::get(cond->getType(), 0), "ifcond");

      llvm::Function* function = m_builder.GetInsertBlock()->getParent();

      // Создаём блоки then, else (если есть), merge
      llvm::BasicBlock* thenBlock = llvm::BasicBlock::Create(m_context, "if.then", function);
      llvm::BasicBlock* mergeBlock = llvm::BasicBlock::Create(m_context, "if.end", function);

      llvm::BasicBlock* elseBlock = nullptr;
      if (ctx->statement().size() > 1) {
          elseBlock = llvm::BasicBlock::Create(m_context, "if.else", function);
      }

      // Условный переход
      m_builder.CreateCondBr(cond, thenBlock, elseBlock ? elseBlock : mergeBlock);

      // THEN блок
      m_builder.SetInsertPoint(thenBlock);
      visit(ctx->statement(0));
      if (!m_builder.GetInsertBlock()->getTerminator()) {
          m_builder.CreateBr(mergeBlock);
      }

      // ELSE блок (если есть)
      if (elseBlock) {
          m_builder.SetInsertPoint(elseBlock);
          visit(ctx->statement(1));
          if (!m_builder.GetInsertBlock()->getTerminator()) {
              m_builder.CreateBr(mergeBlock);
          }
      }

      // Устанавливаем точку вставки в merge-блок
      m_builder.SetInsertPoint(mergeBlock);
      return nullptr;
//    return visitChildren(ctx);
  }

  virtual std::any visitCasestmt(bParser::CasestmtContext *ctx) override
  {
      printInfo(__FUNCTION__, ctx);
      if (m_switchStack.empty()) {
          std::cerr << "Ошибка: case вне switch\n";
          return nullptr;
      }

      auto& [switchInst, endBlock] = m_switchStack.top();
      llvm::Function* function = m_builder.GetInsertBlock()->getParent();

      // Получаем значение case
      llvm::Value* val = std::any_cast<llvm::Value*>(visit(ctx->constant()));
      auto* constInt = llvm::dyn_cast<llvm::ConstantInt>(val);
      if (!constInt) {
          std::cerr << "Ошибка: значение case не является целым числом\n";
          return nullptr;
      }

      // Создаём новый блок под этот case
      llvm::BasicBlock* caseBlock = llvm::BasicBlock::Create(m_context, "case", function);

      // Добавляем переход из switch в этот блок
      switchInst->addCase(constInt, caseBlock);

      // Если предыдущее место вставки не закончилось — явно переходим сюда
      if (!m_builder.GetInsertBlock()->getTerminator()) {
          m_builder.CreateBr(caseBlock);
      }

      // Переходим в case-блок
      m_builder.SetInsertPoint(caseBlock);
      visit(ctx->statement());

      return nullptr;
//    return visitChildren(ctx);
  }

  virtual std::any visitExternsmt(bParser::ExternsmtContext *ctx) override
  {
      printInfo(__FUNCTION__, ctx);
        for (auto* nameCtx : ctx->name())
        {
            std::string name = nameCtx->getText();
            llvm::GlobalVariable* var = new llvm::GlobalVariable(
                    *m_module,
                    llvm::Type::getInt32Ty(m_context),  // по умолчанию int
                    false,
                    llvm::GlobalValue::ExternalLinkage,
                    nullptr,
                    name
                    );
            m_namedValues[name] = var; // refactor
        }
        return nullptr;
//    return visitChildren(ctx);
  }

  virtual std::any visitAutosmt(bParser::AutosmtContext *ctx) override
  {
      printInfo(__FUNCTION__, ctx);
      auto names = ctx->name();
      auto constants = ctx->constant();
      for (size_t i = 0; i < names.size(); ++i) {
          std::string name = names[i]->getText();
          llvm::AllocaInst* alloca = getOrCreateVariable(name);

          // Если есть значение
          if (i < constants.size() && constants[i]) {
              auto* init = std::any_cast<llvm::Value*>(visit(constants[i]));
              m_builder.CreateStore(init, alloca);
          }
      }
      return nullptr;
//    return visitChildren(ctx);
  }

  virtual std::any visitRvalue(bParser::RvalueContext *ctx) override
  {
      printInfo(__FUNCTION__, ctx);
    return visitChildren(ctx);
  }

  virtual std::any visitTernary(bParser::TernaryContext *ctx) override
  {
        printInfo(__FUNCTION__, ctx);
      llvm::Value* cond = std::any_cast<llvm::Value*>(visit(ctx->expression()));
      if (!cond) return nullptr;

      cond = m_builder.CreateICmpNE(cond, llvm::ConstantInt::get(cond->getType(), 0), "cond");

      llvm::Function* function = m_builder.GetInsertBlock()->getParent();

      // Блоки then/else сразу с parent — будут добавлены в функцию
      llvm::BasicBlock* ifTrueBlock = llvm::BasicBlock::Create(m_context, "ternary.true", function);
      llvm::BasicBlock* ifFalseBlock = llvm::BasicBlock::Create(m_context, "ternary.false");
      llvm::BasicBlock* mergeBlock  = llvm::BasicBlock::Create(m_context, "ternary.merge");

      m_builder.CreateCondBr(cond, ifTrueBlock, ifFalseBlock);

      // True ветка
      m_builder.SetInsertPoint(ifTrueBlock);
      llvm::Value* trueVal = std::any_cast<llvm::Value*>(visit(ctx->rvalue(0)));
      if (!m_builder.GetInsertBlock()->getTerminator())
          m_builder.CreateBr(mergeBlock);

      ifTrueBlock = m_builder.GetInsertBlock();

      // False ветка
      function->insert(function->end(), ifFalseBlock);
      m_builder.SetInsertPoint(ifFalseBlock);
      llvm::Value* falseVal = std::any_cast<llvm::Value*>(visit(ctx->rvalue(1)));
      if (!m_builder.GetInsertBlock()->getTerminator())
          m_builder.CreateBr(mergeBlock);

      ifFalseBlock = m_builder.GetInsertBlock();

      // Merge
      function->insert(function->end(), mergeBlock);
      m_builder.SetInsertPoint(mergeBlock);

      llvm::PHINode* phi = m_builder.CreatePHI(trueVal->getType(), 2, "ternarytmp");
      phi->addIncoming(trueVal, ifTrueBlock);
      phi->addIncoming(falseVal, ifFalseBlock);

      return phi;
//    return visitChildren(ctx);
  }

  virtual std::any visitComparison(bParser::ComparisonContext *ctx) override
  {
      printInfo(__FUNCTION__, ctx);
      // Получаем левое значение — expression
      llvm::Value* lhs = std::any_cast<llvm::Value*>(visit(ctx->expression()));
      if (!lhs) return nullptr;

      // Получаем правое значение — rvalue
      llvm::Value* rhs = std::any_cast<llvm::Value*>(visit(ctx->rvalue()));
      if (!rhs) return nullptr;

      // Получаем бинарный оператор как строку
      std::string op = ctx->binary()->getText();

      // Определяем, какой тип сравнения генерировать
      llvm::Value* result = nullptr;
      if (op == "==") {
          result = m_builder.CreateICmpEQ(lhs, rhs, "eqtmp");
      } else if (op == "!=") {
          result = m_builder.CreateICmpNE(lhs, rhs, "netmp");
      } else if (op == "<") {
          result = m_builder.CreateICmpSLT(lhs, rhs, "lttmp");
      } else if (op == "<=") {
          result = m_builder.CreateICmpSLE(lhs, rhs, "letmp");
      } else if (op == ">") {
          result = m_builder.CreateICmpSGT(lhs, rhs, "gttmp");
      } else if (op == ">=") {
          result = m_builder.CreateICmpSGE(lhs, rhs, "getmp");
      } else {
          std::cerr << "Unknown comparison operator: " << op << "\n";
          return nullptr;
      }

      return result;
//    return visitChildren(ctx);
  }

  virtual std::any visitAssignment(bParser::AssignmentContext *ctx) override
  {
      printInfo(__FUNCTION__, ctx);
      // Получаем имя переменной
      std::string varName = ctx->name()->getText();

      // Получаем указатель на память переменной
      llvm::AllocaInst* ptr = getOrCreateVariable(varName);
      if (!ptr) {
          std::cerr << "Ошибка: переменная '" << varName << "' не найдена или не alloca\n";
          return nullptr;
      }

      // Генерируем значение правой части (rvalue)
      llvm::Value* value = std::any_cast<llvm::Value*>(visit(ctx->rvalue()));
      if (!value) {
          std::cerr << "Ошибка: rvalue не определено\n";
          return nullptr;
      }

      // Создаём инструкцию store
      m_builder.CreateStore(value, ptr);

      return value;
//    return visitChildren(ctx);
  }

  virtual std::any visitExpression(bParser::ExpressionContext *ctx) override
  {
      printInfo(__FUNCTION__, ctx);
      // (rvalue)
      if (ctx->rvalue() && ctx->getStart()->getText() == "(") {
          return visit(ctx->rvalue());
      }

      // name
      if (ctx->name() && !ctx->incdec() && ctx->children.size() == 1) {
          return visit(ctx->name());
      }

      // constant
      if (ctx->constant()) {
          return visit(ctx->constant());
      }

      // incdec name (префикс)
      if (ctx->incdec() && ctx->name()) {
          return visit(ctx->incdec()); // логика инкремента будет обращаться к имени через parent
      }

      // name incdec (постфикс)
      if (ctx->name() && ctx->incdec()) {
          return visit(ctx->incdec()); // логика та же — name доступен через parent
      }

      // unary rvalue
      if (ctx->unary() && ctx->rvalue()) {
          return visit(ctx->unary());
      }

      // &name (получение адреса)
      if (ctx->getStart()->getText() == "&" && ctx->name()) {
          llvm::Value* ptr = getOrCreateVariable(ctx->name()->getText());
          return ptr;
      }

      // functioninvocation
      if (ctx->functioninvocation()) {
          return visit(ctx->functioninvocation());
      }

      std::cerr << "Не удалось распознать выражение\n";
      return nullptr;
//    return visitChildren(ctx);
  }

  virtual std::any visitFunctioninvocation(bParser::FunctioninvocationContext *ctx) override
  {
      printInfo(__FUNCTION__, ctx);
      // Имя функции
      std::string funcName = ctx->name()->getText();

      // 🔹 Поддержка встроенной функции print
      if (funcName == "print") {
          std::vector<llvm::Value*> args;

          if (ctx->functionparameters()) {
              args = std::any_cast<std::vector<llvm::Value*>>(visit(ctx->functionparameters()));
          }

          if (args.empty()) {
              std::cerr << "Ошибка: print() должен принимать хотя бы один аргумент\n";
              return nullptr;
          }

          llvm::Value* value = args[0];

          // Создаём строку формата "%d\n" (или "%f\n", если у тебя float)
          llvm::Value* formatStr = m_builder.CreateGlobalStringPtr("%d\n");

          // Получаем printf из модуля
          llvm::Function* printfFunc = m_module->getFunction("printf");

          if (!printfFunc) {
              std::cerr << "Ошибка: printf не добавлен в модуль\n";
              return nullptr;
          }

          return m_builder.CreateCall(printfFunc, {formatStr, value});
      }

      // Поиск функции
      llvm::Function* callee = m_module->getFunction(funcName);
      if (!callee) {
          std::cerr << "Ошибка: функция \"" << funcName << "\" не найдена в модуле\n";
          return nullptr;
      }

      // Аргументы
      std::vector<llvm::Value*> args;
      if (ctx->functionparameters()) {
          args = std::any_cast<std::vector<llvm::Value*>>(visit(ctx->functionparameters()));
      }

      // Проверка аргументов по количеству
      if (callee->arg_size() != args.size()) {
          std::cerr << "Ошибка: количество аргументов не совпадает для функции \"" << funcName << "\"\n";
          return nullptr;
      }

      // Вызов функции
      return m_builder.CreateCall(callee, args, "calltmp");
//    return visitChildren(ctx);
  }

  virtual std::any visitFunctionparameters(bParser::FunctionparametersContext *ctx) override
  {
      printInfo(__FUNCTION__, ctx);
      std::vector<llvm::Value*> args;
      for (auto* expr : ctx->rvalue()) {
          llvm::Value* val = std::any_cast<llvm::Value*>(visit(expr));
          args.push_back(val);
      }
      return args;
//    return visitChildren(ctx);
  }

  virtual std::any visitAssign(bParser::AssignContext *ctx) override
  {
      printInfo(__FUNCTION__, ctx);
      if (!ctx->binary()) {
          std::cerr << "Предупреждение: пустое присваивание\n";
          return nullptr;
      }

      // Получаем значение правой части
      llvm::Value* value = std::any_cast<llvm::Value*>(visit(ctx->binary()));

      // Предполагаем, что родитель — lvalue, где мы запомним имя
      auto* parent = ctx->parent;
      auto* lvalueCtx = dynamic_cast<bParser::LvalueContext*>(parent);
      if (!lvalueCtx || !lvalueCtx->name()) {
          std::cerr << "Ошибка: присваивание без имени слева\n";
          return nullptr;
      }

      std::string name = lvalueCtx->name()->getText();

      // Получаем указатель на переменную
//      llvm::Value* ptr = getOrCreateVariable(name);
      llvm::AllocaInst* ptr = getOrCreateVariable(name);

      // Генерируем store
      return m_builder.CreateStore(value, ptr);
//    return visitChildren(ctx);
  }

  virtual std::any visitIncdec(bParser::IncdecContext *ctx) override
  {
      printInfo(__FUNCTION__, ctx);
      // Предполагаем, что incdec — часть lvalue, где есть имя переменной
      auto* lvalueCtx = dynamic_cast<bParser::LvalueContext*>(ctx->parent);
      if (!lvalueCtx || !lvalueCtx->name()) {
          std::cerr << "Ошибка: incdec без имени переменной\n";
          return nullptr;
      }

      std::string name = lvalueCtx->name()->getText();

      llvm::AllocaInst* ptr = getOrCreateVariable(name);
      // Загружаем текущее значение
      llvm::Type* elementType = ptr->getAllocatedType();
      llvm::Value* val = m_builder.CreateLoad(elementType, ptr, "loadtmp");

      // Вычисляем новое значение
      llvm::Value* one = llvm::ConstantInt::get(val->getType(), 1);
      llvm::Value* result = nullptr;

      if (ctx->getText() == "++") {
          result = m_builder.CreateAdd(val, one, "inctmp");
      } else if (ctx->getText() == "--") {
          result = m_builder.CreateSub(val, one, "dectmp");
      } else {
          std::cerr << "Ошибка: неизвестный оператор incdec\n";
          return nullptr;
      }

      // Сохраняем результат
      m_builder.CreateStore(result, ptr);

      // Возвращаем новое значение (по необходимости)
      return result;
//    return visitChildren(ctx);
  }

  virtual std::any visitUnary(bParser::UnaryContext *ctx) override
  {
      printInfo(__FUNCTION__, ctx);
      // Ищем родителя, у которого есть rvalue
      auto parent = ctx->parent;
      auto rvalueCtx = dynamic_cast<bParser::RvalueContext*>(parent);

      if (!rvalueCtx) {
          std::cerr << "Ошибка: унарный оператор без rvalue\n";
          return nullptr;
      }

      // Получаем значение выражения
      llvm::Value* val = std::any_cast<llvm::Value*>(visit(rvalueCtx));
      if (!val) return nullptr;

      // Определяем тип унарного оператора
      std::string op = ctx->getStart()->getText();

      if (op == "-") {
          llvm::Value* zero = llvm::ConstantInt::get(val->getType(), 0);
          return m_builder.CreateSub(zero, val, "negtmp");
      } else if (op == "!") {
          llvm::Value* zero = llvm::ConstantInt::get(val->getType(), 0);
          return m_builder.CreateICmpEQ(val, zero, "nottmp");
      }

      return nullptr;
//    return visitChildren(ctx);
  }

  virtual std::any visitBinary(bParser::BinaryContext *ctx) override
  {
      printInfo(__FUNCTION__, ctx);
      // Если это бинарное выражение (3 дочерних узла)
      if (ctx->children.size() == 3) {
          auto lhs = std::any_cast<llvm::Value*>(visit(ctx->children[0]));
          auto op = ctx->children[1]->getText(); // это binary
          auto rhs = std::any_cast<llvm::Value*>(visit(ctx->children[2]));

          if (!lhs || !rhs) return nullptr;

          if (op == "+") {
              return m_builder.CreateAdd(lhs, rhs, "addtmp");
          } else if (op == "-") {
              return m_builder.CreateSub(lhs, rhs, "subtmp");
          } else if (op == "*") {
              return m_builder.CreateMul(lhs, rhs, "multmp");
          } else if (op == "/") {
              return m_builder.CreateSDiv(lhs, rhs, "divtmp"); // предполагаем знаковые int
          } else if (op == "%") {
              return m_builder.CreateSRem(lhs, rhs, "modtmp");
          } else if (op == "==") {
              return m_builder.CreateICmpEQ(lhs, rhs, "eqtmp");
          } else if (op == "!=") {
              return m_builder.CreateICmpNE(lhs, rhs, "netmp");
          } else if (op == "<") {
              return m_builder.CreateICmpSLT(lhs, rhs, "lttmp");
          } else if (op == "<=") {
              return m_builder.CreateICmpSLE(lhs, rhs, "letmp");
          } else if (op == ">") {
              return m_builder.CreateICmpSGT(lhs, rhs, "gttmp");
          } else if (op == ">=") {
              return m_builder.CreateICmpSGE(lhs, rhs, "getmp");
          } else if (op == "&") {
              return m_builder.CreateAnd(lhs, rhs, "andtmp");
          } else if (op == "|") {
              return m_builder.CreateOr(lhs, rhs, "ortmp");
          } else if (op == "<<") {
              return m_builder.CreateShl(lhs, rhs, "shltmp");
          } else if (op == ">>") {
              return m_builder.CreateAShr(lhs, rhs, "shrtmp");
          } else {
              std::cerr << "Неизвестный бинарный оператор: " << op << std::endl;
              return nullptr;
          }
      }
      std::cerr << "Кол-во аргументов не соответствует данной операции" << std::endl;
      return nullptr;
//    return visitChildren(ctx);
  }

  virtual std::any visitLvalue(bParser::LvalueContext *ctx) override
  {
      printInfo(__FUNCTION__, ctx);
    return visitChildren(ctx);
  }

  virtual std::any visitConstant(bParser::ConstantContext *ctx) override
  {
      printInfo(__FUNCTION__, ctx);
      if (ctx->INT()) {
          // Целочисленная константа
          int value = std::stoi(ctx->INT()->getText());
          return llvm::ConstantInt::get(llvm::Type::getInt32Ty(m_context), value);
      }
      else if (ctx->STRING1() || ctx->STRING2()) {
          // Строковая константа — убираем кавычки и создаем LLVM строковый литерал
          std::string raw = ctx->getText();
          std::string stripped = raw.substr(1, raw.length() - 2); // Удаляем кавычки
          llvm::Value *str = m_builder.CreateGlobalStringPtr(stripped);
          return str;
      }
      std::cerr << "Ошибка: неизвестный тип константы\n";
      return nullptr;
//    return visitChildren(ctx);
  }

  virtual std::any visitName(bParser::NameContext *ctx) override
  {
      printInfo(__FUNCTION__, ctx);
      std::string name = ctx->getText();
      llvm::Value* ptr = getOrCreateVariable(name);
      return ptr;
//    return visitChildren(ctx);
  }


};

