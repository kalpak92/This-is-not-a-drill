#include <stdio.h>   // printf
#include <stdlib.h>  // EXIT_SUCCESS

int sumAll(int a[], int size);  // prototype

int main(int argc, char** argv) {
    int numbers[] = {9, 8, 1, 9, 5};
    int sum = sumAll(numbers, 5);
    printf("sum is: %d\n", sum);

    return EXIT_SUCCESS;
}

int sumAll(int a[], int size) {
    int i, sum = 0;

    for ( i = 0; i < size; i++ ) {
        sum += a[i];
    }

    return sum;
}