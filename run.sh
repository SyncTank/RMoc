#!/bin/bash

# Define the directories
OUT_DIR="out"
SRC_DIR="src"
INCLUDE_DIR="include"
TEST_DIR="tests"

LIB_FILE="BUILDC"

# Check if the out directory exists, if not, create it | outputs
if [ ! -d "$OUT_DIR" ]; then
    echo "Creating directory: $OUT_DIR"
    mkdir -p "$OUT_DIR"
else
    echo "Directory already exists: $OUT_DIR"
fi

# Check if the src directory exists, if not, create it | C code
if [ ! -d "$SRC_DIR" ]; then
    echo "Creating directory: $SRC_DIR"
    mkdir -p "$SRC_DIR"
	echo "#include <stdio.h>
#include \"util.h\"
	
int main(void){
char line[256];
printf(\"Hello World\");
fgets(line, sizeof(line), stdin);
}" > "$SRC_DIR/main.c"
	echo "int add(int a, int b){return a+b;}" > "$SRC_DIR/util.c"
else
    echo "Directory already exists: $SRC_DIR"
fi

# Check if the include directory exists, if not, create it | headers
if [ ! -d "$INCLUDE_DIR" ]; then
    echo "Creating directory: $INCLUDE_DIR"
    mkdir -p "$INCLUDE_DIR"
	echo "#ifndef UTIL_H
#define UTIL_H
int add(int a, int b);
#endif" > "$INCLUDE_DIR/util.h"
else
    echo "Directory already exists: $INCLUDE_DIR"
fi

# Check if the tests directory exists, if not, create it
if [ ! -d "$TEST_DIR" ]; then
    echo "Creating directory: $TEST_DIR"
    mkdir -p "$TEST_DIR"
	echo "#include <stdio.h>
#include \"util.h\"  // Test your library headers

// Simple test case
int main(void) {
    if (add(2, 3) != 5) {  // Example test
        fprintf(stderr, \"Test failed!\n\");
        return 1;
    }
    printf(\"All tests passed!\n\");
    return 0;
}" > "$TEST_DIR/test_main.c"
	echo "cmake_minimum_required(VERSION 3.10)
	project(tests)
	
	add_executable(test_runner test_main.c)
	target_link_libraries(test_runner PRIVATE "$LIB_FILE")
	add_test(NAME main_tests COMMAND test_runner)
	# include(GoogleTest)
	# gtest_discover_tests(test_runner)
	" > "$TEST_DIR/CMakeLists.txt"
else
    echo "Directory already exists: $TEST_DIR"
fi

cd "$OUT_DIR"

cmake -G "Ninja" -DBUILD_TESTING=ON ..
ninja

# Testing with different verbosity levels
echo -e "\n\033[1;34m=== Basic test listing ===\033[0m"
ctest -N

echo -e "\n\033[1;34m=== Running tests with output on failure ===\033[0m"
ctest --output-on-failure

echo -e "\n\033[1;34m=== Verbose test output ===\033[0m"
ctest -VV