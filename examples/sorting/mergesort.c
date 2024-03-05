#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// merge two sorted arrays, putting result into out
void merge(int n1, const int a1[], int n2, const int a2[], int out[]) {
    int i1;
    int i2;
    int iout;

    i1 = i2 = iout = 0;
    while(i1 < n1 || i2 < n2) {
        if (i2 >= n2 || ((i1 < n1) && (a1[i1] < a2[i2]))) {
            out[iout++] = a1[i1++];
        } else {
            out[iout++] = a2[i2++];
        }
    }
}

void mergeSort(int n, const int a[], int out[]) {
    int *a1;
    int *a2;

    if (n < 2) {
        memcpy(out, a, sizeof(int) * n);
    } else {
        a1 = malloc(sizeof(int) * (n/2));
        a2 = malloc(sizeof(int) * (n - n/2));

        mergeSort(n/2, a, a1);
        mergeSort(n - n/2, a + n/2, a2);

        merge(n/2, a1, n - n/2, a2, out);

        free(a1);
        free(a2);
    }
}

#define N   (20)

int main(int argc, char **argv) {
    int a[N];
    int b[N];
    int i;

    for (i = 0; i < N; i++) {
        a[i] = N-i-1;
    }

    for (i = 0; i < N; i++) {
        printf("%d ", a[i]);
    }
    putchar('\n');

    mergeSort(N, a, b);

    for (i = 0; i < N; i++) {
        printf("%d ", b[i]);
    }
    putchar('\n');

    return 0;
}