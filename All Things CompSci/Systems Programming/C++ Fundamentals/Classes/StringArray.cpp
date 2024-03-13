// Write a C++ function that:
// - uses new to dynamically allocate an array of strings
//    - and uses delete[ ] to free it
// - uses new to dynamically allocate an array of pointers to strings
//    - and then iterates through the array to use new to allocate a
//      string for each array entry and to assign to each array
//       element a pointer to the associated allocated string
//    - and then uses delete to delete each allocated string
//    - and then uses delete[] to delete the string pointer array
// (whew!)

#include <iostream>
#include <cstdlib>

int main(int argc, char **argv) {
    // Allocate an array of 10 strings
    std::string *s_arr = new std::string[10];

    // Append to each string in the array.
    for (int i = 0; i < 10; i++)
        s_arr[i] += "Yo!";

    // Free it
    delete[] s_arr;

    // Allocate an array of 10 string pointers.
    std::string **sptr_arr = new std::string*[10];

    // Allocate a string for each array, assign array element to it.
    for (int i = 0; i < 10; i++)
        sptr_arr[i] = new std::string("yo!");

    // Delete each allocated string.
    for (int i = 0; i < 10; i++)
        delete sptr_arr[i];

    // Delete the array of string pointers.
    delete[] sptr_arr;

    return EXIT_SUCCESS;
}