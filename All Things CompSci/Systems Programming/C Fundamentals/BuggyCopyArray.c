#include <stdio.h>   // printf
#include <stdlib.h>  // EXIT_SUCCESS

int* copyArray(int src[], int size);

int main(int argc, char **argv) {
  int numbers[5] = {9, 8, 1, 9, 5};
  int numcopy[5] = copyArray(numbers, 5);  // no -- buggy
  int i;

  for (i = 0; i < 5; i++) {
    printf("numbers [%d]: %d;  numcopy[%d]: %d\n",
           i, numbers[i], i, numcopy[i]);
  }
  return EXIT_SUCCESS;
}

int* copyArray(int src[], int size) {
  int i, dst[size];                     // allowed in C99, but discouraged more recently

  for (i = 0; i < size; i++) {
    dst[i] = src[i];
  }
  return dst;                           // no -- buggy
}