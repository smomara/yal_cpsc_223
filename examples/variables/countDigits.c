#include <stdio.h>
#include <ctype.h>

unsigned long SpuriousGlobalVariable = 127;

int main(int argc, char **argv) {
    int c;
    int count = 0;

    while ((c = getchar()) != EOF) {
        if (isdigit(c)) {
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}