%top{
#include "parser.tab.hh"
#define YY_DECL yy::parser::symbol_type yylex()
#include "Node.h"
}
%option noyywrap nounput batch noinput stack

%%
([0-9])+    {return(NUM);}
"int"       {return(INT);}
"("         {return(L_PARENTHESE);}
")"         {return(R_PARENTHESE);}
"!" {return(NOT);}
"new" {return(NEW);}
"[" {return(L_BRACKET);}
"]" {return(R_BRACKET);}
"this" {return(THIS);}
"false" {returnFALSE);}
"true" {return(TRUE);}
"." {return(DOT);}
"," {return(COMMA);}
"length" {return(length_OP);}
"-" {return(SUB);}
"*" {return(MUL);}
"/" {return(DIV);}
"+" {return(ADD);}
"==" {return(EQUAL_TO);}
"=" {return(EQUAL);}
"<" {return(LT_OP);}
">" {return(GT_OP);}
"||" {return(OR_OP);}
"&&" {return(AND_OP);}
"\\" {return(SEMICOLON);}
"System.out.printIn" {return(printIn);}
"While" {return(WHILE);}
"else" {return(ELSE);}
"{" {return(L_C_BRACKET);}
"}" {return(R_C_BRACKET);}
"boolean" {return(BOOLEAN);}
"return" {return(RETURN);}
"public" {return(PUBLIC);}
"extends" {return(EXTENDS);}
"class" {return(CLASS);}
"string" {return(STRING);}
"main" {return(MAIN);}
"void" {return(VOID);}
"static" {return(STATIC);}
<<EOF>> {return(EOF);}

%%
/* Pattern matching end */

/* C code start */


/* C code End */