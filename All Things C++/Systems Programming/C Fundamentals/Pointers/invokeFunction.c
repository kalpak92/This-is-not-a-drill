// Write a function that:
//  - accepts a function pointer and an integer as an argument
//  - invokes the pointed-to function, with the integer as its argument

#include <stdio.h>     // needed for the definition of NULL, printf
#include <assert.h>    // needed for the definition of assert()
#include <stdlib.h>    // EXIT_SUCCESS

// The C syntax for function pointers is pretty confusing.
// Read the manual (CARM); I've also found this web page
// to be pretty helpful:
//
//   http://www.newty.de/fpt/index.html
//
void InvokeFunction(void (*f)(int), int arg) {
    assert(f != NULL);
    f(arg);
}

void FirstFunction(int a) {
  printf("In FirstFunction with argument '%d'\n", a);
}

void SecondFunction(int b) {
  printf("In SecondFunction with argument '%d'\n", b);
}

void ThirdFunction(int c) {
  printf("In ThirdFunction with argument '%d'\n", c);
}

int main(int argc, char **argv) {
  void (*g)(int);

  InvokeFunction(&FirstFunction, 5);
  InvokeFunction(&SecondFunction, 6);

  g = &ThirdFunction;
  InvokeFunction(g, 7);
  return EXIT_SUCCESS;
}