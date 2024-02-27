#include <stdlib.h>

#include "split.h"

char *join(char **a, int c) {
    size_t totalLength = 0; // total length
    size_t count = 0; // number of strings
    for(size_t i = 0; a[i] != 0; i++) {
        totalLength += strlen(a[i]);
        count++;
    }

    // add separators (if not null) and null terminator
    if (c != '\0') {
        totalLength += count - 1;
    }
    totalLength++;

    // allocate space
    char *output = malloc(totalLength);
    assert(output);

    // where to input next string
    char *tail = output;

    for (size_t i = 0; i + 1 < count; i++) {
        strcpy(tail, a[i]);
        tail += strlen(a[i]);
        if (c != '\0') {
            *tail++ = c;
        }
    }

    if (count > 0) {
        strcpy(tail, a[count-1]);
    } else {
        *output = '\0';
    }

    return output;
}

char **split(const char *s, int c) {
    size_t count = 0;
    for (const char *p = s; *p; p++) {
        if (*p == c) {
            count++;
        }
    }

    size_t n = count+1;
    char **pointers = calloc(n+1, sizeof(char *));
    char *data = strdup(s);
    size_t top = 0;
    char *tail = data;

    for (;;) {
        pointers[top++] = tail;

        char *next = strchr(tail, c);

        if (c == '\0' || next == 0) {
            break;
        } else {
            *next = '\0';
            tail = next + 1;
        }
    }

    assert(top == n);

    pointers[top] = 0;

    return pointers;
}

void freeSplit(char **a) {
    free(a[0]);
    free(a);
}