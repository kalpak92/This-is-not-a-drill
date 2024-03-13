
#include <stdio.h>   // needed for printf
#include <stdlib.h>  // EXIT_SUCCESS

// Write a program that prints out whether the computer it is running
// on is little endian or big endian.

int main(int argc, char **argv) {
    int x = 1;
    char *charptr = (char *) &x;

    if (*charptr == 1) {
        printf("little endian\n");
    } else {
        printf("big endian\n");
    }

    return EXIT_SUCCESS;
}