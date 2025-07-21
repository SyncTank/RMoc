cmake_minimum_required(VERSION 3.10)
project(main C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_BUILD_TYPE Debug)
#set(CMAKE_BUILD_TYPE Release)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# List all your source files here
set(SOURCES
    src/main.c
)


add_executable(main ${SOURCES})

set_target_properties(main PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out
)

# way to include directories and compile options
target_include_directories(main PRIVATE include)
target_compile_options(main PRIVATE -Wall -Wextra -pedantic)
# target_compile_options(main PRIVATE -Wall -Wextra -Werror) # compiler warnings
