#include <vector>
#include <typeinfo> // for debugging
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <list>
#include <iterator>
#include "Node.h"
#include "symbol_table.h"

using namespace std;

int expression()
{

  return 0;
}

int statement()
{

  return 0;
}

int method_dec()
{

  return 0;
}

int method_call()
{

  return 0;
}

int array_check()
{

  return 0;
}

// int scope_handling()
// {
//
//   return 0;
// }

int tree_traversal(Node* root, SymbolTable* symboltable, int scope_depth, int depth=0)
{
    Node* child;

    for (auto i = root->children.begin(); i != root->children.end(); i++)
    {
      //SCOPE HANDLING STARTS HERE
        for(int i=0; i<depth; i++)
        cout << "    ";
        child = *i;
        cout << "Type: " <<  child->type << "   Value: " << child->value << "\n";

        if(child->type == "MAINCLASS")
        {
          scope_depth = -1;
          symboltable->current = symboltable->current->next_Child();
        }

        if(child->type == "CLASSDECLARATION")
        {
          if (scope_depth = -1)
          {
            symboltable->current = symboltable->current->parentScope;
          }
          scope_depth = 0;
          cout << scope_depth << "\n";
          symboltable->current = symboltable->current->next_Child();
        }

        if (child->type == "METHODDECLARATION")
        {
          if (scope_depth == -1)
          {
            symboltable->current = symboltable->current->parentScope;
          }

          else
          {
            scope_depth = -1;
          }

          symboltable->current = symboltable->current->next_Child();
        }
        //SCOPE HANDLING ENDS HERE


        if (child->type == "STATEMENTBODY")
        {
          cout << "\nSTATEMENTBODY\n\n";
        }

        //SEMANTIC ANALYSIS STARTS HERE


        //DUPLICATE CHECK begins here
        if (child->type == "VARDECLARATION")
        {

        }
        //DUPLICATE CHECK ends here


        //INT HANDLING begins here
        if (child->type == "ADD" || child->type == "SUB" || child->type == "MUL" || child->type == "DIV" || child->type == "LESS" || child->type == "MORE")
        {
          cout << "INT HANDLING HAS BEGUN\n";
          Node* node_1 = child->children.front();
          Node* node_2 = child->children.back();
          cout << "1\n";
          Record node_1_rec;
          Record node_2_rec;
          string node_1_type;
          string node_2_type;

          if (node_1->type == "IDENTIFIER")
          {
            cout << "1.1\n";
            node_1_rec = symboltable->lookup(node_1->value);
            cout << "1.2\n";
            node_1_type = node_1_rec.type;
          }
          cout << "2\n";
          if (node_2->type == "IDENTIFIER")
          {
            node_2_rec = symboltable->lookup(node_2->value);
            node_2_type = node_2_rec.type;
          }
          cout << "3\n";
          if (node_1->type == "INT")
          {
            node_1_type = "INT";
          }

          if (node_2->type == "INT")
          {
            node_1_type = "INT";
          }
          cout << "4\n";
          if (node_1_type != node_2_type)
          {
            cout << "SEMANTIC ERROR: Mathematical expressions must be between two or more integers\n";
            return 0;
          }
          cout << "5\n";
        }
        //INT HANDLING ends here


        //TYPE CHECKING begins here
        if (child->type == "EQUAL")
        {
          cout << "TYPE CHECKING HAS BEGUN\n";
          Node* node_1 = child->children.front();
          Node* node_2 = child->children.back();
          Record node_1_rec;
          Record node_2_rec;
          string node_1_type;
          string node_2_type;

          if (node_1->type == "IDENTIFIER")
          {
            node_1_rec = symboltable->lookup(node_1->value);
          }

          if (node_2->type == "IDENTIFIER")
          {
            node_2_rec = symboltable->lookup(node_2->value);
          }

          if (node_2->type ==  "ADD" || node_2->type == "SUB" || node_2->type == "MUL" || node_2->type == "DIV")
          {
            node_2_type = "INT";
          }

          if (node_1_type != node_2_type)
          {
            cout << "SEMANTIC ERROR: Equal expressions must be between two identifiers of the same type\n";
            return 0;
          }

        }
        //TYPE CHECKING ends here


        if (child->type == "MEMBER FUNCTION CALL")
        {

        }

        if (child->type == "SYSTEMOUTPRINT")
        {

        }

        if (child->type == "ARRAY SUBSCRIPT")
        {

        }

        if (child->type == "NEW ARRAY SUBSCRIPT")
        {

        }

        if (child->type == "MEMBER SELECTION")
        {

        }

        if (child->type == "MEMBER SELECTION LENGTH")
        {

        }

        if (child->type == "WHILE")
        {
          // check so everything is OK
          // Kiddos
          Node* node_1 = child->children.front();
          //  check if a boolean statement
          
          
          if(node_1->type == "IDENTIFIER" || node_1->type == "LESS" || node_1->type == "MORE" || node_1->type == "COMPARE" || node_1->type == "boolExpression" || node_1->type == "NEGATION")
          {

          } else
          {
            cout << "SEMANTIC ERROR: A boolean expression is required for WHILE statement." << endl;
            // TODO: exit
          }


        }

        if (child->type == "IF")
        {
          Node* node_1 = child->children.front();
          if(node_1->type == "LESS" || node_1->type == "MORE" || node_1->type == "COMPARE" || node_1->type == "boolExpression"  || node_1->type == "NEGATION")
          {
            cout << "I validated IF" << endl;
          }
          else
          {
            if(node_1->type == "MEMBER SELECTION FUNCTION CALL") 
            {
              Node* child;
              // to lookup on function to get type
              for (auto j = node_1->children.begin(); j != node_1->children.end(); j++)
              {
                child = *j;
                if(child->type == "IDENTIFIER")
                {
                  Record node_j_rec = symboltable->lookup(child->value);
                  if(node_j_rec.type == "BOOL")
                  {
                    cout << "I validated IF" << endl;
                    break;
                  }
                  else
                  {
                    cout << "SEMANTIC ERROR: A boolean expression is required for IF statement." << endl;
                    // TODO: exit
                  }
                }
              }
            }
            else
            {
              cout << "SEMANTIC ERROR: A boolean expression is required for IF statement." << endl;
              // TODO: exit
            }
            

          }

        }

      if (child->type == "NEGATION")
      {
          Node* node_1 = child->children.front();
          
          // Negatable expressions
          if(node_1->type == "PARENTHESES" || node_1->type == "boolExpression")
          {
            cout << "NEGATED BOOL OR PARENTHESES" << endl;
          }
          else
          {
            Record node_1_rec = symboltable->lookup(node_1->value);
            if(node_1_rec.type == "BOOL")
            {
              cout << "NEGATED BOOL VARIABLE" << endl;
            }           
            else
            {
              cout << "SEMANTIC ERROR: The expression is not negateable" << endl;
              // TODO: exit
            }
          }

        }

        if (child->type == "PARENTHESES")
        {
          Node* node_1 = child->children.front();
          // If it has a child im happy with
          if(child->children.size() >= 1)
          {

          } else
          {
            cout << "SEMANTIC ERROR: Wild parentheses are not allowed" << endl;
            // TODO: exit
          }

        }

        if (child->type == "INDEX EQUAL TO")
        {

        }

        if (child->type == "OR" || child->type == "AND" || child->type == "COMPARE")
        {

        }


        //SEMANTIC ANALYSIS ENDS HERE
        tree_traversal(child, symboltable, scope_depth, depth+1);
    }
}


int semantic(Node* root, SymbolTable* symboltable) // BYT NAMN?
{
  int scope_depth = 0;
  tree_traversal(root, symboltable, scope_depth);
  return 0;
}
