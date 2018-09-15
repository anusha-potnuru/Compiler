%{
#include "ass4_16CS30027.tab.h"
#define YYDEBUG 1
%}

SIGN 				"+"|"-"
NONZERODIGIT	[1-9]
DIGIT 			[0-9]
DIGITSEQUENCE		({DIGIT})+
INTEGERCONSTANT 		({NONZERODIGIT}({DIGIT})*)|[0]
EXPONENT 		[eE]{SIGN}?{DIGITSEQUENCE}
FRACTION 		({DIGITSEQUENCE}[\.])|({DIGITSEQUENCE}?[\.]{DIGITSEQUENCE})
FLOAT 			 (({INTEGERCONSTANT}{EXPONENT})|({FRACTION}{EXPONENT})|{FRACTION})

NONDIGIT 		[a-zA-Z]
IDENTIFIER 		{NONDIGIT}({NONDIGIT}|{DIGIT})*

CONSTANT		{INTEGER_CONSTANT}|{FLOATING_CONSTANT}|{ENUMERATION_CONSTANT}|{CHARACTER_CONSTANT}

ENUMCONSTANT 		{IDENTIFIER}

ESCAPESEQ  		\\['"?\\abfnrtv]
CCHAR			[^'\\\n]|{ESCAPESEQ}
CCHARSEQUENCE 	{CCHAR}+
CHARCONSTANT 	"\'"{CCHARSEQUENCE}"\'"

SCHAR 				[^"\\\n]|{ESCAPESEQ}
SCHARSEQUENCE 	{SCHAR}+
STRINGLITERAL 		\"{SCHARSEQUENCE}?\"
WS 				[ \t\n]

SINGLELINECOMMENT 	"//"[^\n]*"\n"
MULTILINECOMMENT	"/*"([^*]|\*+[^*/])*\*+"/"
COMMENT 			{MULTILINECOMMENT}|{SINGLELINECOMMENT}
%%

"auto"			{ return AUTO; }
"break"         	{ return BREAK; }
"case"          	{ return CASE; }
"char"          	{ return CHAR; }
"const"        	 	{ return CONST; }
"continue"     		{ return CONTINUE; }
"default"       	{ return DEFAULT; }
"do"            	{ return DO; }
"double"        	{ return DOUBLE; }
"else"          	{ return ELSE; }
"enum"          	{ return ENUM; }
"extern"        	{ return EXTERN; }
"float"         	{ return FLOAT; }
"for"           	{ return FOR; }
"goto"          	{ return GOTO; }
"if"            	{ return IF; }
"inline"        	{ return INLINE; }
"int"          	 	{ return INT; }
"long"          	{ return LONG; }
"register"     		{ return REGISTER; }
"restrict"      	{ return RESTRICT; }
"return"        	{ return RETURN; }
"short"         	{ return SHORT; }
"signed"        	{ return SIGNED; }
"sizeof"        	{ return SIZEOF; }
"static"        	{ return STATIC; }
"struct"       	 	{ return STRUCT; }
"switch"        	{ return SWITCH; }
"typedef"      		{ return TYPEDEF; }
"union"         	{ return UNION; }
"unsigned"      	{ return UNSIGNED; }
"void"          	{ return VOID; }
"volatile"      	{ return VOLATILE; }
"while"         	{ return WHILE; }
"_Bool"         	{ return _BOOL; }
"_Complex"      	{ return _COMPLEX; }
"_Imaginary"    	{ return _IMAGINARY; }


{IDENTIFIER}		{return IDENTIFIER;}

{INTEGERCONSTANT}		{return INT_CONSTANT;}
{FLOAT}		{return FLOAT_CONSTANT;}

{CHARCONSTANT}		{return CHAR_CONSTANT;}

{STRINGLITERAL}		{return STRING_LITERAL;}

"["			{ return LSB; }
"]"			{ return RSB; }
"("			{ return LOB; }
")"			{ return ROB; }
"{"			{ return LCB; }
"}"			{ return RCB; }
"."			{ return DOT; }
"->"			{ return PTR_OP; }

"++"			{ return INC_OP; }
"--"			{ return DEC_OP; }
"&"			{ return BITAND; }
"*"			{ return MULT; }
"+"			{ return PLUS; }
"-"			{ return MINUS; }
"~"			{ return  TILDE; }
"!"			{ return EXCLM; }

"/"			{ return DIVSN; }
"%"			{ return MODULO; }
"<<"			{ return LEFT_OP; }
">>"			{ return RIGHT_OP; }
"<"			{ return LT; }
">"			{ return GT; }
"<="			{ return LE_OP; }
">="			{ return GE_OP; }
"=="			{ return EQ_OP; }
"!="			{ return NE_OP; }
"^"			{ return CONJ; }
"|"			{ return PIPE; }
"&&"			{ return AND_OP; }
"||"			{ return OR_OP; }

"?"			{ return QUESMARK; }
":"			{ return COLON; }
";"			{ return SEMICOLON; }
"..."			{ return ELLIPSIS; }

"="			{ return EQUALITY; }
"*="			{ return MUL_ASSIGN; }
"/="			{ return DIV_ASSIGN; }
"%="			{ return MOD_ASSIGN; }
"+="			{ return ADD_ASSIGN; }
"-="			{ return SUB_ASSIGN; }
"<<="			{ return LEFT_ASSIGN; }
">>="			{ return RIGHT_ASSIGN; }
"&="			{ return BITAND_ASSIGN; }
"^="			{ return XOR_ASSIGN; }
"|="			{ return OR_ASSIGN; }

","			{ return COMMA; }
"#"			{ return HASH; }

{WS}		{/* Ignore whitespace */}
{COMMENT}		{}
%%

