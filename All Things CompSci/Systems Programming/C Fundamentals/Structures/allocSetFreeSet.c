// Implement AllocSet( ), FreeSet( )
// - AllocSet( ) needs to use malloc twice:
//   - once to allocate a new ComplexSet
//   -  once to allocate the “points” field inside it
//
// - FreeSet( ) needs to use free twice

#include <stdio.h>   // needed for printf()
#include <assert.h>  // needed for assert()
#include <stdlib.h>  // needed for malloc()

typedef struct complex_st {
    double real;  // real component
    double imag;  // imaginary component
} Complex;

typedef struct complex_set_st {
    int      num_points_in_set;
    Complex *points;             // an array of Complex
} ComplexSet;

// here are the prototypes we need to implement
ComplexSet *AllocSet(Complex c_arr[], int size);
void FreeSet(ComplexSet *set);

int main(int argc, char **argv) {
    Complex arr[5];
    ComplexSet *x;

    x = AllocSet(arr, 5);
    assert(x->num_points_in_set == 5);
    FreeSet(x);

    return EXIT_SUCCESS;
}

ComplexSet *AllocSet(Complex c_arr[], int size) {
    ComplexSet *newset;
    Complex    *pointarray;
    int i;

    assert(size > 0);

    // malloc a new ComplexSet
    newset = (ComplexSet *) malloc(sizeof(ComplexSet));
    if (newset == NULL)
        return NULL;

    // malloc the new pointarray
    pointarray = (Complex *) malloc(size*sizeof(Complex));
    if (pointarray == NULL) {
        // sneaky case: free the malloc'ed ComplexSet if we fail!
        free(newset);
        return NULL;
    }

    // initialize the fields
    newset->points = pointarray;
    for (i = 0; i < size; i++) {
        pointarray[i] = c_arr[i];
    }
    newset->num_points_in_set = size;
    return newset;
}

void FreeSet(ComplexSet *set) {
    // do some sanity checks
    assert(set != NULL);
    assert(set->points != NULL);

    // free the point array within the structure
    free(set->points);
    // good hygiene to set it to NULL after freeing
    set->points = NULL;
    // free the ComplexSet itself
    free(set);
}