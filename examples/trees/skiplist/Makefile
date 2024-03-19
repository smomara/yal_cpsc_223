CC=gcc
CFLAGS=-g3 -Wall

all: test_skiplist

test_skiplist: test_skiplist.o skiplist.o
	$(CC) $(CFLAGS) -o $@ $^

test_skiplist.o skiplist.o: skiplist.h

test: all
	./test_skiplist 100000
	valgrind -q --leak-check=full ./test_skiplist 1000

clean:
	$(RM) test_skiplist *.o
