%{
  #include <stdio.h>

%}
%token INT L_PARENTHESE R_PARENTHESE NOT NEW L_BRACKET R_BRACKET THIS FALSE TRUE DOT COMMA length_OP SUB MUL DIV ADD EQUAL_TO EQUAL LT_OP GT_OP OR_OP AND_OP SEMICOLON printIn WHILE ELSE L_C_BRACKET R_C_BRACKET BOOLEAN RETURN PUBLIC EXTENDS CLASS STRING MAIN VOID STATIC 
%%
S   :  S E '\n' { printf("= %d\n", Top()); } 
    |
    ;
E   :  E E '+' { Push(Pop() + Pop()); }
    |  E E '-' { int op2 = Pop(); Push(Pop() - op2); }
    |  E E '*' { Push(Pop() * Pop()); }
    |  E E '/' { int op2 = Pop(); Push(Pop() / op2); }
    |  T_Int   { Push(yylval); }
    ;
%%
3 
static int stack[100], count = 0;
static int Pop() {
    assert(count > 0);
    return stack[--count];
}
static int Top() {
    assert(count > 0);
    return stack[count-1];
}
static void Push(int val) {
    assert(count < sizeof(stack)/sizeof(*stack));
    stack[count++] = val;
} 
int main() {
   return yyparse();
}