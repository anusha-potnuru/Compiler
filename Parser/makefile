test: ./a.out ass4_16CS30027_test.c
	./a.out < ass4_16CS30027_test.c 2> parse.txt > output.txt

a.out: lex.yy.c ass4_16CS30027.tab.h ass4_16CS30027_main.o
	gcc lex.yy.c ass4_16CS30027.tab.c ass4_16CS30027_main.o -lfl

ass3_16CS30027.o: ass4_16CS30027_main.c
	gcc -c ass4_16CS30027_main.c

lex.yy.c: ass3_16CS30027.l ass4_16CS30027.tab.h
	flex ass3_16CS30027.l

ass4_16CS30027.tab.c: ass4_16CS30027.y 
	bison -dtv ass4_16CS30027.y 

ass4_16CS30027.tab.h: ass4_16CS30027.y 
	bison -dtv ass4_16CS30027.y 

clean:
	rm lex.yy.c ass4_16CS30027.tab.c ass4_16CS30027.tab.h ass4_16CS30027_main.o y.output a.out output.txt parse.txt

