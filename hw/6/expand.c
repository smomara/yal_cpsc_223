#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

#define DELIMITER ('|')

#define GET_SIZE_INITIAL (256)
#define GET_SIZE_MULTIPLIER (2)

// Get all characters up to next DELIMITER or EOF.
// Returns 1 if found delimiter, 0 if hit EOF.
// Null-terminated malloc'd string is assigned to *contents.
// Length of string is assigned to *length.
int
getDelimited(FILE *f, char **contents, size_t *length)
{
    // usual dynamic array thing
    size_t size = GET_SIZE_INITIAL;   // size of data block
    size_t top = 0;    // number of characters read
    char *data = malloc(size);
    int eof = 1;      // got eof?

    assert(data);

    int c;

    // assume eof unless changed
    while((c = getc(f)) != EOF) {
        if(c == DELIMITER) {
            // we win
            eof = 0;
            break;
        } else {
            // make room for c and possible extra null
            if(top+1 >= size) {
                size *= GET_SIZE_MULTIPLIER;
                data = realloc(data, size);
                assert(data);
            }
            data[top++] = c;
        }
    }

    // null doesn't count toward length,
    // so we won't increment top
    data[top] = '\0';
    *contents = data;
    *length = top;
    return eof;
}

// print DELIMITER followed by string
void
putDelimited(const char *contents, size_t length)
{
    putchar(DELIMITER);
    fwrite(contents, length, sizeof(char), stdout);
}

// returns 1 if string contains a NUL character
// this otherwise allows cheating with fopen
int
containsNull(const char *contents, size_t length)
{
    for(size_t i = 0; i < length; i++) {
        if(contents[i] == '\0') {
            return 1;
        } 
    }
    // else
    return 0;
}

// Expand file given by filename.
// For each matching pair of square braces,
// if the characters between them names a file that
// can be read, replace the braces and the filename
// with the expanded contents of the file.
void
expand(FILE *f)
{
    int c;

    while((c = getc(f)) != EOF) {
        if(c == DELIMITER) {
            char *contents;
            size_t length;

            if(getDelimited(f, &contents, &length)) {
                // hit EOF, print DELIMITER and contents
                putDelimited(contents, length);
            } else {
                // got second DELIMITER
                // see if we can open file
                FILE *f2;

                if(!containsNull(contents, length) && (f2 = fopen(contents, "r")) != 0) {
                    // recurse on f2
                    expand(f2);
                    fclose(f2);
                } else {
                    // can't open
                    // treat it as text
                    putDelimited(contents, length);
                    // push closing delimiter back to try again
                    ungetc(DELIMITER, f);
                }
            }
            free(contents);
        } else {
            // pass it through
            putchar(c);
        }
    }
}

int
main(int argc, char **argv)
{

    if(argc < 2) {
        expand(stdin);
    } else {
        for(int i = 1; i < argc; i++) {
            FILE *f;

            if((f = fopen(argv[i], "r")) == 0) {
                perror(argv[i]);
                return 1;
            } else {
                expand(f);
                fclose(f);
            }
        }
    }

    return 0;
}
