/**
 * std::list is a container that supports constant time insertion and removal of elements from anywhere in the container. 
 * Fast random access is not supported. 
 * It is usually implemented as a doubly-linked list. 
 * Compared to std::forward_list this container provides bidirectional iteration capability while being less space efficient.
 * 
 * Adding, removing and moving the elements within the list or across several lists does not invalidate the iterators or references. 
 * An iterator is invalidated only when the corresponding element is deleted.
 * 
*/

// template<
//     class T,
//     class Allocator = std::allocator<T>
// > class list;

// namespace pmr {
//     template< class T >
//     using list = std::list<T, std::pmr::polymorphic_allocator<T>>;
// }

#include <iostream>
#include <list>

void printList(const std::list<int>& myList) {
    for (const int& x : myList) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::list<int> myList;
    
    // Inserting elements - Constant time complexity
    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);
    myList.push_back(4);

    printList(myList);

    // Inserting elements at the front - Constant time complexity
    myList.push_front(0);
    printList(myList);

    // Inserting elements at the end - Constant time complexity
    myList.push_back(5);

    // Inserting elements at the beginning and end - Constant time complexity
    // begin() and end() return an iterator to the first and last element respectively
    myList.insert(begin(myList), -1);
    myList.insert(end(myList), 6);

    printList(myList);

    // Advance our iterator to a specific number of positions
    auto it = cbegin(myList);
    it = std::next(it, 3);
    myList.insert(it, 10);

    printList(myList);

    // Sort the list
    myList.sort();
    std::cout << "Sorted list: ";
    printList(myList);

    // Reverse the list
    myList.reverse();
    std::cout << "Reversed list: ";
    printList(myList);

    // Remove elements from the list based on a condition
    myList.remove_if([](int x) { return x % 2 == 0; });
    std::cout << "List after removing even numbers: ";
    printList(myList);

    // Merge two sorted lists
    // void merge( list&& other ); (since C++11)
    // No elements are copied, and the container other becomes empty after the merge. 
    // This operation is stable: 
    //      For equivalent elements in the two lists, the elements from *this always precede the elements from other, 
    //      and the order of equivalent elements of *this and other does not change.
    std::list<int> list1 = {1, 3, 5, 7, 9};
    std::list<int> list2 = {2, 4, 6, 8, 10};
    list1.merge(list2);
    std::cout << "Merged list: ";
    printList(list1);

    // Splice elements from one list to another.
    // Transfers elements from one list to another.
    // No elements are copied or moved, only the internal pointers of the list nodes are re-pointed.
    // void splice( const_iterator pos, list& other, const_iterator first, const_iterator last ); (since C++11)
    // Moves elements from the range [first, last) from other into *this.
    std::list<int> list3 = {1, 2, 3, 4, 5};
    std::list<int> list4 = {6, 7, 8, 9, 10};
    auto it3 = std::next(list3.begin(), 2); // Iterator to the 3rd element
    auto it4 = std::next(list4.begin(), 2); // Iterator to the 3rd element
    list3.splice(it3, list4, list4.begin(), it4);   // list3: 1 2 6 7 3 4 5 and list4: 8 9 10
    std::cout << "List 3 after splicing: ";
    printList(list3);
    std::cout << "List 4 after splicing: ";
    printList(list4);

    return 0;
}