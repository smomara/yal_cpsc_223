int factorial(int n) {
    int i;
    int product;

    if (n < 2) return n;

    product = 1;
    for (i = 2; i <= n; i++) {
        product *= i;
    }

    return product;
}