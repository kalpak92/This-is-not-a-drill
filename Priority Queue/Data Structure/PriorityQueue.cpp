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
#include <vector>

struct Edge {
    int v1;
    int v2;

    Edge(int _v1, int _v2) : v1(_v1), v2(_v2) {}
};

struct EdgeCompare {
    bool operator()(const Edge& e1, const Edge& e2) const {
        int e1Sum = e1.v1 + e1.v2;
        int e2Sum = e2.v1 + e2.v2;
        return e1Sum < e2Sum;
    }
};


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

    std::cout << "Priority Queue using custom comparator" << std::endl;

    std::priority_queue<Edge, std::vector<Edge>, EdgeCompare> edges;
    edges.push(Edge(1, 2));
    edges.push(Edge(2, 3));
    edges.push(Edge(3, 4));

    while (!edges.empty())
    {
        Edge topEdge = edges.top();
        std::cout << "Top element: " << topEdge.v1 << ", " << topEdge.v2 << std::endl;
        edges.pop();
    }

    // Using lambda to compare elements.
    std::cout << "Priority Queue using lambda comparator" << std::endl;
    const auto data = {1, 8, 5, 6, 3, 4, 0, 9, 7, 2};
    auto cmp = [](int left, int right) { return (left ^ 1) < (right ^ 1); };
    std::priority_queue<int, std::vector<int>, decltype(cmp)> lambda_priority_queue(cmp);
 
    for (int n : data)
        lambda_priority_queue.push(n);

    while (!lambda_priority_queue.empty()) {
        std::cout << lambda_priority_queue.top() << ' ';
        lambda_priority_queue.pop();
    }
    
    return 0;
}