#include <stdio.h>	
#include <stdlib.h>

#define STR_IMPL
#include "string_block.h"

typedef struct StringDynamic
{
  char* var; // mutable - | In-Use with it's associated functions
  size_t length;
  size_t capacity;
} DynString; 

void r_w_file()
{
  FILE *in_file  = fopen("name_of_file", "r"); // read only
  FILE *out_file = fopen("name_of_file", "w"); // write only
  if (in_file == NULL || out_file == NULL)
  {
    printf("Error! Could not open file\n");
    exit(-1); 
  }
}

int main(int argc, char* argv[]){

  printf("Arg count : %i\nArgs pointer %p first item : %s\n", argc, *argv, argv[0]);
  string_test();

  char str[50];
  scanf("%s", str);
  printf("%s\n", str);

}
