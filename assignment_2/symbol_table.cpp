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




int main() {

    printf("Hello world\n");
    ifstream myfile ("tree.dot");
    string line;
    int skips = 0;
    if (myfile.is_open())
    {
        while( getline(myfile, line) )
        {
            cout << "skips == " << skips << endl;
            
            if(skips == 0)
            {
                int i = line.find("label=");
                if(i > 0)
                {
                    int j = line.find("label=\"CLASSDECLARATION:\"");
                    if(j > 0)
                    {
                        skips = 2;
                    }
                    j = line.find("label=\"METHODDECLARATION:\"");
                    if(j > 0)
                    {
                        skips = 0;
                    }
                    j = line.find("label=\"VARDECLARATION:\"");
                    if(j > 0)
                    {
                        skips = 0;
                    }


                    cout << line << '\n';

                }
            } else skips--;




            
        }
        myfile.close();
    } else cout << "Unable to open file";



    return 0;
}
