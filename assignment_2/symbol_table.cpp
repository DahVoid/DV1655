#include <vector>
#include <typeinfo> // for debugging
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <list>

using namespace std;

class Record
{
  public:
    string id;
    string type;
    Record(string id, string type)
    {
        this.id = id;
        this.type = type;
        cout << "contructed: " << type << endl;
    };


  void printRecord()
  {
    cout << "id: " << id << "\n" << "type: " <<  type << "\n";
  }
};

class Container: public Record
{
    public:
        map<string, Variable> variables;
        Container(string id, string type) : Record(id, type)
        {

        };

        void addVariable(string var_id)
        {
            new_var = new Variable(var_id, "Variable");
            //Write code here:
            variables.insert(pair<string ,Variable>(var_id, new_var));
        }
 

}

class Variable: public Record
{
    public:
        // Constructor
        Variable(string id, string type) : Record(id, type)
        {

        };

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
    //Write code here:
    new_par = new Variable(par_id, "Variable");
    //Write code here:
    parameters.insert(pair<string ,Variable>(par_id, new_par));

  }
};


class Class: public Container
{
  public:
    map<string, Method> methods;
    Class(string id, string type) : Container(id, type)
    {

    };
    

  void addMethod(string met_id)
  {
    //Write code here:
    new_met = new Method(met_id, "Method");
    //Write code here:
    methods.insert(pair<string ,Method>(par_id, new_met));


  }

  string lookupVariable()
  {
    //Write code here:

  }

  string lookupMethod()
  {
    //Write code here:

  }
};

class Scope
{
  public:
    int next = 0; //next child to visit
    // Scope* parentScope; //parent scope
    list<Scope> childrenScopes; //children scopes
    map<string, Record> records; //symbol to record map

    Scope(Scope* parentScope_in)
    {
      Scope parentScope = parentScope_in;
    }

    Scope()
    {

    }

    Scope next_Child()
    {
      if(next == childrenScopes.size()) // create new child scopre
      {
        Scope nextChild(this); // VIKTIGT ------> insert "this" i in parameter till scope <--- VIKTIGT
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
      if(records.containskey(Key)) //does it exist in the current scope? Använd map.count (records.count)
      {
        return record.get(Key);
      }

      else
      {
        if (parent == null)
        {
          return null; //identifier not in the symbol table
        }

        else
        {
          return parent.lookup(Key); // delegate the request to the parent scope
        }
      }
    }

    void resetScope()
    {
      next = 0;
      for(int i = 0; i < children.size(); i++)
      {
        children.get(i).resetScope();
      }
    }
};



class SymbolTable
{
  Scope root;
  Scope current;

  void SymbolTable()
  {
    root = new Scope(null);
    current = root;
  }

  void enterScope()
  {
    current = current.nextChild(); //create new scope if needed
  }

  void exitScope()
  {
    current = current.parent();
  }


  void put(String Key, Record item)
  {
    current.put(Key, item);
  }

  Record lookup(String Key)
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
};


int main()
{
  return 0;
}