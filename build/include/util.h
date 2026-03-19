#ifndef UTIL
#define UTIL
int add(int a, int b);
#endif

#ifdef UTIL_IMPL
int add(int a, int b){return a+b;}
#endif

#ifndef STDIO
#define STDIO
#endif

#ifdef STDIO_IMPL
typedef struct VaultString
{
  const char* const var; // immutable pointer and char | READ-ONLY
} Const; // use in passing functions to not edit original

typedef struct LookOutString
{
  const char* var; // mutable pointer and immutable char | iterate strings
} StringLiteral; // change what it's pointing too

typedef struct AnchoredString
{
  char* const var; // immutable pointer and mutable char | buffer 
} StringBuffer; // change its context

typedef struct WildCardString
{
  char* var; // mutable - | UB with String Literals use other struct.
} String; // point it to char array[] or `malloc memory for safetly

typedef struct intvec {
  size_t size;
  size_t capacity;
  int* item;
} Numbers;

typedef struct floatvec {
  size_t size;
  size_t capacity;
  float* item;
} Decimals;

typedef struct charvec {
  size_t size;
  size_t capacity;
  char* item[]; // array of char pointers
} Words;
#endif
