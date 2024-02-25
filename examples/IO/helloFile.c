#include <stdio.h>
#include <stdlib.h>

#define FILENAME "hello.txt"
#define MESSAGE "Hello, World!"

int main(int argc, char **argv) {
    FILE *f;

    f = fopen(FILENAME, "w");
    if (f == 0) {
        perror(FILENAME);
        exit(1);
    }

    fputs(MESSAGE, f);
    putc('\n', f);

    fclose(f);

    return 0;
}