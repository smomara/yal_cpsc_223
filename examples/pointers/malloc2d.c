#include <stdio.h>
#include <stdlib.h>

// frees a 2d array created by malloc2d
void free2d(void **a) {
    // free the rows
    free(a[0]);

    // then free the array of pointers
    free(a);
}

void **malloc2d(size_t numRows, size_t rowSize) {
    void **a;
    size_t i;

    // a is an array of void * pointers that point to the rows
    a = malloc(sizeof(void *) * numRows);
    if (a == 0) {
        // malloc failed
        return 0;
    }

    // now allocate the actual rows
    a[0] = malloc(rowSize * numRows);
    if (a[0] == 0) {
        free(a);
        return 0;
    }

    for (i = 1; i < numRows; i++) {
        a[i] = a[0] + rowSize * i;
    }

    return a;
}

int main(int argc, char **argv) {
    int rows;
    int cols;
    int **a;
    int i;
    int j;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s rows cols\n", argv[0]);
        return 1;
    }

    rows = atoi(argv[1]);
    cols = atoi(argv[2]);

    a = (int **) malloc2d(rows, cols * sizeof(int));
    if (a == 0) {
        fprintf(stderr, "malloc2d failed, exiting\n");
        return 2;
    }

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            a[i][j] = i - j;
        }
    }

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%4d", a[i][j]);
        }
        putchar('\n');
    }

    free2d((void **) a);

    return 0;
}