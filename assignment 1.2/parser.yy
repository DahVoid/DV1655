%skeleton "lalr1.cc" 
%defines
%define parse.error verbose
%define api.value.type variant
%define api.token.constructor

%code requires{
  #include <string>
  // #include "Node.h"
}
%code{
  #define YY_DECL yy::parser::symbol_type yylex()

  YY_DECL;
  
  // Node* root;
  
}
// definition of set of tokens. All tokens are of type string
%token END 0 "end of file"
%token <std::string> INT NUM SEMIC WORD L_PARENTHESE R_PARENTHESE NOT NEW L_BRACKET R_BRACKET THIS FALSE TRUE DOT COMMA length_OP SUB MUL DIV ADD EQUAL_TO EQUAL LT_OP GT_OP OR_OP AND_OP SEMICOLON printIn WHILE ELSE L_C_BRACKET R_C_BRACKET BOOLEAN RETURN PUBLIC EXTENDS CLASS STRING MAIN VOID STATIC 

// definition of the production rules. All production rules are of type Node
/* %type <Node *> expression  addExpression multExpression factor */
