%skeleton "lalr1.cc" 
%defines
%define parse.error verbose
%define api.value.type variant
%define api.token.constructor

%code requires{
  #include <string>
  #include "Node.h"
}

%code{
  #define YY_DECL yy::parser::symbol_type yylex()

  YY_DECL;
  
  Node* root;
  
}
// definition of set of tokens. All tokens are of type string
%token END 0 "end of file"
%token <std::string> INT LP RP ESX NEW LB RB THIS FALSE TRUE DOT COMMA LENGTH SUB MUL DIV PLUS CMP EQUAL LT MT OR AND COMMENT SYSTEMOUTPRINT WHILE ELSE LCB RCB BOOLEAN RETURN PUBLIC EXTENDS CLASS STRING MAIN VOID STATIC SEMICOLON NUM WORD
%type <Node *> expression addExpression multExpression factor
// definition of the production rules. All production rules are of type Node

%%
expression: addExpression {$$ = new Node("Expression", "");
                          $$->children.push_back($1);
                          root = $$;
                          }

addExpression: multExpression {$$ = $1;}
            | addExpression PLUS multExpression {$$ = new Node("AddExpression", "");
                                                 $$->children.push_back($1);
                                                 $$->children.push_back($3);
                                                 }
                                                 
            | addExpression SUB multExpression   {$$ = new Node("AddExpression", "");
                                                 $$->children.push_back($1);
                                                 $$->children.push_back($3);
                                                 }

multExpression: factor {$$ = $1;}
              | multExpression MUL factor{$$ = new Node("MultExpression", "");
                                          $$->children.push_back($1);
                                          $$->children.push_back($3);
                                          }

              | multExpression DIV factor{$$ = new Node("multExpression", "");
                                          $$->children.push_back($1);
                                          $$->children.push_back($3);
                                          }

factor: NUM {$$ = new Node("NUM", $1);}
      | LP expression RP {$$ = $2;}

