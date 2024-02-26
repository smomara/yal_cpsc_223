int counter(void) {
    static count = 0;

    return ++count;
}