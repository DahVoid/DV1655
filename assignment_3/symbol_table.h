#ifndef SYMBOL_H
#define SYMBOL_H

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
        // cout << "contructed: " << type << "  " << id << endl;
    }

    Record()
    {
    }

    void printRecord()
    {
      // cout << "id: " << id << "\n" << "type: " <<  type << "\n";
    }

    string getclass()
    {
      return "RECORD";
    }
};

class Variable: public Record
{
    public:
        // Constructor
        Variable(string id, string type) : Record(id, type)
        {

        }

        string getclass()
        {
          return "VARIABLE";
        }

};

class Container: public Record
{
    public:
        map<string, Variable*> variables;
        Container(string id, string type) : Record(id, type)
        {

        }
        Container()
        {

        }
        void addVariable(string var_id)
        {
            Variable *new_var = new Variable(var_id, "Variable");

            variables.insert(pair<string ,Variable*>(var_id, new_var));
        }

};

class Method: public Container
{
  public:
    map<string, Variable*> parameters;
    Method(string id, string type) : Container(id, type)
    {
    }
    Method() : Container()
    {
    }

  void addParameter(string par_id)
  {
    Variable *new_par = new Variable(par_id, "Variable");
    parameters.insert(pair<string ,Variable*>(par_id, new_par));
  }

  string getclass()
  {
    return "METHOD";
  }
};

class Class: public Container
{
  public:
    map<string, Method*> methods;
    Class(string id, string type) : Container(id, type)
    {

    }

    Class() : Container()
    {
    }

    string getclass()
    {
      return "CLASS";
    }

  void addMethod(string met_id, Method* new_met)
  {

    methods.insert(pair<string ,Method*>(met_id, new_met));

  }

  Method* lookupMethod(string Key)
  {

    int a = methods.count(Key);

    if(methods.count(Key) > 0) //does it exist in the current scope? Använd map.count (records.count)
    {
      return methods.at(Key);
    }else
    {
      cout << "SEMANTIC FAULT: METHOD IS NOT DEFINED\n";
      exit(-1);
        // do nooooothing
    }
  }
    
};

class Scope
{
  public:
    int next = -1; //next child to visit
    Scope* parentScope; //parent scope
    vector<Scope*> childrenScopes; //children scopes
    // list<Scope> childrenScopes; //children scopes
    map<string, Record*> records; //symbol to record map
    map<string, Record*>::iterator it;
    bool isroot;

    Scope(Scope* parentScope_in)
    {
      parentScope = parentScope_in;
      isroot = false;
    }

    Scope()
    {
      isroot = true;
    }

    void put(string Key, Record* record)
    {
      records.insert(pair<string, Record*>(Key, record));
      return;
    }

    Scope* next_Child()
    {
      // cout << "NEW SCOPE\n\n";
      next++;
      return childrenScopes[next];
    }

    Record* lookup(string Key)
    {
      if(records.count(Key) > 0) //does it exist in the current scope? Använd map.count (records.count)
      {
        // cout << "FOUND KEY! \n";
        Record* retval = records.at(Key);
        return retval;
      }

      else
      {

        if (this->isroot == true)
        {
          Record *temp_retval = new Record("Notfound", "Notfound");
          return temp_retval;
        }

        else
        {
          // cout << "2\n";
          // cout << "did not find key in scope! \n";
          Record* retval = parentScope->lookup(Key);
          return retval; // delegate the request to the parent scope
        }
      }
    }

    void printScope() //Kommer behöva göras om
    {
      // cout << "\nnew scope!\n";
      map<string, Record*>::iterator it;
      for (it = records.begin(); it != records.end(); it++)
      {
        cout << "VARIABLE Name: " << it->first << " Value: " << it->second->id << " & " << it->second->type <<  "\n";
      }

      // list<Scope*>::iterator its;
      for (int i = 0; i < childrenScopes.size(); i++)
      {
        childrenScopes[i]->printScope();
      }
    }
};

class SymbolTable
{
  public:
    Scope* root;
    Scope* current;

    SymbolTable()
    {

      Scope *root = new Scope();
      current = root;
     
    }

    void exitScope()
    {
      current = this->current->parentScope;
    }


    void put(string Key, Record* item)
    {
      current->put(Key, item);
    }

    Record* lookup(string Key)
    {
      return current->lookup(Key);
    }

    void printTable()
    {
      current->printScope();
    }

    // void resetTable()
    // {
    //   root->resetScope();
    // }

    void start(Node* root)
    {
      //_>_>_>_>_>_>_>_>_>_>_>_> Program <_<_<_<_<_<_<_<_<_<_<_<_<_<_

      //_>_>_>_>_>_>_>_>_>_>_>_> MAINCLASS <_<_<_<_<_<_<_<_<_<_<_<_<_<_
      //Isolera MAINCLASS och gör mainclass för hand
      Node* mainclass = root->children.front();
      Node* child = mainclass->children.front();
      string mainclass_name = child->value;
      string mainclass_type = "INT";
      Class *mainclass_rec = new Class(mainclass_type, mainclass_name);

      this->put(mainclass_name, mainclass_rec);

      //Skapa mainclass scope
      Scope *main_scope = new Scope(this->current);

      this->current->childrenScopes.push_back(main_scope);

      this->current = main_scope;
      // symboltable.enterScope();
      Variable *class_this = new Variable("this", mainclass_name);
      this->put("this", class_this);

      Method *methmainclass = new Method("main", "void");
      this->put("main", methmainclass);

      string type = "VOID";
      string name = "main";
      Method *main_rec = new Method(name, type);

      this->put(name, main_rec);

      //Skapa method main i mainclass //KAN BEHÖVA ÄNDRAS MED EN ITERATOR
      advance(mainclass, 1);
      string vtype = "STRING[]";

      string vname = child->value;

      Variable *vmethod_main = new Variable(vname, vtype);

      Scope *main_meth_scope = new Scope(this->current);
      this->current->childrenScopes.push_back(main_meth_scope);

      this->current = main_meth_scope;
      this->put(name,vmethod_main);

      exitScope();
      exitScope();
      //_>_>_>_>_>_>_>_>_>_>_>_> Classbody <_<_<_<_<_<_<_<_<_<_<_<_<_<_
      Node* class_body = root->children.back();
      // cout << class_body->value;
      classbody(class_body);
      return;
    }

    void classbody(Node* root)
    {
      Node* child;
      for(auto i = root->children.begin(); i != root->children.end(); i++)
      {
        child = *i;
        //Skapa scope för varje class_declaration
        class_dec(child);
      }
      return;
    }

    void class_dec(Node* class_body)
    {
      Node* child;
      Class* class_rec;
      int counter = 0;
      for (auto i = class_body->children.begin(); i != class_body->children.end(); i++)
      {
        child = *i;
        //Lägg till class i current scope (Kolla leftmost child)

        if (counter == 0)
        {
          class_rec = new Class(child->value , "CLASS"); //Type kanske ska va class namnet
          //Skapa nytt scope som har current scope som parent
          Scope *new_scope = new Scope(this->current);
          Variable *class_this = new Variable("this", child->value);
          new_scope->put("this", class_this);
          this->current->childrenScopes.push_back(new_scope);
          //scope
          this->current = new_scope;
        }
        if (child->type == "VARBODY")
        {
          this->class_varbody(child);
        }

        if (child->type == "METHODBODY")
        {
          this->methbody(child, class_rec);
        }

        counter++;
      }
      // Class* child_rec;
      map<string, Method*>::iterator i;

      this->exitScope();

      Record* temp;
      temp = this->lookup(class_rec->id);

      if (temp->id != "Notfound")
      {
        cout << "\n\n\n\n\n\n\n";
        cout << "DUPLICATE VARIABLE\n";
        cout << "\n\n\n\n\n\n\n";
      }

      this->put(class_rec->id, class_rec);
      return;
    }

    void methbody(Node* root, Class* class_rec)
    {
      Node* child;
      for(auto i = root->children.begin(); i != root->children.end(); i++)
      {
        child = *i;
        //Skapa scope för varje class_declaration
        Scope *new_scope = new Scope(this->current);
        this->current->childrenScopes.push_back(new_scope);
        this->current = new_scope;
        method_declaration(child, class_rec);
      }
      return;
    }

    void method_declaration(Node* method, Class* class_rec)
    {
      //Declare method
      Node* child;
      string name;
      string type;
      int counter = 0;

      Method* method_rec;

      for(auto i = method->children.begin(); i != method->children.end(); i++)
      {
        child = *i;

        if (counter == 0)
        {
          type = child->type;
        }

        if (counter == 1)
        {
          name = child->value;
          Method* temp_method = new Method(name, type);
          method_rec = temp_method;
        }

        if (child->type == "PARAMETERBODY")
        {
          Node* grandchild;
          for(auto j = child->children.begin(); j != child->children.end(); j++)
          {
            grandchild = *j;
            Node* grandchildnamenode = grandchild->children.back();
            string name = grandchildnamenode->value;
            grandchildnamenode = grandchild->children.front();
            string type = grandchildnamenode->type;
            Variable *new_var = new Variable("PARAMETER", type);
            // method_rec->addParameter(name);
            Record* temp;
            temp = this->lookup(name);
            if (temp->id != "Notfound")
            {
              cout << "DUPLICATE VARIABLE\n";
            }
            method_rec->parameters.insert(pair<string, Variable*>(name, new_var));
            this->put(name, new_var);
          }
        }

        if (child->type == "VARBODY")
        {
          this->method_varbody(child);
          break;
        }

        counter++;
      }
      this->exitScope();
      // class_rec->addMethod(name, method_rec);
      class_rec->methods.insert(pair<string, Method*>(name, method_rec));
      Record* temp;
      temp = this->lookup(name);
      if (temp->id != "Notfound")
      {
        cout << "DUPLICATE VARIABLE\n";
      }
      this->put(name, method_rec);
      return;
    }

    void class_varbody(Node* varbody)
    {
      Node* child;
      Node* grandchild1;
      Node* grandchild2;
      for (auto i = varbody->children.begin(); i != varbody->children.end(); i++)
      {
        child = *i;
        grandchild1 = child->children.front();
        grandchild2 = child->children.back();
        string type = grandchild1->type;
        string name = grandchild2->value;
        Variable *new_var = new Variable(name, type);
        //Lägg till variabel i current scope (Kolla alla children)
        Record* temp;
        temp = this->lookup(name);
        if (temp->id != "Notfound")
        {
          cout << "DUPLICATE VARIABLE\n";
        }
        this->put(name, new_var);
      }
      return;
    }

    void method_varbody(Node* varbody)
    {
      Node* child;
      Node* grandchild1;
      Node* grandchild2;
      for (auto i = varbody->children.begin(); i != varbody->children.end(); i++)
      {
        child = *i;

        grandchild1 = child->children.front();
        grandchild2 = child->children.back();

        string type = grandchild1->type;
        string name = grandchild2->value;
        // cout << "type : " << type << "   name: " << name << "\n";
        Variable *new_var = new Variable(name, type);
        //Lägg till variabel i current scope (Kolla alla children)
        Record* temp;
        temp = this->lookup(name);
        if (temp->id != "Notfound")
        {
          cout << "DUPLICATE VARIABLE\n";
        }
        this->put(name, new_var);
      }
      return;
    }
};


SymbolTable* symbol_table(Node* root) // BYT NAMN?
{
  // cout << "creating symboltable\n";
  SymbolTable* symboltable = new SymbolTable();
  // cout << "starting symboltable\n";
  symboltable->start(root);

  return symboltable;
}

#endif
