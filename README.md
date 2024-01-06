# Embedded_Linux_Tasks



### By Eng. Nour Alaa-Eldin Hanafy Moharram



# Calculator Project using Cmake README

## Project Overview

This CMake project is a simple calculator that performs basic mathematical operations. It consists of source files for addition (`add.c`), multiplication (`mult.c`), division (`division.c`), and subtraction (`sub.c`). The main functionality is implemented in `main.c`.

## Prerequisites

To build the project, you need CMake version 3.1 or later.

## Project Structure

```lua
calculator/
|-- CMakeLists.txt
|-- include/
|   |-- add.h
|   |-- mult.h
|   |-- division.h
|   |-- sub.h
|
|-- add.c
|-- mult.c
|-- division.c
|-- sub.c
|-- main.c

```

- **CMakeLists.txt:** The build configuration file for CMake.
- **include/:** Directory containing header files.
- **Current Directory**: containing source files.

## Build Instructions

To build the calculator project, follow these steps:

1. Open a terminal and navigate to the project directory.
2. Run the following commands:

```bash
mkdir build
cd build
cmake ..
make

```

These commands create a build directory, configure the project with CMake, and then build the project using `make`.



3. After a successful build, the executable `calculator` will be available in the build directory.

## CMake Configuration (CMakeLists.txt)

### Set Minimum CMake Version

```cmake
cmake_minimum_required(VERSION 3.1...3.22)
```

Specifies the minimum version of CMake required to build the project.

### Project Information

```cmake
project(calculator VERSION 1.0 DESCRIPTION "Calculator for simple operations" LANGUAGES C)
```

Defines the project name, version, description, and language.

### Define Source Files

```cmake
set(SOURCE_FILES add.c mult.c division.c sub.c)
```

Creates a variable `SOURCE_FILES` containing the names of the source files.

### Create Executable

```cmake
add_executable(${PROJECT_NAME} main.c)
```

Creates an executable named `${PROJECT_NAME}` using `main.c`.

### Include Directories for Executable

```cmake
target_include_directories(${PROJECT_NAME} PRIVATE include)
```

Specifies the include directories for the `${PROJECT_NAME}` target. Using `PRIVATE` ensures that these directories are not propagated to other targets depending on `${PROJECT_NAME}`.

### Create Static Library

```cmake
add_library(Math STATIC ${SOURCE_FILES})
```

Creates a static library named `Math` using the source files.

### Link Library with Executable

```cmake
target_link_libraries(${PROJECT_NAME} PUBLIC Math)
```

Links the `Math` library with the `${PROJECT_NAME}` target. The `PUBLIC` keyword ensures that this linkage is visible to other targets that depend on `${PROJECT_NAME}`.
