/**
 * Vectors are same as dynamic arrays with the ability to resize itself automatically when an element is inserted or deleted, 
 * with their storage being handled automatically by the container.
 * 
 * 1) std::vector is a sequence container that encapsulates dynamic size arrays.
 * 2) std::pmr::vector is an alias template that uses a polymorphic allocator.
 * 
 * The storage of the vector is handled automatically, being expanded as needed. 
 * Vectors usually occupy more space than static arrays, because more memory is allocated to handle future growth. 
 * This way a vector does not need to reallocate each time an element is inserted, but only when the additional memory is exhausted.
 * 
 * The complexity (efficiency) of common operations on vectors is as follows:
 *      Random access - constant 𝓞(1).
 *      Insertion or removal of elements at the end - amortized constant 𝓞(1).
 *      Insertion or removal of elements - linear in the distance to the end of the vector 𝓞(n).
*/

// template<
//     class T,
//     class Allocator = std::allocator<T>
// > class vector;
// 	
// namespace pmr {
//     template< class T >
//     using vector = std::vector<T, std::pmr::polymorphic_allocator<T>>;
// }

#include <iostream>
#include <vector>

int main() {
    // Declaring a vector
    std::vector<int> myVector;

    // Inserting elements
    myVector.push_back(1);
    myVector.push_back(2);
    myVector.push_back(3);
    myVector.push_back(4);
    myVector.push_back(5);

    // Size of the vector
    std::cout << "Size of the vector: " << myVector.size() << std::endl;

    // Capacity of the vector
    std::cout << "Capacity of the vector: " << myVector.capacity() << std::endl;

    // Accessing elements
    std::cout << "Element at index 2: " << myVector[2] << std::endl;

    // Using at() to access elements
    std::cout << "Element at index 2: " << myVector.at(2) << std::endl;

    // Iterating over the vector
    std::cout << "Elements in the vector: ";
    for (int i = 0; i < myVector.size(); i++) {
        std::cout << myVector[i] << " ";
    }
    std::cout << std::endl;

    // Range based for loop
    std::cout << "Elements in the vector using range based for loop: ";
    for (int x : myVector) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    // Using iterators on vectors
    std::cout << "Elements in the vector using iterators: ";
    std::vector<int>::iterator it;
    for (it = myVector.begin(); it != myVector.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Using reverse iterators on vectors
    std::cout << "Elements in the vector using reverse iterators: ";
    std::vector<int>::reverse_iterator rit;
    for (rit = myVector.rbegin(); rit != myVector.rend(); rit++) {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;

    // Filling the vector with a value
    std::cout << "Filling the vector with 10: ";
    myVector.assign(5, 10);
    for (int x : myVector) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    // Erasing elements
    // Erase takes an iterator and erases the element at that position.
    myVector.erase(myVector.begin() + 1);
    for (int x : myVector) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    // Inserting elements
    myVector.insert(myVector.begin() + 1, 2, 20);
    for (int x : myVector) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    // Clearing the vector
    myVector.clear();
    std::cout << "Size of the vector after clear: " << myVector.size() << std::endl;

    return 0;
}