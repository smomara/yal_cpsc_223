// Majority dynamics on a graph packed into a picture

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <stddef.h>

#define COLOR0 ('.')
#define COLOR1 ('X')

#define NUM_COLORS (2)

static char Colors[NUM_COLORS] = { COLOR0, COLOR1 };

int
colorToIndex(char color)
{
    return color != COLOR0;
}

char
indexToColor(int index)
{
    return Colors[index];
}

int
isActiveColor(char color)
{
    return color == COLOR0 || color == COLOR1;
}

// we will store cell state separately from edges
struct cell {
    char color;       // a character
    ptrdiff_t count;  // COLOR1 neighbors minus COLOR0 neighbors
};

struct cellList {
    size_t rows;
    size_t columns;
    size_t n;          // rows * columns, for convenience
    struct cell c[];   // packed data
};

// edges will just be in a big array
struct edge {
    // these are indices into cellList
    size_t s;
    size_t t;
};

struct edgeList {
    size_t n;          // number of actual edges
    size_t capacity;   // number of allocated edges
    struct edge e[];
};

size_t
indexPack(const struct cellList *c, size_t row, size_t column)
{
    return row * c->columns + column;
}

struct cellList *
cellListParse(void)
{
    size_t rows;
    size_t columns;

    if(scanf("%zu %zu", &rows, &columns) != 2) {
        fprintf(stderr, "Couldn't parse row and column counts.\n");
        exit(1);
    }

    // eat the newline
    int c = getchar();
    assert(c == '\n');

    struct cellList *cells =
        malloc(sizeof(struct cellList)
                    + rows * columns * sizeof(struct cell));
    assert(cells);

    cells->rows = rows;
    cells->columns = columns;
    cells->n = rows * columns;

    size_t pos = 0;
    for(size_t i = 0; i < rows; i++) {
        for(size_t j = 0; j < columns; j++) {
            cells->c[pos++].color = getchar();
        }

        // eat the newline
        int c = getchar();
        assert(c == '\n');
    }

    return cells;
}

void
cellListDisplay(const struct cellList *cells)
{
    size_t i = 0;
    for(size_t row = 0; row < cells->rows; row++) {
        for(size_t column = 0; column < cells->columns; column++) {
            putchar(cells->c[i++].color);
        }
        putchar('\n');
    }
}

#define EDGES_INITIAL (16)
#define EDGES_MULTIPLIER (2)

struct edgeList *
edgeListParse(const struct cellList *cells)
{
    struct edgeList *edges = malloc(sizeof(struct edgeList) + sizeof(struct edge) * EDGES_INITIAL);
    assert(edges);
    edges->n = 0;
    edges->capacity = EDGES_INITIAL;

    size_t r1;
    size_t c1;
    size_t r2;
    size_t c2;

    while(scanf("%zu %zu %zu %zu", &r1, &c1, &r2, &c2) == 4) {
        if(edges->n >= edges->capacity) {
            edges->capacity *= EDGES_MULTIPLIER;
            edges = realloc(edges, 
                    sizeof(struct edgeList) 
                    + sizeof(struct edge) * edges->capacity);
            assert(edges);
        }

        edges->e[edges->n].s = indexPack(cells, r1, c1);
        edges->e[edges->n].t = indexPack(cells, r2, c2);
        edges->n++;
    }

    return edges;
}

struct state {
    struct cellList *cells;
    struct edgeList *edges;
};

int
colorToDelta(char color)
{
    switch(color) {
        case COLOR0:
            return -1;
        case COLOR1:
            return 1;
        default:
            return 0;
    }
}

void
stateUpdate(struct state *s)
{
    // get counts
    for(size_t i = 0; i < s->cells->n; i++) {
        s->cells->c[i].count = 0;
    }

    for(size_t i = 0; i < s->edges->n; i++) {
        struct edge e = s->edges->e[i];
        s->cells->c[e.s].count += colorToDelta(s->cells->c[e.t].color);
        s->cells->c[e.t].count += colorToDelta(s->cells->c[e.s].color);
    }

    // update colors
    for(size_t i = 0; i < s->cells->n; i++) {
        if(isActiveColor(s->cells->c[i].color)) {
            if(s->cells->c[i].count > 0) {
                s->cells->c[i].color = COLOR1;
            } else if(s->cells->c[i].count < 0) {
                s->cells->c[i].color = COLOR0;
            }
        }
    }
}

int
main(int argc, char **argv)
{

    if(argc != 1) {
        fprintf(stderr, "Usage: %s\n", argv[0]);
        return 1;
    }

    size_t steps;

    if(scanf("%zu", &steps) != 1) {
        fprintf(stderr, "Couldn't parse total steps\n");
        exit(1);
    }

    struct state s;
    s.cells = cellListParse();
    s.edges = edgeListParse(s.cells);

    cellListDisplay(s.cells);

    for(size_t step = 0; step < steps; step++) {
        stateUpdate(&s);
        putchar('\n');
        cellListDisplay(s.cells);
    }

    free(s.cells);
    free(s.edges);

    return 0;
}
