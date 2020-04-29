cmake_minimum_required(VERSION 3.15)
project(barzane)

set(CMAKE_CXX_STANDARD 20)

add_executable(barzane src/barzane.cpp src/Symbol.cpp include/Symbol.h test/SymbolTest.cpp test/SymbolTest.h test/MainTest.cpp)