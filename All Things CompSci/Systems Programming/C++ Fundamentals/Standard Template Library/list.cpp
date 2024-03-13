#include <iostream>
#include <list>
#include <algorithm>
#include <cstdlib>

#include "Tracer.h"

/**
 * A simple program that demonstrates the use of the STL list container.
 * List is a doubly linked list, and is a good choice when you need to insert or delete elements.
 * The elements are not stored in contiguous memory, so random access is not as efficient as with vector.
 * Supports:
 * - push_back and push_front (O(1))
 * - pop_back and pop_front (O(1))
 * - insert and erase (O(1))
 * - sort (O(n log n))
 * - merge (O(n))
 * - splice (O(1))
 * - remove (O(n))
 * - unique (O(n))
 * - reverse (O(n))
*/

using namespace std;

void PrintOut(const Tracer &p) {
    cout << "  printout: " << p << endl;
}

int main(int argc, char **argv) {
    Tracer a, b, c;
    list<Tracer> lst;

    lst.push_back(c);
    lst.push_back(a);
    lst.push_back(b);

    cout << "sort:" << endl;
    lst.sort();
    cout << "done sort!" << endl;
    for_each(lst.begin(), lst.end(), &PrintOut);

    return EXIT_SUCCESS;
}