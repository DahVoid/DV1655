#include <string>
#include <vector>
#include <iostream>
#include "Node.h"



using namespace std;
int counter = 0;

class Tac
{
    public:
        string op, lhs, rhs, res;

        // Getters & Setters
        void dump(){
            printf("%s := %s %s %s\n", res.c_str(), lhs.c_str(), op.c_str(), rhs.c_str());
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

class Condition_expression : public Tac {
    public:
    Condition_expression(string op, string x1, string x2, string label)
    {
        this->op = op;
        this->lhs = x1;
        this->rhs = x2;
        this->res = label;
    }
};


string genName() {
    string name = "block_" + to_string(counter);
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


    BBlock curr_block;
    BBlock* root_block = &curr_block;
    public:
        void create_tree(Node *root, SymbolTable *symbol_table)
        { // This function is used to translate the AST to IR (basic blocks with TACs)
            // Translate statements
            if (root != NULL)
            {
                for(auto const& child : root->children)
                {
                    create_tree(child, symbol_table);
                }
            } else {
                return;
            }
            
            if(root -> type == "IF")
            {
                // child 0 is the condition, 1 is the true block, 2 is the false block
                int i = 0;
                for(auto const& child : root->children)
                {
                    if(i == 0)
                    { // is conditon

                        Condition_expression cond = Condition_expression(child->type, child->children.front()->value, child->children.back()->value, root-> type);
                        curr_block.condition = cond;
                    } else if (i == 1)
                    { // is true block
                        curr_block.trueExit = new BBlock();
                        curr_block.trueExit->label = genName();
                    } else if(i == 2)
                    { // is false block
                        curr_block.falseExit = new BBlock();
                        curr_block.falseExit->label = genName();
                    }
                    i++;
                }

                if (curr_block.trueExit != NULL)
                {
                    // create true exit block
                    auto true_block_node = root->children.begin();
                    advance(true_block_node, 1);
                    curr_block = *curr_block.trueExit;
                    create_tree(*true_block_node, symbol_table);
                }

                if (curr_block.falseExit != NULL)
                {
                    // create false exit block
                    curr_block = *curr_block.falseExit;
                    create_tree(root->children.back(), symbol_table);
                }
                
            }
            else if (root -> type == "WHILE")
            { 
                // child 0 is the condition, 1 is the true block, 2 is the false block
                // true block/node will be the current one because of the while loop
                int i = 0;
                for(auto const& child : root->children)
                {
                    if(i == 0)
                    { // is conditon
                    
                        Condition_expression cond = Condition_expression(child->type, child->children.front()->value, child->children.back()->value, root-> type);
                        curr_block.condition = cond;
                    } else if (i == 1)
                    { // is true block
                        curr_block.trueExit = &curr_block;
                    } else if(i == 2)
                    { // is false block
                        curr_block.falseExit = new BBlock();
                        curr_block.falseExit->label = genName();
                    }
                    i++;
                }

                // create false exit block
                curr_block = *curr_block.falseExit;
                create_tree(root->children.back(), symbol_table);
                               

            } else if (root -> type == "MEMBER SELECTION FUNCTION CALL")
            {
                
            } else
            {  // tanslate expressions
                if(root ->type == "VARDECLARATION")
                {
                    Copy_expression exp =  Copy_expression(root->children.front()->value, root->children.back()->value);
                    curr_block.Tacs.push_back(exp);
                }
                else if(root -> type =="")
                { 

                }

            }
            return;

            

        }

        void generate_tree()
        {

            std::cout << "root block label: " << root_block->label << std::endl;
            std::ofstream outStream;
            outStream.open("ir.dot");
            
            int count = 0;
            outStream << "digraph G {" << endl;
            outStream << "node [shape = box];" << endl;
            outStream << "block_0 [label=\"block_0\"];" << endl;
            generate_tree_bb(&outStream, root_block);

            string final_block_label = genName();
            outStream << final_block_label << " [label=\"" << final_block_label << "\"];" << endl;
            outStream << "}" << endl;
            outStream.close();

            std::cout << "Generated IR Tree" << endl;
            system("dot -Tpng ir.dot -o ir.png");


            return;
        }

        void generate_tree_bb(ofstream *outStream, BBlock *bb)
        {
            // create current block
            *outStream << bb->label << " [label=\""<< bb->label << "\n";

            // add tacs to block
            *outStream << "test TAC \n" << endl;
            for(auto tac_in_block = bb->Tacs.begin(); tac_in_block != bb->Tacs.end(); tac_in_block++)
            {
                (*tac_in_block).dump();
            }

            // close block
            *outStream << "\"];" << endl;
            // create block relationships
            if(bb->trueExit != NULL)
            {
                *outStream << bb->label << " -> " << bb->trueExit->label << ";" << endl;
                generate_tree_bb(outStream, bb->trueExit);
            } else
            {
                return;
            }

            if (bb->falseExit != NULL)
            {
                *outStream << bb->label << " -> " << bb->trueExit->label << ";" << endl;
                generate_tree_bb(outStream, bb->falseExit);
            }

            return;
        }



        

};
