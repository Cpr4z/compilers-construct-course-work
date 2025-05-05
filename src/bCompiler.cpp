#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>

#include "llvm/Support/TargetSelect.h"
#include "llvm/TargetParser//Host.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/MC/TargetRegistry.h"

#include "antlr4-runtime.h"
#include "bLexer.h"
#include "bParser.h"
#include "bBaseVisitor.h"

llvm::LLVMContext bBaseVisitor::m_context;
llvm::Module* bBaseVisitor::m_module = nullptr;
llvm::IRBuilder<> bBaseVisitor::m_builder(m_context);
llvm::Function* bBaseVisitor::m_function = nullptr;

std::vector<llvm::BasicBlock*> bBaseVisitor::m_blocks;
std::unordered_map<std::string, bBaseVisitor::variableWrapper> bBaseVisitor::m_namedValues;
std::unordered_map<std::string, llvm::BasicBlock*> bBaseVisitor::m_labelMap;
std::stack<std::pair<llvm::SwitchInst*, llvm::BasicBlock*>> bBaseVisitor::m_switchStack;

std::unordered_map<std::string, llvm::Function*> bBaseVisitor::m_namedFunctions;
std::unordered_map<std::string, bParser::DefinitionContext*> bBaseVisitor::m_functionBodies;


int main(int argc, const char* argv[])
{
//    if (argc < 2)
//    {
//        std::cerr << "No input file" << std::endl;
//        return 1;
//    }
//    std::filesystem::path pathToFile = argv[1];
//    std::string inputFile;
//    {
//        std::ifstream infile(pathToFile.string());
//        if (infile)
//        {
//            std::ostringstream ss;
//            ss << infile.rdbuf();
//            inputFile = ss.str();
//        }
//        else
//        {
//            throw std::invalid_argument("");
//        }
//    }

//    std::filesystem::path pathToFile = R"(/Users/matvey_agarkov/Desktop/compilers-construct-course-work/src/tests/programs/test1.b)";
//    std::filesystem::path pathToFile = R"(/Users/matvey_agarkov/Desktop/compilers-construct-course-work/src/tests/programs/test2.b)";
//    std::filesystem::path pathToFile = R"(/Users/matvey_agarkov/Desktop/compilers-construct-course-work/src/tests/programs/test3.b)";
//    std::filesystem::path pathToFile = R"(/Users/matvey_agarkov/Desktop/compilers-construct-course-work/src/tests/programs/bubble.b)";
//    std::filesystem::path pathToFile = R"(/Users/matvey_agarkov/Desktop/compilers-construct-course-work/src/tests/programs/test4.b)";
//    std::filesystem::path pathToFile = R"(/Users/matvey_agarkov/Desktop/compilers-construct-course-work/src/tests/programs/test5.b)";
//    std::filesystem::path pathToFile = R"(/Users/matvey_agarkov/Desktop/compilers-construct-course-work/src/tests/programs/test6.b)";
    std::filesystem::path pathToFile = R"(/Users/matvey_agarkov/Desktop/compilers-construct-course-work/src/tests/programs/test7.b)";
    std::filesystem::path currentDirectory = std::filesystem::current_path();
    std::string inputFile;
    {
        std::ifstream infile(pathToFile);
        std::ostringstream  ss;
        ss << infile.rdbuf();
        inputFile = ss.str();
    }

    antlr4::ANTLRInputStream input(inputFile);
    bLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    bParser parser(&tokens);

    llvm::InitializeNativeTarget();

    std::string targetTriple = llvm::sys::getDefaultTargetTriple();
    std::string error;
    const llvm::Target* target = llvm::TargetRegistry::lookupTarget(targetTriple, error);

    if (!target) {
        llvm::errs() << "Failed to lookup target: " << error << "\n";
        return 1;
    }

    llvm::TargetOptions opt;
    auto RM = std::optional<llvm::Reloc::Model>();
    llvm::TargetMachine* targetMachine = target->createTargetMachine(targetTriple, "generic", "", opt, RM);

    bBaseVisitor::m_module = new llvm::Module("generated", bBaseVisitor::m_context);
    bBaseVisitor::m_module->setDataLayout(targetMachine->createDataLayout());
    bBaseVisitor::m_module->setTargetTriple(targetTriple);

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
    bBaseVisitor::m_module->print(File, nullptr);
    delete bBaseVisitor::m_module;
    return 0;
}
