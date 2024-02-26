#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv) {
    int pos = 0;

    srandom(time(0));

    do {
        pos += random() & 0x1 ? +1 : -1;
        printf("%d\n", pos);
    } while (pos != 0);

    return 0;
}