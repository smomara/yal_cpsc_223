CC=gcc
CFLAGS=-g3 -Wall

all: search

examples: all
	./search g 20 | dot -Tpng > graph20.png
	./search b 20 | dot -Tpng > bfs20.png
	./search d 20 | dot -Tpng > dfs20.png

test: all
	valgrind -q ./search b 14

clean:
	$(RM) *.o search *.png
