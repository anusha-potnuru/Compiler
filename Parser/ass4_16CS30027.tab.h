/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
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
/* Line 2058 of yacc.c  */
#line 7 "ass4_16CS30027.y"

int intval;
  float floatval;
  char *charval;


/* Line 2058 of yacc.c  */
#line 160 "ass4_16CS30027.tab.h"
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
