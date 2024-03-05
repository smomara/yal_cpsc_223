#include <stddef.h>

#include "binarySearch.h"

int binarySearch(int target, const int *a, size_t length) {
    size_t i;

    for (;;) {
        i = length / 2;

        if (length == 0) {
            return 0;
        }

        if (target < a[i]) {
            length = i;
        } else if (target > a[i]) {
            a = a + i + 1;
            length = length - (i + i);
        } else {
            return 1;
        }
    }
}