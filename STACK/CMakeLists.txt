cmake_minimum_required(VERSION 3.22.1 FATAL_ERROR)

project(STACK)

include_directories(include)

add_library(STACK src/Stack.cpp)
