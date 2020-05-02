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
    src/barzane.cpp
    src/Symbol.cpp
    src/ErrorHandler.cpp
    src/Lexer.cpp
)
