lex lexer.flex
make clean
make
./compiler < tests/test_fac.txt