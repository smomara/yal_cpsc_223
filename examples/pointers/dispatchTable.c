#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>

int putcharTwice(int c) {
    if (putchar(c) == EOF || putchar(c) == EOF) {
        return EOF;
    } else {
        return c;
    }
}

#define NUM_CHARS (UCHAR_MAX + 1)

int main(int argc, char **argv) {
    int (*table[UCHAR_MAX+1])(int);
    int i;
    int c;

    for (i = 0; i < UCHAR_MAX; i++) {
        table[i] = putchar;
    }

    table['a'] = putcharTwice;
    table['e'] = putcharTwice;
    table['i'] = putcharTwice;
    table['o'] = putcharTwice;
    table['u'] = putcharTwice;

    while((c = getchar()) != EOF) {
        table[c](c);
    }

    return 0;
}