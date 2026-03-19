#!/bin/bash

# Define the directories
OUT_DIR="out"
SRC_DIR="src"
INCLUDE_DIR="include"

LIB_FILE="BUILDC"

# Check if the out directory exists, if not, create it | outputs
if [ ! -d "$OUT_DIR" ]; then
    echo "Creating directory: $OUT_DIR"
    mkdir -p "$OUT_DIR"
else
    echo "Directory already exists: $OUT_DIR"
fi

# Check if the src directory exists, if not, create it | inject main C code
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

cd "$OUT_DIR"

cmake -G "Ninja" -DBUILD_TESTING=ON ..
ninja

echo ""
sleep .2s

echo "Moving compiled commands for linking headers..."
cp "compile_commands.json" "../"

echo ""
echo "Executing program..."
mapfile -t files < <(find "$PWD/bin")

for file in "${files[@]}"; do
  if [[ -f "$file" && -x "$file" && "$file" != *"test"* ]]; then
      echo ""
      "$file" $*
  fi
done
echo ""
