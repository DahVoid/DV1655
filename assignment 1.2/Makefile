compiler: lex.yy.c parser.tab.o main.cc
		g++ -g -w -ocompiler parser.tab.o lex.yy.c main.cc -std=c++14
parser.tab.o: parser.tab.cc
		g++ -g -w -c parser.tab.cc -std=c++14
parser.tab.cc: parser.yy
		bison parser.yy
lex.yy.c: lexer.ll parser.tab.cc
		flex lexer.ll
# tree: 
# 		 dot -Tpdf tree.dot -otree.pdf
clean:
		rm -f parser.tab.* lex.yy.c* compiler stack.hh tree.dot tree.pdf
		rm -R compiler.dSYM



# compiler: lex.yy.c main.cc
# 		g++ -g -ocompiler lex.yy.c main.cc

# lex.yy.c: lexer.ll
# 		flex lexer.ll
# clean:
# 		rm -f lex.yy.c* compiler
# 		rm -R compiler.dSYM

