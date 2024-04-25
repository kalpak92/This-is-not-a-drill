/**
 * std::deque is an indexed sequence container that allows fast insertion and deletion at both the beginning and the end.
 * It is similar to std::vector, but with an efficient insertion and deletion of elements also at the beginning of the sequence.
 * 
 * As opposed to std::vector, the elements of a deque are not stored contiguously: 
 *      typical implementations use a sequence of individually allocated fixed-size arrays, 
 *      with additional bookkeeping, which means indexed access to deque must perform two pointer dereferences, 
 *      compared to vector's indexed access which performs only one.
 * 
 * The storage of a deque is automatically expanded and contracted as needed. 
 * Expansion of a deque is cheaper than the expansion of a std::vector because it does not involve copying of the existing elements to a new memory location. 
 * On the other hand, deques typically have large minimal memory cost; 
 *      a deque holding just one element has to allocate its full internal array 
 *      (e.g. 8 times the object size on 64-bit libstdc++; 16 times the object size or 4096 bytes, 
 *      whichever is larger, on 64-bit libc++).
 * 
 * The complexity (efficiency) of common operations on deques is as follows:
 *      Random access - constant O(1).
 *      Insertion or removal of elements at the end or beginning - constant O(1).
 *      Insertion or removal of elements - linear O(n).
 * 
 * Deques have the following operations:
 *      - push_back: Adds an element to the end.
 *      - push_front: Adds an element to the beginning.
 *      - pop_back: Removes the last element.
 *      - pop_front: Removes the first element.
 *      - front: Accesses the first element.
*       - back: Accesses the last element.
 *      - empty: Checks if the deque is empty.
 * 
*/

#include <iostream>
#include <deque>

void printDeque(const std::deque<int>& myDeque) {
    for (const int& x : myDeque) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::deque<int> myDeque{1, 2, 3, 4, 5};
    printDeque(myDeque);

    // Inserting elements
    std::cout << "Inserting elements" << std::endl;
    std::deque<int>::iterator it = myDeque.begin();
    it++;
    myDeque.insert(it, 500);
    printDeque(myDeque);

    // Push front
    std::cout << "Push front" << std::endl;
    myDeque.push_front(999);
    printDeque(myDeque);

    // Push back
    std::cout << "Push back" << std::endl;
    myDeque.push_back(1000);
    printDeque(myDeque);

    // Pop front
    std::cout << "Pop front" << std::endl;
    myDeque.pop_front();
    printDeque(myDeque);

    // Pop back
    std::cout << "Pop back" << std::endl;
    myDeque.pop_back();
    printDeque(myDeque);

    // Front and back
    std::cout << "Front element: " << myDeque.front() << std::endl;
    std::cout << "Back element: " << myDeque.back() << std::endl;
    return 0;
}