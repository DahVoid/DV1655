%top{
#include "parser.tab.hh"
#define YY_DECL yy::parser::symbol_type yylex()
#include "Node.h"
}
%option noyywrap nounput batch noinput stack
%%

yy::parser::make_PLUSOP(yytext)
"int"                   {return yy::parser::make_INT(yytext);}
"if"                     {return yy::parser::make_IF(yytext);}
"("                     {return yy::parser::make_LP(yytext);}
")"                     {return yy::parser::make_RP(yytext);}
"!"                     {return yy::parser::make_ESX(yytext);}
"new"                   {return yy::parser::make_NEW(yytext);}
"["                     {return yy::parser::make_LB(yytext);}
"]"                     {return yy::parser::make_RB(yytext);}
"this"                  {return yy::parser::make_THIS(yytext);}
"false"                 {return yy::parser::make_FALSE(yytext);}
"true"                  {return yy::parser::make_TRUE(yytext);}
"."                     {return yy::parser::make_DOT(yytext);}
","                     {return yy::parser::make_COMMA(yytext);}
"length"                {return yy::parser::make_LENGTH(yytext);}
"-"                     {return yy::parser::make_SUB(yytext);}
"*"                     {return yy::parser::make_MUL(yytext);}
"/"                     {return yy::parser::make_DIV(yytext);}
"+"                     {return yy::parser::make_PLUS(yytext);}
"=="                    {return yy::parser::make_CMP(yytext);}
"="                     {return yy::parser::make_EQUAL(yytext);}
"<"                     {return yy::parser::make_LT(yytext);}
">"                     {return yy::parser::make_MT(yytext);}
"||"                    {return yy::parser::make_OR(yytext);}
"&&"                    {return yy::parser::make_AND(yytext);}
"\\"                    {return yy::parser::make_COMMENT(yytext);}
"System.out.println"    {return yy::parser::make_SYSTEMOUTPRINT(yytext);}
"While"                 {return yy::parser::make_WHILE(yytext);}
"else"                  {return yy::parser::make_ELSE(yytext);}
"{"                     {return yy::parser::make_LCB(yytext);}
"}"                     {return yy::parser::make_RCB(yytext);}
"boolean"               {return yy::parser::make_BOOLEAN(yytext);}
"return"                {return yy::parser::make_RETURN(yytext);}
"public"                {return yy::parser::make_PUBLIC(yytext);}
"extends"               {return yy::parser::make_EXTENDS(yytext);}
"class"                 {return yy::parser::make_CLASS(yytext);}
"String"                {return yy::parser::make_STRING(yytext);}
"main"                  {return yy::parser::make_MAIN(yytext);}
"void"                  {return yy::parser::make_VOID(yytext);}
"static"                {return yy::parser::make_STATIC(yytext);}
";"                     {return yy::parser::make_SEMICOLON(yytext);}
[0-9]+                  {return yy::parser::make_NUM(yytext);}
[A-Za-z0-9_]+           {return yy::parser::make_WORD(yytext);}
%%
/*<<EOF>>                 {printf("found EOF: %s \n", yytext);}*/