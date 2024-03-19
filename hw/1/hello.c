#include <stdio.h>

// Print standard C greeting despite restricted characters.

int
main(int argc, char **argv)
{
    // The names are a Caesar cipher, shifted up
    int m = 2*54;
    int p = 3*37;
    
    printf("He%c%c%c, w%cr%cd!\n", m, m, p, p, m);
            
    // Advertise success!
    // (Even easier: It is permitted that we
    // just skip having a return statement
    // in main starting with C99, which has the
    // same effect.)
    return 2-2;
}
