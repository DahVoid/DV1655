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
%token <std::string>  IF INT LP RP ESX NEW LB RB THIS FALSE TRUE DOT COMMA LENGTH SUB MUL DIV PLUS CMP EQUAL GT LT MT OR AND COMMENT SYSTEMOUTPRINT WHILE ELSE LCB RCB BOOLEAN RETURN PUBLIC EXTENDS CLASS STRING MAIN VOID STATIC SEMICOLON NUM WORD
%type <Node *> goal mainclass classdeclaration vardeclaration methoddeclaration type statement lengthExpression otherExpression boolExpression funccallExpression expression addExpression multExpression logExpression indexExpression number identifier
// definition of the production rules. All production rules are of type Node

%%
goal: mainclass classdeclaration END {$$ = new Node("Goal", "");
                          $$->children.push_back($1);
                          $$->children.push_back($2);
                          root = $$;
                          }

mainclass: CLASS identifier LCB PUBLIC STATIC VOID MAIN LP STRING LB RB identifier RP LCB statement RCB RCB {$$ = new Node("MainClass", "");
                          $$->children.push_back($2);
                          $$->children.push_back($12);
                          $$->children.push_back($15);
                          root = $$;
                          }

classdeclaration: CLASS identifier LCB vardeclaration methoddeclaration RCB {$$ = new Node("ClassDeclaration", "");
                          $$->children.push_back($2);
                          $$->children.push_back($4);
                          $$->children.push_back($5);
                          root = $$;
                          }

vardeclaration: type identifier SEMICOLON {$$ = new Node("VarDeclaration", "");
                          $$->children.push_back($1);
                          $$->children.push_back($2);
                          root = $$;
                          }

methoddeclaration: PUBLIC type identifier LP type identifier COMMA identifier RP LCB vardeclaration statement RETURN expression SEMICOLON RCB {$$ = new Node("MethodDeclaration", "");
                          $$->children.push_back($2);
                          $$->children.push_back($3);
                          $$->children.push_back($5);
                          $$->children.push_back($6);
                          $$->children.push_back($8);
                          $$->children.push_back($11);
                          $$->children.push_back($12);
                          $$->children.push_back($14);
                          root = $$;
                          }

type: INT LB RB {$$ = new Node("Type", "");
                          }
    | BOOLEAN {$$ = new Node("Type", "");
                          }
    | INT {$$ = new Node("Type", "");
                          }
    | identifier {$$ = new Node("Type", "");
                          $$->children.push_back($1);
                          root = $$;
                          }

statement: LCB statement RCB {$$ = new Node("Statement", "");
                          $$->children.push_back($2);
                          root = $$;
                          }

         | IF LP expression RP statement ELSE statement {$$ = new Node("Statement", "");
                          $$->children.push_back($3);
                          $$->children.push_back($5);
                          $$->children.push_back($7);
                          root = $$;
                          }
         | WHILE LP expression RP statement {$$ = new Node("Statement", "");
                          $$->children.push_back($3);
                          $$->children.push_back($5);
                          root = $$;
                          }
         | SYSTEMOUTPRINT LP expression RP SEMICOLON {$$ = new Node("Statement", "");
                          $$->children.push_back($3);
                          root = $$;
                          }
         | identifier EQUAL expression SEMICOLON {$$ = new Node("Statement", "");
                          $$->children.push_back($1);
                          $$->children.push_back($3);
                          root = $$;
                          }
         | identifier LB expression RB EQUAL expression SEMICOLON {$$ = new Node("Statement", "");
                          $$->children.push_back($1);
                          $$->children.push_back($3);
                          $$->children.push_back($6);
                          root = $$;
                          }

expression: addExpression {$$ = new Node("Expression", "");
                          $$->children.push_back($1);
                          root = $$;
                          }
          | logExpression {$$ = new Node("Expression", "");
                          $$->children.push_back($1);
                          root = $$;
                          }
          | indexExpression {$$ = new Node("Expression", "");
                          $$->children.push_back($1);
                          root = $$;
                          }
          | lengthExpression {$$ = new Node("Expression", "");
                          $$->children.push_back($1);
                          root = $$;
                          }
          | funccallExpression {$$ = new Node("Expression", "");
                          $$->children.push_back($1);
                          root = $$;
                          }
          | boolExpression {$$ = new Node("Expression", "");
                          $$->children.push_back($1);
                          root = $$;
                          }
          | identifier {$$ = new Node("Expression", "");
                          $$->children.push_back($1);
                          root = $$;
                          }
          | otherExpression {$$ = new Node("Expression", "");
                          $$->children.push_back($1);
                          root = $$;
                          }

otherExpression: THIS
               | NEW INT LB expression RB {$$ = new Node("otherExpression", "");
                                                 $$->children.push_back($4);
                                                 } 
               | NEW identifier LP RP {$$ = new Node("otherExpression", "");
                                                 $$->children.push_back($2);
                                                 } 
               | ESX expression {$$ = new Node("otherExpression", "");
                                                 $$->children.push_back($2);
                                                 } 
               | LP expression RP {$$ = new Node("otherExpression", "");
                                                 $$->children.push_back($2);
                                                 } 

boolExpression: TRUE {$$ = new Node("boolExpression", $1);}
              | FALSE {$$ = new Node("boolExpression", $1);}

funccallExpression: expression DOT identifier LP expression COMMA expression RP {$$ = new Node("funccallExpression", "");
                                                 $$->children.push_back($1);
                                                 $$->children.push_back($3);
                                                 $$->children.push_back($5);
                                                 $$->children.push_back($7);
                                                 } 

lengthExpression: expression DOT LENGTH {$$ = new Node("lengthExpression", "");
                                                 $$->children.push_back($1);
                                                 }  
          

indexExpression: expression LB expression RB {$$ = new Node("indexExpression", "");
                                                 $$->children.push_back($1);
                                                 $$->children.push_back($3);
                                                 }                        

logExpression: expression OR expression {$$ = new Node("logExpression", "");
                                                 $$->children.push_back($1);
                                                 $$->children.push_back($3);
                                                 }
             | expression AND expression {$$ = new Node("logExpression", "");
                                                 $$->children.push_back($1);
                                                 $$->children.push_back($3);
                                                 }
             | expression CMP expression {$$ = new Node("logExpression", "");
                                                 $$->children.push_back($1);
                                                 $$->children.push_back($3);
                                                 }
             | expression GT expression {$$ = new Node("logExpression", "");
                                                 $$->children.push_back($1);
                                                 $$->children.push_back($3);
                                                 }
             | expression LT expression {$$ = new Node("logExpression", "");
                                                 $$->children.push_back($1);
                                                 $$->children.push_back($3);
                                                 }

addExpression: multExpression {$$ = $1;}
            | addExpression PLUS multExpression {$$ = new Node("AddExpression", "");
                                                 $$->children.push_back($1);
                                                 $$->children.push_back($3);
                                                 }
                                                 
            | addExpression SUB multExpression   {$$ = new Node("SubExpression", "");
                                                 $$->children.push_back($1);
                                                 $$->children.push_back($3);
                                                 }

multExpression: number {$$ = $1;}
              | multExpression MUL number{$$ = new Node("MultExpression", "");
                                          $$->children.push_back($1);
                                          $$->children.push_back($3);
                                          }

              | multExpression DIV number{$$ = new Node("DivExpression", "");
                                          $$->children.push_back($1);
                                          $$->children.push_back($3);
                                          }

number: NUM {$$ = new Node("NUM", $1);}
      | LP expression RP {$$ = $2;}

identifier: WORD {$$ = new Node("identifier", $1);}
