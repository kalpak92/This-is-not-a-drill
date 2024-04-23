/**
 * The priority queue is a container adaptor that provides constant time lookup of the largest (by default) element, 
 * at the expense of logarithmic insertion and extraction.
 * 
 * A user-provided Compare can be supplied to change the ordering, 
 * e.g. using std::greater<T> would cause the smallest element to appear as the top().
 * 
 * Working with a priority_queue is similar to managing a heap in some random access container, 
 * with the benefit of not being able to accidentally invalidate the heap.
 * 
 * The operations of a priority queue are:
 *     - Push: Adds an element to the priority queue.
 *     - Pop: Removes the top element from the priority queue.
 *     - Top: Accesses the top element of the priority queue.
 *     - Empty: Checks if the priority queue is empty.
 * 
*/

// template<
//     class T,
//     class Container = std::vector<T>,
//     class Compare = std::less<typename Container::value_type>
// > class priority_queue;

#include <iostream>
#include <queue>

int main() {
    std::priority_queue<int> myPriorityQueue;
    myPriorityQueue.push(3);
    myPriorityQueue.push(1);
    myPriorityQueue.push(4);
    myPriorityQueue.push(1);
    myPriorityQueue.push(5);

    std::cout << "Top element: " << myPriorityQueue.top() << std::endl;
    myPriorityQueue.pop();
    std::cout << "Top element after pop: " << myPriorityQueue.top() << std::endl;

    return 0;
}