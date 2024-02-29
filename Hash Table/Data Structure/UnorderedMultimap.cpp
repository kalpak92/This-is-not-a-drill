/**
 * Overview:
 *      std::unordered_multimap is an associative container that stores key-value pairs with unique keys.
 *      It provides efficient search, insertion, and removal operations with an average constant-time complexity.
 *      Unlike std::map, the elements in an unordered_multimap are not sorted in any particular order.
 * 
 * Hash Table Implementation:
 *      Internally, std::unordered_multimap uses a hash table to organize its elements.
 * 
 * Here’s how it works:
 *      Hashing: The keys are hashed into the hash table using a hashing function.
 *      Buckets: The hash table is divided into buckets based on the hash values of keys.
 *      Mapping: Each key-value pair is mapped to a specific bucket.
 *      Fast Access: This organization allows for fast access to individual elements directly by their key values.
 * 
 * Ordering:
 *      The elements within each bucket are not sorted with respect to either their key or mapped values.
 *      Keys with the same hash code appear in the same bucket, but their order is unordered.
 * 
 * Performance:
 *      std::unordered_multimap containers are generally faster than std::map containers for accessing individual elements by their key.
 * However, they may be less efficient for range iteration through a subset of elements.
 * In summary, std::unordered_multimap provides a powerful and efficient way to manage key-value associations, leveraging the underlying hash table structure. Remember that the keys are unordered, making it suitable for scenarios where sorting is not a requirement.
*/

#include <iostream>
#include <unordered_map>

/*
Definition:

template<
    class Key,
    class T,
    class Compare = std::less<Key>,
    class Allocator = std::allocator<std::pair<const Key, T>>
> class map;
*/

struct Edge {
    unsigned long v1;
    unsigned long v2;

    Edge() {
        v1 = -1;
        v2 = -1;
    }

    Edge(unsigned long v1, unsigned long v2) : v1(v1), v2(v2) {}

    // Associative containers require a equality operator to check for duplicate keys
    bool operator==(const Edge& other) const {
        return v1 == other.v1 && v2 == other.v2;
    }

    friend std::ostream& operator<<(std::ostream& os, const Edge& edge) {
        os << "v1: " << edge.v1 << ", v2: " << edge.v2;
        return os;
    }
};

struct MyHash {
    std::size_t operator()(const Edge& edge) const noexcept {
        return edge.v1 + edge.v2;
    }
};

int main() {
    // Key is a string, value is an Edge
    std::unordered_multimap<std::string, Edge> mymap;

    // Inserting in the unordered_multimap
    Edge e1(1, 1);
    mymap.insert({"string", e1});

    Edge e2(2, 2);
    Edge e3(3, 3);
    
    // Inserting using the insert operator
    mymap.insert({"edge2", e2});
    mymap.insert({"edge3", e3});

    for (std::unordered_multimap<std::string, Edge>::iterator it = mymap.begin(); it != mymap.end(); it++) {
        std::cout << it->first << " => " << it->second << std::endl;
    }

    // Using range-based for loop
    for (auto const& pair : mymap) {
        std::cout << pair.first << " => " << pair.second << std::endl;
    }

    // Using range-based for loop with structured bindings
    for (auto const& [key, value] : mymap) {
        std::cout << key << " => " << value << std::endl;
    }

    mymap.insert({"edge4", e3});
    mymap.insert({"edge4", e2});
    mymap.insert({"edge4", e1});

    for (auto const& [key, value] : mymap) {
        std::cout << key << " => " << value << std::endl;
    }

    std::cout << "Print elements within a range\n";
    auto range = mymap.equal_range("edge4");
    auto start = range.first;
    auto end = range.second;
    for (; start != end; start++) {
        std::cout << start->first << " => " << start->second << std::endl;
    }
    std::cout << "======================\n";
    // Erase some elements
    mymap.erase("edge2");

    std::unordered_multimap<std::string, Edge>::iterator it = mymap.begin();
    mymap.erase(it);

    for (auto const& [key, value] : mymap) {
        std::cout << key << " => " << value << std::endl;
    }

    Edge e4(99, 100);
    mymap.insert({"edge3", e4});
    for (auto const& [key, value] : mymap) {
        std::cout << key << " => " << value << std::endl;
    }

    if (mymap.contains("edge3")) {
        std::cout << "Map contains edge3" << std::endl;
    }

    // Statistics of unordered_multimap hashtable
    std::cout << "mymap has " << mymap.bucket_count() << " buckets." << std::endl;
    std::cout << "mymap has " << mymap.load_factor() << " load factor." << std::endl;

    std::unordered_multimap<Edge, std::string, MyHash> mymap2;
    Edge edgeTest(100, 100);
    mymap2.insert({edgeTest, "Edge 100"});

    for (auto const& [key, value] : mymap2) {
        std::cout << key << " => " << value << std::endl;
    }

    return 0;
}