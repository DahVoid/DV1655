compiler: lex.yy.c main.cc
		g++ -g -ocompiler lex.yy.c main.cc

lex.yy.c: lexer.ll
		flex lexer.ll
clean:
		rm -f lex.yy.c* compiler
		rm -R compiler.dSYM