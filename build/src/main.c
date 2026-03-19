#include <stdio.h>

#define UTIL_H
#define DYN_TYPES
#include "util.h"
	
int main(void){

  char* test = "test";
  char test2[] =  "Test2";
  char test3[] = {'1', '2', '3', '\0'};
  char* test4 [] = {"1234", "5678"};
  printf("Yes %s %s %s %s", test, test2, test3, test4[0]);
}
