#include <stdio.h>
#include <stdlib.h>

void
print_binary(unsigned int n)
{
    unsigned int mask = 0;

    mask = ~mask ^ (~mask >> 1);

    for(; mask != 0; mask >>= 1) {
        putchar((n & mask) ? '1' : '0');
    }
}

int
main(int argc, char **argv)
{
    if(argc != 2) {
        fprintf(stderr, "Usage: %s n\n", argv[0]);
        return 1;
    }

    print_binary(atoi(argv[1]));
    putchar('\n');

    return 0;
}