#include <stdio.h>   // needed for printf
#include <stdlib.h>  // needed for malloc, free, EXIT_SUCCESS
#include <assert.h>  // needed for assert

// Write a function that:
//
//  - accepts an (array of ints) and an (array length) as arguments
//
//  - malloc’s an (array of (int *)) of the same length
//
//  - initializes each element of the newly allocated array to point to
//    the corresponding element in the passed-in array
//
//  - returns a pointer to the newly allocated array

int **MakePointerArray(int *intarray, int arraylen) {
    int **parray;
    int   i;

    // do some sanity checking on the arguments
    assert(intarray != NULL);
    assert(arraylen > 0);

    // malloc the array, make sure we had the memory for it
    parray = (int **) malloc(arraylen*sizeof(int *));
    assert(parray != NULL);

    // initialize the array
    for (i = 0; i < arraylen; i++) {
    parray[i] = &(intarray[i]);
    }

    // return the array
    return parray;
}

int main(int argc, char **argv) {
    int **parray = NULL;
    int   intarray[2] = {1, 2};

    parray = MakePointerArray(intarray, 2);
    assert(parray != NULL);
    assert(parray[0] == &(intarray[0]));
    assert(parray[1] == &(intarray[1]));
    
    free(parray);

    return EXIT_SUCCESS;
}