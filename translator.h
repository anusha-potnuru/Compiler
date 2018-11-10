// By Anusha Potnuru
#ifndef TRANSLATE
#define TRANSLATE
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>

#define CHAR_SIZE 		    1
#define INT_SIZE  		    4
#define FLOAT_SIZE		    8
#define POINTER_SIZE		4

extern  char* yytext;
extern  int yyparse();

using namespace std;

//  Forward class declarations to avoid conflicts
class symbol_type;					// Type of a symbol in symbol table
class quad;						// Entry in quad array
class quadArray;				// QuadArray
class symbl;						// Entry in a symbol table
class symbol_Table;					// Symbol Table


// global variables used in the translator.cxx file are declared here
extern symbol_Table* table;						// Current Symbol Table
extern symbol_Table* global_Table;				// Global Symbol Table
extern quadArray q;							// Array of Quads
extern symbl* current_Symbl;					// Pointer to just encountered symbol


// Class definitions, non terminal type strucure and attributes and global functions
class symbol_type { // Type of symbols in symbol table
public:
	symbol_type(string type, symbol_type* ptr = NULL, int width = 1);
	string type;
	int width;					// Size of array (in case of arrays)
	symbol_type* ptr;				// for 2d arrays and pointers
};

class quad { // Quad Class
public:
	string op;					// Operator
	string result;				// Result
	string argu1;				// Argument 1
	string argu2;				// Argument 2

	void print ();								// Print Quad
	quad (string result, string argu1, string op = "EQUAL", string argu2 = "");			//constructors
	quad (string result, int argu1, string op = "EQUAL", string argu2 = "");				//constructors
	quad (string result, float argu1, string op = "EQUAL", string argu2 = "");			//constructors
};

class quadArray { // Array of quads
public:
	vector <quad> array;		                // Vector of quads
	void print ();								// Print the quadArray
};

class symbl { // Symbols class
public:
	string name;				// Name of the symbol
	symbol_type *type;				// Type of the Symbol
	string initial_value;		// Symbol initial valus (if any)
	string category;    		// global, local or param
	int size;					// Size of the symbol
	int offset;					// Offset of symbol
	symbol_Table* nested;				// Pointer to nested symbol table

	symbl (string name, string t="INTEGER", symbol_type* ptr = NULL, int width = 0); //constructor declaration
	symbl* update(symbol_type * t); 	// A method to update different fields of an existing entry.
	symbl* link_to_symbolTable(symbol_Table* t);
};

class symbol_Table { // Symbol Table class
public:
	string name;				// Name of Table
	int count;					// Count of temporary variables
	list<symbl> table; 			// The table of symbols
	symbol_Table* parent;				// Immediate parent of the symbol table
	map<string, int> ar;			//activation record
	
	symbol_Table (string name="NULL");
	symbl* look_Up (string name);			// Lookup for a symbol in symbol table
	void print();							// Print the symbol table
	list<symbol_Table*> printheader();					            			
	void update();						    // Update offset of the complete symbol table
};


//Attributes and their explanation for different non terminal type
//Attributes for statements
struct statement {
	list<int> nextlist;				// Nextlist for statement
};

//Attributes for array
struct array {
	string cat;
	symbl* loc;					// Temporary used for computing array address
	symbl* array;					// Pointer to symbol table
	symbol_type* type;				// type of the subarray generated
};


//Attributes for expressions
struct expr {
	string type; 							//to store whether the expression is of type int or bool

	// Valid for non-bool type
	symbl* loc;								// Pointer to the symbol table entry

	// Valid for bool type
	list<int> truelist;						// Truelist valid for boolean
	list<int> falselist;					// Falselist valid for boolean expressions

	// Valid for statement expression
	list<int> nextlist;
};

//      Global functions required for the translator //
void emit(string op, string result, string argu1="", string argu2 = "");    //emits for adding quads to quadArray
void emit(string op, string result, int argu1, string argu2 = "");		  //emits for adding quads to quadArray (argu1 is int)
void emit(string op, string result, float argu1, string argu2 = "");        //emits for adding quads to quadArray (argu1 is float)


symbl* conv (symbl*, string);							// TAC for Type conversion in program
bool typecheckwithoutconv(symbl* &s1, symbl* &s2);							
bool typecheck(symbl* &sm1, symbl* &sm2);					// Checks if two symbols have same type
bool typecheck(symbol_type* t1, symbol_type* t2);			//checks if two symbol_type objects have same type

void backpatch (list <int> lst, int a);
list<int> makelist ();	
list<int> makelist (int j);							        // Make a new list contaninig an integer
list<int> merge (list<int> &lst1, list <int> &lst2);		// Merge two lists into a single list

expr* convert2Bool (expr*);				// convert any expression (int) to bool
expr* convertBool2Int (expr*);				// convert bool to expression (int)

void changeTable (symbol_Table* newtable);               //for changing the current sybol table
int next_instr();									// Returns the next instruction number

symbl* gentemp (symbol_type* t, string initial = "");		// Generate a temporary variable and insert it in current symbol table

int size_of_type (symbol_type*);							// Calculate size of any symbol type 
string print_type(symbol_type*);						// For printing type of symbol recursive printing of type

string conv2string(int);
string conv2string(float);

#endif