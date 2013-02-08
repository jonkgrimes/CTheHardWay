CFLAGS=-Wall -g

all: ex1 ex3

ex1:
	cc 2/2.1/ex1.c -o ex1

ex3:
	cc 4/4.3/ex3.c -o ex3

clean: 
	rm -f ex*
