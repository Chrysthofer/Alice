%{
#include "parser.tab.h"
extern int yylineno; // Line number variable from Bison
%}

digit       [0-9]
letter      [a-zA-Z]
identifier  {letter}({letter}|{digit})*
number      {digit}+

%%

\n          { yylineno++; }
[ \t]       ; // Ignore spaces and tabs
"int"       { return INT; }
"return"    { return RETURN; }
"if"        { return IF; }
"else"      { return ELSE; }
"while"     { return WHILE; }
"for"       { return FOR; }
"+"         { return PLUS; }
"-"         { return MINUS; }
"*"         { return TIMES; }
"/"         { return DIVIDE; }
"="         { return ASSIGN; }
";"         { return SEMICOLON; }
"("         { return LPAREN; }
")"         { return RPAREN; }
"{"         { return LBRACE; }
"}"         { return RBRACE; }
"<"         { return LT; }
">"         { return GT; }
"<="        { return LE; }
">="        { return GE; }
"++"        { return PLUSPLUS; }
"--"        { return MINUSMINUS; }

{identifier} {
    yylval.sval = strdup(yytext);
    return IDENTIFIER;
}

{number}    {
    yylval.ival = atoi(yytext);
    return NUMBER;
}

[ \t\n]+    { /* skip whitespace */ }

.           { return yytext[0]; }
<<EOF>>     { return 0; }

%%

int yywrap() {
    return 1;
}
