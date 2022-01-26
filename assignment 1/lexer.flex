%top{
    // Put C code here
}
/* Variable / option start */
/* Variable / option end */
/* Regex */

%%

"int" {return(yy::parser::make_yy::parser::make_INT);}
"(" {return(yy::parser::make_L_PARENTHESE);}
")" {return(yy::parser::make_R_PARENTHESE);}
"!" {return(yy::parser::make_NOT);}
"new" {return(yy::parser::make_NEW);}
"[" {return(yy::parser::make_L_BRACKET);}
"]" {return(yy::parser::make_R_BRACKET);}
"this" {return(yy::parser::make_THIS);}
"false" {return(yy::parser::make_FALSE);}
"true" {return(yy::parser::make_TRUE);}
"." {return(yy::parser::make_DOT);}
"," {return(yy::parser::make_COMMA);}
"length" {return(yy::parser::make_length_OP);}
"-" {return(yy::parser::make_SUB);}
"*" {return(yy::parser::make_MUL);}
"/" {return(yy::parser::make_DIV);}
"+" {return(yy::parser::make_ADD);}
"==" {return(yy::parser::make_EQUAL_TO);}
"=" {return(yy::parser::make_EQUAL);}
"<" {return(yy::parser::make_LT_OP);}
">" {return(yy::parser::make_GT_OP);}
"||" {return(yy::parser::make_OR_OP);}
"&&" {return(yy::parser::make_AND_OP);}
"\\" {return(yy::parser::make_SEMICOLON);}
"System.out.printIn" {return(yy::parser::make_printIn);}
"While" {return(yy::parser::make_WHILE);}
"else" {return(yy::parser::make_ELSE);}
"{" {return(yy::parser::make_L_C_BRACKET);}
"}" {return(yy::parser::make_R_C_BRACKET);}
"boolean" {return(yy::parser::make_BOOLEAN);}
"return" {return(yy::parser::make_RETURN);}
"public" {return(yy::parser::make_PUBLIC);}
"extends" {return(yy::parser::make_EXTENDS);}
"class" {return(yy::parser::make_CLASS);}
"string" {return(yy::parser::make_STRING);}
"main" {return(yy::parser::make_MAIN);}
"void" {return(yy::parser::make_VOID);}
"static" {return(yy::parser::make_STATIC);}
<<EOF>> {return(yy::parser::make_EOF);}

%%
/* Pattern matching end */

/* C code start */


/* C code End */