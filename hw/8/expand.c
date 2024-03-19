#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <string.h>

#include "dict.h"

// Macro processor for telegram-style commercial code
// defined inline.
//
// Assumes input is s sequence of words separated by
// whitespace.
//
// Output is expansion of words separated by whitespace.

// A definition is of the form
// DEFINE word expansion STOP
// where expansion is 0 or more words.
//
// Subsequent uses of word will be replaced by expansion.
#define START_DEFINITION "DEFINE"
#define END_DEFINITION "STOP"

#define SEPARATOR (' ')

// Paste two malloc'd strings together with SEPARATOR
// if s1 is not empty.
// Frees argument strings.
static char *
join(char *s1, char *s2)
{
    if(*s1 == 0) {
        // s1 is empty, no SEPARATOR
        free(s1);
        return s2;
    } else {
        // 1 for space, 1 for '\0'
        char *combined = malloc(strlen(s1) + strlen(s2) + 2);
        assert(combined);

        // this is not very efficient but we are promised
        // that definitions will not get very long
        strcpy(combined, s1);
        strcat(combined, " ");
        strcat(combined, s2);

        free(s1);
        free(s2);

        return combined;
    }
}

int
main(int argc, char **argv)
{

    if(argc != 1) {
        fprintf(stderr, "Usage: %s < input\n", argv[0]);
        return 1;
    }

    Dict *d = dictCreate();

    char *word;
    const char *expansion;

    while(scanf("%ms", &word) == 1) {
        if(!strcmp(word, START_DEFINITION)) {
            free(word);

            char *key;

            if(scanf("%ms", &key) != 1) {
                // something went wrong
                goto cleanup;
            }

            // else we got key, get definition
            char *definition = strdup("");

            for(;;) {
                if(scanf("%ms", &word) != 1) {
                    // something went wrong
                    free(word);
                    free(key);
                    free(definition);
                    goto cleanup;
                } else if(!strcmp(word, END_DEFINITION)) {
                    // definition is complete
                    dictSet(d, key, definition);
                    free(word);
                    free(key);
                    free(definition);
                    break;
                } else {
                    definition = join(definition, word);
                }
            }
        } else if((expansion = dictGet(d, word)) != 0) {
            // print expansion
            fputs(expansion, stdout);
            putchar(' ');
            free(word);
        } else {
            // just print the word
            fputs(word, stdout);
            putchar(' ');
            free(word);
        }
    }

cleanup:

    putchar('\n');
    dictDestroy(d);
    return 0;
}
