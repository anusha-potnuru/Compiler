%{
extern void yyerror(const char *);
#define KEYWORD 1
#define	IDENTIFIER	2
#define	CONSTANT	3
#define	PUNCTUATOR	4
#define STRINGLITERAL 5
%}

SIGN 				"+"|"-"
NONZERODIGIT	[1-9]
DIGIT 			[0-9]
DIGITSEQUENCE		({DIGIT})+
INTEGERCONSTANT 		({NONZERODIGIT}({DIGIT})*)|[0]
EXPONENT 		[eE]{SIGN}?{DIGITSEQUENCE}
FRACTION 		({DIGITSEQUENCE}[\.])|({DIGITSEQUENCE}?[\.]{DIGITSEQUENCE})
FLOAT 			 ({INTEGERCONSTANT}{EXPONENT})|({FRACTION}{EXPONENT})|{FRACTION}
NONDIGIT 		[a-zA-Z]
KEYWORD     "int"|"float"|"auto"|"enum"|"break"|"extern"|"case"|"char"|"for"|"const"|"goto"|"continue"|"if"|"default"|"inline"|"do"|"double"|"long"|"else"|"register"|"restrict"|"return"|"short"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"void"|"volatile"|"while"|"_Bool"|"_Complex"|"_Imaginary"
IDENTIFIER 		{NONDIGIT}({NONDIGIT}|{DIGIT})*
ENUMCONSTANT 		{IDENTIFIER}
ESCAPESEQ  	\\['"?\\abfnrtv]
CCHAR		[^'\\\n]|{ESCAPESEQ}
CCHARSEQUENCE 	{CCHAR}+
CHARCONSTANT 	"\'"{CCHARSEQUENCE}"\'"
CONSTANT 		{FLOAT}|{INTEGERCONSTANT}|{ENUMCONSTANT}|{CHARCONSTANT}
SCHAR 		[^"\\\n]|{ESCAPESEQ}
SCHARSEQUENCE 	{SCHAR}+
STRINGLITERAL 		\"{SCHARSEQUENCE}?\"
PUNC 		"["|"]"|"("|")"|"{"|"}"|"."|"->"|"++"|"--"|"&"|"*"|"+"|"-"|"~"|"!"|"/"|"%"|"<<"|">>"|"<"|">"|"<="|">="|"=="|"!="|"^"|"|"|"&&"|"||"|"?"|":"|";"|"..."|"="|"*="|"/="|"%="|"+="|"-="|"<<="|">>="|"&="|"^="|"|="|","|"#"
WS 		[ \t\n]
SINGLELINECOMMENT 	"//"[^\n]*"\n"
MULTILINECOMMENT	"/*"([^*]|\*+[^*/])*\*+"/"

%%
{KEYWORD} 	{return KEYWORD;}
{IDENTIFIER}		{return IDENTIFIER;}
{CONSTANT}		{return CONSTANT;}
{PUNC}		{ return PUNCTUATOR;}
{STRINGLITERAL}	{return STRINGLITERAL;}
{WS}		{/* Ignore whitespace */}
{SINGLELINECOMMENT}		{}
{MULTILINECOMMENT}		{}
%%

