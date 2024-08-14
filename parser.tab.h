/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2006, 2009-2010 Free Software
   Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* "%code requires" blocks.  */

/* Line 1685 of yacc.c  */
#line 15 "parser.y"

#include "ast.h"



/* Line 1685 of yacc.c  */
#line 45 "parser.tab.h"

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT = 258,
     FLOAT = 259,
     VOID = 260,
     DOUBLE = 261,
     RETURN = 262,
     TRUE = 263,
     FALSE = 264,
     IF = 265,
     ELSE = 266,
     WHILE = 267,
     FOR = 268,
     PLUS = 269,
     MINUS = 270,
     TIMES = 271,
     DIVIDE = 272,
     ASSIGN = 273,
     EQUAL = 274,
     SEMICOLON = 275,
     PLUSPLUS = 276,
     MINUSMINUS = 277,
     LPAREN = 278,
     RPAREN = 279,
     LBRACE = 280,
     RBRACE = 281,
     COMMA = 282,
     LT = 283,
     GT = 284,
     LE = 285,
     GE = 286,
     IDENTIFIER = 287,
     NUMBER = 288,
     FLOAT_NUMBER = 289,
     DOUBLE_NUMBER = 290
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1685 of yacc.c  */
#line 19 "parser.y"

    int ival;
    float fval;
    double dval;
    char *sval;
    ASTNode *node;



/* Line 1685 of yacc.c  */
#line 107 "parser.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


