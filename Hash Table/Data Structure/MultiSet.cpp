/**
 * std::multiset is an associative container that contains a sorted set of objects of type Key. 
 * Unlike set, multiple keys with equivalent values are allowed. Sorting is done using the key comparison function Compare. 
 * Search, insertion, and removal operations have logarithmic complexity.
*/

// template<
//     class Key,
//     class Compare = std::less<Key>,
//     class Allocator = std::allocator<Key>
// > class multiset;

#include <iostream>
#include <set>

// print out a container
template<class Os, class K>
Os& operator<<(Os& os, const std::multiset<K>& v)
{
    os << '[' << v.size() << "] {";
    bool o{};
    for (const auto& e : v)
        os << (o ? ", " : (o = 1, " ")) << e;
    return os << " }\n";
}

struct Custom {
    int field1;
    int field2;

    // Constructor
    Custom(int f1, int f2) : field1(f1), field2(f2) {}

    // Comparison operator
    bool operator<(const Custom& other) const {
        int lhs_sum = field1 + field2;
        int rhs_sum = other.field1 + other.field2;
        return lhs_sum < rhs_sum;
    }

    // Print helper
    void print() const {
        std::cout << "(" << field1 << "," << field2 << ")" << std::endl;
    }
};

struct compare {
    constexpr bool operator()(const Custom& lhs, const Custom& rhs) const {
        int lhs_sum = lhs.field1 + lhs.field2;
        int rhs_sum = rhs.field1 + rhs.field2;
        return lhs_sum < rhs_sum;
    }
};

int main() {
    std::multiset<int> myset{1, 2, 3 ,4, 5, 5, 5, 4, 3, 2, 1};

    myset.insert(1);
    myset.insert(-6);

    for (auto elem : myset) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    std::cout << "Count of 1: " << myset.count(1) << std::endl;
    std::cout << "1? " << myset.contains(1) << std::endl;

    auto found = myset.find(4);
    if (found != myset.end()) {
        std::cout << "Found 4." << std::endl;
        myset.erase(4);
        std::cout << "4? " << myset.contains(4) << std::endl;
        std::cout << "All 4's removed." << std::endl;
    }

    // Taking range in the sets
    std::multiset<int> myset2{4, 6, 8, 10, 12, 14, 16};
    auto lower = myset2.lower_bound(8);
    auto higher = myset2.upper_bound(14);

    for (auto itr = lower; itr != higher; itr++) {
        std::cout << *itr << std::endl;
    }

    std::cout << "Merging two sets" << std::endl;
    // N * log(size() + N)), where N is source.size().
    // No elements are copied or moved, only the internal pointers of the container nodes are repointed.
    std::multiset<char>
        p{'C', 'B', 'B', 'A'}, 
        q{'D', 'E', 'F', 'G'};

    p.merge(q);
    std::cout << "p.merge(q);\n" << "p: " << p << "q: " << q;


    std::multiset<Custom, compare> customSet;

    customSet.insert(Custom(1, 2));
    customSet.insert(Custom(3, 4));
    customSet.insert(Custom(5, 6));
    customSet.insert(Custom(7, 8));
    customSet.insert(Custom(3, 4));

    std::for_each(customSet.begin(), customSet.end(), [](const Custom& c) {
        c.print();
    });
}