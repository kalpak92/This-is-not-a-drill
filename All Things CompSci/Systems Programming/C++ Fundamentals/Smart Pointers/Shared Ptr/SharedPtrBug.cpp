#include <cstdlib>   // for EXIT_SUCCESS
#include <iostream>  // for std::cout, std::endl
#include <memory>    // for std::shared_ptr

int main(int argc, char **argv) {
    // x contains a pointer to an int and has reference count 1.
    std::shared_ptr<int> x(new int(10));
    // y contains a pointer to the same int and it now has reference
    // count 2 - works fine
    std::shared_ptr<int> y(x);

    int *p = new int;

    // xbug contains a pointer to int *p and has reference count 1.
    std::shared_ptr<int> xbug(p);

    // ybug contains a pointer to the same *p and also has a reference
    // count of 1.  x and y don't know about each other
    std::shared_ptr<int> ybyg(p);

    // on exit, x and y decrement their shared reference count and the
    // shared int they own is correctly deleted once.
    // BUT: xbug and ybug both independently delete their separate
    // reference counts and the p is deleted twice - bug!
    return EXIT_SUCCESS;
}