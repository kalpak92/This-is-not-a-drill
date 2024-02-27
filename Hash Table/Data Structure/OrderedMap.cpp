#include <iostream>
#include <map>

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

    friend std::ostream& operator<<(std::ostream& os, const Edge& edge) {
        os << "v1: " << edge.v1 << ", v2: " << edge.v2;
        return os;
    }

    struct EdgeCompare {
        bool operator()(const Edge& lhs, const Edge& rhs) const {
            return lhs.v1 + lhs.v2 < rhs.v1 + rhs.v2;
        }
    };
};

int main() {
    std::map<std::string, Edge> mymap;

    mymap["edge1"] = Edge(0, 0);
    std::cout << mymap["edge1"] << std::endl;
    mymap["edge2"] = Edge(1, 1);
    // Create another edge
    mymap["edge7"] = Edge(7, 7);

    // Update
    mymap["edge1"] = Edge(2, 2);

    std::cout << mymap.at("edge1") << std::endl;
    // std::cout << mymap.at("edge3") << std::endl;  // Throws an exception

    mymap.insert(std::pair<std::string, Edge>("edge3", Edge(3, 3)));    // Insert using std::pair
    std::cout << mymap.at("edge3") << std::endl;

    // Use a structured binding to return successful
    // And retrieve an interator to where the element was inserted
    const auto[it, success] = mymap.insert(std::pair("edge4", Edge(4, 4)));
    std::cout << "Edge 4 was added. Is success == " << success << std::endl;
    std::cout << it->first << " => " << it->second << std::endl;

    // Print the map
    std::cout << "\nmymap contains:" << std::endl;
    for(std::map<std::string, Edge>::iterator itr = mymap.begin(); itr != mymap.end(); itr++) {
        std::cout << itr->first << " => " << itr->second << std::endl;
    }

    // Range-based for loop
    std::cout << "\nmymap contains:" << std::endl;
    for (const auto& keys : mymap) {
        std::cout << keys.first << " => " << keys.second << std::endl;
    }

    if (mymap.contains("edge3")) {
        mymap.erase("edge3");
    }

    std::cout << "\nmymap contains:" << std::endl;
    for(const auto& [key, value] : mymap) {
        std::cout << key << " => " << value << std::endl;
    }

    // Create a map with a custom comparator
    // Here key is the edge supplied with a custom comparator
    std::map<Edge, std::string, Edge::EdgeCompare> mymap2;
    Edge e1(8, 8);
    Edge e2(0, 8);
    mymap2[e1] = "Edge 1";
    mymap2[e2] = "Edge 2";
    // Ranged based loops (structured bindings)
    std::cout << "\nmymap2 contains:" << std::endl;
    for (const auto& [key, value] : mymap2) {
        std::cout << key << " => " << value << std::endl;
    }

    return 0;
}