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

%token INT FLOAT /*VOID*/ DOUBLE RETURN
%token TRUE FALSE AND OR XOR NORM
%token IF ELSE WHILE FOR
%token PLUS MINUS TIMES DIVIDE MODULUS ASSIGN EQUAL DIF SEMICOLON PLUSPLUS MINUSMINUS
%token LPAREN RPAREN LBRACE RBRACE LBRACKET RBRACKET COMMA
%token LT GT LE GE
%token IN OUT
%token <sval> IDENTIFIER
%token <ival> NUMBER
%token <fval> FLOAT_NUMBER
%token <dval> DOUBLE_NUMBER

%type <node> program decls decl /*func_decl params param_list param*/ boolean_literal stmt stmt_list expr 

%right COMMA

%left OR
%left XOR
%left AND
%left EQUAL
%left LT GT LE GE
%left PLUS MINUS
%left TIMES DIVIDE

%%

program:
    decls { $$ = create_node('RTN', $1, NULL, NULL, NULL, 0, 0.0, 0.0, NULL); generate_code_from_ast($$); }
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
//  | func_decl                               { $$ = $1;                                                         }
    | stmt                                    { $$ = $1;                                                         }
;

/*

func_decl:
    INT IDENTIFIER LPAREN params RPAREN LBRACE stmt_list RBRACE     { $$ = create_node('FUNC', $4, $7, NULL, NULL, 0, 0.0, 0.0, $2); }
    | FLOAT IDENTIFIER LPAREN params RPAREN LBRACE stmt_list RBRACE { $$ = create_node('FUNC', $4, $7, NULL, NULL, 0, 0.0, 0.0, $2); }
    | VOID IDENTIFIER LPAREN params RPAREN LBRACE stmt_list RBRACE  { $$ = create_node('FUNC', $4, $7, NULL, NULL, 0, 0.0, 0.0, $2); }
;

*/

//params:
//    param_list    { $$ = $1;  }
//    | /* empty */ { $$ = NULL; }
//;

/*
param_list:
    param                    { $$ = $1;                                                      }
    | param_list COMMA param { $$ = create_node(',', $1, $3, NULL, NULL, 0, 0.0, 0.0, NULL); }
;

param:
    INT IDENTIFIER      { $$ = create_node('P', NULL, NULL, NULL, NULL, 0, 0.0, 0.0, $2); }
    | FLOAT IDENTIFIER  { $$ = create_node('P', NULL, NULL, NULL, NULL, 0, 0.0, 0.0, $2); }
    | DOUBLE IDENTIFIER { $$ = create_node('P', NULL, NULL, NULL, NULL, 0, 0.0, 0.0, $2); }
;

*/

boolean_literal:
    TRUE    { $$ = create_node('B', NULL, NULL, NULL, NULL, 1, 0.0, 0.0, NULL); }
    | FALSE { $$ = create_node('B', NULL, NULL, NULL, NULL, 0, 0.0, 0.0, NULL); }
;

stmt:
    IDENTIFIER ASSIGN expr SEMICOLON                                             { $$ = create_node('=', NULL, $3, NULL, NULL, 0, 0.0, 0.0, $1);     }
    | IDENTIFIER ASSIGN expr                                                     { $$ = create_node('=', NULL, $3, NULL, NULL, 0, 0.0, 0.0, $1);     }
    | RETURN expr SEMICOLON                                                      { $$ = create_node('R', $2, NULL, NULL, NULL, 0, 0.0, 0.0, NULL);   }
    | IF LPAREN expr RPAREN LBRACE stmt_list RBRACE ELSE LBRACE stmt_list RBRACE { $$ = create_node('E', $3, $6, $10, NULL, 0, 0.0, 0.0, NULL);      }
    | IF LPAREN expr RPAREN LBRACE stmt_list RBRACE                              { $$ = create_node('IF', $3, $6, NULL, NULL, 0, 0.0, 0.0, NULL);    }
    | WHILE LPAREN expr RPAREN LBRACE stmt_list RBRACE                           { $$ = create_node('W', $3, $6, NULL, NULL, 0, 0.0, 0.0, NULL);     }
    | FOR LPAREN stmt expr SEMICOLON stmt RPAREN LBRACE stmt_list RBRACE         { $$ = create_node('F', $3, $4, $6, $9, 0, 0.0, 0.0, NULL);         }
    | OUT LPAREN expr COMMA expr RPAREN SEMICOLON                                { $$ = create_node('OUT', $3, $5, NULL, NULL, 0, 0.0, 0.0, NULL);   }
    | IN LPAREN expr RPAREN SEMICOLON                                            { $$ = create_node('IN', $3, NULL, NULL, NULL, 0, 0.0, 0.0, NULL);  }
    | IDENTIFIER PLUSPLUS SEMICOLON                                              { $$ = create_node('++', NULL, NULL, NULL, NULL, 0, 0.0, 0.0, $1);  }
    | IDENTIFIER PLUSPLUS                                                        { $$ = create_node('++', NULL, NULL, NULL, NULL, 0, 0.0, 0.0, $1);  }
    | IDENTIFIER MINUSMINUS SEMICOLON                                            { $$ = create_node('--', NULL, NULL, NULL, NULL, 0, 0.0, 0.0, $1);  }
    | IDENTIFIER MINUSMINUS                                                      { $$ = create_node('--', NULL, NULL, NULL, NULL, 0, 0.0, 0.0, $1);  }
    | INT IDENTIFIER LBRACKET RBRACKET EQUAL LBRACE expr RBRACE SEMICOLON        { $$ = create_node('ARA', $7, NULL, NULL, NULL, 0, 0.0, 0.0, $2);   }
    | FLOAT IDENTIFIER LBRACKET RBRACKET EQUAL LBRACE expr RBRACE SEMICOLON      { $$ = create_node('ARA', $7, NULL, NULL, NULL, 0, 0.0, 0.0, $2);   }
    | error SEMICOLON                                                            { yyerror("Syntax error in statement"); yyerrok; YYABORT;           }
;

stmt_list:
    stmt             { $$ = $1;                                                      }
    | stmt_list stmt { $$ = create_node(';', $1, $2, NULL, NULL, 0, 0.0, 0.0, NULL); }

expr:
    expr PLUS expr                                { $$ = create_node('+', $1, $3, NULL, NULL, 0, 0.0, 0.0, NULL);      }
    | expr MINUS expr                             { $$ = create_node('-', $1, $3, NULL, NULL, 0, 0.0, 0.0, NULL);      }
    | expr TIMES expr                             { $$ = create_node('*', $1, $3, NULL, NULL, 0, 0.0, 0.0, NULL);      }
    | expr DIVIDE expr                            { $$ = create_node('/', $1, $3, NULL, NULL, 0, 0.0, 0.0, NULL);      }
    | expr MODULUS expr                           { $$ = create_node('%', $1, $3, NULL, NULL, 0, 0.0, 0.0, NULL);      }
    | expr LT expr                                { $$ = create_node('<', $1, $3, NULL, NULL, 0, 0.0, 0.0, NULL);      }
    | expr GT expr                                { $$ = create_node('>', $1, $3, NULL, NULL, 0, 0.0, 0.0, NULL);      }
    | expr LE expr                                { $$ = create_node(LE, $1, $3, NULL, NULL, 0, 0.0, 0.0, NULL);       }
    | expr GE expr                                { $$ = create_node(GE, $1, $3, NULL, NULL, 0, 0.0, 0.0, NULL);       }
    | expr AND expr                               { $$ = create_node('&&', $1, $3, NULL, NULL, 0, 0.0, 0.0, NULL);     }
    | expr OR expr                                { $$ = create_node('||', $1, $3, NULL, NULL, 0, 0.0, 0.0, NULL);     }
    | expr XOR expr                               { $$ = create_node('^', $1, $3, NULL, NULL, 0, 0.0, 0.0, NULL);      }
    | expr COMMA                                  { $$ = $1;                                                           }
    | IDENTIFIER EQUAL expr                       { $$ = create_node('EQU', NULL, $3, NULL, NULL, 0, 0.0, 0.0, $1);    }
    | expr DIF expr                               { $$ = create_node('DIF', $1, $3, NULL, NULL, 0, 0.0, 0.0, NULL);    } 
    | expr EQUAL expr                             { $$ = create_node('SEQU', $1, $3, NULL, NULL, 0, 0.0, 0.0, NULL);   }
    | boolean_literal                                                                                                   
    | IDENTIFIER                                  { $$ = create_node('I', NULL, NULL, NULL, NULL, 0, 0.0, 0.0, $1);    }
    | NUMBER                                      { $$ = create_node('N', NULL, NULL, NULL, NULL, $1, 0.0, 0.0, NULL); }
    | FLOAT_NUMBER                                { $$ = create_node('FL', NULL, NULL, NULL, NULL, 0, $1, 0.0, NULL);  }
    | DOUBLE_NUMBER                               { $$ = create_node('DB', NULL, NULL, NULL, NULL, 0, 0.0, $1, NULL);  }
    | LPAREN expr RPAREN                          { $$ = $2;                                                           }
    | IN LPAREN expr RPAREN                       { $$ = create_node('IN', $3, NULL, NULL, NULL, 0, 0.0, 0.0, NULL);   }
    | NORM expr                                   { $$ = create_node('/>', $2, NULL, NULL, NULL, 0, 0.0, 0.0, NULL);   }
    | error                                       { yyerror("Syntax error in expression"); yyerrok; YYABORT;           }
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