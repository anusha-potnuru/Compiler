// By Anusha Potnuru
#include "translator.h"
#include <sstream>
extern int yydebug;
extern char * yytext;
extern void yyerror(const char *);
using namespace std;

//reference to global variables declared in header file 
quadArray q;							// Quad Array
string Type;							// Stores latest type
symbol_Table* global_Table;					// Global Symbbol Table
symbol_Table* table;						// Points to current symbol table
symbl* current_Symbl; 					// points to current symbol


//Returns a string for given int
string conv2string(int v)
{
	stringstream sbuff;
	sbuff<<v;
	return sbuff.str();
}

// Converts double to string
string conv2string(float v)
{
	stringstream sbuff;
	sbuff<<v;
	return sbuff.str();
}

// converts int to string
int conv2int(string s)
{
	return atoi(s.c_str());
}

// quad class constructors
quad::quad (string result, string argu1, string op, string argu2)
{
	this->result = result;
	this->argu1 = argu1; 
	this->argu2 = argu2; 
	this->op = op;
}

quad::quad (string result, int argu1, string op, string argu2):
	result (result), argu2(argu2), op (op) {
		this->argu1 = conv2string(argu1); 
	}

quad::quad (string result, float argu1, string op, string argu2):
	result (result), argu2(argu2), op (op) {
		std::ostringstream buff;
   		buff<<argu1;
		this->argu1 = buff.str();
	}


map<std::string,std::string> opSymbols;


// Auxillary function for quad print
void push_op_Symbol(std::string result,std::string argu1,std::string argu2){
	//For all of the arithmetic operations
	opSymbols["ADD"]=result+" = "+argu1+" + "+argu2;
	opSymbols["SUB"]=result+" = "+argu1+" - "+argu2;
	opSymbols["MULT"]=result+" = "+argu1+" * "+argu2;
	opSymbols["DIVIDE"]=result+" = "+argu1+" / "+argu2;
	opSymbols["MODOP"]=result+" = "+argu1+" % "+argu2;
	opSymbols["XOR"]=result+" = "+argu1+" ^ "+argu2;
	opSymbols["INOR"]=result+" = "+argu1+" | "+argu2;
	opSymbols["BAND"]=result+" = "+argu1+" & "+argu2;
	
	opSymbols["LEFTOP"]=result+" = "+argu1+" << "+argu2;
	opSymbols["RIGHTOP"]=result+" = "+argu1+" >> "+argu2;
	opSymbols["EQUAL"]=result+" = "+argu1;
	opSymbols["EQUALCHAR"]=result+" = "+argu1; //check
	opSymbols["EQUALSTR"]=result+" = "+argu2;

	opSymbols["ADDRESS"]=result+" = &"+argu1;
	opSymbols["PTRR"]=result+" = *"+argu1 ;
	opSymbols["PTRL"]="*"+result+" = "+argu1 ;
	opSymbols["UMINUS"]=result+" = -"+argu1;
	opSymbols["BNOT"]=result+" = ~"+argu1;
	opSymbols["LNOT"]=result+" = !"+argu1;

	opSymbols["EQOP"]="if "+argu1+" == "+argu2+" goto "+result;
	opSymbols["NEOP"]="if "+argu1+" != "+argu2+" goto "+result;
	opSymbols["LT"]="if "+argu1+" < "+argu2+" goto "+result;
	opSymbols["GT"]="if "+argu1+" > "+argu2+" goto "+result;
	opSymbols["GE"]="if "+argu1+" >= "+argu2+" goto "+result;
	opSymbols["LE"]="if "+argu1+" <= "+argu2+" goto "+result;
	opSymbols["GOTOOP"]="goto "+result;

	opSymbols["ARRR"]=result+" = "+argu1+"["+argu2+"]";
	opSymbols["ARRL"]=result+"["+argu1+"]"+" = "+argu2;
	opSymbols["RETURN"]="ret "+result;
	opSymbols["PARAM"]="param "+result;
	opSymbols["CALL"]=result+" = "+"call "+argu1+", "+argu2;
	opSymbols["FUNC"]=result+": ";
	opSymbols["FUNCEND"]="";
}

// Functions
void quad::print () {
	// Binary Operations
	push_op_Symbol(result,argu1,argu2);
	string ans;
	if(opSymbols.find(op)!=opSymbols.end())
	{		
		ans = opSymbols[op];
		cout<<ans<<"\n";
	}
	// else if(op == "EQUALSTR" || op == "EQUALCHAR")
	// {
	// 	return;
	// }
	else
	{
		ans = "op";
		cout<<ans<<"\n";
	}	
}

void quadArray::print() {
	cout << string(35, '=') << endl;
	cout << "Quad Translation:" << endl;
	cout << string(35, '-') << endl;
	vector<quad>::iterator iter = array.begin();
	// int i=1;
	while(iter< array.end())
	{
		if (iter->op == "FUNC") 
		{
			cout << "\n";	
			iter->print();
			cout << "\n";			
		}
		else if(iter->op == "FUNCEND" ) {} //|| iter->op == "EQUALSTR" || iter->op == "EQUALCHAR"
		else 
		{			
			cout << "\t" << setw(4) << iter - array.begin() << ":\t";
			// cout << "\t" << setw(4) << i << ":\t";
			iter->print();
			
		}
		// i++;
		iter++;
	}
	cout << string(35, '-') << endl;
}

// Constructors
symbol_type::symbol_type(string type, symbol_type* ptr, int wid)
{
	this->type = type;
	this->ptr = ptr;
	this->width = wid;
}

symbl::symbl (string name, string t, symbol_type* ptr, int wid): name(name)  
{
	type = new symbol_type (t, ptr, wid);
	initial_value = "";
	category = "";
	nested = NULL;	
	offset = 0;
	offset++; offset--;
	size = size_of_type(type);
}

symbl* symbl::update(symbol_type* t) 
{
	type = t;
	this ->size = size_of_type(t);
	return this;
}

symbol_Table::symbol_Table (string name): name (name), count(0) {}

list<symbol_Table*> symbol_Table::printheader()
{
	list<symbol_Table*> tablelist;
	cout << string(120, '=') << endl;
	cout << "Symbol Table: " << setfill (' ') << left << setw(50)  << this -> name ;
	cout << right << setw(25) << "Parent: ";
	if (this->parent!= NULL)
		cout << this -> parent->name;
	else cout << "null" ;
	cout << endl;
	cout << setw(100) << setfill ('-') << "-"<< endl;
	cout << setfill (' ') << left << setw(20) << "Name";
	cout << left << setw(26) << "Type";
	cout << left << setw(15) << "Category";
	cout << left << setw(21) << "Initial Value";
	cout << left << setw(13) << "Size";
	cout << left << setw(13) << "Offset";
	cout << left << "Nested Table" << endl;
	cout << string(120, '=') << endl;
	return tablelist;
}

// FUNCTIONS
void symbol_Table::print() {
	list<symbol_Table*> tablelist = printheader();	
	for (list <symbl>::iterator it = table.begin(); it!=table.end(); it++) {
		cout << left << setw(20) << it->name;
		string stype = print_type(it->type);
		cout << left << setw(26) << stype;
		cout << left << setw(17) << it->initial_value;
		cout << left << setw(15) << it->category;
		cout << left << setw(13) << it->size;
		cout << left << setw(13) << it->offset;
		cout << left;
		if (it->nested == NULL) {
			cout << "null" << endl;	
		}
		else {
			cout << "ptr-to-ST(" <<it->nested->name << ")" <<  endl;
			tablelist.push_back (it->nested);
		}
	}
	cout << string(120, '=') << endl;
	cout << endl;
	list<symbol_Table*>::iterator iter = tablelist.begin();
	while(iter!= tablelist.end())
	{
		(*iter)->print();
		++iter;
	}
}

void symbol_Table::update() {
	list<symbol_Table*> table_list;
	int off;
	for (list <symbl>::iterator iter = table.begin(); iter!=table.end(); iter++) {
		if (iter==table.begin()) {
			iter->offset = 0;
			off = iter->size;
		}
		else {
			iter->offset = off;
			off = iter->offset + iter->size;
		}
		if (iter->nested!=NULL) table_list.push_back (iter->nested);
	}
	list<symbol_Table*>::iterator iter = table_list.begin();
	while(iter!=table_list.end())
	{
	    (*iter)->update();
	    ++iter;
	}
}

symbl* symbol_Table::look_Up (string name) {
	symbl* s;
	list <symbl>::iterator it;
	for (it = table.begin(); it!=table.end(); it++) 
	{
		if (it->name == name ) 
			break;
	}
	// New symbol to be added to table
	if (it ==table.end()) 
	{
		
		s =  new symbl (name);
		s->category = "local";
		table.push_back (*s);
		return &table.back();
	}
	else 
	{
		
			return &*it;
	}
}

// Overloaded function to push quad to array
void emit(string op, string result, int argu1, string argu2) {
	q.array.push_back(*(new quad(result,argu1,op,argu2)));
}
void emit(string op, string result, string argu1, string argu2) {
	q.array.push_back(*(new quad(result,argu1,op,argu2)));
}

void emit(string op, string result, float argu1, string argu2) {
	q.array.push_back(*(new quad(result,argu1,op,argu2)));
}


// Auxillary functions for conv
symbl* convsymfromint(symbl*s, string t)
{
	symbl* tempor = gentemp(new symbol_type(t));
	if (t=="FLOAT") {
			emit ("EQUAL", tempor->name, " int2float(" + s->name + ")");
			return tempor;
	}
	else if (t=="CHAR") {
		emit ("EQUAL", tempor->name, " int2char(" + s->name + ")");
		return tempor;
	}
	return s;
}

symbl* convsymfromchar(symbl*s, string t)
{
	symbl* tempor = gentemp(new symbol_type(t));
	if (t=="INTEGER") {
			emit ("EQUAL", tempor->name, " char2int(" + s->name + ")");
			return tempor;
		}
	if (t=="FLOAT") {
			emit ("EQUAL", tempor->name, " char2float(" + s->name + ")");
			return tempor;
		}
	return s;
}

symbl* convsymfromfloat(symbl* s, string t)
{
	symbl* tempor = gentemp(new symbol_type(t));
	if (t=="INTEGER") {
			emit ("EQUAL", tempor->name, " float2int(" + s->name + ")");
			return tempor;
		}
		else if (t=="CHAR") {
			emit ("EQUAL", tempor->name, " float2char(" + s->name + ")");
			return tempor;
		}
		return s;
}


/*
Input: Symbol s, type as string t
Output: Generates corresponding code to convert s to t
Algorithm: Creates temporary of type t and creates code if it is compaitable
Purpose: Used for typecasting symbols
*/
symbl* conv (symbl* s, string t) {
	symbl* tempor = gentemp(new symbol_type(t));
	if (s->type->type=="INTEGER" ) 
	{
		return convsymfromint(s, t);
	}
	else if (s->type->type=="CHAR") {
		return convsymfromchar(s,t);
	}
	else if (s->type->type=="FLOAT" ) {
		return convsymfromfloat(s,t);
	}
	return s;
}

/*
Input: Symbol s1, s2
Output: Boolean if the symbol s1 and s2 have same type or compaitable types 
		and typecasts to higher datatype
Algorithm: Checks if their symbol_type is same or not, does that recursively if arrays 
			and uses overloaded function.
Purpose: Checks if the symbols have same type or not and typecasts if they are compaitable
*/
bool typecheck(symbl*& s1, symbl*& s2)
{ 	
	symbol_type* type1 = s1->type;
	symbol_type* type2 = s2->type;
	if ( typecheck (type1, type2) ) return true;
	// else if(s1 = conv (s1, type2->type) ) return true;
	else if ( type1!=NULL && type2!=NULL && (size_of_type(type1) <= size_of_type(type2)) )
	{
		if (s1 = conv (s1, type2->type) ) return true;
	}
	else if (s2 = conv (s2, type1->type) ) return true;
	else return false;
}

// Check if the symbol types are same or not
bool typecheck(symbol_type* t1, symbol_type* t2){ 	
	if (t1 != NULL || t2 != NULL) 
	{
		if (t2==NULL || t1==NULL ) return false;
		// if (t1==NULL) return false;		
		if (t1->type==t2->type) return typecheck(t1->ptr, t2->ptr);
		else 
			return false;
	}
	return true;
}

/*
Input: List l, address addr
Output: Adds the address a in the result of the quad
Algorithm: Adds the address a in the result of the quad
Purpose: To add addresses later in code
*/
void backpatch (list <int> l, int a) {
 //changed
	list<int>::iterator ite= l.begin();
	while(ite!= l.end())
	{
		q.array[*ite].result = conv2string(a);
		ite++;
	}
}

/*
Input: int i
Output: Returns a list containing int i
Algorithm: Uses inbuilt list<int> datatype
Purpose: To creates lists needed for truelist, falselist or nextlist
*/
list<int> makelist (int j) {
	j++; j--;
	list<int> l(1,j);
	return l;
}
list<int> makelist () {
	list<int> li;
	return li;
}

/*
Input: Pointers to Lists a , b
Output: Returns a contatenated list of a and b
Algorithm: Uses inbuilt merge function
Purpose: Support funtion To merge lists
*/
list<int> merge (list<int> &a, list <int> &b) {
	a.merge(b);
	return a;
}

// Convert any expression to bool and generates corresponding code
expr* convert2Bool (expr* e) {	
	if(e->type == "BOOL")
	{
	}
	else {
		e->falselist = makelist (next_instr());
		emit ("EQOP", "", e->loc->name, "0");
		e->truelist = makelist (next_instr());
		emit ("GOTOOP", "");
	}
}

// Convert any expression to bool and generates corresponding code
expr* convertBool2Int (expr* e) {	

	if (e->type=="BOOL") {
		e->loc = gentemp(new symbol_type("INTEGER"));
		backpatch (e->truelist, next_instr());
		emit ("EQUAL", e->loc->name, "1");
		stringstream strs;
	    strs << next_instr()+2;
	    string temp_str = strs.str();
	    char* intStr = (char*) temp_str.c_str();
		string str = string(intStr);
		emit ("GOTOOP", str);
		backpatch (e->falselist, next_instr());
		emit ("EQUAL", e->loc->name,  "0");
	}	
}

int next_instr() {
	return q.array.size();
}

// Returns a new temporary whenever called
symbl* gentemp (symbol_type* t, string initial) 
{
	char c[10];
	sprintf(c, "t%02d", table->count++);
	symbl* s = new symbl (c);
	s->size=size_of_type(t);
	s-> initial_value = initial;
	s->category = "temp";
	s->type = t;	
	table->table.push_back ( *s);
	return &table->table.back();
}

// Returns symbol type
string print_type (symbol_type* t)
{
	if (t==NULL) 	return "null";
	else if(t->type=="VOID")	
		return "void";
	else if(t->type=="INTEGER") 
		return "int";
	else if(t->type=="CHAR") 
		return "char";	
	else if(t->type=="FLOAT") 
		return "float";
	else if(t->type=="PTR") 
		return "ptr("+ print_type(t->ptr)+")";
	else if(t->type=="ARR") 
	{
		stringstream strs;
	    strs << t->width;
	    string temp_str = strs.str();
	    char* int_Str = (char*) temp_str.c_str();
		string str = string(int_Str);
		return "arr(" + str + " , "+ print_type( t->ptr) + ")";
	}
	else if(t->type=="FUNC") 
			return "function";
	else return "_";
}

// Returns size of the input type t
int size_of_type( symbol_type* t)
{	
	if( strcmp(t->type.c_str(), "VOID") ==0 )	return 0;
	else if( strcmp(t->type.c_str(), "CHAR") ==0 ) 
		return CHAR_SIZE;
	else if( strcmp(t->type.c_str(),"INTEGER")==0) 
		return INT_SIZE;
	else if(strcmp(t->type.c_str(),"FLOAT") ==0) 
		return  FLOAT_SIZE;
	else if(strcmp(t->type.c_str(),"PTR")==0) 
		return POINTER_SIZE;
	else if(strcmp(t->type.c_str(),"ARR")==0) return t->width * size_of_type (t->ptr);
	else if(strcmp(t->type.c_str(), "FUNC")==0) 
		return 0;
}

// Change current symbol table to given table
void changeTable (symbol_Table* newtbl) 
{	
	table = newtbl;
} 

