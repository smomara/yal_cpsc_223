#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct elt {
    struct elt *next;
    int value;
};

struct queue {
    struct elt *head;
    struct elt *tail;
};

typedef struct queue *Queue;

// create a new empty queue
Queue queueCreate(void) {
    Queue q = malloc(sizeof(struct queue));
    assert(q);
    q->head = q->tail = NULL;
    return q;
}

// add a new value to the back of the queue
void enq(Queue q, int value) {
    struct elt *e = malloc(sizeof(struct elt));
    assert(e);

    e->value = value;
    e->next = NULL;
    if (q->head == NULL) {
        q->head = e;
    } else {
        q->tail->next = e;
    }
    q->tail = e;
}

int queueEmpty(const Queue q) {
    return (q->head == NULL);
}

// remove and return value from front of queue
int deq(Queue q) {
    assert(!queueEmpty(q));

    struct elt *e = q->head;
    int ret = q->head->value;

    q->head = e->next;
    free(e);

    return ret;
}

// print contents of queue on a single line, head first
void queuePrint(const Queue q) {
    for(struct elt *e = q->head; e != NULL; e = e->next) {
        printf("%d ", e->value);
    }
    putchar('\n');
}

void queueDestroy(Queue q) {
    while (!queueEmpty(q)) {
        deq(q);
    }
    free(q);
}

int main(int argc, char **argv) {
    int i;
    struct queue *q;

    q = queueCreate();

    for (i = 0; i < 5; i++) {
        printf("enq %d\n", i);
        enq(q, i);
        queuePrint(q);
    }

    while (!queueEmpty(q)) {
        printf("deq gets %d\n", deq(q));
        queuePrint(q);
    }

    queueDestroy(q);

    return 0;
}