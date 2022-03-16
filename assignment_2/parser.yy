%skeleton "lalr1.cc"
%defines
%define parse.error verbose
%define api.value.type variant
%define api.token.constructor

%code requires{
  #include <string>
  #include "Node.h"
  #include <stdio.h>
}

%code{
  #define YY_DECL yy::parser::symbol_type yylex()

  YY_DECL;

  Node* root;

}
// definition of set of tokens. All tokens are of type string
%token END 0 "end of file"
%token <std::string>  IF INT LP RP ESX NEW LB RB THIS FALSE TRUE DOT COMMA LENGTH SUB MUL DIV PLUS CMP EQUAL GT LT MT OR AND COMMENT SYSTEMOUTPRINT WHILE ELSE LCB RCB BOOLEAN RETURN PUBLIC EXTENDS CLASS STRING MAIN VOID STATIC SEMICOLON NUM WORD
%type <Node *> parameter OR_expression AND_expression EQUALITY_expression REL_expression negation_expression par_expression statement_rep methoddeclaration_rep parameterdeclaration_rep argdeclaration_rep vardeclaration_rep classdeclaration_rep goal mainclass classdeclaration vardeclaration methoddeclaration type statement expression addExpression multExpression number identifier
// definition of the production rules. All production rules are of type Node
%right AND OR
%left MT LT CMP ESX

%%
goal: mainclass classdeclaration_rep END {$$ = new Node("GOAL", "");
                          $$->children.push_back($1);
                          $$->children.push_back($2);
                          root = $$;
                          }

mainclass: CLASS identifier LCB PUBLIC STATIC VOID MAIN LP STRING LB RB identifier RP LCB statement RCB RCB {$$ = new Node("MAINCLASS", "");
                          $$->children.push_back($2);
                          $$->children.push_back($12);
                          $$->children.push_back($15);
                          }

classdeclaration: CLASS identifier LCB vardeclaration_rep methoddeclaration_rep RCB {$$ = new Node("CLASSDECLARATION", "");
                          $$->children.push_back($2);
                          $$->children.push_back($4);
                          $$->children.push_back($5);
                          }
                | CLASS identifier EXTENDS identifier LCB vardeclaration_rep methoddeclaration_rep RCB {$$ = new Node("CLASSDECLARATION", "");
                                          $$->children.push_back($2);
                                          $$->children.push_back($4);
                                          $$->children.push_back($6);
                                          $$->children.push_back($7);
                                          }

vardeclaration: type identifier SEMICOLON {$$ = new Node("VARDECLARATION", "");
                          $$->children.push_back($1);
                          $$->children.push_back($2);
                          }

methoddeclaration: PUBLIC type identifier LP RP LCB vardeclaration_rep statement_rep RETURN expression SEMICOLON RCB {$$ = new Node("METHODDECLARATION", "");
                          $$->children.push_back($2);
                          $$->children.push_back($3);
                          $$->children.push_back($7);
                          $$->children.push_back($8);
                          $$->children.push_back($10);
                          }
                 | PUBLIC type identifier LP parameterdeclaration_rep RP LCB vardeclaration_rep statement_rep RETURN expression SEMICOLON RCB {$$ = new Node("METHODDECLARATION", "");
                                           $$->children.push_back($2);
                                           $$->children.push_back($3);
                                           $$->children.push_back($5);
                                           $$->children.push_back($8);
                                           $$->children.push_back($9);
                                           $$->children.push_back($11);
                                           }

type: INT LB RB {$$ = new Node("INT ARRAY", "");
                          }
    | BOOLEAN {$$ = new Node("BOOL", "");
                          }
    | INT {$$ = new Node("INT", "");
                          }
    | identifier {$$ = new Node("OBJECT", "");
                          $$->children.push_back($1);
                          }

statement: LCB statement_rep RCB {
                          $$ = $2;
                          }

         | IF LP expression RP statement ELSE statement {$$ = new Node("IF","");
                          $$->children.push_back($3);
                          $$->children.push_back($5);
                          $$->children.push_back($7);
                          }
         | WHILE LP expression RP statement {$$ = new Node("WHILE","");
                          $$->children.push_back($3);
                          $$->children.push_back($5);
                          }
         | SYSTEMOUTPRINT LP expression RP SEMICOLON {$$ = new Node("SYSTEMOUTPRINT","");
                          $$->children.push_back($3);
                          }
         | identifier EQUAL expression SEMICOLON {$$ = new Node("EQUAL","");
                          $$->children.push_back($1);
                          $$->children.push_back($3);
                          }
         | identifier LB expression RB EQUAL expression SEMICOLON {$$ = new Node("INDEX EQUAL TO","");
                          $$->children.push_back($1);
                          $$->children.push_back($3);
                          $$->children.push_back($6);
                          }

expression: OR_expression {$$ = $1;}
          | TRUE {$$ = new Node("boolExpression", $1);}
          | FALSE {$$ = new Node("boolExpression", $1);}
          | THIS {$$ = new Node("THIS", $1);}
          | NEW identifier LP RP {$$ = $2;}

OR_expression: AND_expression {$$ = $1;}
             | expression OR expression {$$ = new Node("OR", "");
                                                 $$->children.push_back($1);
                                                 $$->children.push_back($3);
                                                 }

AND_expression: EQUALITY_expression {$$ = $1;}
              | expression AND expression {$$ = new Node("AND", "");
                                                  $$->children.push_back($1);
                                                  $$->children.push_back($3);
                                                  }
EQUALITY_expression: REL_expression {$$ = $1;}
                   | expression CMP expression {$$ = new Node("COMPARE", "");
                                                       $$->children.push_back($1);
                                                       $$->children.push_back($3);
                                                       }

REL_expression: addExpression {$$ = $1;}
              | expression LT expression {$$ = new Node("LESS", "");
                                                  $$->children.push_back($1);
                                                  $$->children.push_back($3);
                                                  }
              | expression MT expression {$$ = new Node("GREATER", "");
                                                  $$->children.push_back($1);
                                                  $$->children.push_back($3);
                                                  }

addExpression: multExpression {$$ = $1;}
             | addExpression PLUS multExpression {$$ = new Node("ADD", "");
                                                 $$->children.push_back($1);
                                                 $$->children.push_back($3);
                                                 }

             | addExpression SUB multExpression   {$$ = new Node("SUB", "");
                                                 $$->children.push_back($1);
                                                 $$->children.push_back($3);
                                                 }

multExpression: negation_expression {$$ = $1;}
              | number {$$ = $1;}
              | identifier {$$ = $1;}
              | multExpression MUL number {$$ = new Node("MUL", "");
                                          $$->children.push_back($1);
                                          $$->children.push_back($3);
                                          }

              | multExpression DIV number {$$ = new Node("DIV", "");
                                          $$->children.push_back($1);
                                          $$->children.push_back($3);
                                          }
              | multExpression MUL identifier {$$ = new Node("MUL", "");
                                          $$->children.push_back($1);
                                          $$->children.push_back($3);
                                          }

              | multExpression DIV identifier {$$ = new Node("DIV", "");
                                          $$->children.push_back($1);
                                          $$->children.push_back($3);
                                          }

negation_expression: par_expression {$$ = $1;}
                   | ESX expression {$$ = new Node("NEGATION", "");
                                               $$->children.push_back($2);
                                               }

par_expression: LP expression RP {$$ = new Node("PARENTHESES", "");
                            $$->children.push_back($2);
                            }
              | expression DOT identifier LP argdeclaration_rep RP {$$ = new Node("MEMBER SELECTION FUNCTION CALL", "");
                                          $$->children.push_back($1);
                                          $$->children.push_back($3);
                                          $$->children.push_back($5);
                                          }
              | expression DOT identifier LP RP {$$ = new Node("MEMBER SELECTION", "");
                                          $$->children.push_back($1);
                                          $$->children.push_back($3);
                                          }
              | expression DOT LENGTH {$$ = new Node("MEMBER SELECTION LENGTH", "");
                                          $$->children.push_back($1);
                                          }
              | NEW INT LB expression RB {$$ = new Node("NEW ARRAY SUBSCRIPT", "");
                                          $$->children.push_back($4);
                                          }
              | expression LB expression RB {$$ = new Node("ARRAY SUBSCRIPT", "");
                                          $$->children.push_back($1);
                                          $$->children.push_back($3);
                                          }

vardeclaration_rep: %empty {$$ = new Node("VARBODY", "");}
                  | vardeclaration_rep vardeclaration {$$ = new Node("VARDECLARATION", "");
                                              $$ = $1;
                                              $$->children.push_back($2);
                                              }

classdeclaration_rep: %empty {$$ = new Node("CLASSBODY", "");}
                    | classdeclaration_rep classdeclaration {$$ = new Node("CLASSDECLARATION", "");
                                                $$ = $1;
                                                $$->children.push_back($2);
                                                }

statement_rep: %empty {$$ = new Node("STATEMENTBODY", "");}
             | statement statement_rep {$$ = new Node("STATEMENT", "");
                                       $$ = $2;
                                       $$->children.push_back($1);
                                       }

methoddeclaration_rep: %empty {$$ = new Node("METHODBODY", "");}
                      | methoddeclaration_rep methoddeclaration {$$ = new Node("METHODDECLARATION", "");
                                              $$ = $1;
                                              $$->children.push_back($2);
                                             }

parameterdeclaration_rep: parameter {$$ = new Node("PARAMETERBODY", "");
                            $$->children.push_back($1);
                            }
                         | parameterdeclaration_rep COMMA parameter{
                                                    $$ = $1;
                                                    $$->children.push_back($3);
                                                    }

argdeclaration_rep: %empty {$$ = new Node("END", "");}
                 | expression {
                            $$ = $1;
                            }
                 | expression COMMA argdeclaration_rep {
                                             $$ = $1;
                                             $$ = $3;
                                             }

parameter: type identifier {$$ = new Node("PARAMETER", "");
                            $$->children.push_back($1);
                            $$->children.push_back($2);
                            }

identifier: WORD {$$ = new Node("IDENTIFIER", $1);}

number: NUM {$$ = new Node("INT", $1);}
      | LP expression RP {$$ = $2;}
