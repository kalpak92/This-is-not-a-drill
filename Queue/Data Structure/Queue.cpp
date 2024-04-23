/**
 * The std::queue class is a container adaptor that gives the functionality of a queue - specifically, 
 * a FIFO (first-in, first-out) data structure.
 * The class template acts as a wrapper to the underlying container - only a specific set of functions is provided. 
 * The queue pushes the elements on the back of the underlying container and pops them from the front.
 * 
 * The operations of a queue are:
 *     - Push: Adds an element to the back of the queue.
 *     - Pop: Removes the front element from the queue.
 *     - Front: Accesses the front element of the queue.
 *     - Back: Accesses the back element of the queue.
 *     - Empty: Checks if the queue is empty.
*/

// template<
//     class T,
//     class Container = std::deque<T>
// > class queue;

#include <iostream>
#include <queue>


int main() {
    std::queue<int> myQueue;
    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);

    std::cout << "Front element: " << myQueue.front() << std::endl;
    std::cout << "Back element: " << myQueue.back() << std::endl;

    myQueue.pop();
    std::cout << "Front element after pop: " << myQueue.front() << std::endl;
    std::cout << "Size of the queue: " << myQueue.size() << std::endl;

    return 0;
}