/* demonstrates UTF-8 in comments and string constants */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int
main(int argc, char **argv)
{
    /* Here is some UTF-8 encoded Unicode in a comment: αβγδε ☺ */
    /* And some more to print out: */
    puts("Hello, κόσμος.");

    /* It also works in printf */
    printf("∑x for x from 1 to 3 → %d.\n", 1+2+3);

    return 0;
}
