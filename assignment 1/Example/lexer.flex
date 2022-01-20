%top{
#include "parser.tab.hh"
#define YY_DECL yy::parser::symbol_type yylex()
#include "Node.h"
}
%option noyywrap nounput batch noinput stack
%%

"+"                     {return yy::parser::make_PLUSOP(yytext);}
"*"                     {return yy::parser::make_MULTOP(yytext);}
"("                     {return yy::parser::make_LP(yytext);}
")"                     {return yy::parser::make_RP(yytext);}

0|[1-9][0-9]*           {return yy::parser::make_INT(yytext);}


[ \t\n]+                  {}

<<EOF>>                 return yy::parser::make_END();
%%