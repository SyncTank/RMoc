#ifndef STR
#define STR

typedef struct VaultString { const char* const var; } Const; 
typedef struct LookOutString { const char* var;       } StringLiteral;
typedef struct AnchoredString { char* const var;       } StringEdit;
typedef struct WildCardString { char* var;             } StringMem;
typedef struct StringBlock { const char* var; int count; } StringView;

#define SB_Fmt "%.*s"
#define SB_Args(s) (s).count, (s).var

#endif

#ifdef STR_IMPL
#include <stdio.h>
#include <string.h>
#include <ctype.h>

static inline StringView sv(StringLiteral cstr)
{ return (StringView){ .var = cstr.var, .count = strlen(cstr.var) }; }

static inline StringView sv_ccptr(const char* cstr)
{ return (StringView){ .var = cstr, .count = strlen(cstr) }; }

static inline void sb_chop_left(StringView *sv, int n)
{
    if (n >= sv->count) n = sv->count;
    if (sv->count == 0) return;
    sv->count -= n;
    sv->var   += n;
}
static inline void sb_chop_right(StringView *sv, int n)
{
    if (n >= sv->count) n = sv->count;
    sv->count -= n;
}
static inline void sb_trim_space_left(StringView *sv)
{
    while (sv->count > 0 && isspace(sv->var[0]))
        sb_chop_left(sv, 1);
}
static inline void sb_trim_space_right(StringView *sv)
{
    while (sv->count > 0 && isspace(sv->var[sv->count - 1]))
        sb_chop_right(sv, 1);
}
static inline void sb_trim(StringView *sv)
{
    sb_trim_space_left(sv);
    sb_trim_space_right(sv);
}
void string_test(void)
{
  char* test = "test";
  char test2[] =  "Test2";
  char test3[] = {'1', '2', '3', '\0'};
  char* test4 [] = {"1234", "5678"};

  printf("Yes %s %s %s %s\n", test, test2, test3, test4[0]);
  printf("Char %s %s\n", test+1, (strlen(test) - 1) + (test) );

  StringLiteral s = {0};
  s.var = "test";
  printf("%c %zu\n", s.var[0], sizeof(s));

  StringView sb = sv(s);
  StringView sb2 = sv_ccptr("test2");
  printf("%s \n", sb.var);
  printf("%s \n", sb2.var);

  StringView sb3 = sv_ccptr("         test3, test4     ");
  printf("|"SB_Fmt"|\n", sb3.count, sb3.var);
  printf("|"SB_Fmt"|\n", SB_Args(sb3));

  sb_chop_left(&sb3, 2);
  sb_trim(&sb3);
  printf("|"SB_Fmt"|\n", sb3.count, sb3.var);
  printf("|"SB_Fmt"|\n", SB_Args(sb3));

  char* test_walk = "12345";
  for (size_t i = 0; i <= strlen(test_walk); ++i)
  {
    printf("%s \n", (strlen(test_walk) - i) + (test_walk)  );
  }

  for (size_t i = 0; i <= strlen(test_walk); ++i)
  {
    printf("%s \n", i + (test_walk)  );
  }
}
#endif
