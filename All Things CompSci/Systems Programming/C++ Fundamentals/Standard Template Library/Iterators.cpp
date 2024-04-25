/**
 * Iterators are a generalization of pointers that allow a program to iterate over the elements of a container 
 * without knowing the underlying data structure.
 * 
 * Iterators can be of various types:
 * 1. Input Iterators
 *      Input iterators are the simplest type of iterators. They can be used to read the elements of a container.
 * 2. Output Iterators
 *      Output iterators are like input iterators, but they can be used to write elements to a container.
 * 3. Forward Iterators
 *      Forward iterators are like input iterators, but they can be used to read the same element multiple times.
 * 4. Bidirectional Iterators
 *      Bidirectional iterators are like forward iterators, but they can be used to iterate in both directions.
 * 5. Random Access Iterators
 *     Random access iterators are like bidirectional iterators, but they can be used to jump to any element in the container.
 * 
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

int main() {
    std::vector<int> vec{1, 2, 3, 4, 5};

    // Raw loop
    std::cout << "Raw loop: ";
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    // Iterator form (C++ 03)
    std::cout << "Iterator form: ";
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Range-based for loop (C++ 11)
    std::cout << "Range-based for loop: ";
    for (int& i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // Distance and Advance
    // Distance : Returns the number of elements between two iterators
    // Advance : Moves the iterator by a certain number of elements
    std::vector<int>::iterator it = vec.begin();
    std::advance(it, 2);
    std::cout << "Advance the iterator and print the value : " << *it << std::endl;
    std::cout << "Distance between the begin and the iterator" << std::distance(vec.begin(), it) << std::endl;

    // Key value pair of strings and integers
    std::unordered_map<std::string, int> map = {{"a", 1}, {"b", 2}, {"c", 3}};
    std::cout << "Key value pair of strings and integers" << std::endl;
    for (auto& itr : map) {
        std::cout << itr.first << " : " << itr.second << std::endl;
    }

}