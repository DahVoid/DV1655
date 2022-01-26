%top{
    // Put C code here
    #define YYSTYPE int
}
/* Variable / option start */
%option noyywrap

/*
From lang spec, in order of dependence, least dependent to most dependent
 */
%x IDENTIFIER
%x EXPRESSION
%x STATEMENT
%x TYPE 
%x METHODDECLARATION
%x VARDECLARATION
%x CLASSDECLARATION
%x MAINCLASS
%x GOAL

/* Variable / option end */

%% /* Pattern matching start   */
[^A-Za-z0-9_]*           {BEGIN IDENTIFIER;}
<IDENTIFIER> [ 	\{ \[ \( ]+  {BEGIN INITIAL;}
<IDENTIFIER> [^ 	\{\} \[\] \(\) \n} \.]* {printf(" \n IDENTIFIER: %s\n", yytext);}

[^A-Za-z0-9_]*           {BEGIN TYPE;}
<TYPE> ((	| {4})(int\[[0-9]*\]|boolean|int){1})  {printf("\n TYPE %s\n", yytext); }/*Typ klart*/ 
<TYPE> [    ]*  {BEGIN INITIAL;}

[^A-Za-z0-9_]*           {BEGIN TYPE;}
<TYPE> <IDENTIFIER>   {printf("\n VARDECLARATION %s\n", yytext); } /* VARDECLARATION */
<VARDECLARATION> [;]*     {BEGIN INITIAL;}
%%/* Pattern matching end */


/* C code start */


/* C code End */