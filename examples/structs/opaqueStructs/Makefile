CC=gcc
CFLAGS=-Wall -g3

all: testCounter

test: all
	./testCounter

testCounter: testCounter.o counter.o
	$(CC) $(CFLAGS) -o $@ $^

testCounter.o: testCounter.c counter.h

counter.o: counter.c counter.h

clean:
	$(RM) testCounter *.o
