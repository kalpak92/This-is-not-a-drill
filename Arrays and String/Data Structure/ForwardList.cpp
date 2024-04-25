/**
 * Forward List is a singly linked list. 
 * It is a sequence container that allows constant time insert and erase operations anywhere within the sequence, and linear time iteration. 
 * Unlike std::list, std::forward_list only supports forward iteration.
 * 
 * Fast random access is not supported. It is implemented as a singly-linked list. 
 * Compared to std::list this container provides more space efficient storage when bidirectional iteration is not needed.
 * 
 * The operations of a forward_list are:
 *      - Push Front: Adds an element to the front of the forward_list.
 *      - Pop Front: Removes the first element of the forward_list.
 *      - Insert After: Adds an element after a specific position.
 *      - Sort: Sorts the forward_list.
 *      - Merge: Merges two forward_lists.
 *      - Unique: Removes consecutive duplicate elements.
 *      - Splice After: Transfers elements from one forward_list to another.
 */

#include <iostream>
#include <forward_list>

void printList(const std::forward_list<int>& myList) {
    for (const int& x : myList) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

void push_back(std::forward_list<int>& myList, int value) {
    auto pos = begin(myList);
    int distance = std::distance(begin(myList), end(myList));
    std::advance(pos, distance - 1);
    myList.insert_after(pos, value);
}

int main() {
    std::forward_list<int> myList{1, 2, 3, 4, 5};
    printList(myList);

    // Push Front - Constant time complexity
    myList.push_front(0);
    printList(myList);

    // Insert After - Adds an element after a specific position
    // Constant time complexity
    auto it = begin(myList);
    std::cout << "Insert after the beginning" << std::endl;
    myList.insert_after(it, 6);
    printList(myList);

    std::cout << "Insert after the second position" << std::endl;
    std::advance(it, 2);
    myList.insert_after(it, 7);
    printList(myList);

    // Push Back - Adds an element to the end of the forward_list
    // Linear time complexity
    // Needs a custom function since forward_list does not support push_back
    std::cout << "Push back" << std::endl;
    push_back(myList, 8);
    printList(myList);

    // Sorting the forward_list
    std::cout << "Sorting the forward_list" << std::endl;
    myList.sort();
    printList(myList);

    // Merge two forward_lists
    std::forward_list<int> myList2{9, 10, 11};
    std::cout << "Merging two forward_lists" << std::endl;
    myList.merge(myList2);
    printList(myList);

    // Unique - Removes consecutive duplicate elements
    std::cout << "Removing consecutive duplicate elements" << std::endl;
    std::forward_list<int> myList3{1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
    myList3.unique();
    printList(myList3);

    // Splice After - Transfers elements from one forward_list to another
    std::cout << "Splicing elements from one forward_list to another" << std::endl;
    std::forward_list<int> myList4{6, 7, 8};
    auto pos = begin(myList3);
    std::advance(pos, 2);
    myList3.splice_after(pos, myList4);
    printList(myList3);

    return 0;
}