/**
 * std::set is an associative container that contains a sorted set of unique objects of type Key. 
 * Sorting is done using the key comparison function Compare. Search, removal, and insertion operations have logarithmic complexity. 
 * Sets are usually implemented as Red–black trees
*/

// template<
//     class Key,
//     class Compare = std::less<Key>,
//     class Allocator = std::allocator<Key>
// > class set;

#include <iostream>
#include <set>

// print out a container
template<class Os, class K>
Os& operator<<(Os& os, const std::set<K>& v)
{
    os << '[' << v.size() << "] {";
    bool o{};
    for (const auto& e : v)
        os << (o ? ", " : (o = 1, " ")) << e;
    return os << " }\n";
}

int main() {
    std::set<int> myset{1, 2, 3 ,4, 5};

    myset.insert(1);
    myset.insert(-6);

    for (auto elem : myset) {
        std::cout << elem << std::endl;
    }

    std::cout << "Count of 1: " << myset.count(1) << std::endl;
    std::cout << "1? " << myset.contains(1) << std::endl;

    auto found = myset.find(4);
    if (found != myset.end()) {
        std::cout << "Found 4." << std::endl;
        myset.erase(4);
        std::cout << "4? " << myset.contains(4) << std::endl;
    }

    // Taking range in the sets
    std::set<int> myset2{4, 6, 8, 10, 12, 14, 16};
    auto lower = myset2.lower_bound(8);
    auto higher = myset2.upper_bound(14);

    for (auto itr = lower; itr != higher; itr++) {
        std::cout << *itr << std::endl;
    }

    std::cout << "Merging two sets" << std::endl;
    // N * log(size() + N)), where N is source.size().
    // No elements are copied or moved, only the internal pointers of the container nodes are repointed.
    std::set<char>
        p{'C', 'B', 'B', 'A'}, 
        q{'E', 'D', 'E', 'C'};
 
    std::cout << "p: " << p << "q: " << q;
 
    p.merge(q);
 
    std::cout << "p.merge(q);\n" << "p: " << p << "q: " << q;

    return 0;
}