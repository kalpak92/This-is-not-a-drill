// Write a function that:
//  - accepts an array of 32-bit unsigned integers, and a length
//  - reverses the elements of the array in place
//  - returns void  (nothing)

#include <stdio.h>     // needed for the declaration of NULL, printf
#include <stdint.h>    // needed for the declaration of uint32_t
#include <assert.h>    // needed for the declaration of assert()
#include <stdlib.h>    // needed for the declaration of EXIT_SUCCESS

/**
 * @brief Reverse the elements of an array in place
*/
void ReverseArray(uint32_t *arr, unsigned int len) {
    int i;
    // check the obvious corner case of no reversal needed
    if (len <= 1)
        return;

    // make sure the caller passed us a valid array
    assert(arr != NULL);

    // do the reversal.  think through the termination
    // condition carefully.  If there are an even number
    // of elements (2, 4, 6, ...), we want to loop through
    // the first half, swapping with the second half, so
    // we want (len/2) iterations.  
    // If there are an odd number of elements, we want to loop through
    // (len-1)/2.  Since we're doing integer division,
    // for odd lens, (len-1/2) == (len/2).  So, it's the
    // same termination condition for both odd and even cases!
    for (i = 0; i < (len/2); i++) {
        uint32_t tmp;

        tmp = arr[i];
        arr[i] = arr[len-i-1];
        arr[len-i-1] = tmp;
    }
}

// here's some code to test our function

void PrintArray(uint32_t *arr, int len) {
    int i;

    for (i = 0; i < len; i++) {
        if (i == 0)
            printf("%u", arr[0]);
        else
            printf(" %u", arr[i]);
    }   
    printf("\n");
}

int main(int argc, char **argv) {
    uint32_t arr[3] = {1, 2, 3};
    uint32_t arr2[4] = {1, 2, 3, 4};

    PrintArray(arr, 3);
    ReverseArray(arr, 3);
    PrintArray(arr, 3);

    PrintArray(arr2, 4);
    ReverseArray(arr2, 4);
    PrintArray(arr2, 4);

    return EXIT_SUCCESS;
}