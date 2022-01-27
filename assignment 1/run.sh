lex lexer.flex
bison parser.yy
make clean
make
./compiler < tests/test_fac.txt