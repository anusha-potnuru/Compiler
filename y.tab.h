#define AUTO 257
#define ENUM 258
#define RESTRICT 259
#define UNSIGNED 260
#define BREAK 261
#define EXTERN 262
#define RETURN 263
#define VOID 264
#define CASE 265
#define FLOAT 266
#define SHORT 267
#define VOLATILE 268
#define CHAR 269
#define FOR 270
#define SIGNED 271
#define WHILE 272
#define CONST 273
#define GOTO 274
#define SIZEOF 275
#define BOOL 276
#define CONTINUE 277
#define IF 278
#define STATIC 279
#define COMPLEX 280
#define DEFAULT 281
#define INLINE 282
#define STRUCT 283
#define IMAGINARY 284
#define DO 285
#define INT 286
#define SWITCH 287
#define DOUBLE 288
#define LONG 289
#define TYPEDEF 290
#define ELSE 291
#define REGISTER 292
#define UNION 293
#define IDENTIFIER 294
#define INTEGER_CONSTANT 295
#define FLOATING_CONSTANT 296
#define CHARACTER_CONSTANT 297
#define ENUMERATION_CONSTANT 298
#define STRING_LITERAL 299
#define SQBRAOPEN 300
#define SQBRACLOSE 301
#define ROBRAOPEN 302
#define ROBRACLOSE 303
#define CURBRAOPEN 304
#define CURBRACLOSE 305
#define DOT 306
#define ACC 307
#define INC 308
#define DEC 309
#define AMP 310
#define MUL 311
#define ADD 312
#define SUB 313
#define NEG 314
#define EXCLAIM 315
#define DIV 316
#define MODULO 317
#define SHL 318
#define SHR 319
#define BITSHL 320
#define BITSHR 321
#define LTE 322
#define GTE 323
#define EQ 324
#define NEQ 325
#define BITXOR 326
#define BITOR 327
#define AND 328
#define OR 329
#define QUESTION 330
#define COLON 331
#define SEMICOLON 332
#define DOTS 333
#define ASSIGN 334
#define STAREQ 335
#define DIVEQ 336
#define MODEQ 337
#define PLUSEQ 338
#define MINUSEQ 339
#define SHLEQ 340
#define SHREQ 341
#define BINANDEQ 342
#define BINXOREQ 343
#define BINOREQ 344
#define COMMA 345
#define HASH 346
#define THEN 347
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
  int intval;
  char* charval;
  float* floatval;
  int instr;
  symbl* symp;
  symbol_type* symtp;
  expr* E;
  statement* S;
  array* A;
  char unaryOperator;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
