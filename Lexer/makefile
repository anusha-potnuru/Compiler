output.txt: a.out ass3_16CS30027_test.c
	./a.out < ass3_16CS30027_test.c > output.txt

a.out: lex.yy.c
	gcc -Wall ass3_16CS30027.c -lfl

lex.yy.c: ass3_16CS30027.l
	flex ass3_16CS30027.l

clean:
	rm lex.yy.c output.txt a.out


	
