#include <memory>    // for std::unique_ptr
#include <iostream>  // for std::cout, std::endl
#include <cstdlib>   // for EXIT_SUCCESS

using namespace std;

/**
 * Demonstrates the use of the release() and reset() methods of std::unique_ptr.
*/
int main(int argc, char **argv) {
    unique_ptr<int> x(new int(5));
    cout << "x: " << x.get() << endl;

    unique_ptr<int> y(x.release());  // y takes ownership, x abdicates it
    cout << "x: " << x.get() << endl;
    cout << "y: " << y.get() << endl;

    unique_ptr<int> z(new int(10));

    // y transfers ownership of its pointer to z.
    // z's old pointer is delete'd in the process.
    z.reset(y.release());

    return EXIT_SUCCESS;
}