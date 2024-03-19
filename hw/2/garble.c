// CPSC 223 HW2 sample solution
// 
// Introduce occasional transposition errors.
//
// The rule is that we swap each pair of adjacent
// lower case letters, provided their ASCII codes
// are equivalent mod 7.

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <ctype.h>

#define MODULUS (7)

int
main(int argc, char **argv)
{
    if(argc != 1) {
        fprintf(stderr, "Usage: %s\n", argv[0]);
        return 1;
    }

    // previous input character, or EOF if there is none
    int previous = EOF;

    // current input character
    int current;

    while((current = getchar()) != EOF) {

        if(previous == EOF) {
            // don't do anything with this character yet
            previous = current;
        } else if(
                islower(previous)
                && islower(current) 
                && (previous % MODULUS == current % MODULUS)) {
            // swap
            putchar(current);
            putchar(previous);

            // reset to starting state
            previous = EOF;
        } else {
            // don't swap, just flush previous and update
            putchar(previous);
            previous = current;
        }
    }

    // make sure we output previous if we haven't already
    if(previous != EOF) {
        putchar(previous);
    }

    return 0;
}
