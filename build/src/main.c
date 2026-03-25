#include <stdio.h>	

#define STR_IMPL
#include "string_block.h"

typedef struct StringDynamic
{
  char* var; // mutable - | In-Use with it's associated functions
  size_t length;
  size_t capacity;
} DynString; 


int main(int argc, char* argv[]){

  printf("Arg count : %i\nArgs pointer %p first item : %s\n", argc, *argv, argv[0]);
  string_test();

}
