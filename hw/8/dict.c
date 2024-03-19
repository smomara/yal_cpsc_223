#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <string.h>

#include "dict.h"

// hash table entry
struct elt {
    char *key;   // if null, this slot is empty
    char *value;
};

struct dict {
    size_t size;    // number of slots in data
    size_t n;       // number of nonempty slots
    struct elt *data;  // hash table
};

#define SIZE_INITIAL (16)  // initial size of hash table
#define LOAD_FACTOR (2)    // 1/(max load factor)
#define SIZE_MULTIPLIER (2)

// make a new dict object with all values == 0
static Dict *
dictCreateInternal(size_t size)
{
    Dict *d = malloc(sizeof(*d));
    assert(d);

    d->size = size;
    d->n = 0;
    d->data = calloc(d->size, sizeof(*(d->data)));
    assert(d->data);

    // calloc probably does this but let's be safe
    for(size_t i = 0; i < d->size; i++) {
        d->data[i].key = 0;
    }

    return d;
}

Dict *
dictCreate(void)
{
    return dictCreateInternal(SIZE_INITIAL);
}

// free space used by dict object
void
dictDestroy(Dict *d)
{
    for(size_t i = 0; i < d->size; i++) {
        if(d->data[i].key != 0) {
            free(d->data[i].key);
            free(d->data[i].value);
        }
    }
    free(d->data);
    free(d);
}

// Fowler-Noll-Vo hash function from 223 notes
// modified to work on strings
#define FNV_PRIME_64 ((1ULL<<40)+(1<<8)+0xb3)
#define FNV_OFFSET_BASIS_64 (14695981039346656037ULL)

static uint64_t
FNV1a(const char *s)
{
    uint64_t h = FNV_OFFSET_BASIS_64;

    while(*s) {
        h ^= *s++;
        h *= FNV_PRIME_64;
    }

    return h;
}

// find position where key should be in table
static struct elt *
dictFind(Dict *d, const char *key)
{
    size_t h;

    for(h = FNV1a(key) % d->size;   
            d->data[h].key != 0
            && strcmp(d->data[h].key, key) != 0;
            h = (h+1) % d->size);

    return &d->data[h];
}

const char *
dictGet(Dict *d, const char *key)
{
    struct elt *e = dictFind(d, key);

    if(e->key == 0) {
        // empty slot
        return 0;
    } else {
        // filled slot, equal to key
        return e->value;
    }
}

void
dictSet(Dict *d, const char *key, const char *value)
{
    struct elt *e = dictFind(d, key);

    if(e->key == 0) {
        // empty slot
        e->key = strdup(key);
        e->value = strdup(value);
        d->n++;  // increase dict of used slots

        if(d->n * LOAD_FACTOR >= d->size) {
            // too small, make it bigger
            Dict *d2 = dictCreateInternal(d->size * SIZE_MULTIPLIER);

            // copy everything across
            for(size_t i = 0; i < d->size; i++) {
                if(d->data[i].key != 0 && d->data[i].value != 0) {
                    dictSet(d2, d->data[i].key, d->data[i].value);
                }
            }

            // swap brains of d and d2
            Dict tmp = *d;
            *d = *d2;
            *d2 = tmp;

            dictDestroy(d2);
        }
    } else {
        // filled slot, equal to key
        // replace old value
        free(e->value);
        e->value = strdup(value);
    }

}
