#include <stdio.h>
#include <stdlib.h>  // EXIT_SUCCESS

int main(int argc, char **argv) {
    int *p = NULL;
    *p = 1;  // causes a segmentation fault
    return EXIT_SUCCESS;
}