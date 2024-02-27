/**
 * Overview:
 *      std::multimap is an associative container that stores a sorted list of key-value pairs.
 *      Unlike std::map, it allows multiple entries with the same key.
 *      The sorting is based on a comparison function (usually the default is less-than).
 * Operations like search, insertion, and removal have logarithmic complexity.
 * 
 * Internal Implementation:
 *      Red-Black Tree: Internally, a multimap is implemented as a self-balancing binary search tree known as a Red-Black Tree.
 *      This design ensures that operations like insertion and deletion are executed efficiently while preserving the sorted order.
 * 
 * Iteration Order:
 *      Iterators of std::multimap iterate in non-descending order of keys.
 *      The order is defined by the comparison function used during construction.
 *      Equivalent keys (keys that compare equal) maintain the order of insertion and do not change 2.
 * 
 * Equivalence and Comparison:
 *      Everywhere the standard library uses the comparison requirements, equivalence is determined by using the equivalence relation described by the comparison.
 *      Two objects a and b are considered equivalent if neither compares less than the other: !comp(a, b) && !comp(b, a).
 * 
 * Template Parameters:
 *      The template parameters for std::multimap include:
 *          Key: The key type.
 *          T: The value type.
 *          Compare: The comparison function (default is std::less<Key>).
 *          Allocator: The allocator type for memory management 2.
 * 
 * In summary, std::multimap provides a flexible way to store key-value pairs with duplicate keys while maintaining a sorted order. 
 * Its internal Red-Black Tree structure ensures efficient operations.
*/

#include <iostream>
#include <map>
#include <string>


int main() {
    std::multimap<std::string, int> mymultimap;

    mymultimap.insert(std::pair{"Kalpak", 1});
    mymultimap.insert(std::pair{"Kalpak", 2});
    mymultimap.insert(std::pair{"Kalpak", 3});
    mymultimap.insert(std::pair{"Kalpak", 4});

    // The Order of insertion is maintained
    for (const auto& [key, value] : mymultimap) {
        std::cout << key << " => " << value << std::endl;
    }

    std::cout << "Number of elements with key Kalpak: " << mymultimap.count("Kalpak") << std::endl;

    std::multimap<std::string, int>::iterator it = mymultimap.find("Kalpak");
    if (it != mymultimap.end()) {
        mymultimap.erase(it);
    }

    std::cout << "Number of elements with key Kalpak: " << mymultimap.count("Kalpak") << std::endl;

    for (const auto& [key, value] : mymultimap) {
        std::cout << key << " => " << value << std::endl;
    }

    mymultimap.erase("Kalpak");

    if (mymultimap.empty()) {
        std::cout << "No elements in the multimap." << std::endl;
    } else {
        for (const auto& [key, value] : mymultimap) {
            std::cout << key << " => " << value << std::endl;
        }
    }


    // Lower Bound and Upper Bound
    std::multimap<std::string, int> mymultimap2;

    mymultimap2.insert(std::pair{"Kalpak", 1});
    mymultimap2.insert(std::pair{"Tomoki", 2});
    mymultimap2.insert(std::pair{"Kalpak", 2});
    mymultimap2.insert(std::pair{"Kalpak", 3});
    mymultimap2.insert(std::pair{"Kalpak", 4});
    mymultimap2.insert(std::pair{"Nick", 5});

    // Print will show that the keys are sorted as expected.
    for (const auto& [key, value] : mymultimap2) {
        std::cout << key << " => " << value << std::endl;
    }

    std::cout << "Lower Bound and Upper Bound Functionality." << std::endl;

    auto firstEntry = mymultimap2.lower_bound("Kalpak");
    auto lastEntry = mymultimap2.upper_bound("Kalpak");

    for (auto it = firstEntry; it != lastEntry; it++) {
        std::cout << it->first << " => " << it->second << std::endl;
    }

    // More efficient way to get a pair of iterators
    // start_end is a pair of iterators representing the range of elements with key "Kalpak"
    std::cout << "Equal Range Functionality." << std::endl;
    auto start_end = mymultimap2.equal_range("Kalpak");
    for (auto it = start_end.first; it != start_end.second; it++) {
        std::cout << it->first << " => " << it->second << std::endl;
    }

    return 0;
}