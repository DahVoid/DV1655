%top{
#include "parser.tab.hh"
#define YY_DECL yy::parser::symbol_type yylex()
#include "Node.h"
}
%option noyywrap nounput batch noinput stack
%%

"int"    {printf(yytext + "\n");}
"("      {printf(yytext + "\n");}
")"      {printf(yytext + "\n");}
"!"      {printf(yytext + "\n");}
"new"    {printf(yytext + "\n");}
"["      {printf(yytext + "\n");}
"]"      {printf(yytext + "\n");}
"this"   {printf(yytext + "\n");}
"false"  {printf(yytext + "\n");}
"true"   {printf(yytext + "\n");}
"."      {printf(yytext + "\n");}
","      {printf(yytext + "\n");}
"length" {printf(yytext + "\n");}
"-"      {printf(yytext + "\n");}
"*"      {printf(yytext + "\n");}
"/"      {printf(yytext + "\n");}
"+"      {printf(yytext + "\n");}
"=="     {printf(yytext + "\n");}
"=" {printf(yytext + "\n");}
"<" {printf(yytext + "\n");}
">" {printf(yytext + "\n");}
"||" {printf(yytext + "\n");}
"&&" {printf(yytext + "\n");}
"\\" {printf(yytext + "\n");}
"System.out.printIn" {printf(yytext + "\n");}
"While" {printf(yytext + "\n");}
"else" {printf(yytext + "\n");}
"{" {printf(yytext + "\n");}
"}" {printf(yytext + "\n");}
"boolean" {printf(yytext + "\n");}
"return" {printf(yytext + "\n");}
"public" {printf(yytext + "\n");}
"extends" {printf(yytext + "\n");}
"class" {printf(yytext + "\n");}
"string" {printf(yytext + "\n");}
"main" {printf(yytext + "\n");}
"void" {printf(yytext + "\n");}
"static" {printf(yytext + "\n");}
<<EOF>> {printf(yytext + "\n");}
%%