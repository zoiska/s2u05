cmake_minimum_required(VERSION 3.27)
project(s2u05)

set(CMAKE_CXX_STANDARD 20)

add_executable(s2u05 main.cpp
        Array.cpp
        Array.h
        sum.h
        linearlist.h)
