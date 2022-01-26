%top{ 
// c kod
#define YYSTYPE int
}
/*
Variabler /options


*/
%option noyywrap
%x STRING
%x NUMBERS

%% /* Pattern matching below */
[0-9]+             {printf("no math plz\n");}
[^"\n\r0-9]*           { printf("OTHER: %s\n",yytext);}    /* Any character */
["]              {BEGIN STRING;} /*Andra regler sluta gälla när vi går in i string*/
<STRING>["]      {BEGIN INITIAL;}
<STRING>[^"]*   {printf("STRING: %s\n", yytext);}

%% /* Pattern matching below */
((	| {4})(int\[[0-9]*\]|boolean|int){1}) /*Typ klart*/


//More C

