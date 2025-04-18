cmake_minimum_required(VERSION 3.29)
project(bCompiler)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory( Antlr/antlr4/runtime/Cpp )

set(LLVM_DIR "/opt/homebrew/opt/llvm/lib/cmake/llvm")

find_package( LLVM CONFIG REQUIRED )

add_executable(${PROJECT_NAME}
        #  main.cpp
        bCompiler.cpp
        bBaseVisitor.cpp
        bBaseVisitor.h
        bLexer.cpp
        bParser.cpp
        bVisitor.cpp
        bVisitor.h
		bBaseListener.h
		bBaseListener.cpp
)

target_include_directories( ${PROJECT_NAME} PRIVATE Antlr/antlr4/runtime/Cpp/runtime/src )

llvm_map_components_to_libnames(llvm_libs
    core
    orcjit
    nativecodegen
    support
    target
)

target_include_directories( ${PROJECT_NAME} SYSTEM PUBLIC ${LLVM_INCLUDE_DIRS} )
target_link_libraries( ${PROJECT_NAME} 
    PUBLIC 
        ${llvm_libs}
	    #antlr4_shared
	    antlr4_static
)
