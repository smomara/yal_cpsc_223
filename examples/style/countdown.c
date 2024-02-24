#include <stdio.h>

#define COUNTDOWN_START (10)

int
main(int argc, char **argv)
{
    for(int i = COUNTDOWN_START; i >= 0; i--) {
        printf("%d\n", i);
    }

    return 0;
}