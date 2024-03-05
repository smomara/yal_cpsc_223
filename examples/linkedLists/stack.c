#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct elt {
    struct elt *next;
    int value;
};

struct stack {
    struct elt *head;
};

typedef struct stack *Stack;

Stack stackCreate(void) {
    Stack s = malloc(sizeof(struct stack));
    assert(s);
    s->head = NULL;
    return s;
}

// push a new value onto top of stack
void stackPush(Stack s, int value) {
    struct elt *e = malloc(sizeof(struct elt));
    assert(e);

    e->value = value;
    e->next = s->head;
    s->head = e;
}

// check if stack is empty
int stackEmpty(const Stack s) {
    return (s->head == NULL);
}

// pop off stack
int stackPop(Stack s) {
    assert(!stackEmpty(s));

    struct elt *e = s->head;
    int ret = e->value;

    s->head = e->next;
    free(e);

    return ret;
}

// print contents of stack on a single line
void stackPrint(const Stack s) {
    for (struct elt *e = s->head; e != NULL; e = e->next) {
        printf("%d ", e->value);
    }
    putchar('\n');
}

int main(int argc, char **argv) {
    Stack s = stackCreate();

    for (int i = 0; i < 5; i++) {
        printf("push %d\n", i);
        stackPush(s, i);
        stackPrint(s);
    }

    while (!stackEmpty(s)) {
        printf("pop gets %d\n", stackPop(s));
        stackPrint(s);
    }

    free(s);

    return 0;
}