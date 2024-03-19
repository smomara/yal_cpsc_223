// Vector data type.
//
// Acts like an array of ints,
// but allows insertion of new slots.

typedef struct vector Vector;

// Create a new vector with indices 0..n-1
// and all values initialized to value.
Vector *vectorCreate(size_t n, int value);

// Destroy a vector, freeing all space.
void vectorDestroy(Vector *);

// Return the number of slots in a vector
size_t vectorSize(const Vector *);

// Return a pointer to position i in a vector.
// This is equivalent to a+i for an array.
//
// The pointer is only guaranteed to be valid
// until the next insert or delete operation.
//
// Return 0 if i is out of range.
int *vectorRef(Vector *, size_t i);

// Insert a new slot at position i.
// Slots previously at positions i or
// higher will move up by 1.
//
// New slot is initialized to value.
void vectorInsert(Vector *, size_t i, int value);
