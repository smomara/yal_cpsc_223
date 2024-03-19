CC=gcc
CFLAGS=-g3 -Wall

PROGRAMS=expand

all: $(PROGRAMS)

test: all
	echo "DEFINE XYZZY I SEE A GRUE STOP XYZZY XYZZY HELP" | ./expand

expand: expand.o dict.o
	$(CC) $(CFLAGS) -o $@ $^

expand.o: expand.c dict.h
dict.o: dict.c dict.h

clean:
	$(RM) *.o $(PROGRAMS)
