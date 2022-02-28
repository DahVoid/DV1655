#include <vector>
#include <typeinfo> // for debugging
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <list>
#include <iterator>

using namespace std;

class Record
{
  public:
    string id;
    string type;
    Record(string id, string type)
    {
        this -> id = id;
        this -> type = type;
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
            Variable new_var = Variable(var_id, "Variable");
            //Write code here:
            variables.insert(pair<string ,Variable>(var_id, new_var));
        }
 

};

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
    Variable new_par = Variable(par_id, "Variable");
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
    Method new_met = Method(met_id, "Method");
    //Write code here:
    methods.insert(pair<string ,Method>(met_id, new_met));


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

        return records[Key];
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
};


int main()
{
  return 0;
}
