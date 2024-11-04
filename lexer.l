%{
#include "parser.tab.h"
#include "handle_include.c"
extern int yylineno; // Line number variable from Bison
extern FILE *yyin;
void handle_include(const char *filename); // Multiple files
%}

digit             [0-9]
letter            [a-zA-Z]
identifier        {letter}({letter}|{digit})*
int_number        -?{digit}+
double_number     {digit}*\.{digit}+([eE][+-]?{digit}+)?|{digit}+\.[{digit}]*[eE][+-]?{digit}+
float_number      [0-9]*\.[0-9]+([eE][+-]?[0-9]+)?
scientific_number [0-9]+(\.[0-9]*)?[eE][+-]?[0-9]+

%%

"#include"[ \t]*\"{identifier}.c\" {
    char filename[256];
    sscanf(yytext, "#include \"%[^\"]\"", filename);
    handle_include(filename);
}

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
"in"        { return IN;         }
"out"       { return OUT;        }
"true"      { return TRUE;       }
"false"     { return FALSE;      }
"&&"        { return AND;        }
"||"        { return OR;         }
"^"         { return XOR;        }
"/>"        { return NORM;       }
"+"         { return PLUS;       }
"-"         { return MINUS;      }
"*"         { return TIMES;      }
"/"         { return DIVIDE;     }
"%"         { return MODULUS;    }
"="         { return ASSIGN;     }
"=="        { return EQUAL;      }
"!="        { return DIF;        }
";"         { return SEMICOLON;  }
","         { return COMMA;      }
"("         { return LPAREN;     }
")"         { return RPAREN;     }
"{"         { return LBRACE;     }
"}"         { return RBRACE;     }
"["         { return LBRACKET;   }
"]"         { return RBRACKET;   }
"<"         { return LT;         }
">"         { return GT;         }
"<="        { return LE;         }
">="        { return GE;         }
"++"        { return PLUSPLUS;   }
"--"        { return MINUSMINUS; }

{identifier} {
    printf("Recognized id: %s\n", yytext);  // Debugging output
    yylval.sval = strdup(yytext);
    return IDENTIFIER;
}

{double_number} {
    printf("Recognized double: %s\n", yytext);  // Debugging output
    yylval.dval = atof(yytext);
    return DOUBLE_NUMBER;
}

{float_number} {
    printf("Recognized float: %s\n", yytext);  // Debugging output
    yylval.fval = atof(yytext);
    return FLOAT_NUMBER;
}

{scientific_number} {
    yylval.fval = atof(yytext);
    return FLOAT_NUMBER;
}

{int_number}    {
    printf("Recognized int: %s\n", yytext);  // Debugging output
    yylval.ival = atoi(yytext);
    return INT_NUMBER;
}

[ \t\n]+    { /* skip whitespace */ }

.           { return yytext[0]; }
<<EOF>>     { return 0; }

%%

int yywrap() {
    return 1;
}
