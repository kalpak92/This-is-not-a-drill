#include <iostream>  // for std::cout, std::cin, std::cerr
#include <cstdlib>   // for EXIT_SUCCESS
#include <cassert>   // for assert()
#include <string>    // for the string object

// Write a C++ program that uses streams to:
//  - prompt  the user to type in 5 floats
//  - print them out in opposite order with 4 digits of precision

using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::string;

#define NUMFLOATS 5

int main(int argc, char **argv) {
    float input[NUMFLOATS];
    int i;

    cout << "Type in a whitespace-separated list of " << NUMFLOATS << " ";
    cout << "floats:" << endl;

    for (i = 0; i < NUMFLOATS; ++i) {
        // Try to read the next float from cin; we'll call cin's
        // good() method to make sure the input and float conversion
        // was successful.
        if (!((cin >> input[i]).good())) {
            cerr << "Failed to read float " << i << ":" << endl;

            // Did we fail because we hit the end of file?
            if (cin.eof()) {
                cerr << "  [hit EOF]" << endl;
                return EXIT_FAILURE;
            }

            // Help out the user by printing the offending input.
            string broken;
            cin.clear();
            cin >> broken;
            cerr << "  [" << broken << "]" << endl;
            return EXIT_FAILURE;
        }       
    }

    // Print out the array, but reversed.
    for (i = NUMFLOATS-1; i > 0; --i) {
        cout << input[i] << " ";
    }
    cout << input[0] << endl;

    return EXIT_SUCCESS;
}