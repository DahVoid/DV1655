%top{
/* #include "parser.tab.hh"
#define YY_DECL yy::parser::symbol_type yylex()
#include "Node.h" */
}
%option noyywrap nounput batch noinput stack
%%

"int"                   {printf("found: %s \n", yytext);}
"("                     {printf("found: %s \n", yytext);}
")"                     {printf("found: %s \n", yytext);}
"!"                     {printf("found: %s \n", yytext);}
"new"                   {printf("found: %s \n", yytext);}
"["                     {printf("found: %s \n", yytext);}
"]"                     {printf("found: %s \n", yytext);}
"this"                  {printf("found: %s \n", yytext);}
"false"                 {printf("found: %s \n", yytext);}
"true"                  {printf("found: %s \n", yytext);}
"."                     {printf("found: %s \n", yytext);}
","                     {printf("found: %s \n", yytext);}
"length"                {printf("found: %s \n", yytext);}
"-"                     {printf("found: %s \n", yytext);}
"*"                     {printf("found: %s \n", yytext);}
"/"                     {printf("found: %s \n", yytext);}
"+"                     {printf("found: %s \n", yytext);}
"=="                    {printf("found: %s \n", yytext);}
"="                     {printf("found: %s \n", yytext);}
"<"                     {printf("found: %s \n", yytext);}
">"                     {printf("found: %s \n", yytext);}
"||"                    {printf("found: %s \n", yytext);}
"&&"                    {printf("found: %s \n", yytext);}
"\\"                    {printf("found: %s \n", yytext);}
"System.out.println"    {printf("found: %s \n", yytext);}
"While"                 {printf("found: %s \n", yytext);}
"else"                  {printf("found: %s \n", yytext);}
"{"                     {printf("found: %s \n", yytext);}
"}"                     {printf("found: %s \n", yytext);}
"boolean"               {printf("found: %s \n", yytext);}
"return"                {printf("found: %s \n", yytext);}
"public"                {printf("found: %s \n", yytext);}
"extends"               {printf("found: %s \n", yytext);}
"class"                 {printf("found: %s \n", yytext);}
"String"                {printf("found: %s \n", yytext);}
"main"                  {printf("found: %s \n", yytext);}
"void"                  {printf("found: %s \n", yytext);}
"static"                {printf("found: %s \n", yytext);}
";"                     {printf("found: %s \n", yytext);}
[0-9]+                  {printf("found: %s \n", yytext);}
[A-Za-z0-9_]+           {printf("word: %s \n", yytext);}

%%
/*<<EOF>>                 {printf("found EOF: %s \n", yytext);}*/