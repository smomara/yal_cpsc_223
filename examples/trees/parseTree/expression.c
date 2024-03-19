#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>

#include "expression.h"

#define BINARY_ARGS (2)

struct expression {
    enum {
        TYPE_CONSTANT,
        TYPE_VARIABLE,
        TYPE_BINARY_OPERATION
    } tag;

    union {
        int constant;
        int variable;
        struct {
            int operator;
            Expression *arg[BINARY_ARGS];
        } op;
    } value;
};

// We won't do precedence here.
//
// Expression is one of:
//
// '(' expression operator expression ')'
// number
// variable
//
// where
//
// number is a sequence of digits
// variable is a single lowercase letter
//
// whitespace is ignored
//
// returns 0 on error or EOF

// get the next non-whitespace character
static int
getcIgnoringWhitespace(FILE *f)
{
    int c;

    while((c = getc(f)) != EOF && isspace(c));

    return c;
}

// parse an expression
// returns 0 on failure
Expression *
expressionParse(FILE *f)
{
    // we are going to be lazy and not clean up on error ☹
    Expression *e = malloc(sizeof(*e));

    int c = getcIgnoringWhitespace(f);

    if(c == '(') {
        // look for sub-expressions and operator
        // we'll delay building the Expression
        // so we don't have to free it on failure
        e->tag = TYPE_BINARY_OPERATION;
        e->value.op.arg[0] = expressionParse(f);

        if(e->value.op.arg[0] == 0) {
            return 0;
        }

        e->value.op.operator = getcIgnoringWhitespace(f);

        if(!index("+-*/%", e->value.op.operator)) {
            fprintf(stderr, "bad operator '%c'\n", e->value.op.operator);
            return 0;
        }

        e->value.op.arg[1] = expressionParse(f);

        if(e->value.op.arg[1] == 0) {
            return 0;
        }

        c = getcIgnoringWhitespace(f);
        if(c != ')') {
            fprintf(stderr, "expected ')' got '%c'\n", c);
            return 0;
        }
    } else if(isdigit(c)) {
        ungetc(c, f);  // put it back for fscanf
        e->tag = TYPE_CONSTANT;
        fscanf(f, "%d", &e->value.constant);
    } else if(islower(c)) {
        e->tag = TYPE_VARIABLE;
        e->value.variable = c;
    } else if(c == EOF) {
        // just return 0
        return 0;
    } else {
        fprintf(stderr, "bad character '%c'\n", c);
        return 0;
    }

    return e;
}

void
expressionPrint(const Expression *e, FILE *f)
{
    switch(e->tag) {
        case TYPE_CONSTANT:
            fprintf(f, "%d", e->value.constant);
            break;
        case TYPE_VARIABLE:
            putc(e->value.variable, f);
            break;
        case TYPE_BINARY_OPERATION:
            putc('(', f);
            expressionPrint(e->value.op.arg[0], f);
            putc(e->value.op.operator, f);
            expressionPrint(e->value.op.arg[1], f);
            putc(')', f);
            break;
        default:
            assert(0); // bad tag!
    }
}

int
expressionEval(const Expression *e, const int v[])
{
    switch(e->tag) {
        case TYPE_CONSTANT:
            return e->value.constant;
            break;
        case TYPE_VARIABLE:
            return v[e->value.variable];
            break;
        case TYPE_BINARY_OPERATION:

            ; 

            int value[BINARY_ARGS];

            for(int i = 0; i < BINARY_ARGS; i++) {
                value[i] = expressionEval(e->value.op.arg[i], v);
            }

            switch(e->value.op.operator) {
                case '+':
                    return value[0] + value[1];
                    break;
                case '-':
                    return value[0] - value[1];
                    break;
                case '*':
                    return value[0] * value[1];
                    break;
                case '/':
                    return value[0] / value[1];
                    break;
                case '%':
                    return value[0] % value[1];
                    break;
                default:
                    assert(0); // bad operator
            }

            break;

        default:
            assert(0); // bad tag!
    }
}

void
expressionDestroy(Expression *e)
{
    if(e->tag == TYPE_BINARY_OPERATION) {
        for(int i = 0; i < BINARY_ARGS; i++) {
            expressionDestroy(e->value.op.arg[i]);
        }
    }

    free(e);
}
