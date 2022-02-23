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

struct cls 
{
    string name;
};


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
