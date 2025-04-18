#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>

#include "antlr4-runtime.h"
#include "bLexer.h"
#include "bParser.h"
#include "bBaseVisitor.h"
#include "bVisitor.h"

llvm::LLVMContext bBaseVisitor::m_context;
llvm::IRBuilder<> bBaseVisitor::m_builder(m_context);
llvm::Function* bBaseVisitor::m_function;

std::vector<llvm::BasicBlock*> bBaseVisitor::m_blocks;


int main(int argc, const char* argv[])
{
    if (argc < 2)
    {
        std::cerr << "No input file" << std::endl;
        return 1;
    }
    std::filesystem::path pathToFile = argv[1];
    std::string inputFile;
    {
        std::ifstream infile(pathToFile.string());
        if (infile)
        {
            std::ostringstream ss;
            ss << infile.rdbuf();
            inputFile = ss.str();
        }
        else
        {
            throw std::invalid_argument("");
        }
    }

    antlr4::ANTLRInputStream input(inputFile);
    bLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    bParser parser(&tokens);
    llvm::InitializeNativeTarget();
    llvm::LLVMContext Context;
    auto* module = new llvm::Module("trash_module", Context);

    auto* main_func_type = llvm::FunctionType::get(llvm::Type::getInt32Ty(Context), false);
    bBaseVisitor::m_function = llvm::Function::Create(main_func_type,
                                                llvm::Function::ExternalLinkage,
                                                "main",
                                                module);

    // create m_blocks
    bBaseVisitor::m_blocks.push_back(llvm::BasicBlock::Create(Context, "entry", bBaseVisitor::m_function));

    bBaseVisitor visitor;
    auto* prog = parser.program();
    visitor.visit(prog);
    std::error_code EC;
    llvm::raw_fd_ostream File((pathToFile.parent_path() / pathToFile.filename().replace_extension("ll")).string(), EC);
    if (EC)
    {
        llvm::errs() << "Could not open file: " << EC.message() << "\n";
        return 1;
    }

    module->print(File, nullptr);
    delete module;
    return 0;
}