#include <stdio.h>

#define UTIL_IMPL
#define STDIO_IMPL
#include "util.h"
	
int main(int argc, char* argv[]){

  char* test = "test";
  char test2[] =  "Test2";
  char test3[] = {'1', '2', '3', '\0'};
  char* test4 [] = {"1234", "5678"};
  printf("Yes %s %s %s %s\n", test, test2, test3, test4[0]);
  printf("Arg count : %i\nArgs pointer %p first item : %s", argc, *argv, argv[0]);

}
