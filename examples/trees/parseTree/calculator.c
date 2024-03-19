#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <limits.h>

#include "expression.h"

#define MAX (3)

int
main(int argc, char **argv)
{
    if(argc != 1) {
        fprintf(stderr, "Usage: %s\n", argv[0]);
        return 1;
    }

    Expression *expr;
    int v[UCHAR_MAX+1];

    while((expr = expressionParse(stdin)) != 0) {
        // print value of expression for all combinations of x and y
        // in [0,MAX)
        printf("x\ty\t");
        expressionPrint(expr, stdout);
        putchar('\n');

        for(v['x'] = 0; v['x'] < MAX; v['x']++) {
            for(v['y'] = 0; v['y'] < MAX; v['y']++) {
                printf("%d\t%d\t%d\n", v['x'], v['y'], expressionEval(expr, v));
            }
        }
        putchar('\n');

        expressionDestroy(expr);
    }

    return 0;
}
