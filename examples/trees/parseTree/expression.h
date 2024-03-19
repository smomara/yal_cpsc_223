// Abstract data type for mathematical expressions
typedef struct expression Expression;

// Parse expression from FILE *
Expression *expressionParse(FILE *);

// Print expression to FILE *
void expressionPrint(const Expression *, FILE *);

// Evaluate expression.
// v[variable] gives value of variable with given name
// (a character)
int expressionEval(const Expression *, const int v[]);

// Free all spaces used by expression
void expressionDestroy(Expression *);
