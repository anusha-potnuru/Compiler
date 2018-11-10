//By Anusha Potnuru

%{
#include <iostream>
#include <cstdlib>
#include <string>
#include <stdio.h>
#include <sstream>
#include "translator.h"
extern int yylex();
void yyerror(string s);
extern string Type;

vector <string> allstrings;

using namespace std;
%}

// can modify the type of yylval using any of these
%union {
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
} 

%token AUTO
%token ENUM
%token RESTRICT
%token UNSIGNED
%token BREAK
%token EXTERN
%token RETURN
%token VOID
%token CASE
%token FLOAT
%token SHORT
%token VOLATILE
%token CHAR
%token FOR
%token SIGNED
%token WHILE
%token CONST
%token GOTO
%token SIZEOF
%token BOOL
%token CONTINUE
%token IF
%token STATIC
%token COMPLEX
%token DEFAULT
%token INLINE
%token STRUCT
%token IMAGINARY
%token DO
%token INT
%token SWITCH
%token DOUBLE
%token LONG
%token TYPEDEF
%token ELSE
%token REGISTER
%token UNION
%token<symp> IDENTIFIER
%token<intval> INTEGER_CONSTANT
%token<charval> FLOATING_CONSTANT
%token<charval> CHARACTER_CONSTANT ENUMERATION_CONSTANT
%token<charval> STRING_LITERAL
%token SQBRAOPEN
%token SQBRACLOSE
%token ROBRAOPEN
%token ROBRACLOSE
%token CURBRAOPEN
%token CURBRACLOSE
%token DOT
%token ACC
%token INC
%token DEC
%token AMP
%token MUL
%token ADD
%token SUB
%token NEG
%token EXCLAIM
%token DIV
%token MODULO
%token SHL
%token SHR
%token BITSHL
%token BITSHR
%token LTE
%token GTE
%token EQ
%token NEQ
%token BITXOR
%token BITOR
%token AND
%token OR
%token QUESTION
%token COLON
%token SEMICOLON
%token DOTS
%token ASSIGN
%token STAREQ
%token DIVEQ
%token MODEQ
%token PLUSEQ
%token MINUSEQ
%token SHLEQ
%token SHREQ
%token BINANDEQ
%token BINXOREQ
%token BINOREQ
%token COMMA
%token HASH

%start translation_unit
//to remove dangling else's 
%right THEN ELSE

//Expressions
%type <E>
	expression
	primary_expression 
	multiplicative_expression
	additive_expression
	shift_expression
	relational_expression
	equality_expression
	AND_expression
	exclusive_OR_expression
	inclusive_OR_expression
	logical_AND_expression
	logical_OR_expression
	conditional_expression
	assignment_expression
	expression_statement

//
%type <intval> argument_expression_list

// Auxillary non-terminals MLabel and NLabel
%type <instr> MLabel
%type <S> NLabel

//Array to be used (later)
%type <A> postfix_expression
	unary_expression
	cast_expression

// Unary operators like +,*, ...
%type <unaryOperator> unary_operator

// Rules having symbol assigned by variable Type
%type <symp> constant initializer
%type <symp> direct_declarator init_declarator declarator

// Rules to deal with pointer
%type <symtp> pointer

//Statements
%type <S>  statement
	labeled_statement 
	compound_statement
	selection_statement
	iteration_statement
	jump_statement
	block_item
	block_item_list

%%

primary_expression
	: IDENTIFIER {
		$$ = new expr();
		$$->loc = $1;
		$$->type = $$->loc->type->type;
		$$->truelist = makelist();
		$$->falselist = makelist();
	}
	| constant {
	$$ = new expr();
	$$->loc = $1;
	}
	| STRING_LITERAL {
	$$ = new expr();
	symbol_type* tmp = new symbol_type("PTR");
	$$->loc = gentemp(tmp, $1);
	$$->loc->type->ptr = new symbol_type("CHAR");

	//added
	allstrings.push_back($1);
	stringstream strs;
    strs << allstrings.size()-1;
    string temp_str = strs.str();
    char* intStr = (char*) temp_str.c_str();
	string str = string(intStr);
	emit("EQUALSTR", $$->loc->name, str, $1); // added, was EQUALSTR

	}
	| ROBRAOPEN expression ROBRACLOSE {
	$$ = $2;

	}

	;

constant
	:INTEGER_CONSTANT {
	$$ = gentemp(new symbol_type("INTEGER"), conv2string($1));
	emit("EQUAL", $$->name, $1);
	}
	|FLOATING_CONSTANT {
	$$ = gentemp(new symbol_type("FLOAT"), $1); // change?
	emit("EQUAL", $$->name, string($1));
	}
	|ENUMERATION_CONSTANT  {//to do later
	}
	|CHARACTER_CONSTANT {
	$$ = gentemp(new symbol_type("CHAR"),$1);
	emit("EQUALCHAR", $$->name, string($1));
	}
	;


postfix_expression
	:primary_expression {
		$$ = new array ();
		$$->array = $1->loc;
		$$->loc = $$->array;
		$$->type = $1->loc->type;

	}
	|postfix_expression SQBRAOPEN expression SQBRACLOSE {
		$$ = new array();
		
		$$->array = $1->loc;					// copy the base
		$$->type = $1->type->ptr;				// type = type of element

		$$->loc = gentemp(new symbol_type("INTEGER"));		// store computed address
		//cout << "error in .y " <<endl;
		// New address =(if only) already computed + $3 * new width
		if ($1->cat=="ARR") {						// if already computed
			symbl* t = gentemp(new symbol_type("INTEGER"));

			stringstream strs;
		    strs <<size_of_type($$->type);
		    string temp_str = strs.str();
		    char* intStr = (char*) temp_str.c_str();
			string str = string(intStr);
			
 			emit ("MULT", t->name, $3->loc->name, conv2string(size_of_type($$->type)));

			emit ("ADD", $$->loc->name, $1->loc->name, t->name);
		}
 		else {

 			stringstream strs;
 			//cout<<"type is "<<$$->type <<endl;
		    strs <<size_of_type($$->type);
		    //cout << "error in .y 3" <<endl;
		    string temp_str = strs.str();
		    char* intStr1 = (char*) temp_str.c_str();
			string str1 = string(intStr1);		

	 		emit("MULT", $$->loc->name, $3->loc->name, conv2string(size_of_type($$->type)));

 		}

 		// Mark that it contains array address and first time computation is done
		$$->cat = "ARR";
	}
	|postfix_expression ROBRAOPEN ROBRACLOSE {
	//to do later
	}
	|postfix_expression ROBRAOPEN argument_expression_list ROBRACLOSE {
		$$ = new array();
		$$->array = gentemp($1->type);	
		emit("CALL", $$->array->name, $1->array->name, conv2string($3));
	}
	|postfix_expression DOT IDENTIFIER {//to do later
	}
	|postfix_expression ACC IDENTIFIER {//to do later
	}
	|postfix_expression INC {
		$$ = new array();

		// copy $1 to $$
		$$->array = gentemp($1->array->type);
		emit ("EQUAL", $$->array->name, $1->array->name);

		// Increment $1
		emit ("ADD", $1->array->name, $1->array->name, "1");
	}
	|postfix_expression DEC {
		$$ = new array();

		// copy $1 to $$
		$$->array = gentemp($1->array->type);
		emit ("EQUAL", $$->array->name, $1->array->name);

		// Decrement $1
		emit ("SUB", $1->array->name, $1->array->name, "1");
	}
	|ROBRAOPEN type_name ROBRACLOSE CURBRAOPEN initializer_list CURBRACLOSE {
		//to do later to be added more
		$$ = new array();
		$$->array = gentemp(new symbol_type("INTEGER"));
		$$->loc = gentemp(new symbol_type("INTEGER"));
	}
	|ROBRAOPEN type_name ROBRACLOSE CURBRAOPEN initializer_list COMMA CURBRACLOSE {
		//to do later to be added more
		$$ = new array();
		$$->array = gentemp(new symbol_type("INTEGER"));
		$$->loc = gentemp(new symbol_type("INTEGER"));
	}
	;

argument_expression_list
	:assignment_expression {
	emit ("PARAM", $1->loc->name);
	$$ = 1;
	}
	|argument_expression_list COMMA assignment_expression {
	emit ("PARAM", $3->loc->name);
	$$ = $1+1;
	}
	;

unary_expression
	:postfix_expression {
	$$ = $1;
	}
	|INC unary_expression {
		// Increment $2
		emit ("ADD", $2->array->name, $2->array->name, "1");

		// Use the same value as $2
		$$ = $2;
	}
	|DEC unary_expression {
		// Decrement $2
		emit ("SUB", $2->array->name, $2->array->name, "1");

		// Use the same value as $2
		$$ = $2;
	}
	|unary_operator cast_expression {
		$$ = new array();
		switch ($1) {
			case '&':
			{
				$$->array = gentemp((new symbol_type("PTR")));
				$$->array->type->ptr = $2->array->type; 
				emit ("ADDRESS", $$->array->name, $2->array->name);
			}
				break;
			case '*':
			{
				$$->cat = "PTR";
				$$->loc = gentemp ($2->array->type->ptr);
				emit ("PTRR", $$->loc->name, $2->array->name);
				$$->array = $2->array;
			}
				break;
			case '+':
			{
				$$ = $2;
			}
				break;
			case '-':
			{
				$$->array = gentemp(new symbol_type($2->array->type->type));
				emit ("UMINUS", $$->array->name, $2->array->name);
			}
				break;
			case '~':
			{
				$$->array = gentemp(new symbol_type($2->array->type->type));
				emit ("BNOT", $$->array->name, $2->array->name);
			}
				break;
			case '!':
			{
				$$->array = gentemp(new symbol_type($2->array->type->type));
				emit ("LNOT", $$->array->name, $2->array->name);
			}
				break;
			default:
				break;
		}
	}
	|SIZEOF unary_expression {
	//to do later
	}
	|SIZEOF ROBRAOPEN type_name ROBRACLOSE {
	//to do later
	}
	;

unary_operator
	:AMP {
		$$ = '&';
	}
	|MUL {
		$$ = '*';
	}
	|ADD {
		$$ = '+';
	}
	|SUB {
		$$ = '-';
	}
	|NEG {
		$$ = '~';
	}
	|EXCLAIM {
		$$ = '!';
	}
	;

cast_expression
	:unary_expression {
		// crazy
		$$=$1;
	}
	|ROBRAOPEN type_name ROBRACLOSE cast_expression {
		//to be added later
		$$=$4;
	}
	;

multiplicative_expression
	:cast_expression {
		$$ = new expr();
		if ($1->cat=="ARR") { // Array
			$$->loc = gentemp($1->loc->type);
			emit("ARRR", $$->loc->name, $1->array->name, $1->loc->name);
		}
		else if ($1->cat=="PTR") { // Pointer
			$$->loc = $1->loc;
		}
		else { // otherwise
			$$->loc = $1->array;
		}
	}
	|multiplicative_expression MUL cast_expression {
		if (typecheck ($1->loc, $3->array) ) {
			$$ = new expr();
			$$->loc = gentemp(new symbol_type($1->loc->type->type));
			emit ("MULT", $$->loc->name, $1->loc->name, $3->array->name);
		} // to change
		else cout << "Type Error"<< endl;
	}
	|multiplicative_expression DIV cast_expression {
		if (typecheck ($1->loc, $3->array) ) {
			$$ = new expr();
			$$->loc = gentemp(new symbol_type($1->loc->type->type));
			emit ("DIVIDE", $$->loc->name, $1->loc->name, $3->array->name);
		}
		else cout << "Type Error"<< endl;
	}
	|multiplicative_expression MODULO cast_expression {
		if (typecheck ($1->loc, $3->array) ) {
			$$ = new expr();
			$$->loc = gentemp(new symbol_type($1->loc->type->type));
			emit ("MODOP", $$->loc->name, $1->loc->name, $3->array->name);
		}
		else cout << "Type Error"<< endl;
	}
	;

additive_expression
	:multiplicative_expression {
		$$=$1;
	}
	|additive_expression ADD multiplicative_expression {
		if (typecheck ($1->loc, $3->loc) ) {
			$$ = new expr();
			$$->loc = gentemp(new symbol_type($1->loc->type->type));
			emit ("ADD", $$->loc->name, $1->loc->name, $3->loc->name);
		}
		else cout << "Type Error"<< endl;
	}
	|additive_expression SUB multiplicative_expression {
			if (typecheck ($1->loc, $3->loc) ) {
			$$ = new expr();
			$$->loc = gentemp(new symbol_type($1->loc->type->type));
			emit ("SUB", $$->loc->name, $1->loc->name, $3->loc->name);
		}
		else cout << "Type Error"<< endl;

	}
	;

shift_expression
	:additive_expression {
		$$=$1;
	}
	|shift_expression SHL additive_expression {
		if ($3->loc->type->type == "INTEGER") {
			$$ = new expr();
			$$->loc = gentemp (new symbol_type("INTEGER"));
			emit ("LEFTOP", $$->loc->name, $1->loc->name, $3->loc->name);
		}
		else cout << "Type Error"<< endl;
	}
	|shift_expression SHR additive_expression{
		if ($3->loc->type->type == "INTEGER") {
			$$ = new expr();
			$$->loc = gentemp (new symbol_type("INTEGER"));
			emit ("RIGHTOP", $$->loc->name, $1->loc->name, $3->loc->name);
		}
		else cout << "Type Error"<< endl;
	}
	;

relational_expression
	:shift_expression {$$=$1;}
	|relational_expression BITSHL shift_expression {
		if (typecheck ($1->loc, $3->loc) ) {
			$$ = new expr();
			$$->type = "BOOL";

			$$->truelist = makelist (next_instr());
			$$->falselist = makelist (next_instr()+1);
			emit("LT", "", $1->loc->name, $3->loc->name);
			emit ("GOTOOP", "");
		}
		else cout << "Type Error"<< endl;
	}
	|relational_expression BITSHR shift_expression {
		if (typecheck ($1->loc, $3->loc) ) {
			$$ = new expr();
			$$->type = "BOOL";

			$$->truelist = makelist (next_instr());
			$$->falselist = makelist (next_instr()+1);
			emit("GT", "", $1->loc->name, $3->loc->name);
			emit ("GOTOOP", "");
		}
		else cout << "Type Error"<< endl;
	}
	|relational_expression LTE shift_expression {
		if (typecheck ($1->loc, $3->loc) ) {
			$$ = new expr();
			$$->type = "BOOL";

			$$->truelist = makelist (next_instr());
			$$->falselist = makelist (next_instr()+1);
			emit("LE", "", $1->loc->name, $3->loc->name);
			emit ("GOTOOP", "");
		}
		else cout << "Type Error"<< endl;
	}
	|relational_expression GTE shift_expression {
		if (typecheck ($1->loc, $3->loc) ) {
			$$ = new expr();
			$$->type = "BOOL";

			$$->truelist = makelist (next_instr());
			$$->falselist = makelist (next_instr()+1);
			emit("GE", "", $1->loc->name, $3->loc->name);
			emit ("GOTOOP", "");
		}
		else cout << "Type Error"<< endl;
	}
	;

equality_expression
	:relational_expression {$$=$1;}
	|equality_expression EQ relational_expression { // error to change
		if (typecheck($1->loc, $3->loc)) {
			convertBool2Int ($1);
			convertBool2Int ($3);

			$$ = new expr();
			$$->type = "BOOL";

			$$->truelist = makelist (next_instr());
			$$->falselist = makelist (next_instr()+1);
			emit("EQOP", "", $1->loc->name, $3->loc->name);
			emit ("GOTOOP", "");
		}
		else cout << "Type Error"<< endl;
	}
	|equality_expression NEQ relational_expression {
		if (typecheck ($1->loc, $3->loc) ) {
			// If any is bool get its value
			convertBool2Int ($1);
			convertBool2Int ($3);

			$$ = new expr();
			$$->type = "BOOL";

			$$->truelist = makelist (next_instr());
			$$->falselist = makelist (next_instr()+1);
			emit("NEOP", "", $1->loc->name, $3->loc->name);
			emit ("GOTOOP", "");
		}
		else cout << "Type Error"<< endl;
	}
	;

AND_expression
	:equality_expression {$$=$1;}
	|AND_expression AMP equality_expression {
		if ( $1->loc->type->type == "FLOAT" || $3->loc->type->type == "FLOAT")
			cout << "Invalid operands for BIT AND Error"<< endl;
		else if( $1->loc->type->type == "VOID" || $3->loc->type->type == "VOID" )
			cout << "Incomplete type 'void' for BIT AND Error"<< endl;
		else if(typecheck($1->loc, $3->loc))
		{
			// If any is bool get its value
			convertBool2Int ($1);
			convertBool2Int ($3);
			
			$$ = new expr();
			$$->type = "INTEGER";

			$$->loc = gentemp (new symbol_type("INTEGER"));
			emit ("BAND", $$->loc->name, $1->loc->name, $3->loc->name);
		}
		else cout << "Invalid operands for BIT AND Error"<< endl;
	}
	;

exclusive_OR_expression
	:AND_expression {$$=$1;}
	|exclusive_OR_expression BITXOR AND_expression {
		if ( $1->loc->type->type == "FLOAT" || $3->loc->type->type == "FLOAT")
			cout << "Invalid operands for BIT AND Error"<< endl;
		else if( $1->loc->type->type == "VOID" || $3->loc->type->type == "VOID" )
			cout << "Incomplete type 'void' for BIT AND Error"<< endl;
		else if(typecheck($1->loc, $3->loc))
		{
			// If any is bool get its value
			convertBool2Int ($1);
			convertBool2Int ($3);
			
			$$ = new expr();
			$$->type = "INTEGER";

			$$->loc = gentemp (new symbol_type("INTEGER"));
			emit ("XOR", $$->loc->name, $1->loc->name, $3->loc->name);
		}
		else cout << "Type Error"<< endl;
	}	
	;

inclusive_OR_expression
	:exclusive_OR_expression {$$=$1;}
	|inclusive_OR_expression BITOR exclusive_OR_expression {
		if ( $1->loc->type->type == "FLOAT" || $3->loc->type->type == "FLOAT")
			cout << "Invalid operands for BIT AND Error"<< endl;
		else if( $1->loc->type->type == "VOID" || $3->loc->type->type == "VOID" )
			cout << "Incomplete type 'void' for BIT AND Error"<< endl;
		else if(typecheck($1->loc, $3->loc))
		{
			// If any is bool get its value
			convertBool2Int ($1);
			convertBool2Int ($3);
			
			$$ = new expr();
			$$->type = "INTEGER";

			$$->loc = gentemp (new symbol_type("INTEGER"));
			emit ("INOR", $$->loc->name, $1->loc->name, $3->loc->name);
		}
		else cout << "Type Error"<< endl;
	}
	;

logical_AND_expression
	:inclusive_OR_expression {$$=$1;}
	|logical_AND_expression NLabel AND MLabel inclusive_OR_expression 
	{
		convert2Bool($5);
		// convert $1 to bool and backpatch using NLabel
		backpatch($2->nextlist, next_instr());
		convert2Bool($1);

		$$ = new expr();
		$$->type = "BOOL";

		backpatch($1->truelist, $4);
		$$->truelist = $5->truelist;
		$$->falselist = merge ($1->falselist, $5->falselist);

	}
	;

logical_OR_expression
	:logical_AND_expression {$$=$1;}
	|logical_OR_expression NLabel OR MLabel logical_AND_expression { //marked
		convert2Bool($5);
		// convert $1 to bool and backpatch using NLabel
		backpatch($2->nextlist, next_instr());
		convert2Bool($1);
		
		$$ = new expr();
		$$->type = "BOOL";

		backpatch ($1->falselist, $4); //mark $$ to $1
		$$->truelist = merge ($1->truelist, $5->truelist);
		$$->falselist = $5->falselist;
	}
	;

MLabel 	:
	{	// stores the address of the next instruction
		$$ = next_instr();
	};

NLabel 	:
	{ 	// gaurds against fallthrough by emitting a goto
		$$ = new statement();
		$$->nextlist = makelist(next_instr());
		emit ("GOTOOP","");
	}

conditional_expression
	:logical_OR_expression {
		$$=$1;

	}
	|logical_OR_expression NLabel QUESTION MLabel expression NLabel COLON MLabel conditional_expression {
		$$->loc = gentemp($5->loc->type);
		$$->loc->update($5->loc->type);
		emit("EQUAL", $$->loc->name, $9->loc->name);
		list<int> l = makelist(next_instr());
		emit ("GOTOOP", "");

		backpatch($6->nextlist, next_instr());
		emit("EQUAL", $$->loc->name, $5->loc->name);
		list<int> m = makelist(next_instr());
		l = merge (l, m);
		emit ("GOTOOP", "");

		backpatch($2->nextlist, next_instr());
		convert2Bool($1);
		backpatch ($1->truelist, $4);
		backpatch ($1->falselist, $8);
		backpatch (l, next_instr());
	}
	;

assignment_expression
	:conditional_expression {$$=$1;}
	|unary_expression assignment_operator assignment_expression { 
		if($1->cat=="ARR") {
			$3->loc = conv($3->loc, $1->type->type);
			emit("ARRL", $1->array->name, $1->loc->name, $3->loc->name);	
			}
		else if($1->cat=="PTR") {
			emit("PTRL", $1->array->name, $3->loc->name);	
			}
		else{
			if(!$3->loc)
			{
				//cout <<$3->type <<endl; //Changed
				convertBool2Int($3);
			}
			$3->loc = conv($3->loc, $1->array->type->type); 
			emit("EQUAL", $1->array->name, $3->loc->name);
			}
		$$ = $3;
	}
	;

assignment_operator 
	:ASSIGN {//to do later
	}
	|STAREQ {//to do later
	}
	|DIVEQ {//to do later
	}
	|MODEQ {//to do later
	}
	|PLUSEQ {//to do later
	}
	|MINUSEQ {//to do later
	}
	|SHLEQ {//to do later
	}
	|SHREQ {//to do later
	}
	|BINANDEQ {//to do later
	}
	|BINXOREQ {//to do later
	}
	|BINOREQ {//to do later
	}
	;

expression
	:assignment_expression {$$=$1;}
	|expression COMMA assignment_expression {
	//to do later
	}
	;

constant_expression
	:conditional_expression {
	//to do later
	}
	;

declaration
	:declaration_specifiers init_declarator_list SEMICOLON {//to do later
	}
	|declaration_specifiers SEMICOLON {//to do later
	}
	;


declaration_specifiers
	:storage_class_specifier declaration_specifiers {//to do later
	}
	|storage_class_specifier {//to do later
	}
	|type_specifier declaration_specifiers {//to do later
	}
	|type_specifier {//to do later
	}
	|type_qualifier declaration_specifiers {//to do later
	}
	|type_qualifier {//to do later
	}
	|function_specifier declaration_specifiers {//to do later
	}
	|function_specifier {//to do later
	}
	;

init_declarator_list
	:init_declarator {//to do later
	}
	|init_declarator_list COMMA init_declarator {//to do later
	}
	;

init_declarator
	:declarator {$$=$1;}
	|declarator ASSIGN initializer {
		if ($3->initial_value!="") $1->initial_value=$3->initial_value;
		emit ("EQUAL", $1->name, $3->name);
	}
	;

storage_class_specifier
	: EXTERN {//to do later
	}
	| STATIC {//to do later
	}
	| AUTO {//to do later
	}
	| REGISTER {//to do later
	}
	;

type_specifier
	: VOID {Type="VOID";}
	| CHAR {Type="CHAR";}
	| SHORT 
	| INT {Type="INTEGER";}
	| LONG
	| FLOAT {Type="FLOAT";}
	| DOUBLE 
	| SIGNED
	| UNSIGNED
	| BOOL
	| COMPLEX
	| IMAGINARY
	| enum_specifier
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list {//to do later
	}
	| type_specifier {//to do later
	}
	| type_qualifier specifier_qualifier_list {//to do later
	}
	| type_qualifier {//to do later
	}
	;

enum_specifier
	:ENUM IDENTIFIER CURBRAOPEN enumerator_list CURBRACLOSE {//to do later
	}
	|ENUM CURBRAOPEN enumerator_list CURBRACLOSE {//to do later
	}
	|ENUM IDENTIFIER CURBRAOPEN enumerator_list COMMA CURBRACLOSE {//to do later
	}
	|ENUM CURBRAOPEN enumerator_list COMMA CURBRACLOSE {//to do later
	}
	|ENUM IDENTIFIER {//to do later
	}
	;

enumerator_list
	:enumerator {//to do later
	}
	|enumerator_list COMMA enumerator {//to do later
	}
	;

enumerator
	:IDENTIFIER {//to do later
	}
	|IDENTIFIER ASSIGN constant_expression {//to do later
	}
	;

type_qualifier
	:CONST {//to do later
	}
	|RESTRICT {//to do later
	}
	|VOLATILE {//to do later
	}
	;

function_specifier
	:INLINE {//to do later
	}
	;

declarator
	:pointer direct_declarator {
		symbol_type * t = $1;
		while (t->ptr !=NULL) t = t->ptr;
		t->ptr = $2->type;
		$$ = $2->update($1);
	}
	|direct_declarator {
		$$ = $1;
	}
	;


direct_declarator
	:IDENTIFIER {
		$$ = $1->update(new symbol_type(Type));
		current_Symbl = $$;
	}
	| ROBRAOPEN declarator ROBRACLOSE {$$=$2;}
	| direct_declarator SQBRAOPEN type_qualifier_list assignment_expression SQBRACLOSE {//to do later
	}
	| direct_declarator SQBRAOPEN type_qualifier_list SQBRACLOSE {//to do later
	}
	| direct_declarator SQBRAOPEN assignment_expression SQBRACLOSE {
		symbol_type * t = $1 -> type;
		symbol_type * prev = NULL;
		while (t->type == "ARR") {
			prev = t;
			t = t->ptr;
		}
		if (prev==NULL) {
			int temp = atoi($3->loc->initial_value.c_str());
			symbol_type* s = new symbol_type("ARR", $1->type, temp);
			$$ = $1->update(s);
		}
		else {
			prev->ptr =  new symbol_type("ARR", t, atoi($3->loc->initial_value.c_str()));
			$$ = $1->update ($1->type);
		}
	}
	| direct_declarator SQBRAOPEN SQBRACLOSE {
		symbol_type * t = $1 -> type;
		symbol_type * prev = NULL;
		while (t->type == "ARR") {
			prev = t;
			t = t->ptr;
		}
		if (prev==NULL) {
			symbol_type* s = new symbol_type("ARR", $1->type, 0);
			$$ = $1->update(s);
		}
		else {
			prev->ptr =  new symbol_type("ARR", t, 0);
			$$ = $1->update ($1->type);
		}
	}
	| direct_declarator SQBRAOPEN STATIC type_qualifier_list assignment_expression SQBRACLOSE {//to do later
	}
	| direct_declarator SQBRAOPEN STATIC assignment_expression SQBRACLOSE {//to do later
	}
	| direct_declarator SQBRAOPEN type_qualifier_list MUL SQBRACLOSE {//to do later
	}
	| direct_declarator SQBRAOPEN MUL SQBRACLOSE {//to do later
	}
	| direct_declarator ROBRAOPEN CT parameter_type_list ROBRACLOSE {
		table->name = $1->name;

		if ($1->type->type !="VOID") {
			symbl *s = table->look_Up("return");
			s->update($1->type);		
		}
		$1->nested=table;

		$1->category = "function";
		table->parent = global_Table;
		changeTable (global_Table);				// Come back to globalsymbol table
		current_Symbl = $$;
	}
	| direct_declarator ROBRAOPEN identifier_list ROBRACLOSE {//to do later
	}
	| direct_declarator ROBRAOPEN CT ROBRACLOSE {
		table->name = $1->name;

		if ($1->type->type !="VOID") {
			symbl *s = table->look_Up("return");
			s->update($1->type);		
		}
		$1->nested=table;
		
		$1->category = "function";
		table->parent = global_Table;
		changeTable (global_Table);				// Come back to globalsymbol table
		current_Symbl = $$;
	}
	;

CT	:
	{ 	// Used for changing to symbol table for a function
		if (current_Symbl->nested==NULL) 
			changeTable(new symbol_Table(""));	// Function symbol table doesn't already exist
		else 
		{
			changeTable (current_Symbl ->nested);	// Function symbol table already exists
			emit ("FUNC", table->name);
		}
	}
	;

pointer
	:MUL type_qualifier_list {//to do later
	}
	|MUL {
		$$ = new symbol_type("PTR");
	}
	|MUL type_qualifier_list pointer {//to do later
	}
	|MUL pointer {
		$$ = new symbol_type("PTR", $2);
	}
	;

type_qualifier_list
	:type_qualifier {//to do later
	}
	|type_qualifier_list type_qualifier {//to do later
	}
	;

parameter_type_list
	:parameter_list {//to do later
	}
	|parameter_list COMMA DOTS {//to do later
	}
	;

parameter_list
	:parameter_declaration {//to do later
	}
	|parameter_list COMMA parameter_declaration {//to do later
	}
	;

parameter_declaration
	:declaration_specifiers declarator {//to do later
		$2->category = "param";
	}
	|declaration_specifiers {//to do later
	}
	;

identifier_list
	:IDENTIFIER {//to do later
	}
	|identifier_list COMMA IDENTIFIER {//to do later
	}
	;

type_name
	:specifier_qualifier_list {//to do later
	}
	;

initializer
	:assignment_expression {
		$$ = $1->loc;
	}
	|CURBRAOPEN initializer_list CURBRACLOSE {//to do later
	}
	|CURBRAOPEN initializer_list COMMA CURBRACLOSE {//to do later
	}
	;


initializer_list
	:designation initializer {//to do later
	}
	|initializer {//to do later
	}
	|initializer_list COMMA designation initializer {//to do later
	}
	|initializer_list COMMA initializer {//to do later
	}
	;

designation
	:designator_list ASSIGN {//to do later
	}
	;

designator_list
	:designator {//to do later
	}
	|designator_list designator {//to do later
	}
	;

designator
	:SQBRAOPEN constant_expression SQBRACLOSE {//to do later
	}
	|DOT IDENTIFIER {//to do later
	}
	;

statement
	:labeled_statement {//to do later
	}
	|compound_statement {$$=$1;}
	|expression_statement {
		$$ = new statement();
		$$->nextlist = $1->nextlist;
	}
	|selection_statement {$$=$1;}
	|iteration_statement {$$=$1;}
	|jump_statement {$$=$1;}
	;

labeled_statement
	:IDENTIFIER COLON statement {$$ = new statement();}
	|CASE constant_expression COLON statement {$$ = new statement();}
	|DEFAULT COLON statement {$$ = new statement();}
	;

compound_statement
	:CURBRAOPEN block_item_list CURBRACLOSE {$$=$2;}
	|CURBRAOPEN CURBRACLOSE {$$ = new statement();}
	;

block_item_list
	:block_item {$$=$1;}
	|block_item_list MLabel block_item {
		$$=$3;
		backpatch ($1->nextlist, $2);
	}
	;

block_item
	:declaration {
		$$ = new statement();
	}
	|statement {$$ = $1;}
	;

expression_statement
	:expression SEMICOLON {$$=$1;}
	|SEMICOLON {$$ = new expr();}
	;

selection_statement
	:IF ROBRAOPEN expression NLabel ROBRACLOSE MLabel statement NLabel %prec THEN{
		backpatch ($4->nextlist, next_instr());
		convert2Bool($3);
		$$ = new statement();
		backpatch ($3->truelist, $6);
		list<int> temp = merge ($3->falselist, $7->nextlist);
		$$->nextlist = merge ($8->nextlist, temp);
	}
	|IF ROBRAOPEN expression NLabel ROBRACLOSE MLabel statement NLabel ELSE MLabel statement {
		backpatch ($4->nextlist, next_instr());
		convert2Bool($3);
		$$ = new statement();
		backpatch ($3->truelist, $6);
		backpatch ($3->falselist, $10);
		list<int> temp = merge ($7->nextlist, $8->nextlist);
		$$->nextlist = merge ($11->nextlist,temp);
	}
	|SWITCH ROBRAOPEN expression ROBRACLOSE statement {//to do later
	}
	;

iteration_statement
	:WHILE MLabel ROBRAOPEN expression ROBRACLOSE MLabel statement {
		$$ = new statement();
		convert2Bool($4);
		// M1 to go back to boolean again
		// M2 to go to statement if the boolean is true
		backpatch($7->nextlist, $2);
		backpatch($4->truelist, $6);
		$$->nextlist = $4->falselist;
		// Emit to prevent fallthrough
		stringstream strs;
	    strs << $2;
	    string temp_str = strs.str();
	    char* intStr = (char*) temp_str.c_str();
		string str = string(intStr);
		emit ("GOTOOP", str);
	}
	
	|DO MLabel statement MLabel WHILE ROBRAOPEN expression ROBRACLOSE SEMICOLON {
		$$ = new statement();
		convert2Bool($7);
		// M1 to go back to statement if expression is true
		// M2 to go to check expression if statement is complete
		backpatch ($7->truelist, $2);
		backpatch ($3->nextlist, $4);

		// Some bug in the next statement
		$$->nextlist = $7->falselist;
	}
	|FOR ROBRAOPEN expression_statement MLabel expression_statement ROBRACLOSE MLabel statement{
		$$ = new statement();
		convert2Bool($5);
		backpatch ($5->truelist, $7);
		backpatch ($8->nextlist, $4);
		stringstream strs;
	    strs << $4;
	    string temp_str = strs.str();
	    char* intStr = (char*) temp_str.c_str();
		string str = string(intStr);

		emit ("GOTOOP", str);
		$$->nextlist = $5->falselist;
	}
	|FOR ROBRAOPEN expression_statement MLabel expression_statement MLabel expression NLabel ROBRACLOSE MLabel statement{
		$$ = new statement();
		convert2Bool($5);
		backpatch ($5->truelist, $10);
		backpatch ($8->nextlist, $4);
		backpatch ($11->nextlist, $6);
		stringstream strs;
	    strs << $6;
	    string temp_str = strs.str();
	    char* intStr = (char*) temp_str.c_str();
		string str = string(intStr);
		emit ("GOTOOP", str);
		$$->nextlist = $5->falselist;
	}
	;

jump_statement
	:GOTO IDENTIFIER SEMICOLON {$$ = new statement();}
	|CONTINUE SEMICOLON {$$ = new statement();}
	|BREAK SEMICOLON {$$ = new statement();}
	|RETURN expression SEMICOLON {
		$$ = new statement();
		emit("RETURN",$2->loc->name);
	}
	|RETURN SEMICOLON {
		$$ = new statement();
		emit("RETURN","");
	}
	;

translation_unit
	:external_declaration {}
	|translation_unit external_declaration {}
	;

external_declaration
	:function_definition {}
	|declaration {}
	;

function_definition
	:declaration_specifiers declarator declaration_list CT compound_statement {}
	|declaration_specifiers declarator CT compound_statement 
	{
		emit ("FUNCEND", table->name); //added
		table->parent = global_Table;
		changeTable (global_Table);
	}
	;

declaration_list
	:declaration {//to do later
	}
	|declaration_list declaration {//to do later
	}
	;



%%

void yyerror(string s) {
    cout<<s<<endl;
}