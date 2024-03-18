#minimum version required to start cmake
cmake_minimum_required(VERSION 3.1...3.22)

#project name
project(calculator VERSION 1.0 DESCRIPTION "Calculator for simple operations" LANGUAGES C)

#make variable for source files
set(SOURCE_FILES add.c mult.c division.c sub.c)

#Make an executable
add_executable(${PROJECT_NAME} main.c)

#include header files required for excutable
target_include_directories(${PROJECT_NAME} PRIVATE include)

#make a static library
add_library(Math STATIC ${SOURCE_FILES})

#link the library with the executable
target_link_libraries(${PROJECT_NAME} PUBLIC Math)