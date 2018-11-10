#include "translator.h"
#include <iostream>
#include <cstring>
#include <string>

extern FILE *yyin;
extern vector<string> allstrings;

using namespace std;

int labelCount=0;							// Label count in asm file
std::map<int, int> labelMap;				// map from quad number to label number
ofstream out;								// asm file stream
vector <quad> array;						// quad array
string asmfilename="";		// asm file name
string inputfile="test";		// input file name


void computeActivationRecord(symbol_Table* st) 
{
	int param = -20;
	int local = -24;
	for (list <symbl>::iterator it = st->table.begin(); it!=st->table.end(); it++) 
	{
		if (it->category =="param") {
			st->ar [it->name] = param;
			// cout<<it->name<<" param  offset is"<<param<<endl; 
			param +=it->size;
			
		}
		else if (it->name=="return") continue;
		else {
			st->ar [it->name] = local;
			// cout<<it->name<<" local  offset is"<<local<<endl; 
			local -=it->size;
			

		}
		
	}
}


void genasm() {
	array = q.array;

	//To update the goto labels
	for (vector<quad>::iterator it = array.begin(); it!=array.end(); it++) {
	int i;
	if (it->op=="GOTOOP" || it->op=="LT" || it->op=="GT" || it->op=="LE" || it->op=="GE" || it->op=="EQOP" || it->op=="NEOP") {
		i = atoi(it->result.c_str());
		labelMap [i] = 1;
	}
	}
	int count = 0;
	for (std::map<int,int>::iterator it=labelMap.begin(); it!=labelMap.end(); ++it)
		it->second = count++;
	list<symbol_Table*> tablelist;
	for (list <symbl>::iterator it = global_Table->table.begin(); it!=global_Table->table.end(); it++) {
		if (it->nested!=NULL) tablelist.push_back (it->nested);
	}
	for (list<symbol_Table*>::iterator iterator = tablelist.begin(); 
		iterator != tablelist.end(); ++iterator) {
		computeActivationRecord(*iterator);
	}

	//asmfile
	ofstream asmfile;
	asmfile.open(asmfilename.c_str());

	asmfile << "\t.file	\"test.c\"\n";
	for (list <symbl>::iterator it = table->table.begin(); it!=table->table.end(); it++) {
		if (it->category!="function") {
			if (it->type->type=="CHAR") { // Global char
				if (it->initial_value!="") {
					asmfile << "\t.globl\t" << it->name << "\n";
					asmfile << "\t.type\t" << it->name << ", @object\n";
					asmfile << "\t.size\t" << it->name << ", 1\n";
					asmfile << it->name <<":\n";
					asmfile << "\t.byte\t" << atoi( it->initial_value.c_str()) << "\n";
				}
				else {
					asmfile << "\t.comm\t" << it->name << ",1,1\n";
				}
			}
			if (it->type->type=="INTEGER") { // Global int
				if (it->initial_value!="") {
					asmfile << "\t.globl\t" << it->name << "\n";
					asmfile << "\t.data\n";
					asmfile << "\t.align 4\n";
					asmfile << "\t.type\t" << it->name << ", @object\n";
					asmfile << "\t.size\t" << it->name << ", 4\n";
					asmfile << it->name <<":\n";
					asmfile << "\t.long\t" << it->initial_value << "\n";
				}
				else {
					asmfile << "\t.comm\t" << it->name << ",4,4\n"; //commented
				}
			}
		}
	}
	if (allstrings.size()) {
		asmfile << "\t.section\t.rodata\n";
		for (vector<string>::iterator it = allstrings.begin(); it!=allstrings.end(); it++) {
			asmfile << ".LC" << it - allstrings.begin() << ":\n";
			asmfile << "\t.string\t" << *it << "\n";	
		}	
	}
	asmfile << "\t.text	\n";

	vector<string> params;
	std::map<string, int> theMap;
	for (vector<quad>::iterator it = array.begin(); it!=array.end(); it++) {
		if (labelMap.count(it - array.begin())) {
			asmfile << ".L" << (2*labelCount+labelMap.at(it - array.begin()) + 2 )<< ": " << endl;
		}

		string op = it->op;
		string result = it->result;
		string argu1 = it->argu1;
		string argu2 = it->argu2;
		string s=argu2;

		if(op=="PARAM"){
			params.push_back(result);
		}
		else {
			asmfile << "\t";
			// Binary Operations
			if (op=="ADD") {
				bool flag=true;
				if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) flag=false ;
				else{
					char * p ;
					strtol(s.c_str(), &p, 10) ;
					if(*p == 0) flag=true ;
					else flag=false;
				}
				if (flag) {
					asmfile << "addl \t$" << atoi(argu2.c_str()) << ", " << table->ar[argu1] << "(%rbp)";
				}
				else {
					asmfile << "movl \t" << table->ar[argu1] << "(%rbp), " << "%eax" << endl;
					asmfile << "\tmovl \t" << table->ar[argu2] << "(%rbp), " << "%edx" << endl;
					asmfile << "\taddl \t%edx, %eax\n";
					asmfile << "\tmovl \t%eax, " << table->ar[result] << "(%rbp)";
				}
			}
			else if (op=="SUB") {
				asmfile << "movl \t" << table->ar[argu1] << "(%rbp), " << "%eax" << endl;
				asmfile << "\tmovl \t" << table->ar[argu2] << "(%rbp), " << "%edx" << endl;
				asmfile << "\tsubl \t%edx, %eax\n";
				asmfile << "\tmovl \t%eax, " << table->ar[result] << "(%rbp)";
			}
			else if (op=="MULT") {
				asmfile << "movl \t" << table->ar[argu1] << "(%rbp), " << "%eax" << endl;
				bool flag=true;
				if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) flag=false ;
				else{
					char * p ;
					strtol(s.c_str(), &p, 10) ;
					if(*p == 0) flag=true ;
					else flag=false;
				}
				if (flag) {
					asmfile << "\timull \t$" << atoi(argu2.c_str()) << ", " << "%eax" << endl;
					symbol_Table* t = table;
					string val;
					for (list <symbl>::iterator it = t->table.begin(); it!=t->table.end(); it++) {
						if(it->name==argu1) val=it->initial_value; 
					}
					theMap[result]=atoi(argu2.c_str())*atoi(val.c_str());
				}
				else asmfile << "\timull \t" << table->ar[argu2] << "(%rbp), " << "%eax" << endl;
				asmfile << "\tmovl \t%eax, " << table->ar[result] << "(%rbp)";			
			}
			else if(op=="DIVIDE") {
				asmfile << "movl \t" << table->ar[argu1] << "(%rbp), " << "%eax" << endl;
				asmfile << "\tcltd" << endl;
				asmfile << "\tidivl \t" << table->ar[argu2] << "(%rbp)" << endl;
				asmfile << "\tmovl \t%eax, " << table->ar[result] << "(%rbp)";		
			}

			// Bit Operators /* Ignored */
			else if (op=="MODOP")
			{
				asmfile << "movl \t" << table->ar[argu1] << "(%rbp), " << "%eax" << endl;
				asmfile <<"cltd"<<endl;
				asmfile<<"idivl \t"<<table->ar[argu2] << "(%rbp)"<<endl;
				asmfile << "movl \t" << "%edx ,"<<table->ar[result] << "(%rbp)" << endl;

			}
			else if (op=="XOR")			asmfile << result << " = " << argu1 << " ^ " << argu2;
			else if (op=="INOR")		asmfile << result << " = " << argu1 << " | " << argu2;
			else if (op=="BAND")		asmfile << result << " = " << argu1 << " & " << argu2;
			// Shift Operations /* Ignored */
			else if (op=="LEFTOP")		asmfile << result << " = " << argu1 << " << " << argu2;
			else if (op=="RIGHTOP")		asmfile << result << " = " << argu1 << " >> " << argu2;

			else if (op=="EQUAL")	{
				s=argu1;
				bool flag=true;
				if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) flag=false ;
				else{
					char * p ;
					strtol(s.c_str(), &p, 10) ;
					if(*p == 0) flag=true ;
					else flag=false;
				}
				if (flag) 
					asmfile << "movl\t$" << atoi(argu1.c_str()) << ", " << "%eax" << endl;
				else
					asmfile << "movl\t" << table->ar[argu1] << "(%rbp), " << "%eax" << endl;
				asmfile << "\tmovl \t%eax, " << table->ar[result] << "(%rbp)";
			}			
			else if (op=="EQUALSTR")	
			{ //goto values problem
				asmfile << "movq \t$.LC" << argu1 << ", " << table->ar[result] << "(%rbp)";
			}
			else if (op=="EQUALCHAR")	{
				asmfile << "movb\t$" << atoi(argu1.c_str()) << ", " << table->ar[result] << "(%rbp)";
			}					
			// Relational Operations
			else if (op=="EQOP") {
				asmfile << "movl\t" << table->ar[argu1] << "(%rbp), %eax\n";
				asmfile << "\tcmpl\t" << table->ar[argu2] << "(%rbp), %eax\n";
				asmfile << "\tje .L" << (2*labelCount+labelMap.at(atoi( result.c_str() )) +2 );
			}
			else if (op=="NEOP") {
				asmfile << "movl\t" << table->ar[argu1] << "(%rbp), %eax\n";
				asmfile << "\tcmpl\t" << table->ar[argu2] << "(%rbp), %eax\n";
				asmfile << "\tjne .L" << (2*labelCount+labelMap.at(atoi( result.c_str() )) +2 );
			}
			else if (op=="LT") {
				asmfile << "movl\t" << table->ar[argu1] << "(%rbp), %eax\n";
				asmfile << "\tcmpl\t" << table->ar[argu2] << "(%rbp), %eax\n";
				asmfile << "\tjl .L" << (2*labelCount+labelMap.at(atoi( result.c_str() )) +2 );
			}
			else if (op=="GT") {
				asmfile << "movl\t" << table->ar[argu1] << "(%rbp), %eax\n";
				asmfile << "\tcmpl\t" << table->ar[argu2] << "(%rbp), %eax\n";
				asmfile << "\tjg .L" << (2*labelCount+labelMap.at(atoi( result.c_str() )) +2 );
			}
			else if (op=="GE") {
				asmfile << "movl\t" << table->ar[argu1] << "(%rbp), %eax\n";
				asmfile << "\tcmpl\t" << table->ar[argu2] << "(%rbp), %eax\n";
				asmfile << "\tjge .L" << (2*labelCount+labelMap.at(atoi( result.c_str() )) +2 );
			}
			else if (op=="LE") {
				asmfile << "movl\t" << table->ar[argu1] << "(%rbp), %eax\n";
				asmfile << "\tcmpl\t" << table->ar[argu2] << "(%rbp), %eax\n";
				asmfile << "\tjle .L" << (2*labelCount+labelMap.at(atoi( result.c_str() )) +2 );
			}
			else if (op=="GOTOOP") {
				asmfile << "jmp .L" << (2*labelCount+labelMap.at(atoi( result.c_str() )) +2 );
			}
			// Unary Operators
			else if (op=="ADDRESS") {
				asmfile << "leaq\t" << table->ar[argu1] << "(%rbp), %rax\n";
				asmfile << "\tmovq \t%rax, " <<  table->ar[result] << "(%rbp)";
			}
			else if (op=="PTRR") {
				asmfile << "movq\t" << table->ar[argu1] << "(%rbp), %rax\n"; //change
				asmfile << "\tmovl\t(%rax),%eax\n";
				asmfile << "\tmovl \t%eax, " <<  table->ar[result] << "(%rbp)";	
			}
			else if (op=="PTRL") {
				asmfile << "movq\t" << table->ar[result] << "(%rbp), %rax\n";
				asmfile << "\tmovl\t" << table->ar[argu1] << "(%rbp), %edx\n";
				asmfile << "\tmovl\t%edx, (%rax)";
			} 			
			else if (op=="UMINUS") {
				asmfile << "negl\t" << table->ar[argu1] << "(%rbp)";
			}
			else if (op=="BNOT")		asmfile << result 	<< " = ~" << argu1;
			else if (op=="LNOT")			asmfile << result 	<< " = !" << argu1;
			else if (op=="ARRR") {
				int off=0;
				off=theMap[argu2]*(-1)+table->ar[argu1];
//				asmfile << "movq\t" << table->ar[argu2] << "(%rbp), "<<"%rax" << endl;
				asmfile << "movq\t" << off << "(%rbp), "<<"%rax" << endl;
				asmfile << "\tmovq \t%rax, " <<  table->ar[result] << "(%rbp)";
			}	 			
			else if (op=="ARRL") {
				int off=0;
				off=theMap[argu1]*(-1)+table->ar[result];
//				asmfile << "movq\t" << table->ar[argu1] << "(%rbp), "<<"%rax" << endl;
				asmfile << "movq\t" << table->ar[argu2] << "(%rbp), "<<"%rdx" << endl;
				asmfile << "\tmovq\t" << "%rdx, " << off << "(%rbp)";
			}	 
			else if (op=="RETURN") {
				if(result!="") asmfile << "movl\t" << table->ar[result] << "(%rbp), "<<"%eax";
				else asmfile << "nop";
			}
			else if (op=="PARAM") {
				params.push_back(result);
			}
			else if (op=="CALL") {
				// Function Table
				symbol_Table* t = global_Table->look_Up(argu1)->nested;
				int i,j=0;	// index
				for (list <symbl>::iterator it = t->table.begin(); it!=t->table.end(); it++) {
					i = distance ( t->table.begin(), it);
					if (it->category== "param") {
						if(j==0) {
							asmfile << "movl \t" << table->ar[params[i]] << "(%rbp), " << "%eax" << endl;
							asmfile << "\tmovq \t" << table->ar[params[i]] << "(%rbp), " << "%rdi" << endl;
							//asmfile << "\tmovl \t%eax, " << (t->ar[it->name]-8 )<< "(%rsp)\n\t";
							j++;
						}
						else if(j==1) {
							asmfile << "movl \t" << table->ar[params[i]] << "(%rbp), " << "%eax" << endl;
							asmfile << "\tmovq \t" << table->ar[params[i]] << "(%rbp), " << "%rsi" << endl;
							//asmfile << "\tmovl \t%eax, " << (t->ar[it->name]-8 )<< "(%rsp)\n\t";
							j++;
						}
						else if(j==2) {
							asmfile << "movl \t" << table->ar[params[i]] << "(%rbp), " << "%eax" << endl;
							asmfile << "\tmovq \t" << table->ar[params[i]] << "(%rbp), " << "%rdx" << endl;
							//asmfile << "\tmovl \t%eax, " << (t->ar[it->name]-8 )<< "(%rsp)\n\t";
							j++;
						}
						else if(j==3) {
							asmfile << "movl \t" << table->ar[params[i]] << "(%rbp), " << "%eax" << endl;
							asmfile << "\tmovq \t" << table->ar[params[i]] << "(%rbp), " << "%rcx" << endl;
							//asmfile << "\tmovl \t%eax, " << (t->ar[it->name]-8 )<< "(%rsp)\n\t";
							j++;
						}
						else {
							asmfile << "\tmovq \t" << table->ar[params[i]] << "(%rbp), " << "%rdi" << endl;							
						}
					}
					else break;
				}
				params.clear();
				asmfile << "call\t"<< argu1 << endl; //change
				asmfile << "\tmovl\t%eax, " << table->ar[result] << "(%rbp)";
			}
			else if (op=="FUNC") {
				asmfile <<".globl\t" << result << "\n";
				asmfile << "\t.type\t"	<< result << ", @function\n";
				asmfile << result << ": \n";
				asmfile << ".LFB" << labelCount <<":" << endl;
				asmfile << "\t.cfi_startproc" << endl;
				asmfile << "\tpushq \t%rbp" << endl;
				asmfile << "\t.cfi_def_cfa_offset 8" << endl;
				asmfile << "\t.cfi_offset 5, -8" << endl;
				asmfile << "\tmovq \t%rsp, %rbp" << endl;
				asmfile << "\t.cfi_def_cfa_register 5" << endl;
				table = global_Table->look_Up(result)->nested;
				asmfile << "\tsubq\t$" << table->table.back().offset+24 << ", %rsp"<<endl;
				
				// Function Table
				symbol_Table* t = table;
				int i=0;
				for (list <symbl>::iterator it = t->table.begin(); it!=t->table.end(); it++) {
					if (it->category== "param") {
						if (i==0) {
							asmfile << "\tmovq\t%rdi, " << table->ar[it->name] << "(%rbp)";
							i++;
						}
						else if(i==1) {
							asmfile << "\n\tmovq\t%rsi, " << table->ar[it->name] << "(%rbp)";
							i++;
						}
						else if (i==2) {
							asmfile << "\n\tmovq\t%rdx, " << table->ar[it->name] << "(%rbp)";
							i++;
						}
						else if(i==3) {
							asmfile << "\n\tmovq\t%rcx, " << table->ar[it->name] << "(%rbp)";
							i++;
						}
					}
					else break;
				}
			}		
			else if (op=="FUNCEND") {
				asmfile << "leave\n";
				asmfile << "\t.cfi_restore 5\n";
				asmfile << "\t.cfi_def_cfa 4, 4\n";
				asmfile << "\tret\n";
				asmfile << "\t.cfi_endproc" << endl;
				asmfile << ".LFE" << labelCount++ <<":" << endl;
				asmfile << "\t.size\t"<< result << ", .-" << result;
			}
			else
			{
				cout<<"else case is "<<op<<endl;
				 asmfile << "op";
			}
			asmfile << endl;
		}
	}
	asmfile << 	"\t.ident\t	\"Compiled by 16CS30027\"\n";
	asmfile << 	"\t.section\t.note.GNU-stack,\"\",@progbits\n";
	asmfile.close();
}

template<class T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
	copy(v.begin(), v.end(), ostream_iterator<T>(os, " ")); 
	return os;
}

int main(int ac, char* av[]) {
	inputfile=inputfile+string(av[ac-1])+string(".c");
	asmfilename=asmfilename+string(av[ac-1])+string(".s");
	global_Table = new symbol_Table("Global");
	table = global_Table;
	yyin = fopen(inputfile.c_str(),"r"); 
	yyparse();
	global_Table->update();
	global_Table->print();
	q.print();
	genasm();
}