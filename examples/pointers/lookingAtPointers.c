#include <stdio.h>
#include <stdlib.h>

int G = 0;

int main(int argc, char **argv) {
    static int s;
    int a;
    int *p;

    p = malloc(sizeof(int));

     printf("&G   = %p\n", (void *) &G);
    printf("&s   = %p\n", (void *) &s);
    printf("&a   = %p\n", (void *) &a);
    printf("&p   = %p\n", (void *) &p);
    printf("p    = %p\n", (void *) p);
    printf("main = %p\n", (void *) main);

    free(p);

    return 0;
}