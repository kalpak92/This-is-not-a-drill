#include <cstdlib>   // for EXIT_SUCCESS
#include <memory>    // for std::unique_ptr

using std::unique_ptr;

/**
 * Demonstrates the no copy constructor and no assignment operator of std::unique_ptr.
*/

int main(int argc, char** argv) {
    unique_ptr<int> x(new int(5));

    // fail, no copy constructor
    // unique_ptr<int> y(x);

    // succeed, z starts with NULL pointer
    unique_ptr<int> z;

    // fail, no assignment operator
    // z = x;

    return EXIT_SUCCESS;
}