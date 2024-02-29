#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <string.h>

#include "array.h"

struct array {
    size_t size;
    int *data;
};

#define SIZE_INITIAL (16)
#define SIZE_MULTIPLIER (2)

struct array *arrayCreate(void) {
    struct array *a = malloc(sizeof(struct array));
    assert(a);
    a->size = SIZE_INITIAL;
    a->data = calloc(a->size, sizeof(int));
    assert(a->data);
    return a;
}

static void arrayExpand(struct array *a, size_t position) {
    if (position >= a->size) {
        size_t bigger = a->size * SIZE_MULTIPLIER;

        if (position >= bigger) {
            bigger = position + 1;
        }

        a->data = realloc(a->data, sizeof(int) * bigger);

        memset(&a->data[a->size], 0, sizeof(int) * (bigger - a->size));

        a->size = bigger;
    }
}

int arrayGet(struct array *a, size_t position) {
    if (position >= a->size) { return 0; }
    return a->data[position];
}

int arraySet(struct array *a, size_t position, int value) {
    arrayExpand(a, position);
    return a->data[position] = value;
}

void arrayDestroy(struct array *a) {
    free(a->data);
    free(a);
}