#include <iostream>
#include <vector>
#include <cstdlib>

#include "Tracer.h"

using namespace std;

int main(int argc, char **argv) {
    Tracer a, b, c;
    vector<Tracer> vec;

    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(c);

    cout << "Iterating:" << endl;
    vector<Tracer>::iterator it;
    for (it = vec.begin(); it < vec.end(); it++) {
        cout << *it << endl;
    }
    cout << "Done iterating!" << endl;

    // "auto" is a C++11 feature not available on older compilers
    for (auto &p : vec) {
        cout << p << endl;
    }
    cout << "Done iterating!" << endl;

    return EXIT_SUCCESS;
}