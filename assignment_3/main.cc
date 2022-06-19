#include <iostream>
#include "parser.tab.hh"
#include "semantic.cpp"
#include "symbol_table.h"
#include "Node.h"
extern Node* root;
extern FILE* yyin;

#include "ir.h"
// extern SymbolTable* symboltable;

void yy::parser::error(std::string const&err)
{
  std::cout << "Cannot generate a syntax tree for this input: " << err << std::endl;
}

int main(int argc, char **argv)
{
  //Reads from file if a file name is passed as an argument. Otherwise, reads from stdin.
  if(argc > 1) {
    if(!(yyin = fopen(argv[1], "r"))) {
      perror(argv[1]);
      return 1;
    }
  }

  yy::parser parser;
  SymbolTable* symboltable;
  if(!parser.parse()) {
    // root->print_tree();
    root->generate_tree();
    symboltable = symbol_table(root);
    symboltable->printTable();

    // turn off semantic analysis for now
    semantic(root, symboltable);
    IR ir;
    cout << "Creating IR tree" << endl;
    ir.start(root, symboltable);
    cout << "Generating graph" << endl;
    ir.generate_tree();
  }
  // assigment 3 traverse tree by root node.



  return 0;
}

// #include <stdio.h>

// extern int yylex();

// int yyerror(char *c)
// {
//   printf("Lexical error! Unexpected: %s\n", c);
//   return 0;
// }

// int main(int argc, char **argv)
// {
//   if(!yylex())
//     printf("Done!\n");
//   return 0;
// }
