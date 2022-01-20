#include <stdio.h>

extern int yylex();

int yyerror(char *c)
{
  printf("Lexical error! Unexpected: %s\n", c);
  return 0;
}

int main(int argc, char **argv)
{
  if(!yylex())
    printf("Done!\n");
  return 0;
}