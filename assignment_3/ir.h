#include <string>
#include <vector>
#include <iostream>
#include "Node.h"



using namespace std;
int counterBB = 0;
int counterTAC = 0;

class Tac
{
    public:
        string op, lhs, rhs, res;

        // Getters & Setters
        string dump(){
            return (res + " := " + lhs + " "+ op + " " + rhs);
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


string genNameBB() {
    string name = "block_" + to_string(counterBB);
    counterBB++;
    return name;
}
string genNameTAC() {
    string name = "_+" + to_string(counterTAC);
    counterTAC++;
    return name;
}

class BBlock {
    public:
        vector<Tac> Tacs;
        Tac condition;
        string label = genNameBB();
        BBlock *trueExit, *falseExit;
        BBlock()
        {
            this->trueExit = NULL;
            this->falseExit = NULL;
        }


};

class IR {
    BBlock curr_block;
    vector<BBlock*> root_blocks;
    Node *save_root;

    public:
        void start(Node* root, SymbolTable* symbol_table)
        {
            this->save_root = root;
            BBlock* curr_block = new BBlock;
            root_blocks.push_back(curr_block);
            BBlock* new_bb = create_bb(curr_block, save_root, symbol_table);
            curr_block->trueExit = new_bb;

            return;
        }

        string traverse_ast(BBlock* parent_bb, Node* root, SymbolTable* symbol_table, string tempVar = "")
        {
            cout << "traversing " << root->type << ", Children: "<< root->children.size() << endl;
            // Iterate on all children and add the corresponding TAC
            if(root->children.size() == 0) 
            {
                return "";

            }
            string res ="";
            if(root->type == "ADD" || root->type == "SUB" || root->type == "MUL" || root->type == "DIV"
            || root->type == "OR" || root->type == "COMPARE" || root->type == "AND" || root->type == "GREATER"
            || root->type == "LESS" )
            {
                cout << "enter expression handling for "<< root->type << endl;
                string lhs = "";
                string rhs = "";

                // lhs
                if(root->children.front()->type == "INT" || root->children.front()->type == "boolExpression")
                {
                    lhs = "$" + root->children.front()->value;
                }
                else
                {
                    lhs = traverse_ast(parent_bb, root->children.front(), symbol_table);
                }
                cout << "lhs: " << lhs << endl;
                // rhs
                if(root->children.back()->type == "INT" || root->children.back()->type == "boolExpression")
                {
                    rhs = "$" + root->children.back()->value;   
                }
                else
                {
                    rhs = traverse_ast(parent_bb, root->children.back(), symbol_table);
                }
                cout << "rhs: " << rhs << endl;
                // op
                string op = root->type;
                res = genNameTAC();  
                Expression tac = Expression(op, lhs, rhs, res);
                parent_bb->Tacs.push_back(tac);
                cout << tac.dump() << endl;
                cout << "exit expression handling for "<< root->type << endl;
                
            } else if(root->type == "NEGATION" ) // Unary expression
            {
                cout << "enter expression handling for "<< root->type << endl;
                string lhs = "";
                string rhs = "";
                if(root->children.front()->type == "boolExpression")
                {
                    rhs = "$" + root->children.front()->value;
                }
                string op = "!";
                res = genNameTAC();
                Unary_expression tac = Unary_expression(op, rhs, res);
                parent_bb->Tacs.push_back(tac);
                cout << tac.dump() << endl;
                cout << "exit expression handling for "<< root->type << endl;
        
            } else {
                for(auto const& child : root->children)
                {
                   res = traverse_ast(parent_bb, child, symbol_table);
                }
            }


            return res;
        }

        BBlock* create_bb(BBlock* parent_bb, Node* root, SymbolTable* symbol_table) {
            // Navigate all the BBs and solve the relations between them
            cout << "create_bb" << endl;
            BBlock* new_bb = new BBlock;
            traverse_ast(new_bb, root, symbol_table);

           

            return new_bb;
        }

        // graph functions
        BBlock* test_bb_graph() {
            BBlock* bb = new BBlock();
            bb->label = "1";
            bb->trueExit = new BBlock();
            bb->trueExit->label = "2";
            bb->falseExit = new BBlock();
            bb->falseExit->label = "3";
            bb->condition = Condition_expression("<", "x", "y", "result");
            return bb;
        }

        void generate_graph()
        {   
            std::cout << "root block label: " << root_blocks.front()->label << std::endl;
            //BBlock* ptr_block = test_bb_graph();
            //BBlock* ptr_block = &root_block;
            BBlock* ptr_block = root_blocks.front();

            std::ofstream outStream;
            outStream.open("ir.dot");
            
            int count = 0;
            outStream << "digraph G {" << endl;
            outStream << "node [shape = box];" << endl;
            //outStream << "block_0 [label=\"block_0\"];" << endl;
            generate_graph_bb(&outStream,  ptr_block);

            //   Might need to add back later with a relation to the last bblock
            //string final_block_label = genNameBB();
            // outStream << final_block_label << " [label=\"" << final_block_label << "\"];" << endl;
            outStream << "block_"<< counterBB << "[label = \"block_" << counterBB << "\"]" << endl;
            outStream << "block_"<< counterBB-1  << " -> " << "block_"<< counterBB  << ";" << endl;
            outStream << "}" << endl;
            outStream.close();

            std::cout << "Generated IR graph" << endl;
            system("dot -Tpng ir.dot -o ir.png");


            return;
        }

        void generate_graph_bb(ofstream *outStream, BBlock *bb)
        {
            cout << "generate graph bb: "<< root_blocks.front()->label  << endl;
            
            // create current block
            *outStream << bb->label << " [label=\""<< bb->label << "\n";

            // add tacs to block
            for(auto tac_in_block = bb->Tacs.begin(); tac_in_block != bb->Tacs.end(); tac_in_block++)
            {
               cout << (*tac_in_block).dump() << endl;
               *outStream << (*tac_in_block).dump() << endl;
            }

            // close block
            *outStream << "\"];" << endl;
            // create block relationships
            cout << "create block relationships" << endl;
            if(bb->trueExit != NULL)
            {
                *outStream << bb->label << " -> " << bb->trueExit->label << ";" << endl;
                if(bb->trueExit !=bb)
                {
                    cout << "true exit" << endl;
                    generate_graph_bb(outStream, bb->trueExit);
                }
                
            } else
            {
                return;
            }

            if (bb->falseExit != NULL)
            {
                *outStream << bb->label << " -> " << bb->falseExit->label << ";" << endl;
                generate_graph_bb(outStream, bb->falseExit);
            }

            return;
        }

        // Code generation functions

        void generate_code(BBlock basicBlock)
        {
            cout << "generate code" << endl;
            // generate code for each bb


            return;
        }
};
