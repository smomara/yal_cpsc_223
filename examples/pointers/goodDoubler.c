#include <stdio.h>

void doubler(int *x) {
    *x *= 2;
}

int main(int argc, char **argv) {
    int y;
    
    y = 1;

    doubler(&y);

    printf("%d\n", y);

    return 0;
}