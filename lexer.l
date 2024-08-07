%{
#include "parser.tab.h"
extern int yylineno; // Line number variable from Bison
%}

digit             [0-9]
letter            [a-zA-Z]
identifier        {letter}({letter}|{digit})*
number            {digit}+
double_number     {digit}*\.{digit}+([eE][+-]?{digit}+)?|{digit}+\.[{digit}]*[eE][+-]?{digit}+
float_number      [0-9]*\.[0-9]+([eE][+-]?[0-9]+)?
scientific_number [0-9]+(\.[0-9]*)?[eE][+-]?[0-9]+

%%

\n          { yylineno++;        }
"//".*               ; 
"/*"([^*]|\*+[^/])*\*+"/"   ;
[ \t]       ; // Ignore spaces and tabs
"int"       { return INT;        }
"float"     { return FLOAT;      }
"double"    { return DOUBLE;     }
"return"    { return RETURN;     }
"if"        { return IF;         }
"else"      { return ELSE;       }
"while"     { return WHILE;      }
"for"       { return FOR;        }
"true"      { return TRUE;       }
"false"     { return FALSE;      }
"+"         { return PLUS;       }
"-"         { return MINUS;      }
"*"         { return TIMES;      }
"/"         { return DIVIDE;     }
"="         { return ASSIGN;     }
";"         { return SEMICOLON;  }
"("         { return LPAREN;     }
")"         { return RPAREN;     }
"{"         { return LBRACE;     }
"}"         { return RBRACE;     }
"<"         { return LT;         }
">"         { return GT;         }
"<="        { return LE;         }
">="        { return GE;         }
"++"        { return PLUSPLUS;   }
"--"        { return MINUSMINUS; }

{identifier} {
    yylval.sval = strdup(yytext);
    return IDENTIFIER;
}

{double_number} {
    yylval.dval = atof(yytext);
    return DOUBLE_NUMBER;
}

{float_number} {
    yylval.fval = atof(yytext);
    return FLOAT_NUMBER;
}

{scientific_number} {
    yylval.fval = atof(yytext);
    return FLOAT_NUMBER;
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
