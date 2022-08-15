#include <iostream>
#include "parser.tab.hh"
#include "semantic.cpp"
#include "symbol_table.h"
#include "Node.h"

extern Node* root;
extern FILE* yyin;

#include "ir.h"
#include "interpreter.h"
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
    interpreter interpreter;
    cout << "\n -- Creating IR tree -- " << endl;
    ir.start(root);
    cout << "\n -- Generating graph -- " << endl;
    ir.generate_graph();
    Bytecode bytecode;
    bytecode.traverse_ir(ir.entryBlocks.front());
    bytecode.prgm->dump_methods();
     cout << "\n -- Interpreting code -- " << endl;
    interpreter.interpret("bytecode.prgm");
  }




  return 0;
}


