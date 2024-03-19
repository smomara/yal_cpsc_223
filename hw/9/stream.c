#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <string.h>

#include "stream.h"

#define INTERLEAVED_STREAMS (2)

// We have few enough cases that we will just
// glob everything together.
// Unused pointer fields will be set to null.
struct stream {
    // Advances the stream and returns first character
    int (*next)(Stream *);

    // malloc'd string or null
    // used for streamFromString
    char *s;

    // pointer into s
    char *sNext;

    // used for streamMap
    int (*map)(int);

    // Streams to merge and mod 2 counter.
    // For streamMap, only streams[0] is used.
    Stream  *streams[INTERLEAVED_STREAMS];
    int rotor;
};

// create a stream with default values
static Stream *
streamCreate(void)
{
    Stream  *s = malloc(sizeof(struct stream));

    s->next = 0;
    s->s = 0;
    s->sNext = 0;
    s->map = 0;
    
    for(int i = 0; i < INTERLEAVED_STREAMS; i++) {
        s->streams[i] = 0;
    } 

    s->rotor = 0;

    return s;
}

static int
nextFromString(Stream  *s)
{
    if(*s->s == '\0') {
        return '\0';
    } else {
        if(*s->sNext == '\0') {
            // rewind
            s->sNext = s->s;
        }

        return *s->sNext++;
    }
}

Stream *
streamFromString(const char *s)
{
    Stream  *str = streamCreate();

    str->next = nextFromString;
    str->s = str->sNext = strdup(s);

    return str;
}

int
nextInterleave(Stream  *s)
{
    Stream  *next = s->streams[s->rotor];
    s->rotor = !s->rotor;

    return streamNext(next);
}

Stream *
streamInterleave(Stream  *even, Stream  *odd)
{
    Stream  *s = streamCreate();

    s->next = nextInterleave;
    s->streams[0] = even;
    s->streams[1] = odd;

    return s;
}

int
nextMap(Stream *s)
{
    return s->map(streamNext(s->streams[0]));
}

Stream *
streamMap(int (*f)(int), Stream *ss)
{
    Stream *s = streamCreate();

    s->next = nextMap;
    s->map = f;
    s->streams[0] = ss;

    return s;
}

int
streamNext(Stream *s)
{
    return s->next(s);
}

void
streamDestroy(Stream  *s)
{
    // free, close, or destroy anything that isn't null
    if(s->s) {
        free(s->s);
    }

    for(int i = 0; i < INTERLEAVED_STREAMS; i++) {
        if(s->streams[i]) {
            streamDestroy(s->streams[i]);
        }
    }

    free(s);
}
