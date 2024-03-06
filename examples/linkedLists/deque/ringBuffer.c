#include <stdlib.h>
#include <assert.h>

#include "deque.h"

// Alternative implementation of a deque using a ring buffer.
//
// Conceptually, this is an array whose indices wrap around at
// the endpoints. 
//
// The region in use is specified by a base index pointing
// to the first element, and a length count giving the number
// of elements.  A size field specifies the number of slots
// in the block.
//
// Picture:
//
//  ---------------------------------------------------
//  |7|8|9| | | | | | | | | | | | | | | | |1|2|3|4|5|6|
//  ---------------------------------------------------
//       ^                                 ^
//       |                                 |
//       base + length - 1                 base

struct deque {
    size_t base;    // location of front element
    size_t length;  // length of retgion in use
    size_t size;    // total number of positions in contents
    int *contents;
};

#define INITIAL_SIZE    (8)

// create a new deque of the given size
static Deque *dequeCreateInternal(size_t size) {
    struct deque *d;

    d = malloc(sizeof(struct deque));
    assert(d);

    d->base = 0;
    d->length = 0;
    d->size = size;

    d->contents = malloc(sizeof(int) * d->size);
    assert(d->contents);

    return d;
}

// return a new empty deque
Deque *dequeCreate(void) {
    return dequeCreateInternal(INITIAL_SIZE);
}

void dequePush(Deque *d, int direction, int value) {
    if (d->length == d->size) {
        // not enough space
        struct deque *d2 = dequeCreateInternal(d->size * 2);

        // evacuate d
        while (!dequeIsEmpty(d)) {
            dequePush(d2, DEQUE_BACK, dequePop(d, DEQUE_FRONT));
        }

        int *oldContents = d->contents;
        *d = *d2;

        free(oldContents);
        free(d2);
    }

    if (direction == DEQUE_FRONT) {
        if (d->base == 0) {
            d->base = d->size - 1;
        } else {
            d->base--;
        }

        d->length++;

        d->contents[d->base] = value;
    } else {
        d->contents[(d->base + d->length++) % d->size] = value;
    }
}

// pop and return first value on directoin side of deque d
// returns DEQUE_EMPTY if deque is empty
int dequePop(Deque *d, int direction) {
    int retval;

    if (dequeIsEmpty(d)) {
        return DEQUE_EMPTY;
    }

    if (direction == DEQUE_FRONT) {
        retval = d->contents[d->base];

        d->base = (d->base+1) % d->size;
        d->length--;

        return retval;
    } else {
        return d->contents[(d->base + --d->length) % d->size];
    }
}

int dequeIsEmpty(const Deque *d) {
    return d->length == 0;
}

void dequeDestroy(Deque *d) {
    free(d->contents);
    free(d);
}