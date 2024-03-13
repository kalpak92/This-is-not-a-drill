#include <stdio.h>   // printf
#include <stdlib.h>  // EXIT_SUCCESS

int main(int argc, char** argv) {
    int x = 351;
    int* p;                   // p is a pointer to a int

    p = &x;                   // p now contains the addr of x
    printf("&x is %p\n", &x);
    printf(" p is %p\n",  p);
    printf(" x is %d\n",  x);

    *p = 333;     // change value of x
    printf(" x is %d\n",  x);

    return EXIT_SUCCESS;
}