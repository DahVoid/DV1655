%top{
    // Put C code here
}
/* Variable / option start */
/* Variable / option end */
/* Regex */

%%

"int" {return(yy::parser::make_yy::parser::make_INT(yytext));}
"(" {return(yy::parser::make_L_PARENTHESE(yytext));}
")" {return(yy::parser::make_R_PARENTHESE(yytext));}
"!" {return(yy::parser::make_NOT(yytext));}
"new" {return(yy::parser::make_NEW(yytext));}
"[" {return(yy::parser::make_L_BRACKET(yytext));}
"]" {return(yy::parser::make_R_BRACKET(yytext));}
"this" {return(yy::parser::make_THIS(yytext));}
"false" {return(yy::parser::make_FALSE(yytext));}
"true" {return(yy::parser::make_TRUE(yytext));}
"." {return(yy::parser::make_DOT(yytext));}
"," {return(yy::parser::make_COMMA(yytext));}
"length" {return(yy::parser::make_length_OP(yytext));}
"-" {return(yy::parser::make_SUB(yytext));}
"*" {return(yy::parser::make_MUL(yytext));}
"/" {return(yy::parser::make_DIV(yytext));}
"+" {return(yy::parser::make_ADD(yytext));}
"==" {return(yy::parser::make_EQUAL_TO(yytext));}
"=" {return(yy::parser::make_EQUAL(yytext));}
"<" {return(yy::parser::make_LT_OP(yytext));}
">" {return(yy::parser::make_GT_OP(yytext));}
"||" {return(yy::parser::make_OR_OP(yytext));}
"&&" {return(yy::parser::make_AND_OP(yytext));}
"\\" {return(yy::parser::make_SEMICOLON(yytext));}
"System.out.printIn" {return(yy::parser::make_printIn(yytext));}
"While" {return(yy::parser::make_WHILE(yytext));}
"else" {return(yy::parser::make_ELSE(yytext));}
"{" {return(yy::parser::make_L_C_BRACKET(yytext));}
"}" {return(yy::parser::make_R_C_BRACKET(yytext));}
"boolean" {return(yy::parser::make_BOOLEAN(yytext));}
"return" {return(yy::parser::make_RETURN(yytext));}
"public" {return(yy::parser::make_PUBLIC(yytext));}
"extends" {return(yy::parser::make_EXTENDS(yytext));}
"class" {return(yy::parser::make_CLASS(yytext));}
"string" {return(yy::parser::make_STRING(yytext));}
"main" {return(yy::parser::make_MAIN(yytext));}
"void" {return(yy::parser::make_VOID(yytext));}
"static" {return(yy::parser::make_STATIC(yytext));}
<<EOF>> {return(yy::parser::make_EOF(yytext));}

%%
/* Pattern matching end */

/* C code start */


/* C code End */