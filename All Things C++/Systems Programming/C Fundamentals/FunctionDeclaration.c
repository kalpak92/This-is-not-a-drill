#include <stdio.h>   // printf
#include <stdlib.h>  // EXIT_SUCCESS

// This function prototype is a declaration of sumTo.
// Parameter names are optional in prototypes, but recommended to make it
// easier to parse, as names should provide more information about their
// purpose and context.
int sumTo(int);

int main(int argc, char** argv) {
  printf("sumTo(5) is: %d\n", sumTo(5));
  return EXIT_SUCCESS;
}

// = sum of integers from 1 to max
int sumTo(int max) {
  int i, sum = 0;

  for (i = 1; i <= max; i++) {
    sum += i;
  }
  return sum;
}