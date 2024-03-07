#include <stdlib.h>
#include <assert.h>

#include "hypercomplex.h"

struct h hPack(double a, double b, double u2) {
    struct h z = { a, b, u2 };
    return z;
}

void hUnpack(struct h z, double *a, double *b) {
    *a = z.a;
    *b = z.b;
}

struct h hAdd(struct h z1, struct h z2) {
    assert(z1.u2 == z2.u2);
    struct h z = { z1.a + z2.a, z1.b + z2.b, z1.u2 };
    return z;
}

struct h hSubtract(struct h z1, struct h z2) {
    assert(z1.u2 == z2.u2);
    struct h z = { z1.a - z2.a, z1.b - z2.b, z1.u2 };
    return z;
}

struct h hMultiply(struct h z1, struct h z2) {
    assert(z1.u2 == z2.u2);
    struct h z = { z1.a * z1.a + z1.b * z2.b * z1.u2, z1.b * z2.a + z1.a * z2.b, z1.u2 };
    return z;
}

struct h hConjugate(struct h z) {
    struct h zbar = { z.a, -z.b, z.u2 };
    return zbar;
}

// multiply a hypercomplex by a real number
static struct h hMultiplyScalar(struct h z, double d) {
    struct h zd = { z.a * d, z.b * d, z.u2 };
    return zd;
}

struct h hDivide(struct h z1, struct h z2) {
    assert(z1.u2 == z2.u2);

    // We do the usual trick of multiplying numerator
    // and denominator by the conjugate of the denominator
    struct h z1c = hMultiply(z1, hConjugate(z2));
    struct h z2c = hMultiply(z2, hConjugate(z2));

    // since z2c = (a + b u) (a - b u) = a*a - b*b*u2
    // has only a real component, we can just divide this out
    return hMultiplyScalar(z1c, 1.0 / z2c.a);
}