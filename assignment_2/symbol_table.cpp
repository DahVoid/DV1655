#include <vector>
#include <typeinfo> // for debugging
#include <iostream>
#include <fstream>
#include <string>


using namespace std;

struct Var 
{
    string type;
    string name;
};

struct Meth 
{
    string type;
    string name;
};

struct node 
{
    string name;
    string type;
    vector<node> children;
    
};

vector<node> tree;

int symbol_table(Node* root, int depth=0) 
{
    Node* child;

    for (auto i = root->children.begin(); i != root->children.end(); i++)
    {
        for(int i=0; i<depth; i++)
        cout << "    ";
        child = *i;
        cout << "Type: " <<  child->type << "   Value: " << child->value << "\n";
        symbol_table(child, depth+1);
    }
}


class Scope
{
    int next = 0; // Next child to visit 
    Scope parentScope; // parent scope
    list childrenScopes;
    map records; //Symbol to record map
    // ...

    Scope nextChild()
    {
        Scope nextChild;
        if (next == childrenScopes.size())
        {   // Create new child Scope
            nextChild = new Scope(this);
            childrenScopes.add(nextChild);
        }
        else
        {
            nextChild = childrenScopes.get(next); // visit scope
            next++;
            return nextChild;
        }

        Record lookup(string Key)
        {
            if(record.containsKey(Key)) //does it exists in the current scope?
            {  
                return record.get(Key);
            }
        }
    }

}
