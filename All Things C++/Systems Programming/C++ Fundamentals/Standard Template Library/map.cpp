#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>

#include "Tracer.h"

/**
 * STL map is a sorted associative container that contains key-value pairs with unique keys.
 * The key is used to sort the elements, and must be unique.
 * The elements are sorted by the key, and the key is used to access the elements.
 * The elements are stored as a balanced binary search tree, so the elements are always sorted.
 * The elements are sorted by using the comparison function Compare.
 * The map is similar to the set, but the map stores elements as key-value pairs, while the set only stores keys.
 * 
 * Operations:
 * - begin, end, rbegin, rend, cbegin, cend, crbegin, crend
 * - empty, size, max_size
 * - insert, erase, swap, clear
 * - find, count, lower_bound, upper_bound, equal_range
*/

using namespace std;

void PrintOut(const pair<Tracer,Tracer> &p) {
    cout << "printout [" << p.first << "," << p.second << "]" << endl;
}

int main(int argc, char **argv) {
    Tracer a, b, c, d, e, f;
    map<Tracer,Tracer> table;
    map<Tracer,Tracer>::iterator it;

    table.insert(pair<Tracer,Tracer>(a, b));
    table[c] = d;
    table[e] = f;

    cout << "table[e]:" << table[e] << endl;
    it = table.find(c);
    cout << "PrintOut(*it), where it = table.find(c)" << endl;
    PrintOut(*it);

    cout << "iterating:" << endl;
    for_each(table.begin(), table.end(), &PrintOut);

    return EXIT_SUCCESS;
}