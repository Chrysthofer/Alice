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
     DOUBLE = 260,
     RETURN = 261,
     TRUE = 262,
     FALSE = 263,
     IF = 264,
     ELSE = 265,
     WHILE = 266,
     FOR = 267,
     PLUS = 268,
     MINUS = 269,
     TIMES = 270,
     DIVIDE = 271,
     ASSIGN = 272,
     SEMICOLON = 273,
     PLUSPLUS = 274,
     MINUSMINUS = 275,
     LPAREN = 276,
     RPAREN = 277,
     LBRACE = 278,
     RBRACE = 279,
     LT = 280,
     GT = 281,
     LE = 282,
     GE = 283,
     IDENTIFIER = 284,
     NUMBER = 285,
     FLOAT_NUMBER = 286,
     DOUBLE_NUMBER = 287
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
#line 104 "parser.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


