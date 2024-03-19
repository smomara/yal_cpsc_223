#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

#include "ratHeap.h"

int
main(int argc, char **argv)
{

    if(argc != 1) {
        fprintf(stderr, "Usage: %s\n", argv[0]);
        return 1;
    }

    uint32_t limit;

    // spec says %d, but also guarantees positive,
    // so this should work
    if(scanf("%u", &limit) != 1) {
        fprintf(stderr, "Bad weight limit\n");
        return 1;
    }

    RatHeap *h = ratHeapCreate();
    uint32_t total = 0;  // total denominator of everything in h

    struct elt e;

    while(scanf("%u %u %m[^\n]", &e.numerator, &e.denominator, &e.label) == 3) {
        ratHeapInsert(h, e);
        total += e.denominator;

        while(total > limit) {
            // remove worst element
            // since total > 0 this should be safe
            struct elt worst = ratHeapDeleteMin(h);
            total -= worst.denominator;

            printf("%u %u %s\n", worst.numerator, worst.denominator, worst.label);
            free(worst.label);
        }
    }

    ratHeapDestroy(h);

    return 0;
}
