// #include<iostream>
// // #include "parser.tab.hh"

// // extern Node* root;
// extern FILE* yyin;

// // void yy::parser::error(std::string const&err)
// // {
// //   std::cout << "Cannot generate a syntax tree for this input: " << err << std::endl;
// // }

// int main(int argc, char **argv)
// {
//   //Reads from file if a file name is passed as an argument. Otherwise, reads from stdin.
//   if(argc > 1) {
//     if(!(yyin = fopen(argv[1], "r"))) {
//       perror(argv[1]);
//       return 1;
//     }
//   }

//   yy::parser parser;
	  
//   if(!parser.parse()) {
//     root->print_tree();
//     root->generate_tree();
//   }
  
//   return 0;
// }

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