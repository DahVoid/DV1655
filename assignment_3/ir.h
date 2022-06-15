#include <string>
#include <vector>
#include <Node.h>



using namespace std;
int counter = 0;
BBlock curr_block;
class Tac
{
    public:
        string op, lhs, rhs, res;

        // Getters & Setters
        void dump(){
            printf("%s := %s %s %s", res.c_str(), lhs.c_str(), op.c_str(), rhs.c_str());
        }
};

class Expression : public Tac
{
    public:
        Expression(string op, string lhs, string rhs, string res)
        {
            this->op = op;
            this->lhs = lhs;
            this->rhs = rhs;
            this->res = res;
        }
};

class Unary_expression : public Tac
{
    public:
    Unary_expression(string op, string rhs, string res)
    {
        this->op = op;
        this->rhs = rhs;
        this->res = res;
    }
};

class Copy_expression : public  Tac
{
    public:
    Copy_expression(string lhs, string res)
    {
        this->lhs = lhs;
        this->res = res;
    }
};

class Array_access :public  Tac 
{
    public:
    Array_access(string lhs_i, string res)
    {
        this->lhs = lhs_i;
        this->res = res;
    }
};

class New : public Tac
{
    public:
    New(string type, string res)
    {
        this->lhs = "new";
        this->op = type;
        this->res = res;
    }
};

class New_array : public Tac
{
    public:
    New_array(string type, string res, string N)
    {
        this->lhs = "new";
        this->op = type;
        this->rhs = N;
        this->res = res;
    }
};

class Length : public  Tac
{
    public:
    Length(string op, string res)
    {
        this->lhs = "length";
        this->op = op;
        this->res = res;
    }
};

class Parameter : public  Tac
{
    public:
    Parameter(string name)
    {
        this->lhs = "param";
        this->op = name;
        
    }
};

class MethodCall : public Tac {
    public:
    MethodCall(string f1, string N1, string res)
    {
        this->op = "call";
        this->lhs = f1;
        this->rhs = N1;
        this->res = res;
    }
};

class Return : public Tac {
    public:
    Return(string op)
    {   
        this->lhs = "return";
        this->op = op;
    }
};

class Jump : public Tac {
    public:
    Jump(string label)
    {
        this->op = "goto";
        this->res = label;
    }
};

class Cond_jump : public Tac {
    public:
    Cond_jump(string op, string x1, string label)
    {
        this->op = op;
        this->lhs = x1;
        this->res = label;
    }
};

string genName() {
    string name = "block" + to_string(counter);
    counter++;
    return name;
}
class BBlock {
    public:
        vector<Tac> Tacs;
        Tac condition;
        string label = genName();
        BBlock *trueExit, *falseExit;
        BBlock()
        {
            this->trueExit = NULL;
            this->falseExit = NULL;
        }


};

class IR {
    public:
        void ir_traverse_tree(Node * root, symbol_table symbol_table))
        {
            // print cfg to .dot file
            if(root.type == "IF")
            {
                
            }
            else if (root.type == "WHILE")
            {

            } else if (root.type == "MEMBER SELECTION FUNCTION CALL")
            {
                
            } else
            {  
                if(root-> type == "VARDECLARATION")
                {
                    curr_block.Tacs.push_back(new Copy_expression(root->children[0]->value, root->children[1]->value));
                }
                else if(root-> type =="")
                { 

                }

            }

            
            if (root != NULL)
            {
                ir_traverse_tree(root->left, symbol_table);
                ir_traverse_tree(root->right, symbol_table);
                return;
            }
        }




        

    }

}