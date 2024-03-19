// Dictionary data structure for mapping strings
typedef struct dict Dict;

// create a new empty dict
Dict *dictCreate(void);

// free space used by dict
void dictDestroy(Dict *);

// set d[key] = value
void dictSet(Dict *, const char *key, const char *value);

// return d[key] or 0 if not found
// caller should *not* modify or free value
const char *dictGet(Dict *, const char *key);
