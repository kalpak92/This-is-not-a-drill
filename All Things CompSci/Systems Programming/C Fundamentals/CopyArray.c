#include <stdio.h>   // printf
#include <stdlib.h>  // EXIT_SUCCESS

void copyArray(int src[], int dst[], int size);

int main(int argc, char **argv) {
    int numbers[5] = {9, 8, 1, 9, 5};
    int numcopy[5];
    int i;

    copyArray(numbers, numcopy, 5);

    for (i = 0; i < 5; i++) {
        printf("numbers [%d]: %d;  numcopy[%d]: %d\n",
            i, numbers[i], i, numcopy[i]);
    }
    
    return EXIT_SUCCESS;
}

void copyArray(int src[], int dst[], int size) {
    int i;

    for (i = 0; i < size; i++) {
        dst[i] = src[i];
    }
}