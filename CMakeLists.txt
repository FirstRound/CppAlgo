cmake_minimum_required(VERSION 3.5)
project(CppAlgo)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp ListGraph.h Graph.h headers.h AdjList.h)
add_executable(CppAlgo ${SOURCE_FILES})