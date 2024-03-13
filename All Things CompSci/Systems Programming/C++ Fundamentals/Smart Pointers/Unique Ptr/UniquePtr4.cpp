#include <memory>    // for std::unique_ptr
#include <iostream>  // for std::cout, std::endl
#include <cstdlib>   // for EXIT_SUCCESS

using namespace std;

/**
 * Demonstrates the use of the move constructor and move assignment operator of std::unique_ptr.
*/

int main(int argc, char **argv) {
    unique_ptr<int> x(new int(5));
    cout << "x: " << x.get() << endl;

    unique_ptr<int> y = std::move(x);  // y takes ownership, x abdicates it
    cout << "x: " << x.get() << endl;
    cout << "y: " << y.get() << endl;

    unique_ptr<int> z(new int(10));

    // z delete's its old pointer and takes ownership of y's pointer.
    // y abdicates its ownership.
    z = std::move(y);

    return EXIT_SUCCESS;
}