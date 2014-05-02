CFLAGS=-Wall -g

%/ex%.c: ex%
	cc $(CFLAGS) $< -o $@

clean: 
	rm -f ex*
