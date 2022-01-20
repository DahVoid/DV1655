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
%token <std::string> PLUSOP MINUSOP MULTOP INT LP RP 
%token END 0 "end of file"

// definition of the production rules. All production rules are of type Node
%type <Node *> expression  addExpression multExpression factor

%%
expression: addExpression 
                          { /*  
                                Here we create the root node (named Expression), then we add the content of addExpression (accessed through $1) as a child of the root node. 
                                The "root" is a reference to the root node. 
                            */
                            $$ = new Node("Expression", "");
                            $$->children.push_back($1);
                            root = $$;
                            printf("r1 ");
                          };

addExpression: multExpression { $$ = $1; printf("r2 "); /*simply return the content of multExpression*/}
             | addExpression PLUSOP multExpression {  /*
                                                  Create a subtree that corresponds to the AddExpressions
                                                  The root of the subtree is AddExpression
                                                  The childs of the AddExpression subtree are the left hand side (addExpression accessed through $1) and right hand side of the expression (multExpression accessed through $3)
                                                */
                            $$ = new Node("AddExpression", "");
                            $$->children.push_back($1);
                            $$->children.push_back($3);
                            printf("r3 ");
                          }
      ;

multExpression: factor { $$ = $1; printf("r4 "); /*simply return the content of multExpression*/}
              | multExpression MULTOP factor { /*
                                                  Create a subtree that corresponds to the MultExpression
                                                  The root of the subtree is MultExpression
                                                  The childs of the MultExpression subtree are the left hand side (multExpression accessed through $1) and right hand side of the expression (factor accessed through $3)
                                                */
                            $$ = new Node("MultExpression", ""); 
                            $$->children.push_back($1);
                            $$->children.push_back($3);
                            printf("r5 ");
                      }
        ;

factor: INT  {  $$ = new Node("Int", $1); printf("r6 "); /* Here we create a leaf node Int. The value of the leaf node is $1 */}
    | LP expression RP { $$ = $2; printf("r7 "); /* simply return the expression */}
    ;
