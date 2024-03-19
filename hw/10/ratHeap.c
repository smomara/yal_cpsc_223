#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

#include "ratHeap.h"

struct ratHeap {
    size_t n;               // number of elts in use
    size_t size;            // number of slots in data
    struct elt *data;       // malloc'd data block
};

#define INITIAL_SIZE (16)
#define SIZE_MULTIPLIER (2)

RatHeap *
ratHeapCreate(void)
{
    RatHeap *h = malloc(sizeof(*h));
    assert(h);

    h->n = 0;
    h->size = INITIAL_SIZE;
    h->data = calloc(h->size, sizeof(struct elt));
    assert(h->data);

    return h;
}

void
ratHeapDestroy(RatHeap *h)
{
    for(size_t i = 0; i < h->n; i++) {
        free(h->data[i].label);
    } 

    free(h->data);
    free(h);
}

static size_t
parent(size_t i)
{
    return (i-1)/2;
}

static size_t
child(size_t i, int kid)
{
    return 2*i + 1 + kid;
}

static void
swap(struct elt *x, struct elt *y)
{
    struct elt tmp = *x;
    *x = *y;
    *y = tmp;
}

// returns 1 if x > y when comparing numerator/denominator
static int
isSmaller(struct elt x, struct elt y)
{
    // Compute common numerators.
    // Using uint64_t avoids overflow
    uint64_t xx = ((uint64_t) x.numerator) * ((uint64_t) y.denominator);
    uint64_t yy = ((uint64_t) y.numerator) * ((uint64_t) x.denominator);

    return xx < yy;
}

// float i down until heap property restored
static void
floatDown(RatHeap *h, size_t i)
{
    while(child(i, 0) < h->n) {
        // check s[i] against its children
        size_t smaller = child(i, 0);

        // check for right child being even smaller
        if(child(i, 1) < h->n && isSmaller(h->data[child(i, 1)], h->data[child(i, 0)])) {
            smaller = child(i, 1);
        }

        // am I smaller than my smaller child?
        if(isSmaller(h->data[smaller], h->data[i])) {
            // swap
            swap(&h->data[i], &h->data[smaller]);
            i = smaller;
        } else {
            // done
            return;
        }
    }
}

// float i up until heap property restored
static void
floatUp(RatHeap *h, size_t i)
{
    while(i > 0 && isSmaller(h->data[i], h->data[parent(i)])) {
        swap(&h->data[i], &h->data[parent(i)]);
        i = parent(i);
    }
}

void
ratHeapInsert(RatHeap *h, struct elt e)
{
    // avoid any hint of dividing by 0
    assert(e.denominator != 0);

    if(h->n >= h->size) {
        h->size *= SIZE_MULTIPLIER;
        h->data = realloc(h->data, h->size * sizeof(struct elt));
    }

    // insert at end and float p
    h->data[h->n] = e;
    floatUp(h, h->n);
    h->n++;
}

int
ratHeapIsEmpty(const RatHeap *h)
{
    return h->n == 0;
}

struct elt
ratHeapDeleteMin(RatHeap *h)
{
    assert(!ratHeapIsEmpty(h));

    struct elt ret = h->data[0];

    h->data[0] = h->data[--(h->n)];

    floatDown(h, 0);

    return ret;
}
