/**
 * std::unordered_set is an associative container that contains a set of unique objects of type Key. 
 * Search, insertion, and removal have average constant-time complexity.
 * 
 * Internally, the elements are not sorted in any particular order, but organized into buckets. 
 * Which bucket an element is placed into depends entirely on the hash of its value. 
 * This allows fast access to individual elements, since once a hash is computed, it refers to the exact bucket the element is placed into.
 * 
 * Container elements may not be modified (even by non const iterators) since modification could change an element's hash and corrupt the container.
*/

// template<
//     class Key,
//     class Hash = std::hash<Key>,
//     class KeyEqual = std::equal_to<Key>,
//     class Allocator = std::allocator<Key>
// > class unordered_set;

#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <iterator>

/**
 * This is the generator function that std::generate_n will call to generate the values to be inserted into mySet2. 
 * It must be a function or function object that takes no arguments and returns a value that can be assigned to an element of mySet2.
*/
int gen() {
    static int i = 0;
    return ++i;
}

void printUnorderedSet(const auto& set)
{
    for (const auto& elem : set)
        std::cout << elem << ' ';
    std::cout << '\n';
}
 
int main()
{
    std::unordered_set<int> mySet{2, 7, 1, 8, 2, 8}; // creates a set of ints
    printUnorderedSet(mySet);
 
    mySet.insert(5); // puts an element 5 in the set
    printUnorderedSet(mySet);
 
    if (auto iter = mySet.find(5); iter != mySet.end())
        mySet.erase(iter); // removes an element pointed to by iter
    printUnorderedSet(mySet);
 
    mySet.erase(7); // removes an element 7
    printUnorderedSet(mySet);

    std::cout << "Number of buckets: " << mySet.bucket_count() << std::endl;
    std::cout << "Load Factor: " << mySet.load_factor() << std::endl;

    for (int i = 0; i < mySet.bucket_count(); i++) {
        std::cout << mySet.bucket_size(i) << std::endl;
    }

    std::unordered_set<int> mySet2;
    /**
     * This is a special type of iterator known as an insert iterator. 
     * In this case, it's specifically a std::insert_iterator. 
     * It's designed to insert elements into a container at a specific position. 
     * Here, it's set to insert elements at the beginning of mySet2.
    */
    std::generate_n(std::inserter(mySet2, mySet2.begin()), 10, gen);
    printUnorderedSet(mySet2);
}