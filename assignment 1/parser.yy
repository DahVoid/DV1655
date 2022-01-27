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
%token <std::string> NUM INT L_PARENTHESE R_PARENTHESE NOT NEW L_BRACKET R_BRACKET THIS FALSE TRUE DOT COMMA length_OP SUB MUL DIV ADD EQUAL_TO EQUAL LT_OP GT_OP OR_OP AND_OP SEMICOLON printIn WHILE ELSE L_C_BRACKET R_C_BRACKET BOOLEAN RETURN PUBLIC EXTENDS CLASS STRING MAIN VOID STATIC 
%type <Node *> expression  addExpression subExpression multExpression divExpression factor

%%
expression:
            addExpression 
                          { /*  
                                Here we create the root node (named Expression), then we add the content of addExpression (accessed through $1) as a child of the root node. 
                                The "root" is a reference to the root node. 
                            */
                            $$ = new Node("expression", "");
                            $$->children.push_back($1);
                            root = $$;
                            printf("r1 ");
                          };

addExpression: multExpression { $$ = $1; printf("r2 "); /*simply return the content of multExpression*/}
             | addExpression ADD multExpression
             | addExpression SUB multExpression {  /*
                                                  Create a subtree that corresponds to the AddExpressions
                                                  The root of the subtree is AddExpression
                                                  The childs of the AddExpression subtree are the left hand side (addExpression accessed through $1) and right hand side of the expression (multExpression accessed through $3)
                                                */
                            $$ = new Node("addExpression", "");
                            $$->children.push_back($1);
                            $$->children.push_back($3);
                            printf("r3 ");
                          }
      ;

subExpression: multExpression { $$ = $1; printf("r2 "); /*simply return the content of multExpression*/}      
             | subExpression SUB multExpression {  /*
                                                  Create a subtree that corresponds to the AddExpressions
                                                  The root of the subtree is AddExpression
                                                  The childs of the AddExpression subtree are the left hand side (addExpression accessed through $1) and right hand side of the expression (multExpression accessed through $3)
                                                */
                            $$ = new Node("subExpression", "");
                            $$->children.push_back($1);
                            $$->children.push_back($3);
                            printf("r3 ");
                          }
      ;            

multExpression: factor { $$ = $1; printf("r4 "); /*simply return the content of multExpression*/}
              | multExpression MUL factor { /*
                                                  Create a subtree that corresponds to the MultExpression
                                                  The root of the subtree is MultExpression
                                                  The childs of the MultExpression subtree are the left hand side (multExpression accessed through $1) and right hand side of the expression (factor accessed through $3)
                                                */
                            $$ = new Node("multExpression", ""); 
                            $$->children.push_back($1);
                            $$->children.push_back($3);
                            printf("r5 ");
                      }
        ;

divExpression: factor { $$ = $1; printf("r6 "); /*simply return the content of multExpression*/}
             | divExpression DIV factor { /*
                                                  Create a subtree that corresponds to the MultExpression
                                                  The root of the subtree is MultExpression
                                                  The childs of the MultExpression subtree are the left hand side (multExpression accessed through $1) and right hand side of the expression (factor accessed through $3)
                                                */
                            $$ = new Node("divExpression", ""); 
                            $$->children.push_back($1);
                            $$->children.push_back($3);
                            printf("r7 ");
                      }
        ;

factor: NUM  {  $$ = new Node("Int", $1); printf("r6 "); /* Here we create a leaf node Int. The value of the leaf node is $1 */}
    | L_PARENTHESE expression R_PARENTHESE { $$ = $2; printf("r7 "); /* simply return the expression */}
    ;
