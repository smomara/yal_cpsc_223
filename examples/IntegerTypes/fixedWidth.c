#include <stdio.h>
#include <inttypes.h>

/* largest value we can apply 3x+1 to without overflowing */
#define MAX_VALUE ((UINT64_MAX - 1) / 3)

int main(int argc, char **argv) {
    uint64_t big;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s number\n", argv[0]);
        return 1;
    }

    /* SCNu64 expands to the format string for scanning u64 */
    sscanf(argv[1], "%" SCNu64, &big);

    while (big != 1) {
        /* PRIu64 expands to the format string for printing u64 */
        printf("%" PRIu64 "\n", big);

        if (big % 2 == 0) {
            big /= 2;
        } else if (big <= MAX_VALUE) {
            big = 3*big + 1;
        } else {
            puts("overflow");
            return 1;
        }
    }

    puts("Reached 1");
    return 0;
}