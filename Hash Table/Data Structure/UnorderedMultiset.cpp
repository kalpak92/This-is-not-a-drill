/**
 * std::unordered_multiset is an associative container that contains set of possibly non-unique objects of type Key. 
 * Search, insertion, and removal have average constant-time complexity.
 * 
 * Internally, the elements are not sorted in any particular order, but organized into buckets. 
 * Which bucket an element is placed into depends entirely on the hash of its value. 
 * This allows fast access to individual elements, since once hash is computed, it refers to the exact bucket the element is placed into.
 * 
 * The iteration order of this container is not required to be stable 
 * (so, for example, std::equal cannot be used to compare two std::unordered_multisets), 
 * except that every group of elements whose keys compare equivalent (compare equal with key_eq() as the comparator) 
 * forms a contiguous subrange in the iteration order, also accessible with equal_range().
*/

// template<
//     class Key,
//     class Hash = std::hash<Key>,
//     class KeyEqual = std::equal_to<Key>,
//     class Allocator = std::allocator<Key>
// > class unordered_multiset;

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

void printUnorderedMultiSet(const auto& set)
{
    for (const auto& elem : set)
        std::cout << elem << ' ';
    std::cout << '\n';
}
 
int main()
{
    std::unordered_multiset<int> mySet{2, 7, 1, 8, 2, 8}; // creates a set of ints
    printUnorderedMultiSet(mySet);
 
    mySet.insert(5); // puts an element 5 in the set
    printUnorderedMultiSet(mySet);
 
    if (auto iter = mySet.find(5); iter != mySet.end())
        mySet.erase(iter); // removes an element pointed to by iter
    printUnorderedMultiSet(mySet);
 
    mySet.erase(7); // removes an element 7
    printUnorderedMultiSet(mySet);

    std::cout << "Number of buckets: " << mySet.bucket_count() << std::endl;
    std::cout << "Load Factor: " << mySet.load_factor() << std::endl;

    for (int i = 0; i < mySet.bucket_count(); i++) {
        std::cout << mySet.bucket_size(i) << std::endl;
    }

    std::unordered_multiset<int> mySet2;
    /**
     * This is a special type of iterator known as an insert iterator. 
     * In this case, it's specifically a std::insert_iterator. 
     * It's designed to insert elements into a container at a specific position. 
     * Here, it's set to insert elements at the beginning of mySet2.
    */
    std::generate_n(std::inserter(mySet2, mySet2.begin()), 10, gen);
    std::generate_n(std::inserter(mySet2, mySet2.begin()), 10, gen);
    printUnorderedMultiSet(mySet2);
}