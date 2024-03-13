#include <cstdlib>
#include "ThreeDPoint.h"

int main(int argc, char **argv) {
    ThreeDPoint a, b(1.0, 2.0, 3.0), c(b), d = c, e;

    b += a;
    c += b;
    d -= c;
    e = d + (a + b + c - d);
    a = c - (b + b);
    a = a;

    cout << a << " " << b << " " << c << " " << d << " " << e << endl;
    cout << b.InnerProduct(e) << endl;

    return EXIT_SUCCESS;
}