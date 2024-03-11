#include <iostream>
#include <vector>
#include <cstdlib>

#include "Tracer.h"

// Conditional compilation for displaying vector capacity.
// Note: capacity() is only valid for vector and string.
#define CAP
#ifdef CAP
#define CAPACITY(x) cout << #x << ".capacity() = " << x.capacity() << endl
#else
#define CAPACITY(x)
#endif

using namespace std;

int main(int argc, char **argv) {
    Tracer a, b, c;
    vector<Tracer> vec;

    // vec.reserve(4);  // Note: reserve() is only valid for vector and string
    CAPACITY(vec);
    cout << "vec.push_back " << a << endl;
    vec.push_back(a);
    CAPACITY(vec);
    cout << "vec.push_back " << b << endl;
    vec.push_back(b);
    CAPACITY(vec);
    cout << "vec.push_back " << c << endl;
    vec.push_back(c);
    CAPACITY(vec);

    cout << "vec[0]" << endl;
    cout << vec[0] << endl;

    cout << "vec[2]" << endl;
    cout << vec[2] << endl;

    return EXIT_SUCCESS;
}