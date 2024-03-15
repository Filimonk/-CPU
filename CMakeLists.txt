cmake_minimum_required(VERSION 3.22.1 FATAL_ERROR)


project(project2)

include_directories(STACK/include)

add_executable(Test STACK/test/Test.cpp)

add_executable(project2 src/CPU.cpp)

add_subdirectory(STACK)

target_link_libraries(project2 STACK)
