#include <stdio.h>
#include <stdlib.h>  // EXIT_SUCCESS

int main(int argc, char **argv) {
    int arr[3] = {2, 3, 4};
    int* p = &arr[1];
    int** dp = &p; // double pointer

    *(*dp) += 1;
    p += 1;
    *(*dp) += 1;

    printf("arr[0]: %d\n", arr[0]);
    printf("arr[1]: %d\n", arr[1]);
    printf("arr[2]: %d\n", arr[2]);
    return EXIT_SUCCESS;
}