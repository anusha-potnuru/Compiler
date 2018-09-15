%{
	#include <stdio.h>
	extern int yylex();
	void yyerror(char *s);
%}

%union {
int intval;
  float floatval;
  char *charval;
}

%token TYPEDEF EXTERN STATIC AUTO REGISTER INLINE RESTRICT
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID
%token _BOOL _COMPLEX _IMAGINARY
%token STRUCT UNION ENUM
%token BREAK CASE CONTINUE DEFAULT DO IF ELSE FOR GOTO WHILE SWITCH SIZEOF
%token RETURN

%token ELLIPSIS RIGHT_ASSIGN LEFT_ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN BITAND_ASSIGN
%token DIV_ASSIGN MOD_ASSIGN AND_ASSIGN XOR_ASSIGN OR_ASSIGN RIGHT_OP LEFT_OP 
%token INC_OP DEC_OP PTR_OP AND_OP OR_OP LE_OP GE_OP EQ_OP NE_OP
%token SEMICOLON PIPE HASH COMMA QUESMARK EQUALITY COLON DOT
%token CONJ LT GT MODULO DIVSN LSB RSB LOB ROB LCB RCB
%token BITAND MULT PLUS MINUS TILDE EXCLM


%token IDENTIFIER STRING_LITERAL PUNCTUATORS COMMENT
%token<intval> INT_CONSTANT 
%token<floatval> FLOAT_CONSTANT 
%token ENU_CONSTANT 
%token<charval> CHAR_CONSTANT

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%start translation_unit
%%

primary_expression
	: IDENTIFIER {printf("primary_expression -> identifier \n");}
	| constant      {printf("primary_expression -> constant\n");}
	| STRING_LITERAL {printf("primary_expression-> string-literal \n");}
	| LOB expression ROB {printf("primary_expression -> (expression) \n");}
	
	;

constant
	: INT_CONSTANT  {printf("constant->integer constant \n");}
	| FLOAT_CONSTANT  {printf("constant->float constant \n");}
	| ENU_CONSTANT  {printf("constant-> enumeration constant \n");}
	| CHAR_CONSTANT {printf("constant-> char constant \n");}
	;

postfix_expression
	: primary_expression  {printf("postfix expression-> primary expression\n");}
	| postfix_expression LSB expression RSB {printf("postfix_expression-> postfix_expression ( expression )\n");}
	| postfix_expression LOB ROB {printf("postfix expression-> postfix ( )\n");}
	| postfix_expression LOB argument_expression_list ROB {printf("postfix expression-> postfix expression ( argument expression_list )\n");}
	| postfix_expression DOT IDENTIFIER {printf("postfix expression-> postfix expression . identifier\n");}
	| postfix_expression PTR_OP IDENTIFIER {printf("postfix expression-> postfix expression -> identifier\n");}
	| postfix_expression INC_OP {printf("postfix expression-> postfix expression ++\n");}
	| postfix_expression DEC_OP {printf("postfix expression-> postfix expression --\n");}
	| LOB type_name ROB LCB initializer_list RCB {printf("postfix expression-> '(' type_name ')' '{' initializer_list '}' \n");}	
	|  LOB type_name ROB LCB initializer_list COMMA RCB {printf("postfix expression-> '(' type_name ')' '{' initializer_list , '}' \n");}	

	;

argument_expression_list
	: assignment_expression {printf("argument expression-> assignment expression \n");}	
	| argument_expression_list COMMA assignment_expression  {printf("argument expression-> assignment expression list , assignmentexpression \n");}	

	;

unary_expression
	: postfix_expression  {printf("unary expression-> postfix expression \n");}	
	| INC_OP unary_expression {printf("unary_expression -> ++ unaryexpression\n");}
	| DEC_OP unary_expression {printf("unary_expression -> ++ unaryexpression\n");}
	| unary_operator cast_expression {printf("unary_expression -> unaryoperator castexpression\n");}
	| SIZEOF unary_expression {printf("unary_expression -> sizeof unaryexpression\n");}
	| SIZEOF LOB type_name ROB {printf("unary_expression -> sizeof ( typename )\n");}
	;

unary_operator
	: BITAND {printf("unary operator &\n");}
	| MULT {printf("unary operator *\n");}
	| PLUS {printf("unary operator +\n");}
	| MINUS {printf("unary operator -\n");}
	| TILDE {printf("unary operator ~\n");}
	| EXCLM {printf("unary operator !\n");}
	;

cast_expression
	: unary_expression {printf("cast_expression -> unaryexpression\n");}
	| LOB type_name ROB cast_expression  {printf("cast_expression -> ( typename ) castexpression \n");}
	
	;

multiplicative_expression
	: cast_expression {printf("multiplicative_expression -> castexpression \n");}
	| multiplicative_expression MULT cast_expression {printf("multiplicative_expression -> multiplicative expression * castexpression \n");}
	| multiplicative_expression DIVSN cast_expression {printf("multiplicative_expression -> multiplicative expression / castexpression \n");}
	| multiplicative_expression MODULO cast_expression {printf("multiplicative_expression -> multiplicative expression %% castexpression \n");}
	
	;

additive_expression
	: multiplicative_expression {printf("additive_expression -> multiplicative_expression\n");}
	| additive_expression PLUS multiplicative_expression  {printf("additive_expression -> additiveexpression + multiplicative_expression\n");}
	| additive_expression MINUS multiplicative_expression {printf("additive_expression -> additiveexpression - multiplicative_expression\n");}
	
	;

shift_expression
	: additive_expression  {printf("shift_expression -> additive expression\n");}
	| shift_expression LEFT_OP additive_expression {printf("shift_expression -> shiftexpression << additive expression\n");}
	| shift_expression RIGHT_OP additive_expression  {printf("shift_expression -> shiftexpression >> additive expression\n");}
	
	;

relational_expression
	: shift_expression {printf("relational_expression -> shiftexpression\n");}
	| relational_expression LT shift_expression {printf("relational_expression -> relationalexpression < shiftexpression\n");}
	| relational_expression GT shift_expression  {printf("relational_expression -> relationalexpression > shiftexpression\n");}
	| relational_expression LE_OP shift_expression  {printf("relational_expression -> relationalexpression <= shiftexpression\n");}
	| relational_expression GE_OP shift_expression  {printf("relational_expression -> relationalexpression >= shiftexpression\n");}
	
	;

equality_expression
	: relational_expression {printf("equality-expression -> relational_expression\n");}
	| equality_expression EQ_OP relational_expression {printf("equality-expression -> equalityexpression == relational_expression\n");}
	| equality_expression NE_OP relational_expression {printf("equality-expression -> equalityexpression != relational_expression\n");}

	;

and_expression
	: equality_expression {printf("and_expression -> equality_expression\n");}
	| and_expression BITAND equality_expression  {printf("and_expression -> and_expression & equality_expression\n");}
	
	;

exclusive_or_expression
	: and_expression {printf("exclusive_or_expression -> and_expression \n");}
	| exclusive_or_expression CONJ and_expression {printf("exclusive_or_expression -> exclusive_or_expression ^ and_expression \n");}
	
	;

inclusive_or_expression
	: exclusive_or_expression {printf("inclusive_or_expression -> exclusive_or_expression \n");}
	| inclusive_or_expression PIPE exclusive_or_expression {printf("inclusive_or_expression -> inclusive_or_expression  | exclusive_or_expression \n");}
	
	;

logical_and_expression
	: inclusive_or_expression {printf("logical_and_expression -> inclusive-or-expression\n");}
	| logical_and_expression AND_OP inclusive_or_expression {printf("logical_and_expression -> logical-and-expression && inclusive-or-expression\n");}
	
	;

logical_or_expression
	: logical_and_expression {printf("logical_or_expression -> logical_and_expression\n");}
	| logical_or_expression OR_OP logical_and_expression {printf("logical_or_expression -> logical_or_expression || logical_and_expression\n");}
	
	;

conditional_expression
	: logical_or_expression {printf("conditional_expression -> logical-or-expression\n");}
	| logical_or_expression QUESMARK expression COLON conditional_expression {printf("conditional_expression -> logical-or-expression ? expression : conditional expression\n");}
	
	;

assignment_expression
	: conditional_expression {printf("assignment_expression -> conditional_expression\n");}
	| unary_expression assignment_operator assignment_expression {printf("assignment_expression->unary_expression assignment_operator assignment_expression\n");}
	
	;

assignment_operator
	: EQUALITY {printf("assignment_operator =\n");}
	| MUL_ASSIGN {printf("assignment_operator *=\n");}
	| DIV_ASSIGN {printf("assignment_operator /=\n");}
	| MOD_ASSIGN {printf("assignment_operator %=\n");}
	| ADD_ASSIGN {printf("assignment_operator +=\n");}
	| SUB_ASSIGN {printf("assignment_operator -=\n");}
	| LEFT_ASSIGN {printf("assignment_operator <<=\n");}
	| RIGHT_ASSIGN {printf("assignment_operator >>=\n");}
	| BITAND_ASSIGN {printf("assignment_operator &=\n");}
	| XOR_ASSIGN {printf("assignment_operator ^=\n");}
	| OR_ASSIGN {printf("assignment_operator |=\n");}

	;

expression
	: assignment_expression {printf("expression -> assignment-expression\n");}
	| expression COMMA assignment_expression {printf("expression -> expression , assignment-expression\n");}
	
	;

constant_expression
	: conditional_expression {printf("constant_expression -> conditional-expression\n");}
	
	;

declaration
	: declaration_specifiers SEMICOLON {printf("declaration ->declaration_specifiers initializer_list \n");}
	| declaration_specifiers init_declarator_list SEMICOLON {printf("declaration ->declaration_specifiers initializer_list ; \n");}

	;

declaration_specifiers
	: storage_class_specifier {printf("declaration_specifiers -> storage_class_specifier \n");}
	| storage_class_specifier declaration_specifiers {printf("declaration_specifiers -> storage_class_specifier declaration_specifiers \n");}
	| type_specifier {printf("declaration_specifiers -> typespecifier \n");}
	| type_specifier declaration_specifiers {printf("declaration_specifiers -> type_specifier declaration_specifiers \n");}
	| type_qualifier {printf("declaration_specifiers -> type qualifier \n");}
	| type_qualifier declaration_specifiers {printf("declaration_specifiers -> type qualifier declaration_specifiers \n");}
	| function_specifier  {printf("declaration_specifiers -> functionspecifier  \n");}
	| function_specifier declaration_specifiers {printf("declaration_specifiers -> function_specifier declaration_specifiers \n");}

	;

init_declarator_list
	: init_declarator {printf("init_declarator_list -> init_declarator \n");}
	| init_declarator_list COMMA init_declarator {printf("init_declarator_list -> init_declarator_list , init_declarator \n");}

	;

init_declarator
	: declarator {printf("init_declarator -> declarator \n");}
	| declarator EQUALITY initializer {printf("init_declarator -> declarator = initializer \n");}

	;

storage_class_specifier
	: EXTERN {printf("storage_class_specifier -> extern\n");}
	| STATIC {printf("storage_class_specifier -> static\n");}
	| AUTO {printf("storage_class_specifier -> auto\n");}
	| REGISTER {printf("storage_class_specifier -> register\n");}

	;

type_specifier
	: VOID {printf("type_specifier -> void\n");}
	| CHAR {printf("type_specifier -> char\n");}
	| SHORT {printf("type_specifier -> short\n");}
	| INT {printf("type_specifier -> int\n");}
	| LONG {printf("type_specifier -> long\n");}
	| FLOAT {printf("type_specifier -> float\n");}
	| DOUBLE {printf("type_specifier -> double\n");}
	| SIGNED {printf("type_specifier -> signed\n");}
	| UNSIGNED {printf("type_specifier -> unsigned\n");}
	| _BOOL  {printf("type_specifier -> bool\n");}
	| _COMPLEX {printf("type_specifier -> complex  n");}
	| _IMAGINARY {printf("type_specifier -> imaginary\n");}
	| enum_specifier {printf("type_specifier -> enum specifier\n");}
	
	;



specifier_qualifier_list
	: type_specifier specifier_qualifier_list    {printf("specifier_qualifier_list -> type_specifier specifier_qualifier_list\n");}   
	| type_specifier            {printf("specifier_qualifier_list -> type_specifier \n");}   
	| type_qualifier specifier_qualifier_list {printf("specifier_qualifier_list -> type_qualifier specifier_qualifier_list\n");}   
	| type_qualifier {printf("specifier_qualifier_list -> typequalifier \n");}   

	;


enum_specifier
	: ENUM LCB enumerator_list RCB {printf("enum_specifier -> 'enum' { enumerationlist } \n");}
	| ENUM IDENTIFIER LCB enumerator_list RCB {printf("enum_specifier -> 'enum' identifier { enumerationlist } \n");}
	| ENUM LCB enumerator_list COMMA RCB {printf("enum_specifier -> 'enum' { enumerationlist } \n");}
	| ENUM IDENTIFIER LCB enumerator_list COMMA RCB {printf("enum_specifier -> 'enum' identifier { enumerationlist , } \n");}
	| ENUM IDENTIFIER {printf("enum_specifier -> 'enum' identifier \n");}
	
	;

enumerator_list
	: enumerator {printf("enumerator_list -> enumerator \n");}
	| enumerator_list COMMA enumerator {printf("enumerator_list -> enumerator_list , enumerator \n");}
	
	;

enumerator
	: IDENTIFIER {printf("enumerator -> identifier\n");}
	| IDENTIFIER EQUALITY constant_expression {printf("enumerator -> identifier = constant-expression \n");}
	
	;

type_qualifier
	: CONST {printf("type_qualifier 'const'\n");}
	| VOLATILE {printf("type_qualifier 'volatile'\n");}
	| RESTRICT {printf("type_qualifier 'restrict'\n");}
	
	;
function_specifier
	: INLINE 
	{printf("function_specifier -> 'inline'\n");}
	;
declarator
	: pointer direct_declarator {printf("declarator -> pointer directdeclator\n");}
	| direct_declarator {printf("declarator -> direct_declarator\n");}
	
	;

direct_declarator
	: IDENTIFIER {printf("direct_declarator -> identifier \n");}
	| LOB declarator ROB {printf("direct_declarator -> ( declarator )\n");}
	| direct_declarator LSB  type_qualifier_list_opt assignment_expression_opt RSB {printf(" direct_declarator-> direct_declarator [type_qualifier_list_opt assignment_expression ] \n");} 
	| direct_declarator LSB STATIC type_qualifier_list_opt assignment_expression RSB {printf(" direct_declarator-> direct_declarator [ 'static' type_qualifier_list_opt assignment_expression ] \n");} 
	| direct_declarator LSB type_qualifier_list_opt MULT RSB {printf(" direct_declarator-> direct_declarator [type_qualifier_list_opt * ] \n");} 
	| direct_declarator LOB parameter_type_list ROB {printf(" direct_declarator-> direct_declarator ( parameter_type_list ) \n");} 
	| direct_declarator LOB identifier_list ROB {printf(" direct_declarator-> direct_declarator ( identifier_list ) \n");} 
	| direct_declarator LOB ROB {printf(" direct_declarator-> direct_declarator (  ) \n");} 
	
	;

type_qualifier_list_opt
	:
	type_qualifier_list
	|
	{printf("type_qualifier_list_opt\n");}
	;
assignment_expression_opt
	: 
	assignment_expression
	|
	{printf("assignment_expression_opt\n");}
	;

pointer
	: MULT {printf("pointer -> * \n");}
	| MULT type_qualifier_list {printf("pointer -> * type_qualifier_list\n");}
	| MULT pointer {printf("pointer -> * pointer\n");}
	| MULT type_qualifier_list pointer {printf("pointer -> * type-qualifier-list \n");}
	
	;

type_qualifier_list
	: type_qualifier {printf("type_qualifier_list -> type_qualifier\n");}
	| type_qualifier_list type_qualifier {printf("type_qualifier_list -> type_qualifier_list  type_qualifier \n");}
	
	;


parameter_type_list
	: parameter_list {printf("parameter_type_list -> parameter_list\n");}
	| parameter_list COMMA ELLIPSIS {printf("parameter_type_list -> parameter_list , ...\n");}
	
	;

parameter_list
	: parameter_declaration {printf("parameter_list -> parameter-declaration\n");}
	| parameter_list COMMA parameter_declaration {printf("parameter_list -> parameter-list , parameter-declaration\n");}
	
	;

parameter_declaration
	: declaration_specifiers declarator {printf("parameter_declaration -> declaration-specifiers declarator \n");}
	| declaration_specifiers {printf("parameter_declaration -> declaration-specifiers  \n");}
	
	;

identifier_list
	: IDENTIFIER {printf("identifier_list -> identifier\n");}
	| identifier_list COMMA IDENTIFIER {printf("identifier_list -> identifier_list , identifier \n");}
	
	;

type_name
	: specifier_qualifier_list
	{printf("type_name -> specifier\n");}
	;




initializer
	: assignment_expression {printf("initializer -> assignment-expression\n");}
	| LCB initializer_list RCB {printf("initializer -> { initializer-list }\n");}
	| LCB initializer_list COMMA RCB {printf("initializer -> { initializer-list , }\n");}
	
	;

initializer_list
	: initializer {printf("initializer_list -> initializer\n");}
	| designation initializer {printf("initializer_list -> designation initializer\n");}
	| initializer_list COMMA initializer {printf("initializer_list -> initializer-list , intializer\n");}
	|  initializer_list COMMA designation initializer {printf("initializer_list -> initializer-list , designation intializer\n");}
	
	;

designation
	: designator_list EQUALITY
	{printf("designation -> designator_list =\n");}
	;

designator_list
	: designator {printf("designator_list -> designator\n");}
	| designator_list designator  {printf("designator_list -> designator_list designator\n");}
	
	;

designator
	: LSB constant_expression RSB {printf("designator -> [ constant-expression ]\n");}
	| DOT IDENTIFIER {printf("designator -> . identifier\n");}
	
	;

statement
	: labeled_statement {printf("statement -> labeled statement\n");}
	| compound_statement {printf("statement -> compound statement\n");}
	| expression_statement {printf("statement -> expression statement\n");}
	| selection_statement {printf("statement -> selection statement\n");}
	| iteration_statement {printf("statement -> iteration statement\n");}
	| jump_statement {printf("statement -> jump statement\n");}
	
	;

labeled_statement
	: IDENTIFIER COLON statement {printf("labeled_statement -> identifier : statement\n");}
	| CASE constant_expression COLON statement  {printf("labeled_statement -> case constant_expression : statement\n");}
	| DEFAULT COLON statement  {printf("labeled_statement -> default : statement\n");}
	
	;

compound_statement
	: LCB RCB {printf("compound_statement -> { }\n");}
	| LCB block_item_list RCB {printf("compound_statement -> { block_item_list }\n");}
	
	;

block_item_list
	: block_item {printf("block_item_list -> block_item\n");}
	| block_item_list block_item  {printf("block_item_list -> block_item_list block_item\n");}
	
	;

block_item
	: declaration {printf("block_item -> declarator \n");}
	| statement {printf("block_item -> statement \n");}
	
	;


expression_statement
	: SEMICOLON {printf("expression_statement ->  ;\n");}
	| expression SEMICOLON {printf("expression_statement -> expression ;\n");}
	
	;

selection_statement
	: IF LOB expression ROB statement %prec LOWER_THAN_ELSE {printf("selection_statement -> 'if' ( expression ) statement\n");}
	| IF LOB expression ROB statement ELSE statement {printf("selection_statement -> 'if' ( expression ) statement 'else' statement \n");}
	| SWITCH LOB expression ROB statement {printf("selection_statement -> 'switch' ( expression ) statement  \n");}
	
	;

iteration_statement
	: WHILE LOB expression ROB statement {printf("iteration_statement -> 'while' '(' expression ')' statement\n");}
	| DO statement WHILE LOB expression ROB SEMICOLON {printf("iteration_statement -> 'do' statement 'while' '(' expression ')' ;\n");}
	| FOR LOB expression_statement expression_statement expression ROB statement {printf("iteration_statement -> 'for' '(' expression_statement expression_statement expression ')' statement\n");}

	| FOR LOB expression_statement expression_statement ROB statement {printf("iteration_statement -> 'for' '(' expression_statement expression_statement ')' statement\n");}

	| FOR LOB declaration expression_statement expression ROB statement  {printf("iteration_statement -> 'for' '(' declaration expression_statement expression ')' statement\n");}

	| FOR LOB declaration expression_statement  ROB statement  {printf("iteration_statement -> 'for' '(' declaration expression_statement ';' ')' statement\n");}
	;

jump_statement
	: GOTO IDENTIFIER SEMICOLON {printf("jump_statement -> 'goto' identifier ';'\n");}
	| CONTINUE SEMICOLON {printf("jump_statement -> 'continue' ';'\n");}
	| BREAK SEMICOLON {printf("jump_statement -> 'break' ';'\n");}
	| RETURN SEMICOLON {printf("jump_statement -> 'return' ';'\n");}
	| RETURN expression SEMICOLON	{printf("jump_statement -> 'return' expression ';'\n");}
	
	;

translation_unit
	: external_declaration {printf("translation_unit -> external_declaration\n");}
	| translation_unit external_declaration {printf("translation_unit -> translation_unit external_declaration\n");}
	
	;

external_declaration
	: function_definition {printf("external_declaration -> function_definition\n");}
	| declaration {printf("external_declaration -> declaration\n");}
	
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement {printf("function_definition -> declaration_specifiers declarator declaration_list compound_statement\n");}
	| declaration_specifiers declarator compound_statement {printf("function_definition -> declaration_specifiers declarator compound_statement\n");}
	| declarator declaration_list compound_statement {printf("function_definition -> declarator declaration_list compound_statement\n");}
	| declarator compound_statement {printf("function_definition -> declarator compound_statement\n");}
	;
declaration_list
	: declaration {printf("declaration_list -> declaration\n");}
	| declaration_list declaration  {printf("declaration_list -> declaration_list declaration\n");}
	
	;

%%


void yyerror(char *s) {
	printf ("\n ERROR: %s\n",s);
}
