#include <cstdlib>  // for EXIT_SUCCESS
#include <memory>   // for std::unique_ptr

using std::unique_ptr;

int main(int argc, char** argv) {
    // x is a unique_ptr that holds the address of an array of 5 ints
    unique_ptr<int[]> x(new int[5]);

    x[0] = 1;
    x[2] = 2;

    return EXIT_SUCCESS;
}