/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "ass4_16CS30027.y"

	#include <stdio.h>
	extern int yylex();
	void yyerror(char *s);

/* Line 371 of yacc.c  */
#line 74 "ass4_16CS30027.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "ass4_16CS30027.tab.h".  */
#ifndef YY_YY_ASS4_16CS30027_TAB_H_INCLUDED
# define YY_YY_ASS4_16CS30027_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TYPEDEF = 258,
     EXTERN = 259,
     STATIC = 260,
     AUTO = 261,
     REGISTER = 262,
     INLINE = 263,
     RESTRICT = 264,
     CHAR = 265,
     SHORT = 266,
     INT = 267,
     LONG = 268,
     SIGNED = 269,
     UNSIGNED = 270,
     FLOAT = 271,
     DOUBLE = 272,
     CONST = 273,
     VOLATILE = 274,
     VOID = 275,
     _BOOL = 276,
     _COMPLEX = 277,
     _IMAGINARY = 278,
     STRUCT = 279,
     UNION = 280,
     ENUM = 281,
     BREAK = 282,
     CASE = 283,
     CONTINUE = 284,
     DEFAULT = 285,
     DO = 286,
     IF = 287,
     ELSE = 288,
     FOR = 289,
     GOTO = 290,
     WHILE = 291,
     SWITCH = 292,
     SIZEOF = 293,
     RETURN = 294,
     ELLIPSIS = 295,
     RIGHT_ASSIGN = 296,
     LEFT_ASSIGN = 297,
     ADD_ASSIGN = 298,
     SUB_ASSIGN = 299,
     MUL_ASSIGN = 300,
     BITAND_ASSIGN = 301,
     DIV_ASSIGN = 302,
     MOD_ASSIGN = 303,
     AND_ASSIGN = 304,
     XOR_ASSIGN = 305,
     OR_ASSIGN = 306,
     RIGHT_OP = 307,
     LEFT_OP = 308,
     INC_OP = 309,
     DEC_OP = 310,
     PTR_OP = 311,
     AND_OP = 312,
     OR_OP = 313,
     LE_OP = 314,
     GE_OP = 315,
     EQ_OP = 316,
     NE_OP = 317,
     SEMICOLON = 318,
     PIPE = 319,
     HASH = 320,
     COMMA = 321,
     QUESMARK = 322,
     EQUALITY = 323,
     COLON = 324,
     DOT = 325,
     CONJ = 326,
     LT = 327,
     GT = 328,
     MODULO = 329,
     DIVSN = 330,
     LSB = 331,
     RSB = 332,
     LOB = 333,
     ROB = 334,
     LCB = 335,
     RCB = 336,
     BITAND = 337,
     MULT = 338,
     PLUS = 339,
     MINUS = 340,
     TILDE = 341,
     EXCLM = 342,
     IDENTIFIER = 343,
     STRING_LITERAL = 344,
     PUNCTUATORS = 345,
     COMMENT = 346,
     INT_CONSTANT = 347,
     FLOAT_CONSTANT = 348,
     ENU_CONSTANT = 349,
     CHAR_CONSTANT = 350,
     LOWER_THAN_ELSE = 351
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 7 "ass4_16CS30027.y"

int intval;
  float floatval;
  char *charval;


/* Line 387 of yacc.c  */
#line 220 "ass4_16CS30027.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

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

#endif /* !YY_YY_ASS4_16CS30027_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 248 "ass4_16CS30027.tab.c"

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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
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

# define YYCOPY_NEEDED 1

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

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  60
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1307

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  97
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  64
/* YYNRULES -- Number of rules.  */
#define YYNRULES  211
/* YYNRULES -- Number of states.  */
#define YYNSTATES  346

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   351

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    13,    15,    17,    19,
      21,    23,    28,    32,    37,    41,    45,    48,    51,    58,
      66,    68,    72,    74,    77,    80,    83,    86,    91,    93,
      95,    97,    99,   101,   103,   105,   110,   112,   116,   120,
     124,   126,   130,   134,   136,   140,   144,   146,   150,   154,
     158,   162,   164,   168,   172,   174,   178,   180,   184,   186,
     190,   192,   196,   198,   202,   204,   210,   212,   216,   218,
     220,   222,   224,   226,   228,   230,   232,   234,   236,   238,
     240,   244,   246,   249,   253,   255,   258,   260,   263,   265,
     268,   270,   273,   275,   279,   281,   285,   287,   289,   291,
     293,   295,   297,   299,   301,   303,   305,   307,   309,   311,
     313,   315,   317,   319,   322,   324,   327,   329,   334,   340,
     346,   353,   356,   358,   362,   364,   368,   370,   372,   374,
     376,   379,   381,   383,   387,   393,   400,   406,   411,   416,
     420,   422,   423,   425,   426,   428,   431,   434,   438,   440,
     443,   445,   449,   451,   455,   458,   460,   462,   466,   468,
     470,   474,   479,   481,   484,   488,   493,   496,   498,   501,
     505,   508,   510,   512,   514,   516,   518,   520,   524,   529,
     533,   536,   540,   542,   545,   547,   549,   551,   554,   560,
     568,   574,   580,   588,   596,   603,   611,   618,   622,   625,
     628,   631,   635,   637,   640,   642,   644,   649,   653,   657,
     660,   662
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     157,     0,    -1,    88,    -1,    99,    -1,    89,    -1,    78,
     118,    79,    -1,    92,    -1,    93,    -1,    94,    -1,    95,
      -1,    98,    -1,   100,    76,   118,    77,    -1,   100,    78,
      79,    -1,   100,    78,   101,    79,    -1,   100,    70,    88,
      -1,   100,    56,    88,    -1,   100,    54,    -1,   100,    55,
      -1,    78,   142,    79,    80,   144,    81,    -1,    78,   142,
      79,    80,   144,    66,    81,    -1,   116,    -1,   101,    66,
     116,    -1,   100,    -1,    54,   102,    -1,    55,   102,    -1,
     103,   104,    -1,    38,   102,    -1,    38,    78,   142,    79,
      -1,    82,    -1,    83,    -1,    84,    -1,    85,    -1,    86,
      -1,    87,    -1,   102,    -1,    78,   142,    79,   104,    -1,
     104,    -1,   105,    83,   104,    -1,   105,    75,   104,    -1,
     105,    74,   104,    -1,   105,    -1,   106,    84,   105,    -1,
     106,    85,   105,    -1,   106,    -1,   107,    53,   106,    -1,
     107,    52,   106,    -1,   107,    -1,   108,    72,   107,    -1,
     108,    73,   107,    -1,   108,    59,   107,    -1,   108,    60,
     107,    -1,   108,    -1,   109,    61,   108,    -1,   109,    62,
     108,    -1,   109,    -1,   110,    82,   109,    -1,   110,    -1,
     111,    71,   110,    -1,   111,    -1,   112,    64,   111,    -1,
     112,    -1,   113,    57,   112,    -1,   113,    -1,   114,    58,
     113,    -1,   114,    -1,   114,    67,   118,    69,   115,    -1,
     115,    -1,   102,   117,   116,    -1,    68,    -1,    45,    -1,
      47,    -1,    48,    -1,    43,    -1,    44,    -1,    42,    -1,
      41,    -1,    46,    -1,    50,    -1,    51,    -1,   116,    -1,
     118,    66,   116,    -1,   115,    -1,   121,    63,    -1,   121,
     122,    63,    -1,   124,    -1,   124,   121,    -1,   125,    -1,
     125,   121,    -1,   130,    -1,   130,   121,    -1,   131,    -1,
     131,   121,    -1,   123,    -1,   122,    66,   123,    -1,   132,
      -1,   132,    68,   143,    -1,     4,    -1,     5,    -1,     6,
      -1,     7,    -1,    20,    -1,    10,    -1,    11,    -1,    12,
      -1,    13,    -1,    16,    -1,    17,    -1,    14,    -1,    15,
      -1,    21,    -1,    22,    -1,    23,    -1,   127,    -1,   125,
     126,    -1,   125,    -1,   130,   126,    -1,   130,    -1,    26,
      80,   128,    81,    -1,    26,    88,    80,   128,    81,    -1,
      26,    80,   128,    66,    81,    -1,    26,    88,    80,   128,
      66,    81,    -1,    26,    88,    -1,   129,    -1,   128,    66,
     129,    -1,    88,    -1,    88,    68,   119,    -1,    18,    -1,
      19,    -1,     9,    -1,     8,    -1,   136,   133,    -1,   133,
      -1,    88,    -1,    78,   132,    79,    -1,   133,    76,   134,
     135,    77,    -1,   133,    76,     5,   134,   116,    77,    -1,
     133,    76,   134,    83,    77,    -1,   133,    78,   138,    79,
      -1,   133,    78,   141,    79,    -1,   133,    78,    79,    -1,
     137,    -1,    -1,   116,    -1,    -1,    83,    -1,    83,   137,
      -1,    83,   136,    -1,    83,   137,   136,    -1,   130,    -1,
     137,   130,    -1,   139,    -1,   139,    66,    40,    -1,   140,
      -1,   139,    66,   140,    -1,   121,   132,    -1,   121,    -1,
      88,    -1,   141,    66,    88,    -1,   126,    -1,   116,    -1,
      80,   144,    81,    -1,    80,   144,    66,    81,    -1,   143,
      -1,   145,   143,    -1,   144,    66,   143,    -1,   144,    66,
     145,   143,    -1,   146,    68,    -1,   147,    -1,   146,   147,
      -1,    76,   119,    77,    -1,    70,    88,    -1,   149,    -1,
     150,    -1,   153,    -1,   154,    -1,   155,    -1,   156,    -1,
      88,    69,   148,    -1,    28,   119,    69,   148,    -1,    30,
      69,   148,    -1,    80,    81,    -1,    80,   151,    81,    -1,
     152,    -1,   151,   152,    -1,   120,    -1,   148,    -1,    63,
      -1,   118,    63,    -1,    32,    78,   118,    79,   148,    -1,
      32,    78,   118,    79,   148,    33,   148,    -1,    37,    78,
     118,    79,   148,    -1,    36,    78,   118,    79,   148,    -1,
      31,   148,    36,    78,   118,    79,    63,    -1,    34,    78,
     153,   153,   118,    79,   148,    -1,    34,    78,   153,   153,
      79,   148,    -1,    34,    78,   120,   153,   118,    79,   148,
      -1,    34,    78,   120,   153,    79,   148,    -1,    35,    88,
      63,    -1,    29,    63,    -1,    27,    63,    -1,    39,    63,
      -1,    39,   118,    63,    -1,   158,    -1,   157,   158,    -1,
     159,    -1,   120,    -1,   121,   132,   160,   150,    -1,   121,
     132,   150,    -1,   132,   160,   150,    -1,   132,   150,    -1,
     120,    -1,   160,   120,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    41,    41,    42,    43,    44,    49,    50,    51,    52,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      70,    71,    76,    77,    78,    79,    80,    81,    85,    86,
      87,    88,    89,    90,    94,    95,   100,   101,   102,   103,
     108,   109,   110,   115,   116,   117,   122,   123,   124,   125,
     126,   131,   132,   133,   138,   139,   144,   145,   150,   151,
     156,   157,   162,   163,   168,   169,   174,   175,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   195,
     196,   201,   206,   207,   212,   213,   214,   215,   216,   217,
     218,   219,   224,   225,   230,   231,   236,   237,   238,   239,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   263,   264,   265,   266,   272,   273,   274,
     275,   276,   281,   282,   287,   288,   293,   294,   295,   299,
     303,   304,   309,   310,   311,   312,   313,   314,   315,   316,
     322,   324,   328,   330,   334,   335,   336,   337,   342,   343,
     349,   350,   355,   356,   361,   362,   367,   368,   373,   381,
     382,   383,   388,   389,   390,   391,   396,   401,   402,   407,
     408,   413,   414,   415,   416,   417,   418,   423,   424,   425,
     430,   431,   436,   437,   442,   443,   449,   450,   455,   456,
     457,   462,   463,   464,   466,   468,   470,   474,   475,   476,
     477,   478,   483,   484,   489,   490,   495,   496,   497,   498,
     501,   502
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TYPEDEF", "EXTERN", "STATIC", "AUTO",
  "REGISTER", "INLINE", "RESTRICT", "CHAR", "SHORT", "INT", "LONG",
  "SIGNED", "UNSIGNED", "FLOAT", "DOUBLE", "CONST", "VOLATILE", "VOID",
  "_BOOL", "_COMPLEX", "_IMAGINARY", "STRUCT", "UNION", "ENUM", "BREAK",
  "CASE", "CONTINUE", "DEFAULT", "DO", "IF", "ELSE", "FOR", "GOTO",
  "WHILE", "SWITCH", "SIZEOF", "RETURN", "ELLIPSIS", "RIGHT_ASSIGN",
  "LEFT_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN", "BITAND_ASSIGN",
  "DIV_ASSIGN", "MOD_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN",
  "RIGHT_OP", "LEFT_OP", "INC_OP", "DEC_OP", "PTR_OP", "AND_OP", "OR_OP",
  "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "SEMICOLON", "PIPE", "HASH", "COMMA",
  "QUESMARK", "EQUALITY", "COLON", "DOT", "CONJ", "LT", "GT", "MODULO",
  "DIVSN", "LSB", "RSB", "LOB", "ROB", "LCB", "RCB", "BITAND", "MULT",
  "PLUS", "MINUS", "TILDE", "EXCLM", "IDENTIFIER", "STRING_LITERAL",
  "PUNCTUATORS", "COMMENT", "INT_CONSTANT", "FLOAT_CONSTANT",
  "ENU_CONSTANT", "CHAR_CONSTANT", "LOWER_THAN_ELSE", "$accept",
  "primary_expression", "constant", "postfix_expression",
  "argument_expression_list", "unary_expression", "unary_operator",
  "cast_expression", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "and_expression", "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier", "specifier_qualifier_list",
  "enum_specifier", "enumerator_list", "enumerator", "type_qualifier",
  "function_specifier", "declarator", "direct_declarator",
  "type_qualifier_list_opt", "assignment_expression_opt", "pointer",
  "type_qualifier_list", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "type_name", "initializer",
  "initializer_list", "designation", "designator_list", "designator",
  "statement", "labeled_statement", "compound_statement",
  "block_item_list", "block_item", "expression_statement",
  "selection_statement", "iteration_statement", "jump_statement",
  "translation_unit", "external_declaration", "function_definition",
  "declaration_list", YY_NULL
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    97,    98,    98,    98,    98,    99,    99,    99,    99,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     101,   101,   102,   102,   102,   102,   102,   102,   103,   103,
     103,   103,   103,   103,   104,   104,   105,   105,   105,   105,
     106,   106,   106,   107,   107,   107,   108,   108,   108,   108,
     108,   109,   109,   109,   110,   110,   111,   111,   112,   112,
     113,   113,   114,   114,   115,   115,   116,   116,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   118,
     118,   119,   120,   120,   121,   121,   121,   121,   121,   121,
     121,   121,   122,   122,   123,   123,   124,   124,   124,   124,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   126,   126,   126,   126,   127,   127,   127,
     127,   127,   128,   128,   129,   129,   130,   130,   130,   131,
     132,   132,   133,   133,   133,   133,   133,   133,   133,   133,
     134,   134,   135,   135,   136,   136,   136,   136,   137,   137,
     138,   138,   139,   139,   140,   140,   141,   141,   142,   143,
     143,   143,   144,   144,   144,   144,   145,   146,   146,   147,
     147,   148,   148,   148,   148,   148,   148,   149,   149,   149,
     150,   150,   151,   151,   152,   152,   153,   153,   154,   154,
     154,   155,   155,   155,   155,   155,   155,   156,   156,   156,
     156,   156,   157,   157,   158,   158,   159,   159,   159,   159,
     160,   160
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     4,     3,     4,     3,     3,     2,     2,     6,     7,
       1,     3,     1,     2,     2,     2,     2,     4,     1,     1,
       1,     1,     1,     1,     1,     4,     1,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     5,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     2,     3,     1,     2,     1,     2,     1,     2,
       1,     2,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     2,     1,     4,     5,     5,
       6,     2,     1,     3,     1,     3,     1,     1,     1,     1,
       2,     1,     1,     3,     5,     6,     5,     4,     4,     3,
       1,     0,     1,     0,     1,     2,     2,     3,     1,     2,
       1,     3,     1,     3,     2,     1,     1,     3,     1,     1,
       3,     4,     1,     2,     3,     4,     2,     1,     2,     3,
       2,     1,     1,     1,     1,     1,     1,     3,     4,     3,
       2,     3,     1,     2,     1,     1,     1,     2,     5,     7,
       5,     5,     7,     7,     6,     7,     6,     3,     2,     2,
       2,     3,     1,     2,     1,     1,     4,     3,     3,     2,
       1,     2
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    96,    97,    98,    99,   129,   128,   101,   102,   103,
     104,   107,   108,   105,   106,   126,   127,   100,   109,   110,
     111,     0,     0,   144,   132,   205,     0,    84,    86,   112,
      88,    90,     0,   131,     0,     0,   202,   204,     0,   121,
       0,   148,   146,   145,    82,     0,    92,    94,    85,    87,
      89,    91,     0,   210,     0,   209,     0,   141,     0,   130,
       1,   203,   124,     0,   122,     0,   133,   149,   147,    83,
       0,     0,   207,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   186,     0,
     180,    28,    29,    30,    31,    32,    33,     2,     4,     6,
       7,     8,     9,    10,     3,    22,    34,     0,    36,    40,
      43,    46,    51,    54,    56,    58,    60,    62,    64,    66,
      79,     0,   184,   185,   171,   172,     0,   182,   173,   174,
     175,   176,    94,   211,   208,   141,   143,   140,   139,   156,
     155,     0,   150,   152,     0,     0,     0,   117,     0,    93,
       0,     2,   159,    95,   206,   199,    34,    81,     0,   198,
       0,     0,     0,     0,     0,     0,     0,     0,    26,   200,
       0,     0,    23,    24,     0,   114,   158,   116,     0,     0,
      16,    17,     0,     0,     0,     0,    75,    74,    72,    73,
      69,    76,    70,    71,    77,    78,    68,     0,    25,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   187,     0,
     181,   183,     0,    29,   142,     0,   154,   137,     0,     0,
     138,   125,   119,   123,     0,   118,     0,     0,   162,     0,
       0,     0,   167,     0,   179,     0,     0,     0,     0,   197,
       0,     0,     0,   201,     0,     5,   113,   115,     0,   177,
      15,    14,     0,    12,     0,    20,    67,    39,    38,    37,
      41,    42,    45,    44,    49,    50,    47,    48,    52,    53,
      55,    57,    59,    61,    63,     0,    80,     0,   136,   134,
     151,   153,   157,   120,   170,     0,     0,   160,   163,   166,
     168,   178,     0,     0,     0,     0,     0,     0,    27,     0,
       0,    35,    11,     0,    13,     0,   135,   169,   161,   164,
       0,     0,   188,     0,     0,     0,     0,   191,   190,     0,
      21,    65,   165,     0,     0,   196,     0,   194,     0,     0,
      18,   192,   189,   195,   193,    19
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   103,   104,   105,   264,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     197,   121,   158,    25,    54,    45,    46,    27,    28,   176,
      29,    63,    64,    30,    31,    32,    33,   136,   225,    34,
     137,   141,   142,   143,   144,   178,   238,   239,   240,   241,
     242,   123,   124,   125,   126,   127,   128,   129,   130,   131,
      35,    36,    37,    56
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -281
static const yytype_int16 yypact[] =
{
     676,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,
    -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,
    -281,    45,   130,     8,  -281,  -281,   -32,  1281,  1281,  -281,
    1281,  1281,   799,    54,    21,   566,  -281,  -281,   -22,   -62,
      -8,  -281,  -281,     8,  -281,     7,  -281,   722,  -281,  -281,
    -281,  -281,   286,  -281,   -32,  -281,   799,    59,   699,    54,
    -281,  -281,    33,   -19,  -281,   -22,  -281,  -281,  -281,  -281,
     130,   935,  -281,   799,    12,  1091,    98,    44,   800,    87,
      94,    71,   113,   139,  1109,   189,  1127,  1127,  -281,   584,
    -281,  -281,  -281,  -281,  -281,  -281,  -281,   155,  -281,  -281,
    -281,  -281,  -281,  -281,  -281,   -33,    96,  1091,  -281,    83,
     152,   206,    51,   218,   148,   176,   177,   203,   -43,  -281,
    -281,   149,  -281,  -281,  -281,  -281,   378,  -281,  -281,  -281,
    -281,  -281,   197,  -281,  -281,   210,  1152,   210,  -281,  -281,
     130,   240,   260,  -281,   -54,  1091,   128,  -281,   -12,  -281,
     892,  -281,  -281,  -281,  -281,  -281,  -281,  -281,   258,  -281,
     800,   292,  1091,   470,   266,  1091,  1091,   584,  -281,  -281,
     182,   584,  -281,  -281,    49,   184,  -281,   184,   251,   800,
    -281,  -281,   243,   244,  1091,   953,  -281,  -281,  -281,  -281,
    -281,  -281,  -281,  -281,  -281,  -281,  -281,  1091,  -281,  1091,
    1091,  1091,  1091,  1091,  1091,  1091,  1091,  1091,  1091,  1091,
    1091,  1091,  1091,  1091,  1091,  1091,  1091,  1091,  -281,  1091,
    -281,  -281,  1091,   256,  -281,   257,  -281,  -281,  1244,   247,
    -281,  -281,  -281,  -281,   133,  -281,   248,  1091,  -281,     6,
     935,   170,  -281,   800,  -281,   259,    50,   971,   971,  -281,
      52,    55,   263,  -281,   264,  -281,  -281,  -281,  1013,  -281,
    -281,  -281,    40,  -281,    70,  -281,  -281,  -281,  -281,  -281,
      83,    83,   152,   152,   206,   206,   206,   206,    51,    51,
     218,   148,   176,   177,   203,   -16,  -281,   261,  -281,  -281,
    -281,  -281,  -281,  -281,  -281,   262,   820,  -281,  -281,  -281,
    -281,  -281,  1091,   800,  1031,  1049,   800,   800,   265,   265,
     892,  -281,  -281,  1091,  -281,  1091,  -281,  -281,  -281,  -281,
     935,    84,   311,   800,    88,   800,    89,  -281,  -281,    31,
    -281,  -281,  -281,   283,   800,  -281,   800,  -281,   800,   872,
    -281,  -281,  -281,  -281,  -281,  -281
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -281,  -281,  -281,  -281,  -281,   -26,  -281,  -105,    85,    81,
      48,   100,   135,   137,   134,   136,   138,  -281,   -45,   -71,
    -281,   -82,  -134,   -18,     5,  -281,   282,  -281,   -85,    86,
    -281,   288,  -136,   -15,  -281,   -13,   321,   221,  -281,    -4,
     334,  -281,  -281,   131,  -281,  -123,   -70,    53,  -280,  -281,
     117,   -72,  -281,    20,  -281,   234,  -143,  -281,  -281,  -281,
    -281,   326,  -281,   315
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     152,   153,   198,   170,   175,    26,   161,   174,    41,    40,
     233,   231,   229,    47,    53,   216,   320,     6,    65,    42,
     248,   180,   181,   182,   217,   230,    15,    16,    67,    53,
     157,    44,    48,    49,   122,    50,    51,   183,   133,    68,
      26,   132,    41,   184,   252,   185,    22,   146,   254,   156,
     219,    23,    55,   315,   234,   133,    24,   132,   168,   320,
     172,   173,   147,   140,   135,   224,    62,    72,     6,   235,
      69,    66,   296,    70,   177,   155,   134,    15,    16,   152,
     246,   156,   175,   250,   251,   174,   175,   297,   244,   174,
     175,    23,   175,   154,   267,   268,   269,   339,   233,    22,
     157,   145,   262,   295,   304,   305,   219,   259,   122,    24,
     206,   207,   340,   160,   265,   219,   219,   312,   219,   156,
      41,   219,    67,   208,   209,    38,   266,   226,   255,   303,
      57,   306,    58,    39,   307,   285,   313,   186,   187,   188,
     189,   190,   191,   192,   193,   247,   194,   195,   286,   314,
     219,   287,   177,   311,   219,   219,   177,   199,   200,   164,
     177,   159,   177,   333,   196,   162,   201,   336,   338,   152,
     298,   301,   163,   156,   156,   156,   156,   156,   156,   156,
     156,   156,   156,   156,   156,   156,   156,   156,   156,   156,
     156,   165,   157,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    22,   232,
      21,   156,   218,    23,   293,   219,    62,   166,    24,     6,
     321,    62,   324,   326,   179,   152,   319,    84,    15,    16,
     212,   322,   156,   140,   327,   328,   202,   203,   299,   152,
     236,   214,   330,    86,    87,   253,   237,   213,   219,   152,
     332,   335,   169,   337,   274,   275,   276,   277,   204,   205,
     215,   256,   342,   257,   343,    71,   344,    89,   152,   319,
     331,    91,    92,    93,    94,    95,    96,   151,    98,   210,
     211,    99,   100,   101,   102,   272,   273,   270,   271,   156,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
     278,   279,    21,    74,    75,    76,    77,    78,    79,   227,
      80,    81,    82,    83,    84,    85,   228,   243,   245,   249,
     258,   260,   261,   288,   289,   292,   294,   302,   316,   317,
      86,    87,   308,   309,   334,   310,   341,   280,   282,    88,
     281,   283,   149,   148,   284,    59,   222,    43,   300,   291,
     221,    61,    73,   329,    89,     0,    52,    90,    91,    92,
      93,    94,    95,    96,    97,    98,     0,     0,    99,   100,
     101,   102,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,     0,     0,    21,    74,    75,    76,    77,    78,
      79,     0,    80,    81,    82,    83,    84,    85,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    86,    87,     0,     0,     0,     0,     0,     0,
       0,    88,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    89,     0,    52,   220,
      91,    92,    93,    94,    95,    96,    97,    98,     0,     0,
      99,   100,   101,   102,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,     0,     0,    21,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    84,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    86,    87,     0,     0,     0,     0,
       0,     0,     0,    88,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    89,     0,
       0,     0,    91,    92,    93,    94,    95,    96,   151,    98,
       0,     0,    99,   100,   101,   102,    60,     0,     0,     0,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
       0,     0,    21,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,     0,     0,
      21,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    84,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    86,    87,
       0,     0,     0,     0,    22,     0,     0,     0,     0,    23,
       0,     0,     0,     0,    24,     0,     0,     0,     0,     0,
       0,     0,    89,     0,     0,     0,    91,    92,    93,    94,
      95,    96,   151,    98,     0,     0,    99,   100,   101,   102,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
       0,     0,    21,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,     0,     0,    21,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,     0,     0,    21,     0,
       0,     0,     0,     0,    22,     0,     0,     0,     0,    23,
       0,     0,     0,     0,    24,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   138,     0,
       0,     0,     0,     0,     0,     0,     0,   139,     0,     0,
      71,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    52,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,     0,     0,    21,     0,    74,    75,    76,
      77,    78,    79,     0,    80,    81,    82,    83,    84,    85,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    86,    87,     0,     0,    84,     0,
       0,     0,     0,    88,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    86,    87,     0,     0,    89,    52,
      52,     0,    91,    92,    93,    94,    95,    96,    97,    98,
     236,     0,    99,   100,   101,   102,   237,     0,    89,     0,
     150,   318,    91,    92,    93,    94,    95,    96,   151,    98,
      84,     0,    99,   100,   101,   102,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    86,    87,     0,     0,
      84,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   236,     0,     0,     0,    86,    87,   237,     0,
      89,     0,   150,   345,    91,    92,    93,    94,    95,    96,
     151,    98,   236,     0,    99,   100,   101,   102,   237,     0,
      89,     0,   150,    84,    91,    92,    93,    94,    95,    96,
     151,    98,     0,     0,    99,   100,   101,   102,     0,    86,
      87,    84,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    86,    87,    84,
       0,     0,     0,    89,     0,   150,     0,    91,    92,    93,
      94,    95,    96,   151,    98,    86,    87,    99,   100,   101,
     102,    89,   263,     0,    88,    91,    92,    93,    94,    95,
      96,   151,    98,     0,     0,    99,   100,   101,   102,    89,
       0,    84,     0,    91,    92,    93,    94,    95,    96,   151,
      98,     0,     0,    99,   100,   101,   102,    86,    87,    84,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    86,    87,    84,     0,     0,
       0,    89,     0,   310,     0,    91,    92,    93,    94,    95,
      96,   151,    98,    86,    87,    99,   100,   101,   102,    89,
     323,     0,     0,    91,    92,    93,    94,    95,    96,   151,
      98,     0,     0,    99,   100,   101,   102,    89,   325,    84,
       0,    91,    92,    93,    94,    95,    96,   151,    98,     0,
       0,    99,   100,   101,   102,    86,    87,    84,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    86,    87,    84,     0,     0,     0,    89,
       0,     0,     0,    91,    92,    93,    94,    95,    96,   151,
      98,    86,    87,    99,   100,   101,   102,   167,     0,     0,
      84,    91,    92,    93,    94,    95,    96,   151,    98,     0,
       0,    99,   100,   101,   102,   171,    86,    87,     0,    91,
      92,    93,    94,    95,    96,   151,    98,     0,     0,    99,
     100,   101,   102,     0,     0,     0,     0,     0,     0,     0,
      89,     0,     0,     0,    91,   223,    93,    94,    95,    96,
     151,    98,     0,     0,    99,   100,   101,   102,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,     0,     0,
      21,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   290,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,     0,     0,    21
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-281)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      71,    71,   107,    85,    89,     0,    78,    89,    23,    22,
     146,   145,    66,    26,    32,    58,   296,     9,    80,    23,
     163,    54,    55,    56,    67,    79,    18,    19,    43,    47,
      75,    63,    27,    28,    52,    30,    31,    70,    56,    43,
      35,    54,    57,    76,   167,    78,    78,    66,   171,    75,
      66,    83,    32,    69,    66,    73,    88,    70,    84,   339,
      86,    87,    81,    58,     5,   136,    88,    47,     9,    81,
      63,    79,    66,    66,    89,    63,    56,    18,    19,   150,
     162,   107,   167,   165,   166,   167,   171,    81,   160,   171,
     175,    83,   177,    73,   199,   200,   201,    66,   234,    78,
     145,    68,   184,   237,   247,   248,    66,   179,   126,    88,
      59,    60,    81,    69,   185,    66,    66,    77,    66,   145,
     135,    66,   137,    72,    73,    80,   197,   140,    79,    79,
      76,    79,    78,    88,    79,   217,    66,    41,    42,    43,
      44,    45,    46,    47,    48,   163,    50,    51,   219,    79,
      66,   222,   167,   258,    66,    66,   171,    74,    75,    88,
     175,    63,   177,    79,    68,    78,    83,    79,    79,   240,
     240,   243,    78,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,    78,   237,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    78,    81,
      26,   237,    63,    83,    81,    66,    88,    78,    88,     9,
     302,    88,   304,   305,    69,   296,   296,    38,    18,    19,
      82,   303,   258,   228,   306,   307,    84,    85,    68,   310,
      70,    64,   313,    54,    55,    63,    76,    71,    66,   320,
     320,   323,    63,   325,   206,   207,   208,   209,    52,    53,
      57,   175,   334,   177,   336,    68,   338,    78,   339,   339,
     315,    82,    83,    84,    85,    86,    87,    88,    89,    61,
      62,    92,    93,    94,    95,   204,   205,   202,   203,   315,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
     210,   211,    26,    27,    28,    29,    30,    31,    32,    79,
      34,    35,    36,    37,    38,    39,    66,    69,    36,    63,
      79,    88,    88,    77,    77,    88,    88,    78,    77,    77,
      54,    55,    79,    79,    33,    80,    63,   212,   214,    63,
     213,   215,    70,    65,   216,    34,   135,    23,   241,   228,
     126,    35,    47,   310,    78,    -1,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    -1,    -1,    92,    93,
      94,    95,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    -1,    -1,    26,    27,    28,    29,    30,    31,
      32,    -1,    34,    35,    36,    37,    38,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    -1,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    -1,    -1,
      92,    93,    94,    95,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    -1,    -1,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    54,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    -1,
      -1,    -1,    82,    83,    84,    85,    86,    87,    88,    89,
      -1,    -1,    92,    93,    94,    95,     0,    -1,    -1,    -1,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      -1,    -1,    26,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    -1,    -1,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    55,
      -1,    -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,    83,
      -1,    -1,    -1,    -1,    88,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    -1,    -1,    -1,    82,    83,    84,    85,
      86,    87,    88,    89,    -1,    -1,    92,    93,    94,    95,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      -1,    -1,    26,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    -1,    -1,    26,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    -1,    -1,    26,    -1,
      -1,    -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,    83,
      -1,    -1,    -1,    -1,    88,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    -1,    -1,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    80,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    -1,    -1,    26,    -1,    27,    28,    29,
      30,    31,    32,    -1,    34,    35,    36,    37,    38,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    54,    55,    -1,    -1,    38,    -1,
      -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    54,    55,    -1,    -1,    78,    80,
      80,    -1,    82,    83,    84,    85,    86,    87,    88,    89,
      70,    -1,    92,    93,    94,    95,    76,    -1,    78,    -1,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      38,    -1,    92,    93,    94,    95,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    54,    55,    -1,    -1,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    -1,    -1,    -1,    54,    55,    76,    -1,
      78,    -1,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    70,    -1,    92,    93,    94,    95,    76,    -1,
      78,    -1,    80,    38,    82,    83,    84,    85,    86,    87,
      88,    89,    -1,    -1,    92,    93,    94,    95,    -1,    54,
      55,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    55,    38,
      -1,    -1,    -1,    78,    -1,    80,    -1,    82,    83,    84,
      85,    86,    87,    88,    89,    54,    55,    92,    93,    94,
      95,    78,    79,    -1,    63,    82,    83,    84,    85,    86,
      87,    88,    89,    -1,    -1,    92,    93,    94,    95,    78,
      -1,    38,    -1,    82,    83,    84,    85,    86,    87,    88,
      89,    -1,    -1,    92,    93,    94,    95,    54,    55,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    54,    55,    38,    -1,    -1,
      -1,    78,    -1,    80,    -1,    82,    83,    84,    85,    86,
      87,    88,    89,    54,    55,    92,    93,    94,    95,    78,
      79,    -1,    -1,    82,    83,    84,    85,    86,    87,    88,
      89,    -1,    -1,    92,    93,    94,    95,    78,    79,    38,
      -1,    82,    83,    84,    85,    86,    87,    88,    89,    -1,
      -1,    92,    93,    94,    95,    54,    55,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    54,    55,    38,    -1,    -1,    -1,    78,
      -1,    -1,    -1,    82,    83,    84,    85,    86,    87,    88,
      89,    54,    55,    92,    93,    94,    95,    78,    -1,    -1,
      38,    82,    83,    84,    85,    86,    87,    88,    89,    -1,
      -1,    92,    93,    94,    95,    78,    54,    55,    -1,    82,
      83,    84,    85,    86,    87,    88,    89,    -1,    -1,    92,
      93,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    -1,    -1,    -1,    82,    83,    84,    85,    86,    87,
      88,    89,    -1,    -1,    92,    93,    94,    95,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    -1,    -1,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    40,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    -1,    -1,    26
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    26,    78,    83,    88,   120,   121,   124,   125,   127,
     130,   131,   132,   133,   136,   157,   158,   159,    80,    88,
     132,   130,   136,   137,    63,   122,   123,   132,   121,   121,
     121,   121,    80,   120,   121,   150,   160,    76,    78,   133,
       0,   158,    88,   128,   129,    80,    79,   130,   136,    63,
      66,    68,   150,   160,    27,    28,    29,    30,    31,    32,
      34,    35,    36,    37,    38,    39,    54,    55,    63,    78,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    92,
      93,    94,    95,    98,    99,   100,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   118,   120,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   132,   120,   150,     5,   134,   137,    79,    88,
     121,   138,   139,   140,   141,    68,    66,    81,   128,   123,
      80,    88,   116,   143,   150,    63,   102,   115,   119,    63,
      69,   148,    78,    78,    88,    78,    78,    78,   102,    63,
     118,    78,   102,   102,   118,   125,   126,   130,   142,    69,
      54,    55,    56,    70,    76,    78,    41,    42,    43,    44,
      45,    46,    47,    48,    50,    51,    68,   117,   104,    74,
      75,    83,    84,    85,    52,    53,    59,    60,    72,    73,
      61,    62,    82,    71,    64,    57,    58,    67,    63,    66,
      81,   152,   134,    83,   116,   135,   132,    79,    66,    66,
      79,   119,    81,   129,    66,    81,    70,    76,   143,   144,
     145,   146,   147,    69,   148,    36,   118,   120,   153,    63,
     118,   118,   142,    63,   142,    79,   126,   126,    79,   148,
      88,    88,   118,    79,   101,   116,   116,   104,   104,   104,
     105,   105,   106,   106,   107,   107,   107,   107,   108,   108,
     109,   110,   111,   112,   113,   118,   116,   116,    77,    77,
      40,   140,    88,    81,    88,   119,    66,    81,   143,    68,
     147,   148,    78,    79,   153,   153,    79,    79,    79,    79,
      80,   104,    77,    66,    79,    69,    77,    77,    81,   143,
     145,   118,   148,    79,   118,    79,   118,   148,   148,   144,
     116,   115,   143,    79,    33,   148,    79,   148,    79,    66,
      81,    63,   148,   148,   148,    81
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

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
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




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

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

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  if (yypact_value_is_default (yyn))
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
      if (yytable_value_is_error (yyn))
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
/* Line 1792 of yacc.c  */
#line 41 "ass4_16CS30027.y"
    {printf("primary_expression -> identifier \n");}
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 42 "ass4_16CS30027.y"
    {printf("primary_expression -> constant\n");}
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 43 "ass4_16CS30027.y"
    {printf("primary_expression-> string-literal \n");}
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 44 "ass4_16CS30027.y"
    {printf("primary_expression -> (expression) \n");}
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 49 "ass4_16CS30027.y"
    {printf("constant->integer constant \n");}
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 50 "ass4_16CS30027.y"
    {printf("constant->float constant \n");}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 51 "ass4_16CS30027.y"
    {printf("constant-> enumeration constant \n");}
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 52 "ass4_16CS30027.y"
    {printf("constant-> char constant \n");}
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 56 "ass4_16CS30027.y"
    {printf("postfix expression-> primary expression\n");}
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 57 "ass4_16CS30027.y"
    {printf("postfix_expression-> postfix_expression ( expression )\n");}
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 58 "ass4_16CS30027.y"
    {printf("postfix expression-> postfix ( )\n");}
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 59 "ass4_16CS30027.y"
    {printf("postfix expression-> postfix expression ( argument expression_list )\n");}
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 60 "ass4_16CS30027.y"
    {printf("postfix expression-> postfix expression . identifier\n");}
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 61 "ass4_16CS30027.y"
    {printf("postfix expression-> postfix expression -> identifier\n");}
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 62 "ass4_16CS30027.y"
    {printf("postfix expression-> postfix expression ++\n");}
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 63 "ass4_16CS30027.y"
    {printf("postfix expression-> postfix expression --\n");}
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 64 "ass4_16CS30027.y"
    {printf("postfix expression-> '(' type_name ')' '{' initializer_list '}' \n");}
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 65 "ass4_16CS30027.y"
    {printf("postfix expression-> '(' type_name ')' '{' initializer_list , '}' \n");}
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 70 "ass4_16CS30027.y"
    {printf("argument expression-> assignment expression \n");}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 71 "ass4_16CS30027.y"
    {printf("argument expression-> assignment expression list , assignmentexpression \n");}
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 76 "ass4_16CS30027.y"
    {printf("unary expression-> postfix expression \n");}
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 77 "ass4_16CS30027.y"
    {printf("unary_expression -> ++ unaryexpression\n");}
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 78 "ass4_16CS30027.y"
    {printf("unary_expression -> ++ unaryexpression\n");}
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 79 "ass4_16CS30027.y"
    {printf("unary_expression -> unaryoperator castexpression\n");}
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 80 "ass4_16CS30027.y"
    {printf("unary_expression -> sizeof unaryexpression\n");}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 81 "ass4_16CS30027.y"
    {printf("unary_expression -> sizeof ( typename )\n");}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 85 "ass4_16CS30027.y"
    {printf("unary operator &\n");}
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 86 "ass4_16CS30027.y"
    {printf("unary operator *\n");}
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 87 "ass4_16CS30027.y"
    {printf("unary operator +\n");}
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 88 "ass4_16CS30027.y"
    {printf("unary operator -\n");}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 89 "ass4_16CS30027.y"
    {printf("unary operator ~\n");}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 90 "ass4_16CS30027.y"
    {printf("unary operator !\n");}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 94 "ass4_16CS30027.y"
    {printf("cast_expression -> unaryexpression\n");}
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 95 "ass4_16CS30027.y"
    {printf("cast_expression -> ( typename ) castexpression \n");}
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 100 "ass4_16CS30027.y"
    {printf("multiplicative_expression -> castexpression \n");}
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 101 "ass4_16CS30027.y"
    {printf("multiplicative_expression -> multiplicative expression * castexpression \n");}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 102 "ass4_16CS30027.y"
    {printf("multiplicative_expression -> multiplicative expression / castexpression \n");}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 103 "ass4_16CS30027.y"
    {printf("multiplicative_expression -> multiplicative expression %% castexpression \n");}
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 108 "ass4_16CS30027.y"
    {printf("additive_expression -> multiplicative_expression\n");}
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 109 "ass4_16CS30027.y"
    {printf("additive_expression -> additiveexpression + multiplicative_expression\n");}
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 110 "ass4_16CS30027.y"
    {printf("additive_expression -> additiveexpression - multiplicative_expression\n");}
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 115 "ass4_16CS30027.y"
    {printf("shift_expression -> additive expression\n");}
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 116 "ass4_16CS30027.y"
    {printf("shift_expression -> shiftexpression << additive expression\n");}
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 117 "ass4_16CS30027.y"
    {printf("shift_expression -> shiftexpression >> additive expression\n");}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 122 "ass4_16CS30027.y"
    {printf("relational_expression -> shiftexpression\n");}
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 123 "ass4_16CS30027.y"
    {printf("relational_expression -> relationalexpression < shiftexpression\n");}
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 124 "ass4_16CS30027.y"
    {printf("relational_expression -> relationalexpression > shiftexpression\n");}
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 125 "ass4_16CS30027.y"
    {printf("relational_expression -> relationalexpression <= shiftexpression\n");}
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 126 "ass4_16CS30027.y"
    {printf("relational_expression -> relationalexpression >= shiftexpression\n");}
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 131 "ass4_16CS30027.y"
    {printf("equality-expression -> relational_expression\n");}
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 132 "ass4_16CS30027.y"
    {printf("equality-expression -> equalityexpression == relational_expression\n");}
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 133 "ass4_16CS30027.y"
    {printf("equality-expression -> equalityexpression != relational_expression\n");}
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 138 "ass4_16CS30027.y"
    {printf("and_expression -> equality_expression\n");}
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 139 "ass4_16CS30027.y"
    {printf("and_expression -> and_expression & equality_expression\n");}
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 144 "ass4_16CS30027.y"
    {printf("exclusive_or_expression -> and_expression \n");}
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 145 "ass4_16CS30027.y"
    {printf("exclusive_or_expression -> exclusive_or_expression ^ and_expression \n");}
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 150 "ass4_16CS30027.y"
    {printf("inclusive_or_expression -> exclusive_or_expression \n");}
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 151 "ass4_16CS30027.y"
    {printf("inclusive_or_expression -> inclusive_or_expression  | exclusive_or_expression \n");}
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 156 "ass4_16CS30027.y"
    {printf("logical_and_expression -> inclusive-or-expression\n");}
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 157 "ass4_16CS30027.y"
    {printf("logical_and_expression -> logical-and-expression && inclusive-or-expression\n");}
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 162 "ass4_16CS30027.y"
    {printf("logical_or_expression -> logical_and_expression\n");}
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 163 "ass4_16CS30027.y"
    {printf("logical_or_expression -> logical_or_expression || logical_and_expression\n");}
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 168 "ass4_16CS30027.y"
    {printf("conditional_expression -> logical-or-expression\n");}
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 169 "ass4_16CS30027.y"
    {printf("conditional_expression -> logical-or-expression ? expression : conditional expression\n");}
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 174 "ass4_16CS30027.y"
    {printf("assignment_expression -> conditional_expression\n");}
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 175 "ass4_16CS30027.y"
    {printf("assignment_expression->unary_expression assignment_operator assignment_expression\n");}
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 180 "ass4_16CS30027.y"
    {printf("assignment_operator =\n");}
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 181 "ass4_16CS30027.y"
    {printf("assignment_operator *=\n");}
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 182 "ass4_16CS30027.y"
    {printf("assignment_operator /=\n");}
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 183 "ass4_16CS30027.y"
    {printf("assignment_operator %=\n");}
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 184 "ass4_16CS30027.y"
    {printf("assignment_operator +=\n");}
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 185 "ass4_16CS30027.y"
    {printf("assignment_operator -=\n");}
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 186 "ass4_16CS30027.y"
    {printf("assignment_operator <<=\n");}
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 187 "ass4_16CS30027.y"
    {printf("assignment_operator >>=\n");}
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 188 "ass4_16CS30027.y"
    {printf("assignment_operator &=\n");}
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 189 "ass4_16CS30027.y"
    {printf("assignment_operator ^=\n");}
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 190 "ass4_16CS30027.y"
    {printf("assignment_operator |=\n");}
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 195 "ass4_16CS30027.y"
    {printf("expression -> assignment-expression\n");}
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 196 "ass4_16CS30027.y"
    {printf("expression -> expression , assignment-expression\n");}
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 201 "ass4_16CS30027.y"
    {printf("constant_expression -> conditional-expression\n");}
    break;

  case 82:
/* Line 1792 of yacc.c  */
#line 206 "ass4_16CS30027.y"
    {printf("declaration ->declaration_specifiers initializer_list \n");}
    break;

  case 83:
/* Line 1792 of yacc.c  */
#line 207 "ass4_16CS30027.y"
    {printf("declaration ->declaration_specifiers initializer_list ; \n");}
    break;

  case 84:
/* Line 1792 of yacc.c  */
#line 212 "ass4_16CS30027.y"
    {printf("declaration_specifiers -> storage_class_specifier \n");}
    break;

  case 85:
/* Line 1792 of yacc.c  */
#line 213 "ass4_16CS30027.y"
    {printf("declaration_specifiers -> storage_class_specifier declaration_specifiers \n");}
    break;

  case 86:
/* Line 1792 of yacc.c  */
#line 214 "ass4_16CS30027.y"
    {printf("declaration_specifiers -> typespecifier \n");}
    break;

  case 87:
/* Line 1792 of yacc.c  */
#line 215 "ass4_16CS30027.y"
    {printf("declaration_specifiers -> type_specifier declaration_specifiers \n");}
    break;

  case 88:
/* Line 1792 of yacc.c  */
#line 216 "ass4_16CS30027.y"
    {printf("declaration_specifiers -> type qualifier \n");}
    break;

  case 89:
/* Line 1792 of yacc.c  */
#line 217 "ass4_16CS30027.y"
    {printf("declaration_specifiers -> type qualifier declaration_specifiers \n");}
    break;

  case 90:
/* Line 1792 of yacc.c  */
#line 218 "ass4_16CS30027.y"
    {printf("declaration_specifiers -> functionspecifier  \n");}
    break;

  case 91:
/* Line 1792 of yacc.c  */
#line 219 "ass4_16CS30027.y"
    {printf("declaration_specifiers -> function_specifier declaration_specifiers \n");}
    break;

  case 92:
/* Line 1792 of yacc.c  */
#line 224 "ass4_16CS30027.y"
    {printf("init_declarator_list -> init_declarator \n");}
    break;

  case 93:
/* Line 1792 of yacc.c  */
#line 225 "ass4_16CS30027.y"
    {printf("init_declarator_list -> init_declarator_list , init_declarator \n");}
    break;

  case 94:
/* Line 1792 of yacc.c  */
#line 230 "ass4_16CS30027.y"
    {printf("init_declarator -> declarator \n");}
    break;

  case 95:
/* Line 1792 of yacc.c  */
#line 231 "ass4_16CS30027.y"
    {printf("init_declarator -> declarator = initializer \n");}
    break;

  case 96:
/* Line 1792 of yacc.c  */
#line 236 "ass4_16CS30027.y"
    {printf("storage_class_specifier -> extern\n");}
    break;

  case 97:
/* Line 1792 of yacc.c  */
#line 237 "ass4_16CS30027.y"
    {printf("storage_class_specifier -> static\n");}
    break;

  case 98:
/* Line 1792 of yacc.c  */
#line 238 "ass4_16CS30027.y"
    {printf("storage_class_specifier -> auto\n");}
    break;

  case 99:
/* Line 1792 of yacc.c  */
#line 239 "ass4_16CS30027.y"
    {printf("storage_class_specifier -> register\n");}
    break;

  case 100:
/* Line 1792 of yacc.c  */
#line 244 "ass4_16CS30027.y"
    {printf("type_specifier -> void\n");}
    break;

  case 101:
/* Line 1792 of yacc.c  */
#line 245 "ass4_16CS30027.y"
    {printf("type_specifier -> char\n");}
    break;

  case 102:
/* Line 1792 of yacc.c  */
#line 246 "ass4_16CS30027.y"
    {printf("type_specifier -> short\n");}
    break;

  case 103:
/* Line 1792 of yacc.c  */
#line 247 "ass4_16CS30027.y"
    {printf("type_specifier -> int\n");}
    break;

  case 104:
/* Line 1792 of yacc.c  */
#line 248 "ass4_16CS30027.y"
    {printf("type_specifier -> long\n");}
    break;

  case 105:
/* Line 1792 of yacc.c  */
#line 249 "ass4_16CS30027.y"
    {printf("type_specifier -> float\n");}
    break;

  case 106:
/* Line 1792 of yacc.c  */
#line 250 "ass4_16CS30027.y"
    {printf("type_specifier -> double\n");}
    break;

  case 107:
/* Line 1792 of yacc.c  */
#line 251 "ass4_16CS30027.y"
    {printf("type_specifier -> signed\n");}
    break;

  case 108:
/* Line 1792 of yacc.c  */
#line 252 "ass4_16CS30027.y"
    {printf("type_specifier -> unsigned\n");}
    break;

  case 109:
/* Line 1792 of yacc.c  */
#line 253 "ass4_16CS30027.y"
    {printf("type_specifier -> bool\n");}
    break;

  case 110:
/* Line 1792 of yacc.c  */
#line 254 "ass4_16CS30027.y"
    {printf("type_specifier -> complex  n");}
    break;

  case 111:
/* Line 1792 of yacc.c  */
#line 255 "ass4_16CS30027.y"
    {printf("type_specifier -> imaginary\n");}
    break;

  case 112:
/* Line 1792 of yacc.c  */
#line 256 "ass4_16CS30027.y"
    {printf("type_specifier -> enum specifier\n");}
    break;

  case 113:
/* Line 1792 of yacc.c  */
#line 263 "ass4_16CS30027.y"
    {printf("specifier_qualifier_list -> type_specifier specifier_qualifier_list\n");}
    break;

  case 114:
/* Line 1792 of yacc.c  */
#line 264 "ass4_16CS30027.y"
    {printf("specifier_qualifier_list -> type_specifier \n");}
    break;

  case 115:
/* Line 1792 of yacc.c  */
#line 265 "ass4_16CS30027.y"
    {printf("specifier_qualifier_list -> type_qualifier specifier_qualifier_list\n");}
    break;

  case 116:
/* Line 1792 of yacc.c  */
#line 266 "ass4_16CS30027.y"
    {printf("specifier_qualifier_list -> typequalifier \n");}
    break;

  case 117:
/* Line 1792 of yacc.c  */
#line 272 "ass4_16CS30027.y"
    {printf("enum_specifier -> 'enum' { enumerationlist } \n");}
    break;

  case 118:
/* Line 1792 of yacc.c  */
#line 273 "ass4_16CS30027.y"
    {printf("enum_specifier -> 'enum' identifier { enumerationlist } \n");}
    break;

  case 119:
/* Line 1792 of yacc.c  */
#line 274 "ass4_16CS30027.y"
    {printf("enum_specifier -> 'enum' { enumerationlist } \n");}
    break;

  case 120:
/* Line 1792 of yacc.c  */
#line 275 "ass4_16CS30027.y"
    {printf("enum_specifier -> 'enum' identifier { enumerationlist , } \n");}
    break;

  case 121:
/* Line 1792 of yacc.c  */
#line 276 "ass4_16CS30027.y"
    {printf("enum_specifier -> 'enum' identifier \n");}
    break;

  case 122:
/* Line 1792 of yacc.c  */
#line 281 "ass4_16CS30027.y"
    {printf("enumerator_list -> enumerator \n");}
    break;

  case 123:
/* Line 1792 of yacc.c  */
#line 282 "ass4_16CS30027.y"
    {printf("enumerator_list -> enumerator_list , enumerator \n");}
    break;

  case 124:
/* Line 1792 of yacc.c  */
#line 287 "ass4_16CS30027.y"
    {printf("enumerator -> identifier\n");}
    break;

  case 125:
/* Line 1792 of yacc.c  */
#line 288 "ass4_16CS30027.y"
    {printf("enumerator -> identifier = constant-expression \n");}
    break;

  case 126:
/* Line 1792 of yacc.c  */
#line 293 "ass4_16CS30027.y"
    {printf("type_qualifier 'const'\n");}
    break;

  case 127:
/* Line 1792 of yacc.c  */
#line 294 "ass4_16CS30027.y"
    {printf("type_qualifier 'volatile'\n");}
    break;

  case 128:
/* Line 1792 of yacc.c  */
#line 295 "ass4_16CS30027.y"
    {printf("type_qualifier 'restrict'\n");}
    break;

  case 129:
/* Line 1792 of yacc.c  */
#line 300 "ass4_16CS30027.y"
    {printf("function_specifier -> 'inline'\n");}
    break;

  case 130:
/* Line 1792 of yacc.c  */
#line 303 "ass4_16CS30027.y"
    {printf("declarator -> pointer directdeclator\n");}
    break;

  case 131:
/* Line 1792 of yacc.c  */
#line 304 "ass4_16CS30027.y"
    {printf("declarator -> direct_declarator\n");}
    break;

  case 132:
/* Line 1792 of yacc.c  */
#line 309 "ass4_16CS30027.y"
    {printf("direct_declarator -> identifier \n");}
    break;

  case 133:
/* Line 1792 of yacc.c  */
#line 310 "ass4_16CS30027.y"
    {printf("direct_declarator -> ( declarator )\n");}
    break;

  case 134:
/* Line 1792 of yacc.c  */
#line 311 "ass4_16CS30027.y"
    {printf(" direct_declarator-> direct_declarator [type_qualifier_list_opt assignment_expression ] \n");}
    break;

  case 135:
/* Line 1792 of yacc.c  */
#line 312 "ass4_16CS30027.y"
    {printf(" direct_declarator-> direct_declarator [ 'static' type_qualifier_list_opt assignment_expression ] \n");}
    break;

  case 136:
/* Line 1792 of yacc.c  */
#line 313 "ass4_16CS30027.y"
    {printf(" direct_declarator-> direct_declarator [type_qualifier_list_opt * ] \n");}
    break;

  case 137:
/* Line 1792 of yacc.c  */
#line 314 "ass4_16CS30027.y"
    {printf(" direct_declarator-> direct_declarator ( parameter_type_list ) \n");}
    break;

  case 138:
/* Line 1792 of yacc.c  */
#line 315 "ass4_16CS30027.y"
    {printf(" direct_declarator-> direct_declarator ( identifier_list ) \n");}
    break;

  case 139:
/* Line 1792 of yacc.c  */
#line 316 "ass4_16CS30027.y"
    {printf(" direct_declarator-> direct_declarator (  ) \n");}
    break;

  case 141:
/* Line 1792 of yacc.c  */
#line 324 "ass4_16CS30027.y"
    {printf("type_qualifier_list_opt\n");}
    break;

  case 143:
/* Line 1792 of yacc.c  */
#line 330 "ass4_16CS30027.y"
    {printf("assignment_expression_opt\n");}
    break;

  case 144:
/* Line 1792 of yacc.c  */
#line 334 "ass4_16CS30027.y"
    {printf("pointer -> * \n");}
    break;

  case 145:
/* Line 1792 of yacc.c  */
#line 335 "ass4_16CS30027.y"
    {printf("pointer -> * type_qualifier_list\n");}
    break;

  case 146:
/* Line 1792 of yacc.c  */
#line 336 "ass4_16CS30027.y"
    {printf("pointer -> * pointer\n");}
    break;

  case 147:
/* Line 1792 of yacc.c  */
#line 337 "ass4_16CS30027.y"
    {printf("pointer -> * type-qualifier-list \n");}
    break;

  case 148:
/* Line 1792 of yacc.c  */
#line 342 "ass4_16CS30027.y"
    {printf("type_qualifier_list -> type_qualifier\n");}
    break;

  case 149:
/* Line 1792 of yacc.c  */
#line 343 "ass4_16CS30027.y"
    {printf("type_qualifier_list -> type_qualifier_list  type_qualifier \n");}
    break;

  case 150:
/* Line 1792 of yacc.c  */
#line 349 "ass4_16CS30027.y"
    {printf("parameter_type_list -> parameter_list\n");}
    break;

  case 151:
/* Line 1792 of yacc.c  */
#line 350 "ass4_16CS30027.y"
    {printf("parameter_type_list -> parameter_list , ...\n");}
    break;

  case 152:
/* Line 1792 of yacc.c  */
#line 355 "ass4_16CS30027.y"
    {printf("parameter_list -> parameter-declaration\n");}
    break;

  case 153:
/* Line 1792 of yacc.c  */
#line 356 "ass4_16CS30027.y"
    {printf("parameter_list -> parameter-list , parameter-declaration\n");}
    break;

  case 154:
/* Line 1792 of yacc.c  */
#line 361 "ass4_16CS30027.y"
    {printf("parameter_declaration -> declaration-specifiers declarator \n");}
    break;

  case 155:
/* Line 1792 of yacc.c  */
#line 362 "ass4_16CS30027.y"
    {printf("parameter_declaration -> declaration-specifiers  \n");}
    break;

  case 156:
/* Line 1792 of yacc.c  */
#line 367 "ass4_16CS30027.y"
    {printf("identifier_list -> identifier\n");}
    break;

  case 157:
/* Line 1792 of yacc.c  */
#line 368 "ass4_16CS30027.y"
    {printf("identifier_list -> identifier_list , identifier \n");}
    break;

  case 158:
/* Line 1792 of yacc.c  */
#line 374 "ass4_16CS30027.y"
    {printf("type_name -> specifier\n");}
    break;

  case 159:
/* Line 1792 of yacc.c  */
#line 381 "ass4_16CS30027.y"
    {printf("initializer -> assignment-expression\n");}
    break;

  case 160:
/* Line 1792 of yacc.c  */
#line 382 "ass4_16CS30027.y"
    {printf("initializer -> { initializer-list }\n");}
    break;

  case 161:
/* Line 1792 of yacc.c  */
#line 383 "ass4_16CS30027.y"
    {printf("initializer -> { initializer-list , }\n");}
    break;

  case 162:
/* Line 1792 of yacc.c  */
#line 388 "ass4_16CS30027.y"
    {printf("initializer_list -> initializer\n");}
    break;

  case 163:
/* Line 1792 of yacc.c  */
#line 389 "ass4_16CS30027.y"
    {printf("initializer_list -> designation initializer\n");}
    break;

  case 164:
/* Line 1792 of yacc.c  */
#line 390 "ass4_16CS30027.y"
    {printf("initializer_list -> initializer-list , intializer\n");}
    break;

  case 165:
/* Line 1792 of yacc.c  */
#line 391 "ass4_16CS30027.y"
    {printf("initializer_list -> initializer-list , designation intializer\n");}
    break;

  case 166:
/* Line 1792 of yacc.c  */
#line 397 "ass4_16CS30027.y"
    {printf("designation -> designator_list =\n");}
    break;

  case 167:
/* Line 1792 of yacc.c  */
#line 401 "ass4_16CS30027.y"
    {printf("designator_list -> designator\n");}
    break;

  case 168:
/* Line 1792 of yacc.c  */
#line 402 "ass4_16CS30027.y"
    {printf("designator_list -> designator_list designator\n");}
    break;

  case 169:
/* Line 1792 of yacc.c  */
#line 407 "ass4_16CS30027.y"
    {printf("designator -> [ constant-expression ]\n");}
    break;

  case 170:
/* Line 1792 of yacc.c  */
#line 408 "ass4_16CS30027.y"
    {printf("designator -> . identifier\n");}
    break;

  case 171:
/* Line 1792 of yacc.c  */
#line 413 "ass4_16CS30027.y"
    {printf("statement -> labeled statement\n");}
    break;

  case 172:
/* Line 1792 of yacc.c  */
#line 414 "ass4_16CS30027.y"
    {printf("statement -> compound statement\n");}
    break;

  case 173:
/* Line 1792 of yacc.c  */
#line 415 "ass4_16CS30027.y"
    {printf("statement -> expression statement\n");}
    break;

  case 174:
/* Line 1792 of yacc.c  */
#line 416 "ass4_16CS30027.y"
    {printf("statement -> selection statement\n");}
    break;

  case 175:
/* Line 1792 of yacc.c  */
#line 417 "ass4_16CS30027.y"
    {printf("statement -> iteration statement\n");}
    break;

  case 176:
/* Line 1792 of yacc.c  */
#line 418 "ass4_16CS30027.y"
    {printf("statement -> jump statement\n");}
    break;

  case 177:
/* Line 1792 of yacc.c  */
#line 423 "ass4_16CS30027.y"
    {printf("labeled_statement -> identifier : statement\n");}
    break;

  case 178:
/* Line 1792 of yacc.c  */
#line 424 "ass4_16CS30027.y"
    {printf("labeled_statement -> case constant_expression : statement\n");}
    break;

  case 179:
/* Line 1792 of yacc.c  */
#line 425 "ass4_16CS30027.y"
    {printf("labeled_statement -> default : statement\n");}
    break;

  case 180:
/* Line 1792 of yacc.c  */
#line 430 "ass4_16CS30027.y"
    {printf("compound_statement -> { }\n");}
    break;

  case 181:
/* Line 1792 of yacc.c  */
#line 431 "ass4_16CS30027.y"
    {printf("compound_statement -> { block_item_list }\n");}
    break;

  case 182:
/* Line 1792 of yacc.c  */
#line 436 "ass4_16CS30027.y"
    {printf("block_item_list -> block_item\n");}
    break;

  case 183:
/* Line 1792 of yacc.c  */
#line 437 "ass4_16CS30027.y"
    {printf("block_item_list -> block_item_list block_item\n");}
    break;

  case 184:
/* Line 1792 of yacc.c  */
#line 442 "ass4_16CS30027.y"
    {printf("block_item -> declarator \n");}
    break;

  case 185:
/* Line 1792 of yacc.c  */
#line 443 "ass4_16CS30027.y"
    {printf("block_item -> statement \n");}
    break;

  case 186:
/* Line 1792 of yacc.c  */
#line 449 "ass4_16CS30027.y"
    {printf("expression_statement ->  ;\n");}
    break;

  case 187:
/* Line 1792 of yacc.c  */
#line 450 "ass4_16CS30027.y"
    {printf("expression_statement -> expression ;\n");}
    break;

  case 188:
/* Line 1792 of yacc.c  */
#line 455 "ass4_16CS30027.y"
    {printf("selection_statement -> 'if' ( expression ) statement\n");}
    break;

  case 189:
/* Line 1792 of yacc.c  */
#line 456 "ass4_16CS30027.y"
    {printf("selection_statement -> 'if' ( expression ) statement 'else' statement \n");}
    break;

  case 190:
/* Line 1792 of yacc.c  */
#line 457 "ass4_16CS30027.y"
    {printf("selection_statement -> 'switch' ( expression ) statement  \n");}
    break;

  case 191:
/* Line 1792 of yacc.c  */
#line 462 "ass4_16CS30027.y"
    {printf("iteration_statement -> 'while' '(' expression ')' statement\n");}
    break;

  case 192:
/* Line 1792 of yacc.c  */
#line 463 "ass4_16CS30027.y"
    {printf("iteration_statement -> 'do' statement 'while' '(' expression ')' ;\n");}
    break;

  case 193:
/* Line 1792 of yacc.c  */
#line 464 "ass4_16CS30027.y"
    {printf("iteration_statement -> 'for' '(' expression_statement expression_statement expression ')' statement\n");}
    break;

  case 194:
/* Line 1792 of yacc.c  */
#line 466 "ass4_16CS30027.y"
    {printf("iteration_statement -> 'for' '(' expression_statement expression_statement ')' statement\n");}
    break;

  case 195:
/* Line 1792 of yacc.c  */
#line 468 "ass4_16CS30027.y"
    {printf("iteration_statement -> 'for' '(' declaration expression_statement expression ')' statement\n");}
    break;

  case 196:
/* Line 1792 of yacc.c  */
#line 470 "ass4_16CS30027.y"
    {printf("iteration_statement -> 'for' '(' declaration expression_statement ';' ')' statement\n");}
    break;

  case 197:
/* Line 1792 of yacc.c  */
#line 474 "ass4_16CS30027.y"
    {printf("jump_statement -> 'goto' identifier ';'\n");}
    break;

  case 198:
/* Line 1792 of yacc.c  */
#line 475 "ass4_16CS30027.y"
    {printf("jump_statement -> 'continue' ';'\n");}
    break;

  case 199:
/* Line 1792 of yacc.c  */
#line 476 "ass4_16CS30027.y"
    {printf("jump_statement -> 'break' ';'\n");}
    break;

  case 200:
/* Line 1792 of yacc.c  */
#line 477 "ass4_16CS30027.y"
    {printf("jump_statement -> 'return' ';'\n");}
    break;

  case 201:
/* Line 1792 of yacc.c  */
#line 478 "ass4_16CS30027.y"
    {printf("jump_statement -> 'return' expression ';'\n");}
    break;

  case 202:
/* Line 1792 of yacc.c  */
#line 483 "ass4_16CS30027.y"
    {printf("translation_unit -> external_declaration\n");}
    break;

  case 203:
/* Line 1792 of yacc.c  */
#line 484 "ass4_16CS30027.y"
    {printf("translation_unit -> translation_unit external_declaration\n");}
    break;

  case 204:
/* Line 1792 of yacc.c  */
#line 489 "ass4_16CS30027.y"
    {printf("external_declaration -> function_definition\n");}
    break;

  case 205:
/* Line 1792 of yacc.c  */
#line 490 "ass4_16CS30027.y"
    {printf("external_declaration -> declaration\n");}
    break;

  case 206:
/* Line 1792 of yacc.c  */
#line 495 "ass4_16CS30027.y"
    {printf("function_definition -> declaration_specifiers declarator declaration_list compound_statement\n");}
    break;

  case 207:
/* Line 1792 of yacc.c  */
#line 496 "ass4_16CS30027.y"
    {printf("function_definition -> declaration_specifiers declarator compound_statement\n");}
    break;

  case 208:
/* Line 1792 of yacc.c  */
#line 497 "ass4_16CS30027.y"
    {printf("function_definition -> declarator declaration_list compound_statement\n");}
    break;

  case 209:
/* Line 1792 of yacc.c  */
#line 498 "ass4_16CS30027.y"
    {printf("function_definition -> declarator compound_statement\n");}
    break;

  case 210:
/* Line 1792 of yacc.c  */
#line 501 "ass4_16CS30027.y"
    {printf("declaration_list -> declaration\n");}
    break;

  case 211:
/* Line 1792 of yacc.c  */
#line 502 "ass4_16CS30027.y"
    {printf("declaration_list -> declaration_list declaration\n");}
    break;


/* Line 1792 of yacc.c  */
#line 3248 "ass4_16CS30027.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
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
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
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


/* Line 2055 of yacc.c  */
#line 506 "ass4_16CS30027.y"



void yyerror(char *s) {
	printf ("\n ERROR: %s\n",s);
}
