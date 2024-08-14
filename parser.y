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
    float fval;
    double dval;
    char *sval;
    ASTNode *node;
}

%token INT FLOAT VOID DOUBLE RETURN
%token TRUE FALSE
%token IF ELSE WHILE FOR
%token PLUS MINUS TIMES DIVIDE ASSIGN EQUAL SEMICOLON PLUSPLUS MINUSMINUS
%token LPAREN RPAREN LBRACE RBRACE COMMA
%token LT GT LE GE
%token <sval> IDENTIFIER
%token <ival> NUMBER
%token <fval> FLOAT_NUMBER
%token <dval> DOUBLE_NUMBER

%type <node> program decls decl func_decl params param_list param boolean_literal stmt stmt_list expr 

%%

program:
    decls { generate_code_from_ast($1); }
;

decls:
    decls decl    { $$ = create_node(';', $1, $2, NULL, NULL, 0, 0.0, 0.0, NULL); }
    | /* empty */ { $$ = NULL;                                             }
;

decl:
    INT IDENTIFIER SEMICOLON                  { $$ = create_node('D', NULL, NULL, NULL, NULL, 0, 0.0, 0.0, $2);  }
    | INT IDENTIFIER ASSIGN expr SEMICOLON    { $$ = create_node('=', NULL, $4, NULL, NULL, 0, 0.0, 0.0, $2);    }
    | FLOAT IDENTIFIER SEMICOLON              { $$ = create_node('D', NULL, NULL, NULL, NULL, 0, 0.0, 0.0, $2);  }
    | FLOAT IDENTIFIER ASSIGN expr SEMICOLON  { $$ = create_node('=', NULL, $4, NULL, NULL, 0, 0.0, 0.0, $2);    }
    | DOUBLE IDENTIFIER SEMICOLON             { $$ = create_node('D', NULL, NULL, NULL, NULL, 0, 0.0, 0.0, $2);  }
    | DOUBLE IDENTIFIER ASSIGN expr SEMICOLON { $$ = create_node('=', NULL, $4, NULL, NULL, 0, 0.0, 0.0, $2);    }
    | func_decl                               { $$ = $1;                                                         }
    | stmt                                    { $$ = $1;                                                         }
;

func_decl:
    INT IDENTIFIER LPAREN params RPAREN LBRACE stmt_list RBRACE     { $$ = create_node('FUNC', $4, $7, NULL, NULL, 0, 0.0, 0.0, $2); }
    | FLOAT IDENTIFIER LPAREN params RPAREN LBRACE stmt_list RBRACE { $$ = create_node('FUNC', $4, $7, NULL, NULL, 0, 0.0, 0.0, $2); }
    | VOID IDENTIFIER LPAREN params RPAREN LBRACE stmt_list RBRACE  { $$ = create_node('FUNC', $4, $7, NULL, NULL, 0, 0.0, 0.0, $2); }
;


params:
    param_list    { $$ = $1;  }
    | /* empty */ { $$ = NULL; }
;


param_list:
    param                    { $$ = $1;                                                      }
    | param_list COMMA param { $$ = create_node(',', $1, $3, NULL, NULL, 0, 0.0, 0.0, NULL); }
;

param:
    INT IDENTIFIER      { $$ = create_node('P', NULL, NULL, NULL, NULL, 0, 0.0, 0.0, $2); }
    | FLOAT IDENTIFIER  { $$ = create_node('P', NULL, NULL, NULL, NULL, 0, 0.0, 0.0, $2); }
    | DOUBLE IDENTIFIER { $$ = create_node('P', NULL, NULL, NULL, NULL, 0, 0.0, 0.0, $2); }
;

boolean_literal:
    TRUE    { $$ = create_node('B', NULL, NULL, NULL, NULL, 1, 0.0, 0.0, NULL); }
    | FALSE { $$ = create_node('B', NULL, NULL, NULL, NULL, 0, 0.0, 0.0, NULL); }
;

stmt:
    IDENTIFIER ASSIGN expr SEMICOLON                                             { $$ = create_node('=', NULL, $3, NULL, NULL, 0, 0.0, 0.0, $1);    }
    | IDENTIFIER ASSIGN expr                                                     { $$ = create_node('=', NULL, $3, NULL, NULL, 0, 0.0, 0.0, $1);    }
    | RETURN expr SEMICOLON                                                      { $$ = create_node('R', $2, NULL, NULL, NULL, 0, 0.0, 0.0, NULL);  }
    | IF LPAREN expr RPAREN LBRACE stmt_list RBRACE ELSE LBRACE stmt_list RBRACE { $$ = create_node('E', $3, $6, $10, NULL, 0, 0.0, 0.0, NULL);     }
    | IF LPAREN expr RPAREN LBRACE stmt_list RBRACE                              { $$ = create_node('IF', $3, $6, NULL, NULL, 0, 0.0, 0.0, NULL);   }
    | WHILE LPAREN expr RPAREN LBRACE stmt_list RBRACE                           { $$ = create_node('W', $3, $6, NULL, NULL, 0, 0.0, 0.0, NULL);    }
    | FOR LPAREN stmt expr SEMICOLON stmt RPAREN LBRACE stmt_list RBRACE         { $$ = create_node('F', $3, $4, $6, $9, 0, 0.0, 0.0, NULL);        }
    | IDENTIFIER PLUSPLUS SEMICOLON                                              { $$ = create_node('++', NULL, NULL, NULL, NULL, 0, 0.0, 0.0, $1); }
    | IDENTIFIER PLUSPLUS                                                        { $$ = create_node('++', NULL, NULL, NULL, NULL, 0, 0.0, 0.0, $1); }
    | IDENTIFIER MINUSMINUS SEMICOLON                                            { $$ = create_node('--', NULL, NULL, NULL, NULL, 0, 0.0, 0.0, $1); }
    | IDENTIFIER MINUSMINUS                                                      { $$ = create_node('--', NULL, NULL, NULL, NULL, 0, 0.0, 0.0, $1); }
    | error SEMICOLON                                                            { yyerror("Syntax error in statement"); yyerrok; YYABORT;          }
;

stmt_list:
    stmt             { $$ = $1;                                                 }
    | stmt_list stmt { $$ = create_node(';', $1, $2, NULL, NULL, 0, 0.0, 0.0, NULL); }

expr:
    expr PLUS expr              { $$ = create_node('+', $1, $3, NULL, NULL, 0, 0.0, 0.0, NULL);      }
    | expr MINUS expr           { $$ = create_node('-', $1, $3, NULL, NULL, 0, 0.0, 0.0, NULL);      }
    | expr TIMES expr           { $$ = create_node('*', $1, $3, NULL, NULL, 0, 0.0, 0.0, NULL);      }
    | expr DIVIDE expr          { $$ = create_node('/', $1, $3, NULL, NULL, 0, 0.0, 0.0, NULL);      }
    | expr LT expr              { $$ = create_node('<', $1, $3, NULL, NULL, 0, 0.0, 0.0, NULL);      }
    | expr GT expr              { $$ = create_node('>', $1, $3, NULL, NULL, 0, 0.0, 0.0, NULL);      }
    | expr LE expr              { $$ = create_node(LE, $1, $3, NULL, NULL, 0, 0.0, 0.0, NULL);       }
    | expr GE expr              { $$ = create_node(GE, $1, $3, NULL, NULL, 0, 0.0, 0.0, NULL);       }
    | IDENTIFIER EQUAL expr     { $$ = create_node('==', NULL, $3, NULL, NULL, 0, 0.0, 0.0, $1);     }
    | boolean_literal                                                                          
    | IDENTIFIER                { $$ = create_node('I', NULL, NULL, NULL, NULL, 0, 0.0, 0.0, $1);    }
    | NUMBER                    { $$ = create_node('N', NULL, NULL, NULL, NULL, $1, 0.0, 0.0, NULL); }
    | FLOAT_NUMBER              { $$ = create_node('FL', NULL, NULL, NULL, NULL, 0, $1, 0.0, NULL);  }
    | DOUBLE_NUMBER             { $$ = create_node('DB', NULL, NULL, NULL, NULL, 0, 0.0, $1, NULL);  }
    | LPAREN expr RPAREN        { $$ = $2;                                                           }
    | error                     { yyerror("Syntax error in expression"); yyerrok; YYABORT;           }
;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s at line %d\n", s, yylineno);
}
#ifndef INCLUDE_MAIN
int main() {
    return yyparse();
}
#endif