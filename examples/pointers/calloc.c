#include <stdlib.h>

int *makeIntArray(int n) {
    int *a;

    a = calloc(n, sizeof(int));

    if (a == 0) abort();

    return a;
}