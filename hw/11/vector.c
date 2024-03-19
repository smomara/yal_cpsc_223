#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

#include "vector.h"

// Implementation strategy: augmented balanced BSTs.
//
// We will use randomized treaps for balancing.
// Some of this is adapted from lecture examples.

#define NUM_KIDS (2)
#define LEFT (0)
#define RIGHT (1)

#define EMPTY (0) // null pointer

// note: we don't have keys, we just have order
struct node {
    int value;
    int size;  // size of subtree
    int priority;  // for max heap
    struct node *kids[NUM_KIDS];
};

struct vector {
    struct node *root;
};

Vector *
vectorCreate(size_t n, int value)
{
    // we'll start with an empty vector and insert n slots
    Vector *v = malloc(sizeof(*v));
    assert(v);
    v->root = EMPTY;

    for(size_t i = 0; i < n; i++) {
        vectorInsert(v, 0, value);
    }

    return v;
}

static void
vectorDestroyNodes(struct node *root)
{
    if(root != EMPTY) {
        for(int i = LEFT; i <= RIGHT; i++) {
            vectorDestroyNodes(root->kids[i]);
        }

        free(root);
    }
}

void
vectorDestroy(Vector *v)
{
    vectorDestroyNodes(v->root);
    free(v);
}

static size_t
nodeSize(struct node *root)
{
    if(root == EMPTY) {
        return 0;
    } else {
        return root->size;
    }
}

size_t
vectorSize(const Vector *v)
{
    return nodeSize(v->root);
}

int *
vectorRef(Vector *v, size_t i)
{
    // use iterative version for speed
    struct node *root = v->root;
    while(root != EMPTY) {
        struct node *left = root->kids[LEFT];
        int leftSize = nodeSize(left);

        if(i < leftSize) {
            root = left;
        } else if(i == leftSize) {
            return &root->value;
        } else {
            root = root->kids[RIGHT];
            i = i - leftSize - 1;
        }
    }

    // out of range
    return 0;
}

static void
nodeFixSize(struct node *root)
{
    root->size = 1;
    for(int i = LEFT; i <= RIGHT; i++) {
        root->size += nodeSize(root->kids[i]);
    }
}

// rotate (*root)->kid[dir] in place of *root
static void
nodeRotateUp(struct node **root, int dir)
{
    struct node *x = *root;
    struct node *y = x->kids[dir];

    *root = y;
    x->kids[dir] = y->kids[!dir];
    y->kids[!dir] = x;

    // size of x and y might change
    // must fix x first since it is now child
    nodeFixSize(x);
    nodeFixSize(y);
}

// insert node after i existing nodes
static void
nodeInsert(struct node **root, size_t i, struct node *new)
{
    if(*root == EMPTY) {
        // OK to insert at 0 in empty tree
        if(i == 0) {
            *root = new;
            nodeFixSize(new);
        } else {
            free(new);
        }
    } else {
        size_t leftSize = nodeSize((*root)->kids[LEFT]);
        int side;  // which side to insert into

        if(i <= leftSize) {
            side = LEFT;
        } else {
            side = RIGHT;
            i = i - leftSize - 1;
        } 

        // insert in subtree
        // note: this might fail if i is too big
        nodeInsert(&(*root)->kids[side], i, new);

        // maybe float up new subtree root
        if((*root)->kids[side] != EMPTY) {
            if((*root)->kids[side]->priority > (*root)->priority) {
                // this also fixes size
                nodeRotateUp(root, side);
            } else {
                // fix size anyway
                nodeFixSize(*root);
            }
        }
    }
}

void
vectorInsert(Vector *v, size_t i, int value)
{
    struct node *new = malloc(sizeof(*new));
    assert(new);

    new->value = value;
    new->size = 1;
    new->priority = rand();

    for(int i = LEFT; i <= RIGHT; i++) {
        new->kids[i] = EMPTY;
    }

    nodeInsert(&v->root, i, new);
}
