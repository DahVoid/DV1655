#include <vector>
#include <typeinfo> // for debugging
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <list>
#include <iterator>
#include "Node.h"


using namespace std;

class Record
{
  public:
    string id;
    string type;
    Record(string id_in, string type_in)
    {
        id = id_in;
        type = type_in;
        cout << "contructed: " << type << endl;
    }


    void printRecord()
    {
      cout << "id: " << id << "\n" << "type: " <<  type << "\n";
    }
};

class Variable: public Record
{
    public:
        // Constructor
        Variable(string id, string type) : Record(id, type)
        {

        }

};

class Container: public Record
{
    public:
        map<string, Variable> variables;
        Container(string id, string type) : Record(id, type)
        {

        }

        void addVariable(string var_id)
        {
            Variable new_var = Variable(var_id, "Variable");

            variables.insert(pair<string ,Variable>(var_id, new_var));
        }

        void init_varbody(Node* varbody)
        {
          Node* child;

          for (auto i = varbody->children.begin(); i != varbody->children.end(); i++)
          {
            child = *i;
            //Lägg till variabel i current scope (Kolla alla children)
            type = child->children.begin();
            name = child->children.end();
            symboltable.put(name, type);
          
          }
        }

};

class Method: public Container
{
  public:
    map<string, Variable> parameters;
    Method(string id, string type) : Container(id, type)
    {
    };

  void addParameter(string par_id)
  {
    Variable new_par = Variable(par_id, "Variable");
    parameters.insert(pair<string ,Variable>(par_id, new_par));

  }
};


class Class: public Container
{
  public:
    map<string, Method> methods;
    Class(string id, string type) : Container(id, type)
    {

    }



  void addMethod(string met_id)
  {
    Method new_met = Method(met_id, "Method");
    methods.insert(pair<string ,Method>(met_id, new_met));


  }

  Variable lookupVariable(string Key)
  {
    if(variables.count(Key) > 0) //does it exist in the current scope? Använd map.count (records.count)
    {
      return variables.at(Key);
    } 
    else
    {
        // do nooooothing
    }

  }

  Method lookupMethod(string Key)
  {
    if(methods.count(Key) > 0) //does it exist in the current scope? Använd map.count (records.count)
    {
    return methods.at(Key);
    }
    else
    {
        // do nooooothing
    }
  }
};

class Scope
{
  public:
    int next = 0; //next child to visit
    Scope* parentScope; //parent scope
    vector<Scope> childrenScopes; //children scopes
    // list<Scope> childrenScopes; //children scopes
    map<string, Record> records; //symbol to record map
    map<string, Record>::iterator it;

    Scope(Scope* parentScope_in)
    {
      Scope parentScope = parentScope_in;
    }

    Scope()
    {

    }

    void put(string Key, Record record)
    {
      records.insert(pair<string, Record>(Key, record));
    }

    Scope next_Child()
    {
      Scope nextChild(this); // VIKTIGT ------> insert "this" i in parameter till scope <--- VIKTIGT

      if(next == childrenScopes.size()) // create new child scopre
      {
        childrenScopes.push_back(nextChild);
      }

      else
      {
        Scope nextChild = childrenScopes[next]; //visit scope
      }
      next++;
      return nextChild;
    }

    Record lookup(string Key)
    {
      if(records.count(Key) > 0) //does it exist in the current scope? Använd map.count (records.count)
      {

        return records.at(Key);
      }
      else
      {
        if (&parentScope == NULL)
        {
          //Exit no record found
        }

        else
        {
          return parentScope->lookup(Key); // delegate the request to the parent scope
        }
      }
    }

    void resetScope()
    {
      next = 0;
      for(int i = 0; i < childrenScopes.size(); i++)
      {
        childrenScopes[i].resetScope();
      }
    }

    void printScope() //Kommer behöva göras om
    {
      for (it = records.begin(); it != records.end(); it++)
      {
        cout << "VARIABLE Name: " << it->first << " Value: " << it->second.id << " & " << it->second.type <<  "\n";
      }
    }
};

class SymbolTable
{
  public:
    Scope root;
    Scope current;

    SymbolTable()
    {
      root = new Scope(NULL);
      current = root;
    }
    void class_dec(Node* class_body)
    {
      Node* child;
      for (auto i = class_body->children.begin(); i != class_body->children.end(); i++)
      { 
        //Lägg till class i current scope (Kolla leftmost child)
        list<Node*>::iterator name = class_body->children.begin();

        Class class_rec(name*.id , "CLASS");
        symboltable.put(name*, class_rec);

        //Skapa nytt scope som har current scope som parent
        Scope new_scope(symboltable.current);
        Variable class_this("this", name);
        new_scope.put("this", class_this);
        symboltable.childrenScopes.push_back(new_scope);
      }
      
    }
    void enterScope()
    {
      current = current.next_Child(); //create new scope if needed
    }

    void exitScope()
    {
      current = current.parentScope;
    }


    void put(string Key, Record item)
    {
      current.put(Key, item);
    }

    Record lookup(string Key)
    {
      return current.lookup(Key);
    }


    void printTable()
    {
      root.printScope();
    }

    void resetTable()
    {
      root.resetScope();
    }

    void start(Node* root)
    {
      //_>_>_>_>_>_>_>_>_>_>_>_> MAINCLASS <_<_<_<_<_<_<_<_<_<_<_<_<_<_
      //Isolera MAINCLASS och gör mainclass för hand
      Node* mainclass = *root->children.begin();

      string type = mainclass->type;
      string name = mainclass->name;
      mainclass_rec = new Class(name, type);
      symboltable.put(name, mainclass_rec);

      //Skapa mainclass scope
      Scope main_scope(symboltable.current_class);
      // symboltable.enterScope();
      Variable class_this("this", name);
      main_scope.put("this", class_this);

      Method methmainclass("main", "void");
      main_scope.put("main", methmainclass);

      //Skapa method main i mainclass //KAN BEHÖVA ÄNDRAS MED EN ITERATOR
      advance(mainclass, 1);
      string vtype = mainclass->type;
      string vname = mainclass->name;
      Variable vmethod_main(vname, vtype);

      symboltable.current = main_scope;
      Scope main_meth_scope(symboltable.current_class);

      symboltable.current = main_meth_scope;
      symboltable.put(mname,vmethod_main);

      symboltable.current = scope->parentScope;
      symboltable.current = scope->parentScope;

      //_>_>_>_>_>_>_>_>_>_>_>_> Classbody <_<_<_<_<_<_<_<_<_<_<_<_<_<_
      classbody(root->children.end());

      return;
    }

    void classbody(Node* root)
    {
      Node* child;

      for(auto i = root->children.begin(); i != root->children.end(); i++)
      {
        child = *i;
        //Skapa scope för varje class_declaration
        class_declaration(child);
      }

      return;
    }

    void class_declaration(Node* root)
    {
      return;
    }

    void methbody(Node* root)
    {
      Node* child;

      for(auto i = root->children.begin(); i != root->children.end(); i++)
      {
        child = *i;
        //Skapa scope för varje class_declaration
        method_declaration(child);
      }
      return;
    }
};

int tree_traverse(SymbolTable symboltable, Node* root, int depth=0)
{
    Node* child;

    for (auto i = root->children.begin(); i != root->children.end(); i++)
    {
        for(int i=0; i<depth; i++) //pretty print
        cout << "    ";

        child = *i;
        cout << "Type: " <<  child->type << "   Value: " << child->value << "\n";

        //Write code here!

        if (child->type == "MAINCLASS" || "CLASSDECLARATION")
        {
          //Lägg till class i current scope (Kolla leftmost child)
          list<Node*>::iterator name = root->children.begin();
 
          Class class_rec(name*.id , "CLASS");
          symboltable.put(name*, class_rec);


          //Skapa nytt scope som har current scope som parent
          symboltable

          //Ska göras om
          Scope new_scope(symboltable.current);
          Variable class_this("this", name);
          new_scope.put("this", class_this);
          symboltable.childrenScopes.push_back(new_scope);

        }

        else if (child->type == "METHODDECLARATION")
        {
          //Lägg till method i current scope (Kolla 2 leftmost child)
          child->children::iterator it = child->children.begin();

          type = *it;
          advance(it, 1);
          name = *it;

          current_method = new Method(name, type);

          symboltable.put(name, current_method);

          //Fixa med scope
        }

        else if (child->type == "VARDECLARATION")
        {
          //Lägg till variabel i current scope (Kolla alla children)
          type = child->children.begin();
          name = child->children.end();

          current_variable = new Variable(name, type);

          symboltable.put(name, current_variable);
        }

        //Code ends here!

        tree_traverse(root_scope ,child, depth+1);
    }
}

int symbol_table(Node* root, int depth=0) // BYT NAMN?
{
  SymbolTable symboltable();
  symboltable.start(root);
  return 0;
}
