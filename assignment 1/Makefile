compiler: lex.yy.c parser.tab.o main.cc
		g++ -g -w -ocompiler parser.tab.o lex.yy.c main.cc -std=c++14
parser.tab.o: parser.tab.cc
		g++ -g -w -c parser.tab.clc -std=c++14
parser.tab.cc: parser.yy
		bison parser.yy
lex.yy.c: lexer.flex parser.tab.cc
		flex lexer.flex
tree: 
		 dot -Tpdf tree.dot -otree.pdf
clean:
		rm -f parser.tab.* lex.yy.c* compiler stack.hh tree.dot tree.pdf
		rm -R compiler.dSYM

# compiler: lex.yy.c 
# 		gcc -o compiler lex.yy.c main.c -ll

# parser.tab.cc: parser.y
# 		bison parser.y

# lex.yy.c:
# 		flex lexer.flex
		
# clean:
# 		rm -f lex.yy.c compilerasd