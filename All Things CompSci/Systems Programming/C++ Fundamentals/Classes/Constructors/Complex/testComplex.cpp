#include <iostream>
#include <sstream>
#include <cstdlib>

#include "Complex.h"

int main(int argc, char **argv) {
    // Invokes the constructors for a,b.
    complex::Complex a(1,1), b(2,2);
    complex::Complex c = b;      // Invokes the copy constructor for c.
    complex::Complex d = a + b;  // Another use of copy constructor, also complex +
    std::cout << "[address of d:] " << &d << std::endl;

    a = d;   // Invokes the "=" operator on a with argument d.
    b += a;  // Invokes the "+=" operator on b with argument a.

    c = 1 + c; // invokes the symmetric "+" operator on Complex(1) and c
                // (implicit conversion from 1 using Complex(real) ctr)

    // Invokes the "<<" operator with args (cout, c), then (cout, endl).
    std::cout << c << std::endl;

    std::stringstream str("(10 + 11i)");

    // Invokes the ">>" operator with args (str, d).
    str >> d;

    // Invokes the "<<" operator with args (cout, d), then (cout, endl).
    std::cout << d << std::endl;

    return EXIT_SUCCESS;
}