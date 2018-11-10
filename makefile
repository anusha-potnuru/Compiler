asmGenerate: compiler
	./compiler 1 > quads1.out
	./compiler 2 > quads2.out
	./compiler 3 > quads3.out
	./compiler 4 > quads4.out
	./compiler 5 > quads5.out

compiler: lex.yy.o y.tab.o translator.o target_translator.o
	g++ lex.yy.o y.tab.o translator.o target_translator.o -lfl -o compiler

target_translator.o: target_translator.cxx
	g++ -c target_translator.cxx

translator.o: translator.cxx translator.h
	g++ -c translator.h
	g++ -c translator.cxx

lex.yy.o: lex.yy.c
	g++ -c lex.yy.c

y.tab.o: y.tab.c
	g++ -c y.tab.c

lex.yy.c: lexer.l y.tab.h translator.h
	flex lexer.l

y.tab.c: parser.y
	yacc -dtv parser.y 

y.tab.h: parser.y
	yacc -dtv parser.y 
	
clean:
	rm lex.yy.c y.tab.c y.tab.h lex.yy.o y.tab.o translator.o test1 test2 test3 test4 test5 y.output compiler target_translator.o libass.a 1.o help_functions.o 2.o 3.o 4.o 5.o

clean1:
	rm test1 1.o libass2_16CS30027.a ass2_16CS30027.o


#Test files
test1: 1.o libass.a
	gcc 1.o -o test1 -L. -lass
1.o: myl.h help_functions.c
	gcc -Wall -c 1.s

test2: 2.o libass.a
	gcc 2.o -o test2 -L. -lass
2.o: myl.h
	gcc -Wall -c 2.s

test3: 3.o libass.a
	gcc 3.o -o test3 -L. -lass
3.o: myl.h
	gcc -Wall -c 3.s

test4: 4.o libass.a
	gcc 4.o -o test4 -L. -lass
4.o: myl.h
	gcc -Wall -c 4.s

test5: 5.o libass.a
	gcc 5.o -o test5 -L. -lass
5.o: myl.h
	gcc -Wall -c 5.s


libass.a: help_functions.o
	ar -rcs libass.a help_functions.o

help_functions.o: help_functions.c myl.h
	gcc -Wall -c help_functions.c