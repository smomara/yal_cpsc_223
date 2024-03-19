#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

#include "rooms.h"

size_t
freeRooms(struct room *start)
{
    // We probably don't have this but let's be safe.
    if(start == 0) {
        return 0;
    }

    // With enough cleverness it is possible to solve this
    // without using any extra data structures.
    //
    // The idea is that we will rearrange the snarl into a single
    // linked list through the north pointers, and then free all
    // the nodes in one pass.

    struct room *last = start;    // last processed node
    struct room *middle = start;  // first node that might still have a south pointer

    free(start->description);
    start->description = 0;

    // Invariants:
    //
    // Every node initially reachable from start stays reachable
    // from start.
    //
    // Every node from start through last has description == 0
    //
    // Every node from start up to but not including middle
    // has south == 0.
    while(middle) {
        if(last->north && last->north->description) {
            // Follow north pointers until we can't
            last = last->north;
            free(last->description);
            last->description = 0;
        } else if(middle->south && middle->south->description) {
            // paste middle->south in place of last->north
            last->north = middle->south;
            middle->south = 0;
            middle = middle->north;
        } else {
            // clear last->north and advance middle
            last->north = 0;
            middle = middle->north;
        }
    }

    // now free everything
    size_t count = 0;
    struct room *next;
    for(struct room *p = start; p; p = next) {
        next = p->north;
        free(p);
        count++;
    }

    return count;
}
