#include <stdio.h>

struct ci {
    char c;
    int i;
};

struct ic {
    int i;
    char c;
};

int main(int argc, char **argv) {
    printf("sizeof(struct ci) == %lu\n", sizeof(struct ci));
    printf("sizeof(struct ic) == %lu\n", sizeof(struct ic));

    return 0;
}