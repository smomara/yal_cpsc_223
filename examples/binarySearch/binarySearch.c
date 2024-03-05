#include <stddef.h>

#include "binarySearch.h"

int binarySearch(int target, const int *a, size_t length) {
    size_t i = length / 2;

    if (length == 0) { // base case -- nothing left
        return 0;
    }

    if (target < a[i]) {
        return binarySearch(target, a, i);
    } else if (target > a[i]) {
        return binarySearch(target, a+i+1, length-(i+1));
    } else {
        return 1;
    }
}