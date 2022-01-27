%top{
    // Put C code here
}
/* Variable / option start */
/* Variable / option end */
/* Regex */

%%

"int" {return(make_make_INT(yytext));}
"(" {return(make_L_PARENTHESE(yytext));}
")" {return(make_R_PARENTHESE(yytext));}
"!" {return(make_NOT(yytext));}
"new" {return(make_NEW(yytext));}
"[" {return(make_L_BRACKET(yytext));}
"]" {return(make_R_BRACKET(yytext));}
"this" {return(make_THIS(yytext));}
"false" {return(make_FALSE(yytext));}
"true" {return(make_TRUE(yytext));}
"." {return(make_DOT(yytext));}
"," {return(make_COMMA(yytext));}
"length" {return(make_length_OP(yytext));}
"-" {return(make_SUB(yytext));}
"*" {return(make_MUL(yytext));}
"/" {return(make_DIV(yytext));}
"+" {return(make_ADD(yytext));}
"==" {return(make_EQUAL_TO(yytext));}
"=" {return(make_EQUAL(yytext));}
"<" {return(make_LT_OP(yytext));}
">" {return(make_GT_OP(yytext));}
"||" {return(make_OR_OP(yytext));}
"&&" {return(make_AND_OP(yytext));}
"\\" {return(make_SEMICOLON(yytext));}
"System.out.printIn" {return(make_printIn(yytext));}
"While" {return(make_WHILE(yytext));}
"else" {return(make_ELSE(yytext));}
"{" {return(make_L_C_BRACKET(yytext));}
"}" {return(make_R_C_BRACKET(yytext));}
"boolean" {return(make_BOOLEAN(yytext));}
"return" {return(make_RETURN(yytext));}
"public" {return(make_PUBLIC(yytext));}
"extends" {return(make_EXTENDS(yytext));}
"class" {return(make_CLASS(yytext));}
"string" {return(make_STRING(yytext));}
"main" {return(make_MAIN(yytext));}
"void" {return(make_VOID(yytext));}
"static" {return(make_STATIC(yytext));}
<<EOF>> {return(make_EOF(yytext));}

%%
/* Pattern matching end */

/* C code start */


/* C code End */