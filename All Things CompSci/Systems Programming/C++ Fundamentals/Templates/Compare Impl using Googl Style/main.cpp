#include <iostream>
#include <cstdlib>
#include "compare.h"

using namespace std;

int main(int argc, char **argv) {
    cout << compare<int>(10, 20);
    cout << endl;
    return EXIT_SUCCESS;
}