#include <string>
#include <vector>
#include <set>
#include <iostream>
#include "Node.h"



using namespace std;
int counterBB = 0;
int counterTAC = 0;

class Tac
{
    public:
        string op, lhs, rhs, res;
        string eqSign = " := ";

        // Getters & Setters
        string dump(){
            return (res + eqSign + lhs + " "+ op + " " + rhs);
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

class NewObj : public Tac
{
    public:
    NewObj(string type, string res)
    {
        this->lhs = "new";
        this->op = type;
        this->res = res;
    }
};

class NewArray : public Tac
{
    public:
    NewArray(string type, string res, string N)
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
        this->eqSign = "";
        this->lhs = "param";
        this->op = name;
        
    }
};

class MethodCall : public Tac {
    public:
    MethodCall(string f1, string N1, string res)
    {
        this->op = f1;
        this->lhs = "call";
        this->rhs = N1;
        this->res = res;
    }
};

class ReturnTac : public Tac {
    public:
    ReturnTac(string lhs)
    {   
        this->eqSign = "return ";
        this->lhs = lhs;
    }
};

class Print : public Tac {
    public:
    Print(string op)
    {   
        this->lhs = "print";
        this->op = op;
        this->eqSign = "";
    }
};

class Jump : public Tac {
    public:
        Jump(string label)
        {
            this->op = label;
            this->eqSign = "";
            this->lhs = "goto";
        }
};

class Cond_jump : public Tac {
    public:
    Cond_jump(string x1, string label)
    {
        this->eqSign = "iffalse ";
        this->op = "goto";
        this->lhs = x1;
        this->rhs = label;
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

class Copy : public Tac {
    public:
    Copy(string lhs, string res)
    {
        this->lhs = lhs;
        this->res = res;
    }
};

class Stop : public Tac{
    public:
    Stop()
    {
        this->res = "Stop";
        this->eqSign = "";
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
    BBlock* curr_block;
    Node *save_root;

    public:
       vector<BBlock*> entryBlocks;
       bool isNegative = false;
        void start(Node* root, SymbolTable* symbol_table)
        {
            
            this->save_root = root;
            curr_block = new BBlock;//create first block
            entryBlocks.push_back(curr_block);
            traverse_ast(root, symbol_table);

            return;
        }

        string traverse_ast(Node* root, SymbolTable* symbol_table, string tempVar = "")
        {
            cout << "traversing " << root->type << ", Children: "<< root->children.size() << endl;
            // Iterate on all children and add the corresponding TAC
            if(root->children.size() == 0) 
            {
                 return root->value;

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
                    lhs = traverse_ast(root->children.front(), symbol_table);
                }
                cout << "lhs: " << lhs << endl;
                // rhs
                if(root->children.back()->type == "INT" || root->children.back()->type == "boolExpression")
                {
                    rhs = "$" + root->children.back()->value;   
                }
                else
                {
                    rhs = traverse_ast(root->children.back(), symbol_table);
                }
                cout << "rhs: " << rhs << endl;
                // op
                string op = root->type;
                if(isNegative) {
                    if(root->type == "ADD") {
                        op = "SUB";
                    }
                }
                if (root->type == "SUB") {
                    isNegative = !isNegative;
                }

                res = genNameTAC();  
                Expression tac = Expression(op, lhs, rhs, res);
                curr_block->Tacs.push_back(tac);
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
                } else {
                    rhs = traverse_ast(root->children.front(), symbol_table);
                }
                string op = "!";
                res = genNameTAC();
                Unary_expression tac = Unary_expression(op, rhs, res);
                curr_block->Tacs.push_back(tac);
                cout << tac.dump() << endl;
                cout << "exit expression handling for "<< root->type << endl;
        
            } else if(root->type == "SYSTEMOUTPRINT") {
                cout << "enter expression handling for "<< root->type << endl;
                string op = "";

                if(root->children.front()->type == "boolExpression" || root->children.front()->type == "INT")
                {
                    op = "$" + root->children.front()->value;
                } else {
                    op = traverse_ast(root->children.front(), symbol_table);
                }

                Print tac = Print(op);
                curr_block->Tacs.push_back(tac);

            } else if (root->type == "STATEMENTBODY") {
                for (std::list<Node *>::reverse_iterator child = root->children.rbegin(); child != root->children.rend(); child++)
                {
                   res = traverse_ast(*child, symbol_table);
                   isNegative = false;
                }

            } else if(root->type == "MEMBER SELECTION FUNCTION CALL" || root->type == "MEMBER SELECTION") {
                int paramCount = 0;
                string selectionStr = "";
                int counter = 0;
                for(auto const& child : root->children)
                {
                    if(counter == 0 ) {

                        // new if not a this. statement
                        if(child->type != "THIS"){
                            res = genNameTAC(); 
                            NewObj tac = NewObj(child->value, res);
                            curr_block->Tacs.push_back(tac);
                            paramCount++;
                            Parameter paramTac = Parameter(res);
                            curr_block->Tacs.push_back(paramTac);
                        } else if(child->type == "THIS") {
                            res = "THIS";
                            paramCount++;
                            Parameter paramTac = Parameter(res);
                            curr_block->Tacs.push_back(paramTac);
                        }
                        

                    } else if (counter == 1){
                        //method to call
                       selectionStr = child->value;
                    } else if (counter == 2) {
                        for(auto const& arg : child->children) {
                            // arguements
                            paramCount++;
                            string val = traverse_ast(arg, symbol_table);
                            Parameter tac = Parameter(val);
                            curr_block->Tacs.push_back(tac);

                        }

                    } 
                        counter++;
                }

                res = genNameTAC();  
                MethodCall tac = MethodCall(selectionStr, to_string(paramCount), res);
                curr_block->Tacs.push_back(tac);
                cout << tac.dump() << endl;
                cout << "exit expression handling for "<< root->type << endl;
            
            } else if(root->type == "METHODDECLARATION") {
                BBlock* new_bb = new BBlock;
                entryBlocks.push_back(new_bb);
                curr_block = new_bb;
                for(auto const& child : root->children)
                {
                    res = traverse_ast(child, symbol_table);
                }

                if(root->children.back()->type == "IDENTIFIER" || root->children.back()->type == "INT") {
                   string res = root->children.back()->value;
                   ReturnTac tac = ReturnTac(res);
                   curr_block->Tacs.push_back(tac);
                   cout << tac.dump() << endl;
                   
                }
                
            } else if(root->type == "EQUAL") {
                string res = root->children.front()->value;
                string lhs = traverse_ast(root->children.back(), symbol_table);
                Copy tac = Copy(lhs, res);
                curr_block->Tacs.push_back(tac);
                cout << tac.dump() << endl;

            } else if(root->type == "MAINCLASS") {
                BBlock* main_bb = new BBlock;
                BBlock* exit_bb = new BBlock;
                curr_block->trueExit = main_bb;
                Jump jumpStart = Jump(main_bb->label);
                curr_block->Tacs.push_back(jumpStart);
                curr_block = main_bb;
                for(auto const& child : root->children)
                {
                   res = traverse_ast(child, symbol_table);
                }
                entryBlocks.front()->trueExit->trueExit =  exit_bb;//create exit block
                Jump jumpExit = Jump(exit_bb->label);
                main_bb->Tacs.push_back(jumpExit);

                Stop stop = Stop();
                exit_bb->Tacs.push_back(stop);

            } else if(root->type == "WHILE") {
                // condition head
                BBlock* loopHeader = new BBlock;
                Jump jumpHeader = Jump(loopHeader->label);
                curr_block->Tacs.push_back(jumpHeader);
                curr_block->trueExit = loopHeader;
                curr_block = loopHeader;
                traverse_ast(root->children.front(), symbol_table);
                
                // body back
                BBlock* loopBody = new BBlock;
                loopHeader->trueExit = loopBody;
                curr_block = loopBody;
                traverse_ast(root->children.back(), symbol_table);
                curr_block->trueExit = loopHeader;
                Jump jumpBody = Jump(loopHeader->label);
                curr_block->Tacs.push_back(jumpBody);
                // loop exit
                BBlock* loopExit = new BBlock;
                loopHeader->falseExit = loopExit;
                curr_block = loopExit;

   
                Cond_jump cond_jump = Cond_jump(loopHeader->Tacs.back().res, loopExit->label);
                loopHeader->Tacs.push_back(cond_jump);




            } else if (root->type == "IF") {
                cout << "enter expression handling for "<< root->type << endl;
                int counter = 0;
                
                BBlock *headerblock, *trueBranch, *falseBranch, *exitBranch ;
                // Jump jumpHeader = Jump(headerblock->label);
                // curr_block->Tacs.push_back(jumpHeader);
                headerblock = curr_block;

                for(auto const& child : root->children)
                {
                    if(counter == 0) { // head
                        if (child->type == "boolExpression" || child->type == "IDENTIFIER" ) {
                            string lhs = child->value;
                            string rhs = "true";        
                            string op = "COMPARE";
                            res = genNameTAC();  
                            Expression tac = Expression(op, lhs, rhs, res);
                            headerblock->Tacs.push_back(tac);
                            cout << tac.dump() << endl;
                        } else {
                            traverse_ast(child, symbol_table);
                        }


                    } else if(counter == 1) { // true branch
                        
                        trueBranch = new BBlock;
                        curr_block->trueExit = trueBranch;
                        curr_block = trueBranch;
                        traverse_ast(child, symbol_table);
                        cout << "exit true branch" << endl;

                    } else if(counter == 2) { // false branch
                        
                        falseBranch = new BBlock;
                        headerblock->falseExit = falseBranch;
                        curr_block = falseBranch;
                        traverse_ast(child, symbol_table);
                        cout << "exit false branch" << endl;
                    }
                    counter++;
                }
                cout << "exit expression handling for "<< root->type << endl;
                exitBranch = new BBlock;
                cout << "true exits" << endl;
                trueBranch->trueExit = exitBranch;
                falseBranch->trueExit = exitBranch;
                
                curr_block = exitBranch;

                // conditions
                // header block
                Cond_jump cond_jump = Cond_jump(headerblock->Tacs.back().res, falseBranch->label);
                headerblock->Tacs.push_back(cond_jump);
                // true  & false block
                Jump jumpBody = Jump(exitBranch->label);
                trueBranch->Tacs.push_back(jumpBody);
                falseBranch->Tacs.push_back(jumpBody);

            }else if(root->type =="ARGUMENT") {
                if(root->children.front()->type == "INT" || root->children.front()->type == "boolExpression")
                {
                    res = "$" + root->children.front()->value;
                }
                else
                {
                    res = traverse_ast(root->children.front(), symbol_table);
                }

            } else {
                for(auto const& child : root->children)
                {
                   res = traverse_ast(child, symbol_table);


                }
            }


            return res;
        }


        // graph 
        std::set<std::string> generatedBBs;
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
            std::cout << "root block label: " << entryBlocks.front()->label << std::endl;
            //BBlock* ptr_block = test_bb_graph();
            //BBlock* ptr_block = &root_block;
            

            std::ofstream outStream;
            outStream.open("ir.dot");
            
            int count = 0;
            outStream << "digraph G {" << endl;
            outStream << "node [shape = box];" << endl;
            //outStream << "block_0 [label=\"block_0\"];" << endl;
            for(auto const& block : entryBlocks)
            {
                //BBlock* ptr_block = entryBlocks.front();
                generate_graph_bb(&outStream,  block);
            }
           

            //   Might need to add back later with a relation to the last bblock
            //string final_block_label = genNameBB();
            // outStream << final_block_label << " [label=\"" << final_block_label << "\"];" << endl;
           
            // outStream << "block_"<< counterBB << "[label = \"block_" << counterBB << "\"]" << endl;
            // outStream << "block_"<< counterBB-1  << " -> " << "block_"<< counterBB  << ";" << endl;
            outStream << "}" << endl;
            outStream.close();

            std::cout << "Generated IR graph" << endl;
            system("dot -Tpng ir.dot -o ir.png");


            return;
        }

        void generate_graph_bb(ofstream *outStream, BBlock *bb)
        {
            cout << "generate graph bb: "<< bb->label  << endl;
            generatedBBs.insert(bb->label);
            
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
                *outStream << bb->label << " -> " << bb->trueExit->label << " [ label=\"true\"]" << ";" << endl;
                if(bb->trueExit !=bb && generatedBBs.find(bb->trueExit->label) == generatedBBs.end() )
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
                *outStream << bb->label << " -> " << bb->falseExit->label  << " [ label=\"false\"]" << ";" << endl;
                generate_graph_bb(outStream, bb->falseExit);
            }

            return;
        }
};



class Instruction{
    int counter = 0;
    int id;
    string argument;

    public:
        Instruction(string argument)
        {
            this->id = counter;
            counter++;
            this->argument = argument;
        }
        string dump()
        {
            return argument;
        }
};

class Meth {
    vector<string*> variables;
    vector<Instruction*> instructions;

    public: 
        void put_variable(string* variable)
        {
            variables.push_back(variable);
        }
        string* pop_variable()
        {
            string* str = variables.back();
            variables.pop_back();
            return str;
        }
        void put_instruction(Instruction* instruction)
        {
           instructions.push_back(instruction);
        }
        Instruction* pop_instruction()
        {
            Instruction* i = instructions.back();
            instructions.pop_back();
            return i;
        }
        void dump_instructions()
        {
            std::ofstream outStream;
            outStream.open("bytecode.prgm");
            for(auto const& instruction : instructions)
            {
                outStream << instruction->dump() << endl;
            }
            outStream.close();
        }

};

class Program {
    public:
    Program() {
        cout << "Program constructor" << endl;
    };

    vector<Meth*> methods;

    Meth* pop_method() {
            Meth* m = methods.back();
            methods.pop_back();
            return m;
        }
    void push_method(Meth* m) {
            methods.push_back(m);
        }
    void dump_methods() {

            for(auto const& method : methods)
            {
                method->dump_instructions();
            }

        }

};

class Bytecode {
    vector<int> stack;
    Meth* new_meth;
    public:
        Program* prgm;
        Bytecode() {
            cout << "Bytecode constructor" << endl;
            this->prgm = new Program();
            this->new_meth = new Meth();
            prgm->methods.push_back(new_meth);
        };

        string parse_bool(string str) {
            if(str == "$true")
            {
                return "$1";
            } else if(str == "$false") {
                return "$0";
            } else {
                return "";
            }
        }



        void traverse_ir(BBlock* bb)
        {
            cout << "traverse ir" << endl;
            for(auto tac_in_block = bb->Tacs.begin(); tac_in_block != bb->Tacs.end(); tac_in_block++)
            {
                if (tac_in_block->lhs == "print")
                {
                    prgm->methods.back()->put_instruction(new Instruction("iload " + tac_in_block->op));
                    prgm->methods.back()->put_instruction(new Instruction("print"));
                    
                }else if (tac_in_block->op == "!") {
                    string rhs = parse_bool(tac_in_block->rhs);
                    prgm->methods.back()->put_instruction(new Instruction("iload " + rhs));
                    prgm->methods.back()->put_instruction(new Instruction("inot"));
                    // prgm->methods.back()->put_instruction(new Instruction("istore " + tac_in_block->res));
                } else if (tac_in_block->op == "MUL") {
                    prgm->methods.back()->put_instruction(new Instruction("iload " + tac_in_block->lhs));
                    prgm->methods.back()->put_instruction(new Instruction("iload " + tac_in_block->rhs));
                    prgm->methods.back()->put_instruction(new Instruction("imul"));
                    prgm->methods.back()->put_instruction(new Instruction("istore " + tac_in_block->res));
                } else if (tac_in_block->op == "SUB") {
                    prgm->methods.back()->put_instruction(new Instruction("iload " + tac_in_block->lhs));
                    prgm->methods.back()->put_instruction(new Instruction("iload " + tac_in_block->rhs));
                    prgm->methods.back()->put_instruction(new Instruction("isub"));
                    prgm->methods.back()->put_instruction(new Instruction("istore " + tac_in_block->res));
                } else if (tac_in_block->op == "ADD") {
                    prgm->methods.back()->put_instruction(new Instruction("iload " + tac_in_block->lhs));
                    prgm->methods.back()->put_instruction(new Instruction("iload " + tac_in_block->rhs));
                    prgm->methods.back()->put_instruction(new Instruction("iadd"));
                    prgm->methods.back()->put_instruction(new Instruction("istore " + tac_in_block->res));
                } else if (tac_in_block->op == "DIV") {
                    prgm->methods.back()->put_instruction(new Instruction("iload " + tac_in_block->lhs));
                    prgm->methods.back()->put_instruction(new Instruction("iload " + tac_in_block->rhs));
                    prgm->methods.back()->put_instruction(new Instruction("idiv"));
                    prgm->methods.back()->put_instruction(new Instruction("istore " + tac_in_block->res));
                } else if (tac_in_block->op == "AND") {
                    string lhs = parse_bool(tac_in_block->lhs);
                    string rhs = parse_bool(tac_in_block->rhs);
                    if(lhs != "") {
                        prgm->methods.back()->put_instruction(new Instruction("iload " + lhs));
                    }
                    if(rhs != "") {
                        prgm->methods.back()->put_instruction(new Instruction("iload " + rhs));
                    }
                    prgm->methods.back()->put_instruction(new Instruction("iand"));
                    prgm->methods.back()->put_instruction(new Instruction("istore " + tac_in_block->res));
                    prgm->methods.back()->put_instruction(new Instruction("iload " + tac_in_block->res));
                } else if (tac_in_block->op == "OR") {
                    string lhs = parse_bool(tac_in_block->lhs);
                    string rhs = parse_bool(tac_in_block->rhs);
                    if(lhs != "") {
                        prgm->methods.back()->put_instruction(new Instruction("iload " + lhs));
                    }
                    if(rhs != "") {
                        prgm->methods.back()->put_instruction(new Instruction("iload " + rhs));
                    }
                    prgm->methods.back()->put_instruction(new Instruction("ior"));
                    prgm->methods.back()->put_instruction(new Instruction("istore " + tac_in_block->res));
                    prgm->methods.back()->put_instruction(new Instruction("iload " + tac_in_block->res));
                } else if (tac_in_block->op == "LESS") {
                    prgm->methods.back()->put_instruction(new Instruction("iload " + tac_in_block->lhs));
                    prgm->methods.back()->put_instruction(new Instruction("iload " + tac_in_block->rhs));
                    prgm->methods.back()->put_instruction(new Instruction("ilt"));
                    prgm->methods.back()->put_instruction(new Instruction("istore " + tac_in_block->res));
                    prgm->methods.back()->put_instruction(new Instruction("iload " + tac_in_block->res));
                } else if (tac_in_block->op == "GREATER") {
                    prgm->methods.back()->put_instruction(new Instruction("iload " + tac_in_block->lhs));
                    prgm->methods.back()->put_instruction(new Instruction("iload " + tac_in_block->rhs));
                    prgm->methods.back()->put_instruction(new Instruction("igt"));
                    prgm->methods.back()->put_instruction(new Instruction("istore " + tac_in_block->res));
                    prgm->methods.back()->put_instruction(new Instruction("iload " + tac_in_block->res));
                } else if (tac_in_block->op == "COMPARE") {
                    string lhs = parse_bool(tac_in_block->lhs);
                    string rhs = parse_bool(tac_in_block->rhs);
                    if(lhs != "") {
                        prgm->methods.back()->put_instruction(new Instruction("iload " + lhs));
                    }
                    if(rhs != "") {
                        prgm->methods.back()->put_instruction(new Instruction("iload " + rhs));
                    }
                    prgm->methods.back()->put_instruction(new Instruction("ieq"));
                    prgm->methods.back()->put_instruction(new Instruction("istore " + tac_in_block->res));
                    prgm->methods.back()->put_instruction(new Instruction("iload " + tac_in_block->res));
                } 

            }

            if(bb->trueExit != NULL)
            {
                traverse_ir(bb->trueExit);
            }
            if(bb->falseExit != NULL)
            {
                traverse_ir(bb->falseExit);
            }
        }
};
