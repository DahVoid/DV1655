#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <fstream>


using namespace std;

class interpreter {
    stack<int> stk;
    struct instruction {
        string op;
        string arg;
    };

    queue<instruction> instructions;
    map<string, int> variables;
    void deserialize(string filename) {
        ifstream inFile;
        string word;
        inFile.open("bytecode.prgm");
        while (inFile >> word) {
            instruction inst;
            inst.op = word;
            if(word == "iload" || word == "istore") {
                inFile >> word;
                inst.arg = word;
            }
            instructions.push(inst);
        }
        inFile.close();
        
    }
   
    int getIntOrVar(string word) {
        if(word[0] == '$') {
            // is int
            word.erase(0,1);
            return stoi(word);
        } else {
            int val = variables[word];
            return val;
        }
    }

public:
    void interpret(string fileName) {
        deserialize(fileName);
        cout << "Interpreting..." << endl;
        while(!instructions.empty()) {
            instruction inst = instructions.front();
            instructions.pop();

            if(inst.op == "iload") {
                int var;
                // get variable from map
                var = getIntOrVar(inst.arg);
                // push variable to stk
                stk.push(var);
            } else if(inst.op == "istore") {
                int val = stk.top();
                stk.pop();
                // store variable in map
                variables[inst.arg] = val;
            } else if(inst.op == "iadd") {
                int v1 = stk.top();
                stk.pop();
                int v2 = stk.top();
                stk.pop();
                stk.push(v2 + v1);
            } else if(inst.op == "isub") {
                int v1 = stk.top();
                stk.pop();
                int v2 = stk.top();
                stk.pop();
                stk.push(v2 - v1);
            } else if(inst.op == "imul") {
                int v1 = stk.top();
                stk.pop();
                int v2 = stk.top();
                stk.pop();
                stk.push(v2 * v1);
            } else if(inst.op == "idiv") {
                int v1 = stk.top();
                stk.pop();
                int v2 = stk.top();
                stk.pop();
                stk.push(v2 / v1);
            } else if (inst.op == "ilt"){
                int v1 = stk.top();
                stk.pop();
                int v2 = stk.top();
                stk.pop();
                if (v2 < v1) {
                    stk.push(1);
                } else {
                    stk.push(0);
                }
            } else if (inst.op == "igt"){
                int v1 = stk.top();
                stk.pop();
                int v2 = stk.top();
                stk.pop();
                if (v2 > v1) {
                    stk.push(1);
                } else {
                    stk.push(0);
                }
            }else if(inst.op == "ieq") {
                int v1 = stk.top();
                stk.pop();
                int v2 = stk.top();
                stk.pop();
                if (v2 == v1) {
                    stk.push(1);
                } else {
                    stk.push(0);
                }
            } else if(inst.op == "iand") {
                int v1 = stk.top();
                stk.pop();
                int v2 = stk.top();
                stk.pop();
                if (v1 * v2 == 0) {
                    stk.push(0);
                } else {
                    stk.push(1);
                }
            } else if(inst.op == "ior") {
                int v1 = stk.top();
                stk.pop();
                int v2 = stk.top();
                stk.pop();
                if (v1 + v2 == 0) {
                    stk.push(0);
                } else {
                    stk.push(1);
                }
            } else if(inst.op == "inot") {
                int val = stk.top();
                stk.pop();
                if (val == 0) {
                    stk.push(1);
                } else {
                    stk.push(0);
                }
            } else if(inst.op == "print") {
                int val = stk.top();
                stk.pop();
                cout << val << endl;
            } else if(inst.op == "stop") {
                return;
            }
        }

    }
};