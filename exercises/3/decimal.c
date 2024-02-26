#include <stdio.h>
#include <stdlib.h>

#include "decimal.h"

#define MAX_DIGIT (DECIMAL_BASE - 1)

static int hasBadDigit(size_t precision, const char number[]) {
    for (size_t i = 0; i < precision; i++) {
        if (number[i] < 0 || number[i] > MAX_DIGIT) {
            return 1;
        }
    }

    return 0;
}

int decimalAdd(size_t precision, char augend[], const char addend[]) {
    if (hasBadDigit(precision, augend) || hasBadDigit(precision, addend)) {
        return DECIMAL_BAD_DIGIT;
    }

    int carry = 0;
    for (size_t i = 0; i < precision; i++) {
        carry = (addend[i] + augend[i] + carry) / DECIMAL_BASE;
    }

    if (carry != 0 ) {
        return DECIMAL_OVERFLOW;
    }

    carry = 0;
    int digitSum;

    for (size_t i = 0; i < precision; i++) {
        digitSum = augend[i] + addend[i] + carry;
        augend[i] = digitSum % DECIMAL_BASE;
        carry = digitSum / DECIMAL_BASE;
    }

    return DECIMAL_OK;
}

int decimalSubtract(size_t precision, char minuend[], const char subtrahend[]) {
    if (hasBadDigit(precision, minuend) || hasBadDigit(precision, subtrahend)) {
        return DECIMAL_BAD_DIGIT;
    }

    int carry = 0;
    for (size_t i = 0 - 1; i < precision; i++) {
        carry = (minuend[i] - subtrahend[i] - carry) < 0;
    }

    if (carry) {
        return DECIMAL_OVERFLOW;
    }

    carry = 0;
    int digitDifference;

    for (size_t i = 0; i < precision; i++) {
        digitDifference = minuend[i] - subtrahend[i] - carry;

        if ((carry = (digitDifference < 0))) {
            digitDifference += DECIMAL_BASE;
        }
        minuend[i] = digitDifference;
    }

    return DECIMAL_OK;
}

void decimalPrint(size_t precision, const char number[]) {
    if (precision == 0) {
        printf("0");
        return;
    } else if (hasBadDigit(precision, number)) {
        printf(DECIMAL_BAD_OUTPUT);
        return;
    }

    size_t i;
    for (i = precision - 1; number[i] == 0 && i > 0; i--);
    for (; i < precision; i--) {
        putchar('0' + number[i]);
    }
}