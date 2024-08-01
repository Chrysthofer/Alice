%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

extern int yylineno; // Line number from the lexer

void yyerror(const char *s);
int yylex(void);

void generate_code_from_ast(ASTNode *node);
%}

%code requires {
#include "ast.h"
}

%union {
    int ival;
    char *sval;
    ASTNode *node;
}

%token INT RETURN
%token PLUS MINUS TIMES DIVIDE ASSIGN SEMICOLON
%token LPAREN RPAREN LBRACE RBRACE
%token LT GT LE GE
%token <sval> IDENTIFIER
%token <ival> NUMBER

%type <node> program decls decl stmt expr

%%

program:
    decls { generate_code_from_ast($1); }
;

decls:
    decls decl { $$ = create_node(';', $1, $2, 0, NULL); }
    | /* empty */ { $$ = NULL; }
;

decl:
    INT IDENTIFIER SEMICOLON { $$ = create_node('D', NULL, NULL, 0, $2); }
    | INT IDENTIFIER ASSIGN expr SEMICOLON { $$ = create_node('=', NULL, $4, 0, $2); }
    | stmt { $$ = $1; }
;

stmt:
    IDENTIFIER ASSIGN expr SEMICOLON { $$ = create_node('=', NULL, $3, 0, $1); }
    | RETURN expr SEMICOLON { $$ = create_node('R', $2, NULL, 0, NULL); }
    | error SEMICOLON { yyerror("Syntax error in statement"); yyerrok; YYABORT; }
;

expr:
    expr PLUS expr { $$ = create_node('+', $1, $3, 0, NULL); }
    | expr MINUS expr { $$ = create_node('-', $1, $3, 0, NULL); }
    | expr TIMES expr { $$ = create_node('*', $1, $3, 0, NULL); }
    | expr DIVIDE expr { $$ = create_node('/', $1, $3, 0, NULL); }
    | expr LT expr { $$ = create_node('<', $1, $3, 0, NULL); }
    | expr GT expr { $$ = create_node('>', $1, $3, 0, NULL); }
    | expr LE expr { $$ = create_node(LE, $1, $3, 0, NULL); }
    | expr GE expr { $$ = create_node(GE, $1, $3, 0, NULL); }
    | IDENTIFIER { $$ = create_node('I', NULL, NULL, 0, $1); }
    | NUMBER { $$ = create_node('N', NULL, NULL, $1, NULL); }
    | LPAREN expr RPAREN { $$ = $2; }
    | error { yyerror("Syntax error in expression"); yyerrok; YYABORT; }
;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s at line %d\n", s, yylineno);
}

int main() {
    return yyparse();
}
