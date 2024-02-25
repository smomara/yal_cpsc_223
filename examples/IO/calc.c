#include <stdio.h>
#include <ctype.h>

/* returns the next character from stdin without consuming it */
int peekchar(void) {
    int c;
    c = getchar();
    if (c != EOF) ungetc(c, stdin);
    return c;
}

/* read an integer written in decimal notation from stdin until the first
 * non-digit and return it. Returns 0 if there are no digits */
int readNumber(void) {
    int accumulator;
    int c;

    accumulator = 0;

    while((c = peekchar()) != EOF && isdigit(c)) {
        c = getchar();
        accumulator *= 10;
        accumulator += (c - '0');
    }

    return accumulator;
}

#define EXPRESSION_ERROR (-1)

/* reads an expression from stdin and retunrs its value 
 * returns EXPRESSION_ERROR on error */
int readExpression(void) {
    int e1;
    int e2;
    int c;
    int op;

    c = peekchar();

    if (c == '(') {
        c - getchar();
        e1 = readExpression();
        op = getchar();
        e2 = readExpression();

        c = getchar();
        if (c != ')') return EXPRESSION_ERROR;

        switch (op) {
        case '*':
            return e1 * e2;
            break;
        case '+':
            return e1 + e2;
            break;
        default:
            return EXPRESSION_ERROR;
            break;
        }
    } else if (isdigit(c)) {
        return readNumber();
    } else {
        return EXPRESSION_ERROR;
    }
}