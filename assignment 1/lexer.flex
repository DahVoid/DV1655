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
<IDENTIFIER>[ 	\{ \[ \( ]+  {BEGIN INITIAL;}
<IDENTIFIER>[^ 	\{\} \[\] \(\) \n} \.]* {printf(" \n IDENTIFIER: %s\n", yytext);}


%%/* Pattern matching end */

/* C code start */


/* C code End */