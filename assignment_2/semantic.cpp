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
          // cout << "1\n";
          Record* node_1_rec;
          Record* node_2_rec;
          string node_1_type;
          string node_2_type;

          if (node_1->type == "IDENTIFIER")
          {
            // cout << "1.1\n";
            node_1_rec = symboltable->lookup(node_1->value);
            // cout << "1.2\n";
            node_1_type = node_1_rec->type;
            // cout << "node_2_type =  " << node_2_type << "\n";
            // node_1_rec.printRecord();

          }
          // cout << "2\n";
          if (node_2->type == "IDENTIFIER")
          {
            node_2_rec = symboltable->lookup(node_2->value);
            node_2_type = node_2_rec->type;
            // cout << "node_2_type =  " << node_2_type << "\n";
            // node_2_rec.printRecord();
          }
          // cout << "3\n";
          if (node_1->type == "INT")
          {
            node_1_type = "INT";
          }

          if (node_2->type == "INT")
          {
            node_2_type = "INT";
          }

          if (node_2->type ==  "ADD" || node_2->type == "SUB" || node_2->type == "MUL" || node_2->type == "DIV" || node_2->type == "PARENTHESES")
          {
            node_2_type = "INT";
          }

          // cout << "4\n";
          if (node_1_type != node_2_type)
          {
            cout << "SEMANTIC ERROR: Mathematical expressions must be between two or more integers\n";
            // return 0;
          }
          // cout << "5\n";
        }
        //INT HANDLING ends here


        //TYPE CHECKING begins here
        if (child->type == "EQUAL")
        {
          cout << "TYPE CHECKING HAS BEGUN\n";
          Node* node_1 = child->children.front();
          Node* node_2 = child->children.back();
          Record* node_1_rec;
          Record* node_2_rec;
          string node_1_type;
          string node_2_type;

          // cout << "3\n";
          if (node_1->type == "INT")
          {
            node_1_type = "INT";
          }

          if (node_2->type == "INT")
          {
            node_2_type = "INT";
          }

          if (node_1->type == "IDENTIFIER")
          {
            node_1_rec = symboltable->lookup(node_1->value);
            node_1_type = node_1_rec->type;
          }

          if (node_2->type == "IDENTIFIER")
          {
            node_2_rec = symboltable->lookup(node_2->value);
            node_2_type = node_2_rec->type;
          }

          if (node_2->type == "ARRAY SUBSCRIPT")
          {

          }

          if(node_2->type == "MEMBER SELECTION FUNCTION CALL")
          {
            //**!*!**!*!**!*!**!*!**!*!**!*!**!!!!!!!!!!!!!***********************!!!!!!!!!!!*!*!**!!!!!!!!!!!!***
            //>>>>>>>>>>>>>>>>>>>>>>>>>>CHECK PARAMETERS OF METHOD !!!!!!!!!!!!!!!!!!!!!!!!! <<<<<<<<<<<<<<<<FIXA
            //**!*!**!*!**!*!**!*!**!*!**!*!**!!!!!!!!!!!!!***********************!!!!!!!!!!!*!*!**!!!!!!!!!!!!***
            Node* child_2;
            int counter = 0;
            Record* child_rec;
            // list<Node*>::iterator it;
            // advance(node_2->children, 1);
            for (auto j = node_2->children.begin(); j != node_2->children.end(); j++)
            {
              if(counter == 1)
              {
                child = *j;
                child_rec = symboltable->lookup(child->value);
                node_2_type = child_rec->type;
                break;
              }
              counter++;
            }
          }

          if(node_2->type == "MEMBER SELECTION LENGTH")
          {
            cout << "\n\n\n\n\n";
            cout << "MEMBER SELECTION LENGTH\n";
            cout << "\n\n\n\n\n";

            Node* child_2 = *node_2->children.begin();
            Record* child_rec;
            child_rec = symboltable->lookup(child_2->value);
            node_2_type = child_rec->type;
            if (node_2_type == "INT ARRAY")
            {
              node_2_type = "INT";
            }
            else
            {
              cout << "A NON ARRAY VARIABLE DOES NOT HAVE A LENGTH\n";
              // return 0;
            }
          }
          if(node_2->type == "MEMBER SELECTION")
          {
            // cout << "\n\n\n\n\n";
            // cout << "MEMBER SELECTION\n";
            // cout << "\n\n\n\n\n";
            Node* child_2;
            int counter = 0;
            Record* child_rec;
            // list<Node*>::iterator it;
            // advance(node_2->children, 1);
            for (auto j = node_2->children.begin(); j != node_2->children.end(); j++)
            {
              if(counter == 1)
              {
                child = *j;
                child_rec = symboltable->lookup(child->value);
                node_2_type = child_rec->type;
                break;
              }
              counter++;
            }
          }

          if(node_2->type == "boolExpression")
          {
            node_2_type = "BOOL";
          }

          if(node_2->type == "ARRAY SUBSCRIPT")
          {
            Node* child_2;
            int counter = 0;
            Record* child_rec;
            // list<Node*>::iterator it;
            // advance(node_2->children, 1);
            for (auto j = node_2->children.begin(); j != node_2->children.end(); j++)
            {
              child = *j;
              if(counter == 0)
              {

                child_rec = symboltable->lookup(child->value);
                if (child_rec->type != "INT ARRAY")
                {
                  cout << "CANNOT INDEX A NON ARRAY VARIABLE\n";
                  // return 0;
                }
              }

              if(counter == 1)
              {
                child_rec = symboltable->lookup(child->value);
                if(child_rec->type != "INT")
                {
                  cout << "CANNOT INDEX AN A ARRAY WITH A NON INT VARIABLE\n";
                  // return 0;
                }
                break;
              }
              counter++;
            }
            node_2_type = "INT";
          }

          if(node_2->type == "NEW ARRAY SUBSCRIPT")
          {
            Node* child_2;
            int counter = 0;
            Record* child_rec;
            // list<Node*>::iterator it;
            // advance(node_2->children, 1);
            for (auto j = node_2->children.begin(); j != node_2->children.end(); j++)
            {
              child = *j;
              if(counter == 0)
              {

                child_rec = symboltable->lookup(child->value);
                if (child_rec->type != "INT")
                {
                  cout << "CANNOT CREATE A NEW ARRAY WITH A NON INT SIZE\n";
                }
                break;
              }
              counter++;
            }
            node_2_type = "INT ARRAY";
          }


          if (node_2->type ==  "ADD" || node_2->type == "SUB" || node_2->type == "MUL" || node_2->type == "DIV" || node_2->type == "PARENTHESES")
          {
            node_2_type = "INT";
          }
          cout << "node_1_type: " << node_1_type << "\n";
          cout << "node_2_type: " << node_2_type << "\n";
          if (node_1_type != node_2_type)
          {
            cout << "SEMANTIC ERROR: Equal expressions must be between two identifiers of the same type\n";
            // return 0;
          }

        }
        //TYPE CHECKING ends here


        if (child->type == "MEMBER SELECTION FUNCTION CALL")
        {
          cout << "\n\n\n\n\n\n\n\n\n\n";
          cout << "MEMBER FUNCTION CALL\n";
          cout << "\n\n\n\n\n\n\n\n\n\n";

          Method* node_method_rec;
          Record* node_parameter_rec;
          string node_method_type;
          string node_parameter_type;
          map<string, Variable*> parameters;


          Node* child_2;
          int counter = 0;
          Class* child_rec;

          int parameter_counter = 0;
          //Check number of parameters begins here
          Record* parameter;
          for (auto p = symboltable->current->records.begin(); p != symboltable->current->records.end(); p++)
          {
            parameter = p->second;
            if (parameter->id == "PARAMETER")
            {
              parameter_counter++;
            }
          }
          cout << "Number of parameters: " << parameter_counter << "\n";
          //Check number of parameters ends here

          for (auto j = child->children.begin(); j != child->children.end(); j++)
          {
            child = *j;
            if(counter == 0)
            {
              //Check if "THIS" exists in scope
              child_rec = (Class*)symboltable->lookup(child->value);
            }

            if(counter == 1)
            {
              //Check if method exists in scope
              cout << "1\n";
              node_method_rec = child_rec->lookupMethod(child->value);
              cout << "2\n";
              // node_method_rec = symboltable->lookup(child->value);
              cout << node_method_rec->id << "\n";
              cout << node_method_rec->type << "\n";
              node_method_type = node_method_rec->type;
              cout << "3\n";
            }

            if(counter > 1)
            {
              node_parameter_rec = symboltable->lookup(child->value);

              //Parameter check
            }
            counter++;
          }
          //CHECK SCOPE ENDS HERE


          //CHECK PARAMETERS BEGINS HERE

          //CHECK PARAMETERS ENDS HERE


          //CHECK RETURN TYPE BEGINS HERE

          //CHECK RETURN TYPE ENDS HERE
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
                  Record *node_j_rec = symboltable->lookup(child->value);
                  if(node_j_rec -> type == "BOOL")
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
            Record *node_1_rec = symboltable->lookup(node_1->value);
            if(node_1_rec -> type == "BOOL")
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
          Node *node_1 = child->children.front();
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
