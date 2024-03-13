#include <cstdlib>   // for EXIT_SUCCESS
#include <iostream>  // for std::cout, std::endl
#include <memory>    // for std::unique_ptr
#include <map>       // for std::map

using std::unique_ptr;
using std::map;

// Function object to use in map construction
struct MapComp {
    bool operator()(const unique_ptr<int> &lhs,
                    const unique_ptr<int> &rhs) const {
    return *lhs < *rhs;
    }
};

/**
 * Demonstrates the use of std::unique_ptr as a key in a std::map.
 * Must specify a comparison function object to use unique_ptr as a key.
*/
int main(int argc, char **argv) {
    // Create the map
    map<unique_ptr<int>,int,MapComp> a_map;

    // Create the three unique_ptrs that will be keys
    unique_ptr<int> a(new int(5));
    unique_ptr<int> b(new int(9));
    unique_ptr<int> c(new int(7));

    // Transfer ownership of the unique_ptrs into the
    // map using std::move; after this, a, b, and c
    // will contain NULL.
    a_map[std::move(a)] = 25;
    a_map[std::move(b)] = 81;
    a_map[std::move(c)] = 49;

    // Iterate through the map, printing out the values.
    // Could alternatively be done with for (auto& p : a_map) { }
    map<unique_ptr<int>,int>::iterator it;
    for (it = a_map.begin(); it != a_map.end(); it++) {
    std::cout << "key: " << *(it->first);
    std::cout << " value: " << it->second;
    std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}