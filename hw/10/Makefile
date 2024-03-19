CC=gcc
CFLAGS=-g3 -Wall

PROGRAM=inventoryManager

all: $(PROGRAM)

test: all
	echo "2\n1 2 half\n1 1 one\n2 1 two\n3 1 three\n4 1 four" | ./inventoryManager

inventoryManager: inventoryManager.o ratHeap.o
	$(CC) $(CFLAGS) -o $@ $^

inventoryManager.o: inventoryManager.c ratHeap.h
ratHeap.o: ratHeap.c ratHeap.h

clean:
	$(RM) *.o $(PROGRAM)
