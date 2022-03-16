compiler: lex.yy.c parser.tab.o main.cc semantic
		g++ -g -w -ocompiler parser.tab.o lex.yy.c main.cc -std=c++14
parser.tab.o: parser.tab.cc
		g++ -g -w -c parser.tab.cc -std=c++14
parser.tab.cc: parser.yy
		bison parser.yy
lex.yy.c: lexer.ll parser.tab.cc
		flex lexer.ll
tree:
		dot -Tpdf tree.dot -otree.pdf
# symbol_table: symbol_table.cpp
# 		g++ -g -w -c symbol_table.cpp -std=c++14
semantic: semantic.cpp
		g++ -g -w -c semantic.cpp -std=c++14
clean:
		rm -f parser.tab.* lex.yy.c* compiler stack.hh tree.dot tree.pdf
		rm -R compiler.dSYM

# symbol:
# 		g++ symbol_table.cpp -o symbol_table.exe -std=c++14

# compiler: lex.yy.c main.cc
# 		g++ -g -ocompiler lex.yy.c main.cc

# lex.yy.c: lexer.ll
# 		flex lexer.ll
# clean:
# 		rm -f lex.yy.c* compiler
# 		rm -R compiler.dSYM
