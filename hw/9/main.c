#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

#include "stream.h"

static int
plus1(int x)
{
    return x+1;
}

// print the first n characters in stream to file
static void
streamPrint(size_t n, Stream  *s, FILE *f)
{
    for(size_t i = 0; i < n; i++) {
        putc(streamNext(s), f);
    }
}

#define FNV_PRIME_64 ((1ULL<<40)+(1<<8)+0xb3)
#define FNV_OFFSET_BASIS_64 (14695981039346656037ULL)

// compute FNV1a hash of first n characters in stream
static uint64_t
streamHash(size_t n, Stream *s)
{
    uint64_t h = FNV_OFFSET_BASIS_64;

    for(size_t i = 0; i < n; i++) {
        h ^= streamNext(s);
        h *= FNV_PRIME_64;
    }

    return h;
}

// max stream args to stream functions
#define MAX_ARGS (2)

// parse stream expression from stdin
//
// grammar is
//
// "<string>" -> streamFromString(<string>)
// x<stream1><stream2> -> streamInterleave(<stream1>,<stream2>)
// +<stream> -> streamMap(plus1, <stream>)
//
// returns 0 on error or EOF
static Stream *
streamParse(void)
{
    int c;
    char *string;
    Stream *s;
    Stream *args[MAX_ARGS];

    switch((c = getchar())) {

        case '"':
            // scanf %[ specifier doesn't allow empty strings
            // hence this grotesque hack
            if((c = getchar()) == '\"') {
                return streamFromString("");
            } else {
                ungetc(c, stdin);
            }

            if(scanf("%m[^\"]\"", &string) == 1) {
                s = streamFromString(string);
                free(string);
                return s;
            } else {
                return 0;
            }

        case 'x':
            if((args[0] = streamParse()) == 0) {
                return 0;
            } else if((args[1] = streamParse()) == 0) {
                streamDestroy(args[0]);
                return 0;
            } else {
                return streamInterleave(args[0], args[1]);
            }

        case '+':
            if((args[0] = streamParse()) == 0) {
                return 0;
            } else {
                return streamMap(plus1, args[0]);
            }

        default:
            fprintf(stderr, "unexpected '%c'\n", c);
            return 0;
    }
}

int
main(int argc, char **argv)
{
    Stream *s;

    if((s = streamParse()) == 0) {
        return 1;
    }
    // else print and hash based on argv
    for(int i = 1; i < argc; i++) {

        long long n = strtoll(argv[i], 0, 0);
        
        if(n > 0) {
            // positive n: print n chars
            streamPrint(n, s, stdout);
            putchar('\n');
        } else {
            // negative n: hash -n chars
            printf("%zx\n", streamHash(-n, s));
        }
    }

    streamDestroy(s);

    return 0;
}
