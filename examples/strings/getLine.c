#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define NAME_LENGTH (2)

#define INITIAL_LINE_LENGTH (2)

char *getLine(void) {
    char *line;
    int size; // amount of space
    int length; // amount of chars used
    int c;

    size = INITIAL_LINE_LENGTH;
    line = malloc(size);
    assert(line);

    length = 0;

    while ((c = getchar()) != EOF && c != '\n') {
        if (length >= size-1) {
            size *= 2;
            line = realloc(line, size);
        }

        line[length++] = c;
    }

    line[length] = '\0';

    return line;
}

int main(int argc, char **argv) {
    int x = 12;
    char *line;
    int y = 17;

    puts("What is your name?");

    line = getLine();

    printf("Hi %s! Did you know that x == %d and y == %d?\n", line, x, y);

    free(line);

    return 0;
}