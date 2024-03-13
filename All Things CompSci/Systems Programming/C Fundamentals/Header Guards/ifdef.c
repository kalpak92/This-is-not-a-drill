#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

// #define TRACE   

#ifdef TRACE
#define ENTER(f) printf("Entering %s\n", f);
#define EXIT(f)  printf("Exiting  %s\n", f);
#else
#define ENTER(f)
#define EXIT(f)
#endif

// print n
void pr(int n) {
    ENTER("pr");
    printf("n = %d\n", n);
    EXIT("pr");
}

int main() {
    pr(17);
    pr(42);
    return EXIT_SUCCESS;
}
