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
    vector<BBlock*> root_blocks;
    Node *save_root;

    public:
        void start(Node *root, SymbolTable *symbol_table)
        {
            this->save_root = root;
            BBlock* curr_block = new BBlock;
            root_blocks.push_back(curr_block);
            BBlock new_bb = create_bb(curr_block, save_root, symbol_table);
            curr_block->trueExit = &new_bb;
            //create_tree(root, symbol_table);
            return;
        }

        void add_tacs(BBlock *curr_bb, Scope *scope)
        {
            // Iterate on all children and add the corresponding TAC
            for(auto const& rec: scope->records)
            {

            }
        }

        void add_cond(BBlock *curr_bb, Node *root, SymbolTable *symbol_table)
        {
            // Add the condition TAC to bb
            if(root -> type == "IF") {
                cout << "IF" << endl;
                // child 0 is the condition, 1 is the true block, 2 is the false block
                int i = 0;
                for(auto const& child : root->children)
                {
                    if(i == 0)
                    { 
                        // is conditon
                        string res;
                        string op;
                        string x1;
                        string x2;

                        cout << "condition" << endl;
                        if(child->type == "IDENTIFIER")
                        {
                            cout << "child is identifier" << endl;
                            res = child->value;
                            op = "";
                            x1 = "";
                            x2 = "";
                        } else {
                            cout << "child is other" << endl;
                            cout << child->type << endl;
                            res = root->type;
                            op = child->type;
                            x1 = child->children.front()->value;
                            x2 = child->children.back()->value;
                        }




                        Condition_expression cond = Condition_expression(op, x1, x2, res);
                        curr_block.condition = cond;
                    } else if (i == 1)
                    { // is true block
                        cout << "true block" << endl;
                        BBlock new_bb = create_bb(curr_bb, child, symbol_table);
                        curr_block.trueExit = &new_bb;
                    } else if(i == 2)
                    { // is false block
                        cout << " false block" << endl;
                        BBlock new_bb = create_bb(curr_bb, child, symbol_table);
                        curr_block.falseExit = &new_bb;
                    }
                    i++;
                }
                
            } else if (root -> type == "WHILE") { 
                cout << "WHILE" << endl;
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
                    } 

                    i++;
                }

                // create false exit block
                BBlock new_bb = create_bb(curr_bb, root, symbol_table);
                curr_block.falseExit = &new_bb;                         

            } else if (root -> type == "MEMBER SELECTION FUNCTION CALL")  {
                cout << "MEMBER SELECTION FUNCTION CALL" << endl;

            }

        }
        
        BBlock create_bb(BBlock *parent_bb, Node *root, SymbolTable *symbol_table) {
            // Navigate all the BBs and solve the relations between them
            BBlock *new_bb = new BBlock;
            add_tacs(*new_bb);

           

            return *new_bb;
        }


        // void create_tree(Node *root, SymbolTable *symbol_table)
        // { // This function is used to translate the AST to IR (basic blocks with TACs)
        //   // Måste gå på scopes och inte gå på Nodes/ följa tree.pdf som den gör nu

        //     // get scope content from symbol table
        //     cout << "Entering create tree" << endl;

        //     // // Translate statements
        //     // if (root != NULL)
        //     // {
        //     //     for(auto const& child : root->children)
        //     //     {
        //     //         create_tree(child, symbol_table);
        //     //     }
        //     // } else {
        //     //     cout << "hit dead end" << endl;
        //     //     return;
        //     // }
            
        //      else
        //     {  // tanslate expressions
        //         if(root ->type == "VARDECLARATION")
        //         {
        //             cout << "VARDECLARATION" << endl;
        //             Copy_expression exp =  Copy_expression(root->children.front()->value, root->children.back()->value);
        //             curr_block.Tacs.push_back(exp);
        //         } else if(root -> type =="EQUAL")
        //         {   
        //             cout << "EQUAL" << endl;
        //             if(root->children.back()->type == "ADD")
        //             {
        //                 cout << "ADD" << endl;
        //                 Expression exp = Expression("+", root->children.back()->children.front()->value,
        //                      root->children.back()->children.back()->value, root->children.front()->value);
        //                 curr_block.Tacs.push_back(exp);
        //             }

        //         }

        //     }
        //     cout <<"returning from create tree" << endl;
        //     return;
        // }

        // graph functions
        BBlock test_bb_tree() {
            BBlock bb = BBlock();
            bb.label = "1";
            bb.trueExit = new BBlock();
            bb.trueExit->label = "2";
            bb.falseExit = new BBlock();
            bb.falseExit->label = "3";
            bb.condition = Condition_expression("<", "x", "y", "result");
            return bb;
        }

        void generate_tree()
        {   
            std::cout << "root block label: " << root_blocks.front()->label << std::endl;
            // BBlock root_block = test_bb_tree();
            //BBlock* ptr_block = &root_block;
            BBlock* ptr_block = root_blocks.front();

            std::ofstream outStream;
            outStream.open("ir.dot");
            
            int count = 0;
            outStream << "digraph G {" << endl;
            outStream << "node [shape = box];" << endl;
            //outStream << "block_0 [label=\"block_0\"];" << endl;
            generate_tree_bb(&outStream,  ptr_block);

            //   Might need to add back later with a relation to the last bblock
            //string final_block_label = genName();
            // outStream << final_block_label << " [label=\"" << final_block_label << "\"];" << endl;
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
            cout << "create block relationships" << endl;
            if(bb->trueExit != NULL)
            {
                *outStream << bb->label << " -> " << bb->trueExit->label << ";" << endl;
                if(bb->trueExit !=bb)
                {
                    cout << "true exit" << endl;
                    generate_tree_bb(outStream, bb->trueExit);
                }
                
            } else
            {
                return;
            }

            if (bb->falseExit != NULL)
            {
                *outStream << bb->label << " -> " << bb->falseExit->label << ";" << endl;
                generate_tree_bb(outStream, bb->falseExit);
            }

            return;
        }

        void lookup_method(Node *root, string classname, string methodname, string input)
        {
            if (root != NULL)
            {
                for (auto const& child: root->children)
                {
                    lookup_method(child, classname, methodname, input);
                }
            }
            else 
            {
                cout << "hit dead end" << endl;
                return;
            }
            
            if (root->type == "METHODDECLARATION")
            {
                int i=0;
                for(auto const& child : root->children)
                {
                    if (i == 1 || child->value == methodname)
                    {
                        //Build tree 
                        //this->start(root, symbol_table);
                        return;
                    }
                }    
            }

        }

        

};
