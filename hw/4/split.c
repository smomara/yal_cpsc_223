#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

#include "split.h"

// Join strings in a with separator c,
// or no separator if c == '\0'.
char *
join(char **a, int c)
{
    // calculate total length
    // not including null terminator or separators,
    // as well as number of strings
    size_t totalLength = 0;
    size_t count = 0;

    for(size_t i = 0; a[i] != 0; i++) {
        totalLength += strlen(a[i]);
        count++;
    }

    // add separators (if not null) and null terminator
    if(c != '\0') {
        totalLength += count - 1;
    }
    totalLength++;

    // allocate space
    char *output = malloc(totalLength);
    assert(output); // useless on Linux, but a good habit

    // where to insert next string
    char *tail = output;

    // we use i+1 < count here because last one is special
    // we don't use i < count - 1 in case count is 0
    for(size_t i = 0; i+1 < count; i++) {
        // add string
        strcpy(tail, a[i]);
        tail += strlen(a[i]);
        if(c != '\0') {
            *tail++ = c;
        }
    }

    // copy last string if any
    if(count > 0) {
        strcpy(tail, a[count-1]);
    } else {
        // enforce null terminator
        *output = '\0';
    }

    return output;
}

// Inverse of join.
char **
split(const char *s, int c)
{
    // First figure out how many pointers we need.
    // This will be equal to the number of occurrences
    // of c, plus 2 for the last pointer and the null
    // terminator.
    size_t count = 0;
    for(const char *p = s; *p; p++) {
        if(*p == c) {
            count++;
        }
    }

    size_t n = count+1;     // number of strings in split

    // Instead of allocating separate blocks for each
    // substring, make a single copy of string and then replace
    // any c characters with nulls.
    //
    // If we were really getting carried away, we could just
    // allocate one block for both the pointers and the
    // strings, but this would require more pointer hackery.
    // It's easier to just use calloc and strdup.
    char **pointers = calloc(n+1, sizeof(char *));
    char *data = strdup(s);

    size_t top = 0;    // first unused element in pointers
    char *tail = data; // start of unprocessed part of data

    // Process data until we hit the null terminator.
    // We will escape in the middle.
    for(;;) {
        pointers[top++] = tail;

        // look for next copy of c
        char *next = strchr(tail, c);

        if(c == '\0' || next == 0) {
            // there is no next copy of c, we are done
            break;
        } else {
            // zero out *next and skip past it
            *next = '\0';
            tail = next + 1;
        }
    }

    assert(top == n);  // if this isn't true, we made a mistake

    pointers[top] = 0;

    return pointers;
}

// free data structure returned by split
void
freeSplit(char **pointers)
{
    free(pointers[0]);  // zeroth entry points to data block
    free(pointers);
}
