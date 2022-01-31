%top{
#include "parser.tab.hh"
#define YY_DECL yy::parser::symbol_type yylex()
#include "Node.h"
}
%option noyywrap nounput batch noinput stack
%%

yy::parser::make_PLUSOP(yytext)
"int"                   {cout << "input: "<< yytext << " TOKEN: " << "INT" << endl; return yy::parser::make_INT(yytext);}
"if"                     {cout << "input: "<< yytext << " TOKEN: " << "IF" << endl; return yy::parser::make_IF(yytext);}
"("                     {cout << "input: "<< yytext << " TOKEN: " << "LP" << endl; return yy::parser::make_LP(yytext);}
")"                     {cout << "input: "<< yytext << " TOKEN: " << "RP" << endl; return yy::parser::make_RP(yytext);}
"!"                     {cout << "input: "<< yytext << " TOKEN: " << "ESX" << endl; return yy::parser::make_ESX(yytext);}
"new"                   {cout << "input: "<< yytext << " TOKEN: " << "NEW" << endl; return yy::parser::make_NEW(yytext);}
"["                     {cout << "input: "<< yytext << " TOKEN: " << "LB" << endl; return yy::parser::make_LB(yytext);}
"]"                     {cout << "input: "<< yytext << " TOKEN: " << "RB" << endl; return yy::parser::make_RB(yytext);}
"this"                  {cout << "input: "<< yytext << " TOKEN: " << "THIS" << endl; return yy::parser::make_THIS(yytext);}
"false"                 {cout << "input: "<< yytext << " TOKEN: " << "FALSE" << endl; return yy::parser::make_FALSE(yytext);}
"true"                  {cout << "input: "<< yytext << " TOKEN: " << "TRUE" << endl; return yy::parser::make_TRUE(yytext);}
"."                     {cout << "input: "<< yytext << " TOKEN: " << "DOT" << endl; return yy::parser::make_DOT(yytext);}
","                     {cout << "input: "<< yytext << " TOKEN: " << "COMMA" << endl; return yy::parser::make_COMMA(yytext);}
"length"                {cout << "input: "<< yytext << " TOKEN: " << "LENGTH" << endl; return yy::parser::make_LENGTH(yytext);}
"-"                     {cout << "input: "<< yytext << " TOKEN: " << "SUB" << endl; return yy::parser::make_SUB(yytext);}
"*"                     {cout << "input: "<< yytext << " TOKEN: " << "MUL" << endl; return yy::parser::make_MUL(yytext);}
"/"                     {cout << "input: "<< yytext << " TOKEN: " << "DIV" << endl; return yy::parser::make_DIV(yytext);}
"+"                     {cout << "input: "<< yytext << " TOKEN: " << "ADD" << endl; return yy::parser::make_PLUS(yytext);}
"=="                    {cout << "input: "<< yytext << " TOKEN: " << "CMP" << endl; return yy::parser::make_CMP(yytext);}
"="                     {cout << "input: "<< yytext << " TOKEN: " << "EQUAL" << endl; return yy::parser::make_EQUAL(yytext);}
"<"                     {cout << "input: "<< yytext << " TOKEN: " << "LT" << endl; return yy::parser::make_LT(yytext);}
">"                     {cout << "input: "<< yytext << " TOKEN: " << "MT" << endl; return yy::parser::make_MT(yytext);}
"||"                    {cout << "input: "<< yytext << " TOKEN: " << "OR" << endl; return yy::parser::make_OR(yytext);}
"&&"                    {cout << "input: "<< yytext << " TOKEN: " << "AND" << endl; return yy::parser::make_AND(yytext);}
"\\"                    {cout << "input: "<< yytext << " TOKEN: " << "COMMENT" << endl; return yy::parser::make_COMMENT(yytext);}
"System.out.println"    {cout << "input: "<< yytext << " TOKEN: " << "SYSTEMOUTPRINT" << endl; return yy::parser::make_SYSTEMOUTPRINT(yytext);}
"While"                 {cout << "input: "<< yytext << " TOKEN: " << "WHILE" << endl; return yy::parser::make_WHILE(yytext);}
"else"                  {cout << "input: "<< yytext << " TOKEN: " << "ELSE" << endl; return yy::parser::make_ELSE(yytext);}
"{"                     {cout << "input: "<< yytext << " TOKEN: " << "LCB" << endl; return yy::parser::make_LCB(yytext);}
"}"                     {cout << "input: "<< yytext << " TOKEN: " << "RCB" << endl; return yy::parser::make_RCB(yytext);}
"boolean"               {cout << "input: "<< yytext << " TOKEN: " << "BOOLEAN" << endl; return yy::parser::make_BOOLEAN(yytext);}
"return"                {cout << "input: "<< yytext << " TOKEN: " << "RETURN" << endl; return yy::parser::make_RETURN(yytext);}
"public"                {cout << "input: "<< yytext << " TOKEN: " << "PUBLIC" << endl; return yy::parser::make_PUBLIC(yytext);}
"extends"               {cout << "input: "<< yytext << " TOKEN: " << "EXTENDS" << endl; return yy::parser::make_EXTENDS(yytext);}
"class"                 {cout << "input: "<< yytext << " TOKEN: " << "CLASS" << endl; return yy::parser::make_CLASS(yytext);}
"String"                {cout << "input: "<< yytext << " TOKEN: " << "STRING" << endl; return yy::parser::make_STRING(yytext);}
"main"                  {cout << "input: "<< yytext << " TOKEN: " << "MAIN" << endl; return yy::parser::make_MAIN(yytext);}
"void"                  {cout << "input: "<< yytext << " TOKEN: " << "VOID" << endl; return yy::parser::make_VOID(yytext);}
"static"                {cout << "input: "<< yytext << " TOKEN: " << "STATIC" << endl; return yy::parser::make_STATIC(yytext);}
";"                     {cout << "input: "<< yytext << " TOKEN: " << "SEMICOLON" << endl; return yy::parser::make_SEMICOLON(yytext);}
[0-9]+                  {cout << "input: "<< yytext << " TOKEN: " << "NUM" << endl; return yy::parser::make_NUM(yytext);}
[A-Za-z0-9_]+           {cout << "input: "<< yytext << " TOKEN: " << "WORD" << endl; return yy::parser::make_WORD(yytext);}
<<EOF>>                 {return yy::parser::make_END();}
%%
