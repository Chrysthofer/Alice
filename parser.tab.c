/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

extern int yylineno; // Line number from the lexer

void yyerror(const char *s);
int yylex(void);

void generate_code_from_ast(ASTNode *node);


/* Line 189 of yacc.c  */
#line 87 "parser.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

/* "%code requires" blocks.  */

/* Line 209 of yacc.c  */
#line 15 "parser.y"

#include "ast.h"



/* Line 209 of yacc.c  */
#line 117 "parser.tab.c"

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

/* Line 214 of yacc.c  */
#line 19 "parser.y"

    int ival;
    float fval;
    double dval;
    char *sval;
    ASTNode *node;



/* Line 214 of yacc.c  */
#line 179 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 191 "parser.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   301

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  12
/* YYNRULES -- Number of rules.  */
#define YYNRULES  54
/* YYNRULES -- Number of states.  */
#define YYNSTATES  127

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   290

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    13,    19,    23,    29,
      33,    39,    41,    43,    52,    61,    70,    72,    73,    75,
      79,    82,    85,    88,    90,    92,    97,   101,   105,   117,
     125,   133,   144,   148,   151,   155,   158,   161,   163,   166,
     170,   174,   178,   182,   186,   190,   194,   198,   202,   204,
     206,   208,   210,   212,   216
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      37,     0,    -1,    38,    -1,    38,    39,    -1,    -1,     3,
      32,    20,    -1,     3,    32,    18,    47,    20,    -1,     4,
      32,    20,    -1,     4,    32,    18,    47,    20,    -1,     6,
      32,    20,    -1,     6,    32,    18,    47,    20,    -1,    40,
      -1,    45,    -1,     3,    32,    23,    41,    24,    25,    46,
      26,    -1,     4,    32,    23,    41,    24,    25,    46,    26,
      -1,     5,    32,    23,    41,    24,    25,    46,    26,    -1,
      42,    -1,    -1,    43,    -1,    42,    27,    43,    -1,     3,
      32,    -1,     4,    32,    -1,     6,    32,    -1,     8,    -1,
       9,    -1,    32,    18,    47,    20,    -1,    32,    18,    47,
      -1,     7,    47,    20,    -1,    10,    23,    47,    24,    25,
      46,    26,    11,    25,    46,    26,    -1,    10,    23,    47,
      24,    25,    46,    26,    -1,    12,    23,    47,    24,    25,
      46,    26,    -1,    13,    23,    45,    47,    20,    45,    24,
      25,    46,    26,    -1,    32,    21,    20,    -1,    32,    21,
      -1,    32,    22,    20,    -1,    32,    22,    -1,     1,    20,
      -1,    45,    -1,    46,    45,    -1,    47,    14,    47,    -1,
      47,    15,    47,    -1,    47,    16,    47,    -1,    47,    17,
      47,    -1,    47,    28,    47,    -1,    47,    29,    47,    -1,
      47,    30,    47,    -1,    47,    31,    47,    -1,    32,    19,
      47,    -1,    44,    -1,    32,    -1,    33,    -1,    34,    -1,
      35,    -1,    23,    47,    24,    -1,     1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    43,    43,    47,    48,    52,    53,    54,    55,    56,
      57,    58,    59,    63,    64,    65,    70,    71,    76,    77,
      81,    82,    83,    87,    88,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   107,   108,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "VOID", "DOUBLE",
  "RETURN", "TRUE", "FALSE", "IF", "ELSE", "WHILE", "FOR", "PLUS", "MINUS",
  "TIMES", "DIVIDE", "ASSIGN", "EQUAL", "SEMICOLON", "PLUSPLUS",
  "MINUSMINUS", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "COMMA", "LT",
  "GT", "LE", "GE", "IDENTIFIER", "NUMBER", "FLOAT_NUMBER",
  "DOUBLE_NUMBER", "$accept", "program", "decls", "decl", "func_decl",
  "params", "param_list", "param", "boolean_literal", "stmt", "stmt_list",
  "expr", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    36,    37,    38,    38,    39,    39,    39,    39,    39,
      39,    39,    39,    40,    40,    40,    41,    41,    42,    42,
      43,    43,    43,    44,    44,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    45,    46,    46,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    47
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     3,     5,     3,     5,     3,
       5,     1,     1,     8,     8,     8,     1,     0,     1,     3,
       2,     2,     2,     1,     1,     4,     3,     3,    11,     7,
       7,    10,     3,     2,     3,     2,     2,     1,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     1,
       1,     1,     1,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     3,    11,    12,    36,     0,     0,
       0,     0,    54,    23,    24,     0,    49,    50,    51,    52,
      48,     0,     0,     0,     0,     0,    33,    35,     0,     5,
      17,     0,     7,    17,    17,     0,     9,     0,     0,     0,
       0,     0,     0,    27,     0,     0,     0,     0,     0,     0,
       0,    26,    32,    34,     0,     0,     0,     0,     0,    16,
      18,     0,     0,     0,     0,    53,    47,    39,    40,    41,
      42,    43,    44,    45,    46,     0,     0,     0,    25,     6,
      20,    21,    22,     0,     0,     8,     0,     0,    10,     0,
       0,     0,     0,    19,     0,     0,    37,     0,     0,     0,
       0,     0,     0,    29,    38,    30,     0,    13,    14,    15,
       0,     0,     0,     0,     0,    31,    28
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,    14,    15,    68,    69,    70,    30,   106,
     107,    31
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -22
static const yytype_int16 yypact[] =
{
     -22,     2,    50,   -22,   -10,   -11,    12,    20,    27,    14,
      38,    43,    45,   -13,   -22,   -22,   -22,   -22,   -17,    22,
      55,    23,   -22,   -22,   -22,    14,    60,   -22,   -22,   -22,
     -22,   143,    14,    14,     6,    14,    61,    65,    14,   -22,
      69,    14,   -22,    69,    69,    14,   -22,   161,    14,    14,
      14,    14,    14,   -22,    14,    14,    14,    14,   179,   197,
      14,   202,   -22,   -22,   220,    48,    52,    56,    63,    66,
     -22,   227,    67,    70,   245,   -22,   270,   270,   270,   270,
     270,   270,   270,   270,   270,    75,    76,   252,   -22,   -22,
     -22,   -22,   -22,    77,    69,   -22,    78,    79,   -22,     6,
       6,     6,     6,   -22,     6,     6,   -22,    57,    64,    88,
      85,   106,   113,   104,   -22,   -22,   102,   -22,   -22,   -22,
     103,     6,     6,   123,   130,   -22,   -22
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -22,   -22,   -22,   -22,   -22,   -18,   -22,    35,   -22,    -2,
      46,   -21
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -3
static const yytype_int8 yytable[] =
{
      16,    38,     3,    39,    47,    35,    40,     4,    36,    37,
      17,    58,    59,     9,    61,    22,    10,    64,    11,    12,
      71,    18,    23,    24,    74,    72,    73,    76,    77,    78,
      79,    80,    60,    81,    82,    83,    84,    25,    13,    87,
      41,    45,    42,    46,    19,    43,    26,    27,    28,    29,
      -2,     4,    20,     5,     6,     7,     8,     9,     4,    21,
      10,    32,    11,    12,     9,     4,    33,    10,    34,    11,
      12,     9,    65,    66,    10,    67,    11,    12,    44,    48,
      90,    62,    13,   113,    91,    63,     4,    93,    92,    13,
     115,    96,     9,    94,    97,    10,    13,    11,    12,   109,
      99,   100,   102,   104,   105,   114,   114,     4,   114,   114,
     114,   117,   116,     9,     4,   120,    10,    13,    11,    12,
       9,   114,   114,    10,     4,    11,    12,   121,   122,   103,
       9,     4,   118,    10,     0,    11,    12,     9,    13,   119,
      10,     0,    11,    12,     0,    13,   108,     0,   110,   125,
     111,   112,     0,     0,     0,    13,   126,    49,    50,    51,
      52,     0,    13,    53,     0,     0,     0,   123,   124,     0,
       0,    54,    55,    56,    57,    49,    50,    51,    52,     0,
       0,     0,     0,     0,     0,    75,     0,     0,     0,    54,
      55,    56,    57,    49,    50,    51,    52,     0,     0,     0,
       0,     0,     0,    85,     0,     0,     0,    54,    55,    56,
      57,    49,    50,    51,    52,     0,    49,    50,    51,    52,
       0,    86,    88,     0,     0,    54,    55,    56,    57,     0,
      54,    55,    56,    57,    49,    50,    51,    52,     0,     0,
      89,    49,    50,    51,    52,     0,     0,    95,    54,    55,
      56,    57,     0,     0,     0,    54,    55,    56,    57,    49,
      50,    51,    52,     0,     0,    98,    49,    50,    51,    52,
       0,     0,   101,    54,    55,    56,    57,     0,     0,     0,
      54,    55,    56,    57,    49,    50,    51,    52,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    54,    55,
      56,    57
};

static const yytype_int8 yycheck[] =
{
       2,    18,     0,    20,    25,    18,    23,     1,    21,    22,
      20,    32,    33,     7,    35,     1,    10,    38,    12,    13,
      41,    32,     8,     9,    45,    43,    44,    48,    49,    50,
      51,    52,    34,    54,    55,    56,    57,    23,    32,    60,
      18,    18,    20,    20,    32,    23,    32,    33,    34,    35,
       0,     1,    32,     3,     4,     5,     6,     7,     1,    32,
      10,    23,    12,    13,     7,     1,    23,    10,    23,    12,
      13,     7,     3,     4,    10,     6,    12,    13,    23,    19,
      32,    20,    32,    26,    32,    20,     1,    24,    32,    32,
      26,    24,     7,    27,    24,    10,    32,    12,    13,   101,
      25,    25,    25,    25,    25,   107,   108,     1,   110,   111,
     112,    26,    24,     7,     1,    11,    10,    32,    12,    13,
       7,   123,   124,    10,     1,    12,    13,    25,    25,    94,
       7,     1,    26,    10,    -1,    12,    13,     7,    32,    26,
      10,    -1,    12,    13,    -1,    32,   100,    -1,   102,    26,
     104,   105,    -1,    -1,    -1,    32,    26,    14,    15,    16,
      17,    -1,    32,    20,    -1,    -1,    -1,   121,   122,    -1,
      -1,    28,    29,    30,    31,    14,    15,    16,    17,    -1,
      -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    28,
      29,    30,    31,    14,    15,    16,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    24,    -1,    -1,    -1,    28,    29,    30,
      31,    14,    15,    16,    17,    -1,    14,    15,    16,    17,
      -1,    24,    20,    -1,    -1,    28,    29,    30,    31,    -1,
      28,    29,    30,    31,    14,    15,    16,    17,    -1,    -1,
      20,    14,    15,    16,    17,    -1,    -1,    20,    28,    29,
      30,    31,    -1,    -1,    -1,    28,    29,    30,    31,    14,
      15,    16,    17,    -1,    -1,    20,    14,    15,    16,    17,
      -1,    -1,    20,    28,    29,    30,    31,    -1,    -1,    -1,
      28,    29,    30,    31,    14,    15,    16,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,
      30,    31
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    37,    38,     0,     1,     3,     4,     5,     6,     7,
      10,    12,    13,    32,    39,    40,    45,    20,    32,    32,
      32,    32,     1,     8,     9,    23,    32,    33,    34,    35,
      44,    47,    23,    23,    23,    18,    21,    22,    18,    20,
      23,    18,    20,    23,    23,    18,    20,    47,    19,    14,
      15,    16,    17,    20,    28,    29,    30,    31,    47,    47,
      45,    47,    20,    20,    47,     3,     4,     6,    41,    42,
      43,    47,    41,    41,    47,    24,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    24,    24,    47,    20,    20,
      32,    32,    32,    24,    27,    20,    24,    24,    20,    25,
      25,    20,    25,    43,    25,    25,    45,    46,    46,    45,
      46,    46,    46,    26,    45,    26,    24,    26,    26,    26,
      11,    25,    25,    46,    46,    26,    26
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1464 of yacc.c  */
#line 43 "parser.y"
    { generate_code_from_ast((yyvsp[(1) - (1)].node)); ;}
    break;

  case 3:

/* Line 1464 of yacc.c  */
#line 47 "parser.y"
    { (yyval.node) = create_node(';', (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node), NULL, NULL, 0, 0.0, 0.0, NULL); ;}
    break;

  case 4:

/* Line 1464 of yacc.c  */
#line 48 "parser.y"
    { (yyval.node) = NULL;                                             ;}
    break;

  case 5:

/* Line 1464 of yacc.c  */
#line 52 "parser.y"
    { (yyval.node) = create_node('D', NULL, NULL, NULL, NULL, 0, 0.0, 0.0, (yyvsp[(2) - (3)].sval));  ;}
    break;

  case 6:

/* Line 1464 of yacc.c  */
#line 53 "parser.y"
    { (yyval.node) = create_node('=', NULL, (yyvsp[(4) - (5)].node), NULL, NULL, 0, 0.0, 0.0, (yyvsp[(2) - (5)].sval));    ;}
    break;

  case 7:

/* Line 1464 of yacc.c  */
#line 54 "parser.y"
    { (yyval.node) = create_node('D', NULL, NULL, NULL, NULL, 0, 0.0, 0.0, (yyvsp[(2) - (3)].sval));  ;}
    break;

  case 8:

/* Line 1464 of yacc.c  */
#line 55 "parser.y"
    { (yyval.node) = create_node('=', NULL, (yyvsp[(4) - (5)].node), NULL, NULL, 0, 0.0, 0.0, (yyvsp[(2) - (5)].sval));    ;}
    break;

  case 9:

/* Line 1464 of yacc.c  */
#line 56 "parser.y"
    { (yyval.node) = create_node('D', NULL, NULL, NULL, NULL, 0, 0.0, 0.0, (yyvsp[(2) - (3)].sval));  ;}
    break;

  case 10:

/* Line 1464 of yacc.c  */
#line 57 "parser.y"
    { (yyval.node) = create_node('=', NULL, (yyvsp[(4) - (5)].node), NULL, NULL, 0, 0.0, 0.0, (yyvsp[(2) - (5)].sval));    ;}
    break;

  case 11:

/* Line 1464 of yacc.c  */
#line 58 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node);                                                         ;}
    break;

  case 12:

/* Line 1464 of yacc.c  */
#line 59 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node);                                                         ;}
    break;

  case 13:

/* Line 1464 of yacc.c  */
#line 63 "parser.y"
    { (yyval.node) = create_node('FUNC', (yyvsp[(4) - (8)].node), (yyvsp[(7) - (8)].node), NULL, NULL, 0, 0.0, 0.0, (yyvsp[(2) - (8)].sval)); ;}
    break;

  case 14:

/* Line 1464 of yacc.c  */
#line 64 "parser.y"
    { (yyval.node) = create_node('FUNC', (yyvsp[(4) - (8)].node), (yyvsp[(7) - (8)].node), NULL, NULL, 0, 0.0, 0.0, (yyvsp[(2) - (8)].sval)); ;}
    break;

  case 15:

/* Line 1464 of yacc.c  */
#line 65 "parser.y"
    { (yyval.node) = create_node('FUNC', (yyvsp[(4) - (8)].node), (yyvsp[(7) - (8)].node), NULL, NULL, 0, 0.0, 0.0, (yyvsp[(2) - (8)].sval)); ;}
    break;

  case 16:

/* Line 1464 of yacc.c  */
#line 70 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node);  ;}
    break;

  case 17:

/* Line 1464 of yacc.c  */
#line 71 "parser.y"
    { (yyval.node) = NULL; ;}
    break;

  case 18:

/* Line 1464 of yacc.c  */
#line 76 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node);                                                      ;}
    break;

  case 19:

/* Line 1464 of yacc.c  */
#line 77 "parser.y"
    { (yyval.node) = create_node(',', (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), NULL, NULL, 0, 0.0, 0.0, NULL); ;}
    break;

  case 20:

/* Line 1464 of yacc.c  */
#line 81 "parser.y"
    { (yyval.node) = create_node('P', NULL, NULL, NULL, NULL, 0, 0.0, 0.0, (yyvsp[(2) - (2)].sval)); ;}
    break;

  case 21:

/* Line 1464 of yacc.c  */
#line 82 "parser.y"
    { (yyval.node) = create_node('P', NULL, NULL, NULL, NULL, 0, 0.0, 0.0, (yyvsp[(2) - (2)].sval)); ;}
    break;

  case 22:

/* Line 1464 of yacc.c  */
#line 83 "parser.y"
    { (yyval.node) = create_node('P', NULL, NULL, NULL, NULL, 0, 0.0, 0.0, (yyvsp[(2) - (2)].sval)); ;}
    break;

  case 23:

/* Line 1464 of yacc.c  */
#line 87 "parser.y"
    { (yyval.node) = create_node('B', NULL, NULL, NULL, NULL, 1, 0.0, 0.0, NULL); ;}
    break;

  case 24:

/* Line 1464 of yacc.c  */
#line 88 "parser.y"
    { (yyval.node) = create_node('B', NULL, NULL, NULL, NULL, 0, 0.0, 0.0, NULL); ;}
    break;

  case 25:

/* Line 1464 of yacc.c  */
#line 92 "parser.y"
    { (yyval.node) = create_node('=', NULL, (yyvsp[(3) - (4)].node), NULL, NULL, 0, 0.0, 0.0, (yyvsp[(1) - (4)].sval));    ;}
    break;

  case 26:

/* Line 1464 of yacc.c  */
#line 93 "parser.y"
    { (yyval.node) = create_node('=', NULL, (yyvsp[(3) - (3)].node), NULL, NULL, 0, 0.0, 0.0, (yyvsp[(1) - (3)].sval));    ;}
    break;

  case 27:

/* Line 1464 of yacc.c  */
#line 94 "parser.y"
    { (yyval.node) = create_node('R', (yyvsp[(2) - (3)].node), NULL, NULL, NULL, 0, 0.0, 0.0, NULL);  ;}
    break;

  case 28:

/* Line 1464 of yacc.c  */
#line 95 "parser.y"
    { (yyval.node) = create_node('E', (yyvsp[(3) - (11)].node), (yyvsp[(6) - (11)].node), (yyvsp[(10) - (11)].node), NULL, 0, 0.0, 0.0, NULL);     ;}
    break;

  case 29:

/* Line 1464 of yacc.c  */
#line 96 "parser.y"
    { (yyval.node) = create_node('IF', (yyvsp[(3) - (7)].node), (yyvsp[(6) - (7)].node), NULL, NULL, 0, 0.0, 0.0, NULL);   ;}
    break;

  case 30:

/* Line 1464 of yacc.c  */
#line 97 "parser.y"
    { (yyval.node) = create_node('W', (yyvsp[(3) - (7)].node), (yyvsp[(6) - (7)].node), NULL, NULL, 0, 0.0, 0.0, NULL);    ;}
    break;

  case 31:

/* Line 1464 of yacc.c  */
#line 98 "parser.y"
    { (yyval.node) = create_node('F', (yyvsp[(3) - (10)].node), (yyvsp[(4) - (10)].node), (yyvsp[(6) - (10)].node), (yyvsp[(9) - (10)].node), 0, 0.0, 0.0, NULL);        ;}
    break;

  case 32:

/* Line 1464 of yacc.c  */
#line 99 "parser.y"
    { (yyval.node) = create_node('++', NULL, NULL, NULL, NULL, 0, 0.0, 0.0, (yyvsp[(1) - (3)].sval)); ;}
    break;

  case 33:

/* Line 1464 of yacc.c  */
#line 100 "parser.y"
    { (yyval.node) = create_node('++', NULL, NULL, NULL, NULL, 0, 0.0, 0.0, (yyvsp[(1) - (2)].sval)); ;}
    break;

  case 34:

/* Line 1464 of yacc.c  */
#line 101 "parser.y"
    { (yyval.node) = create_node('--', NULL, NULL, NULL, NULL, 0, 0.0, 0.0, (yyvsp[(1) - (3)].sval)); ;}
    break;

  case 35:

/* Line 1464 of yacc.c  */
#line 102 "parser.y"
    { (yyval.node) = create_node('--', NULL, NULL, NULL, NULL, 0, 0.0, 0.0, (yyvsp[(1) - (2)].sval)); ;}
    break;

  case 36:

/* Line 1464 of yacc.c  */
#line 103 "parser.y"
    { yyerror("Syntax error in statement"); yyerrok; YYABORT;          ;}
    break;

  case 37:

/* Line 1464 of yacc.c  */
#line 107 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node);                                                 ;}
    break;

  case 38:

/* Line 1464 of yacc.c  */
#line 108 "parser.y"
    { (yyval.node) = create_node(';', (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node), NULL, NULL, 0, 0.0, 0.0, NULL); ;}
    break;

  case 39:

/* Line 1464 of yacc.c  */
#line 111 "parser.y"
    { (yyval.node) = create_node('+', (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), NULL, NULL, 0, 0.0, 0.0, NULL);      ;}
    break;

  case 40:

/* Line 1464 of yacc.c  */
#line 112 "parser.y"
    { (yyval.node) = create_node('-', (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), NULL, NULL, 0, 0.0, 0.0, NULL);      ;}
    break;

  case 41:

/* Line 1464 of yacc.c  */
#line 113 "parser.y"
    { (yyval.node) = create_node('*', (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), NULL, NULL, 0, 0.0, 0.0, NULL);      ;}
    break;

  case 42:

/* Line 1464 of yacc.c  */
#line 114 "parser.y"
    { (yyval.node) = create_node('/', (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), NULL, NULL, 0, 0.0, 0.0, NULL);      ;}
    break;

  case 43:

/* Line 1464 of yacc.c  */
#line 115 "parser.y"
    { (yyval.node) = create_node('<', (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), NULL, NULL, 0, 0.0, 0.0, NULL);      ;}
    break;

  case 44:

/* Line 1464 of yacc.c  */
#line 116 "parser.y"
    { (yyval.node) = create_node('>', (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), NULL, NULL, 0, 0.0, 0.0, NULL);      ;}
    break;

  case 45:

/* Line 1464 of yacc.c  */
#line 117 "parser.y"
    { (yyval.node) = create_node(LE, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), NULL, NULL, 0, 0.0, 0.0, NULL);       ;}
    break;

  case 46:

/* Line 1464 of yacc.c  */
#line 118 "parser.y"
    { (yyval.node) = create_node(GE, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), NULL, NULL, 0, 0.0, 0.0, NULL);       ;}
    break;

  case 47:

/* Line 1464 of yacc.c  */
#line 119 "parser.y"
    { (yyval.node) = create_node('==', NULL, (yyvsp[(3) - (3)].node), NULL, NULL, 0, 0.0, 0.0, (yyvsp[(1) - (3)].sval));     ;}
    break;

  case 49:

/* Line 1464 of yacc.c  */
#line 121 "parser.y"
    { (yyval.node) = create_node('I', NULL, NULL, NULL, NULL, 0, 0.0, 0.0, (yyvsp[(1) - (1)].sval));    ;}
    break;

  case 50:

/* Line 1464 of yacc.c  */
#line 122 "parser.y"
    { (yyval.node) = create_node('N', NULL, NULL, NULL, NULL, (yyvsp[(1) - (1)].ival), 0.0, 0.0, NULL); ;}
    break;

  case 51:

/* Line 1464 of yacc.c  */
#line 123 "parser.y"
    { (yyval.node) = create_node('FL', NULL, NULL, NULL, NULL, 0, (yyvsp[(1) - (1)].fval), 0.0, NULL);  ;}
    break;

  case 52:

/* Line 1464 of yacc.c  */
#line 124 "parser.y"
    { (yyval.node) = create_node('DB', NULL, NULL, NULL, NULL, 0, 0.0, (yyvsp[(1) - (1)].dval), NULL);  ;}
    break;

  case 53:

/* Line 1464 of yacc.c  */
#line 125 "parser.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node);                                                           ;}
    break;

  case 54:

/* Line 1464 of yacc.c  */
#line 126 "parser.y"
    { yyerror("Syntax error in expression"); yyerrok; YYABORT;           ;}
    break;



/* Line 1464 of yacc.c  */
#line 1893 "parser.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1684 of yacc.c  */
#line 129 "parser.y"


void yyerror(const char *s) {
    fprintf(stderr, "Error: %s at line %d\n", s, yylineno);
}
#ifndef INCLUDE_MAIN
int main() {
    return yyparse();
}
#endif
