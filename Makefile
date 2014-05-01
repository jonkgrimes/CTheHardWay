CFLAGS=-Wall -g

ex1:
	cc 1/ex1.c -o ex1

ex3:
	cc 3/ex3.c -o ex3

ex4:
	cc 4/ex4.c -o ex4

ex5:
	cc 5/ex5.c -o ex5

ex6:
	cc -Wall -g 6/ex6.c -o ex6

ex7:
	cc 7/ex7.c -o ex7

ex8:
	cc 8/ex8.c -o ex8

clean: 
	rm -f ex*
