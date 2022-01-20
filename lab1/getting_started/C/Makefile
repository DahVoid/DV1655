compiler: lex.yy.c 
		gcc -ocompiler lex.yy.c main.c -ll
lex.yy.c:
		flex lexer.flex
clean:
		rm -f lex.yy.c compiler