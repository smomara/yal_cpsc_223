CC=gcc
CFLAGS=-g3 -Wall

PROGRAMS=calculator

all: $(PROGRAMS)

test: all
	echo '(x+y) (x*y) ((1+(2*x))*(y+3))' | ./calculator

calculator: calculator.o expression.o
	$(CC) $(CFLAGS) -o $@ $^

calculator.o: calculator.c expression.h
expression.o: expression.c expression.h

clean:
	$(RM) *.o $(PROGRAMS)
