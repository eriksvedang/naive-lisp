OPT = -O -g -Wall
ARCH = -m32
CFLAGS = $(OPT) $(ARCH)
CC = clang

all:
	$(CC) $(CFLAGS) -o lisp *.c	

run:
	$(CC) $(CFLAGS) -o lisp *.c	
	./lisp

clean:
	