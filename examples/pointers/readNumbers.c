

int *readNumbers(int *count) {
    int mycount;
    int size;
    int *a;
    int n;

    mycount = 0;
    size = 1;

    a = malloc(sizeof(int) * size);
    if (a == 0) return 0;

    while (scanf("%d", &n) == 1) {
        while (mycount >= size) {
            size *= 2;
            a = realloc(a, sizeof(int) * size);
            if (a == 0) return 0;
        }

        a[mycount++] = n;
    }

    a = realloc(a, sizeof(int) * mycount);

    *count = mycount;

    return a;
}