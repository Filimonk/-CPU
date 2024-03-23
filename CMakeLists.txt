cmake_minimum_required(VERSION 3.22.1 FATAL_ERROR)


project(project2)

add_subdirectory(STACK)

include_directories(STACK/include)

include_directories(include)

add_library(parser src/parser.cpp)

add_library(preprocessor src/preprocessor.cpp)

target_link_libraries(preprocessor parser)

add_library(command src/command.cpp)

target_link_libraries(command STACK)

add_library(processing src/processing.cpp)

target_link_libraries(processing command STACK)

add_executable(project2 src/CPU.cpp)

target_link_libraries(project2 preprocessor processing)



add_executable(Test STACK/test/Test.cpp)

target_link_libraries(Test STACK)
