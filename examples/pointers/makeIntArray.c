#include <stdlib.h>

int *makeIntArray(int n) {
    int *a;

    a = malloc(sizeof(int) * n);

    if (a == 0) abort();

    return a;
}