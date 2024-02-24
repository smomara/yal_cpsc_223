#include <stdio.h>
#include <ctype.h>

#define MODULUS (7)

int main(int argc, int **argv) {
    if (argc != 1) {
        fprintf(stderr, "Usage: %s\n", argv[0]);
        return 1;
    }

    int current;
    int previous = EOF;
    while ((current = getchar()) != EOF) {
        if (previous == EOF) {
            previous = current;
        } else if (
                islower(previous) &&
                islower(current) &&
                (previous % MODULUS == current % MODULUS)) {
            putchar(current);
            putchar(previous);
            previous = EOF;
        } else {
            putchar(previous);
            previous = current;
        }
    }

    if (previous != EOF) {
        putchar(previous);
    }

    return 0;
}