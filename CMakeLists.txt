cmake_minimum_required(VERSION 3.15)
project(barzane)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)
include_directories(src)
include_directories(test)

add_executable(barzane
    include/str.h
    include/Symbol.h
    include/Indexer.h
    include/Error.h
    include/ErrorHandler.h
    include/Lexer.h
    include/Parser.h
    include/AST.h
    include/Node.h
    src/barzane.cpp
    src/Symbol.cpp
    src/ErrorHandler.cpp
    src/Lexer.cpp
    src/Parser.cpp
    src/AST.cpp
    src/Node.cpp src/node/Declarations.cpp include/node/Declarations.h src/node/Affects.cpp include/node/Affects.h src/node/Builtins.cpp include/node/Builtins.h)
