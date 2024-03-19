// Implements a min-heap with rational keys
// expressed as numerator/denominator, 
// both of type uint32_t.
//
// Each element also has a string label.
// This label is *not* copied on insert;
// instead, the RatHeap takes control and
// eventually either frees the label itself
// or returns it for the caller to free.

struct elt {
    uint32_t numerator;
    uint32_t denominator;
    char *label;   // malloc'd data
};

typedef struct ratHeap RatHeap;

RatHeap *ratHeapCreate(void);
void ratHeapDestroy(RatHeap *);

// takes control of e.label
void ratHeapInsert(RatHeap *, struct elt e);

int rationHeapIsEmpty(const RatHeap *);

// caller should free label
struct elt ratHeapDeleteMin(RatHeap *);
