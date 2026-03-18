#include <stdio.h>

#define UTIL_H
#define DYN_TYPES
#include "util.h"
	
int main(void){

  char* test = "test";
  char test2[] =  "Test2";
  char test3[] = {'1', '2', '3', '\0'};
  printf("Yes %s %s %s", test, test2, test3);
}
