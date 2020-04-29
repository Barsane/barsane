cmake_minimum_required(VERSION 3.15)
project(barzane)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)
include_directories(include)
include_directories(src)
include_directories(test)

add_executable(barzane
        include/Symbol.h
        src/barzane.cpp
        src/Symbol.cpp)
