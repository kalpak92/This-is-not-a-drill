#include <stdio.h>
#include <stdlib.h>  // EXIT_SUCCESS

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(int argc, char **argv) {
    int a = 42, b = -7;

    swap(&a, &b);
    printf("a: %d, b: %d\n", a, b);
    return EXIT_SUCCESS;
}