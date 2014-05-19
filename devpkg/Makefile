PREFIX?=/usr/local/Cellar
CFLAGS=-g -Wall -I${PREFIX}/apr/1.5.1/include/apr-1 -I${PREFIX}/apr-util/1.5.3/include/apr-util-1
LDFLAGS=-L${PREFIX}/apr/1.5.1/lib -lapr-1 -pthread -laprutil-1

all: devpkg

devpkg: bstrlib.o db.o shell.o commands.o

install: all
	install -d $(DESTDIR)/$(PREFIX)/bin/
	install devpkg $(DESTDIR)/$(PREFIX)/bin/

clean:
	rm -f *.o
	rm -f devpkg
	rm -rf *.dSYM
