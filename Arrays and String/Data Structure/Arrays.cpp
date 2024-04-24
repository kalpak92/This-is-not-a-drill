/**
 * std::array is a container that encapsulates fixed size arrays.
 * The struct combines the performance and accessibility of a C-style array with the benefits of a standard container, 
 * such as knowing its own size, supporting assignment, random access iterators, etc.
 * 
 *      - The size of the array is a part of its type, which is known at compile time.
 *      - The array is a fixed-size sequence container: it cannot grow or shrink.
 *      - The elements are stored contiguously, which means that elements can be accessed not only through iterators,
 *          but also using offsets to regular pointers to elements.
 *      - The elements are stored in the array in the same order as they are initialized.
 * 
*/

// template<
//     class T,
//     std::size_t N
// > struct array;

#include <iostream>
#include <array>

void PrintArray(std::array<int, 4> param) {
    std::cout<< "Size of param: " << param.size() << std::endl;
}

int main() {
    std::array<int, 4> arr = {1, 2, 3, 4};
    std::cout << "Size of the array: " << arr.size() << std::endl;
    PrintArray(arr);

    // Accessing elements
    std::cout << "Element at index 2: " << arr[2] << std::endl;

    // Using at() to access elements
    std::cout << "Element at index 2: " << arr.at(2) << std::endl;
    
    // Iterating over the array
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Range based for loop
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    // Using iterators on arrays
    std::array<int, 4>::iterator it;
    for (it = arr.begin(); it != arr.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Using reverse iterators on arrays
    std::array<int, 4>::reverse_iterator rit;
    for (rit = arr.rbegin(); rit != arr.rend(); rit++) {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;

    // Filling the array with a value
    arr.fill(5);
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Swapping two arrays
    std::array<int, 4> arr2 = {5, 6, 7, 8};
    arr.swap(arr2);
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Sorting the array
    std::array<int, 4> arr3 = {4, 3, 2, 1};
    //print the array before sorting
    for (int i = 0; i < arr3.size(); i++) {
        std::cout << arr3[i] << " ";
    }
    std::cout << std::endl;
    std::sort(arr3.begin(), arr3.end());
    //print the array after sorting
    for (int i = 0; i < arr3.size(); i++) {
        std::cout << arr3[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}