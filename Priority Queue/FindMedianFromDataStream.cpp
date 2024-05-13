/**
 * The median is the middle value in an ordered integer list. 
 * If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.
 * 
 * For example, for arr = [2,3,4], the median is 3.
 * For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
 * 
 * Implement the MedianFinder class:
 *      MedianFinder() initializes the MedianFinder object.
 *      void addNum(int num) adds the integer num from the data stream to the data structure.
 *      double findMedian() returns the median of all elements so far. 
 *              Answers within 10^(-5) of the actual answer will be accepted.
 * 
 * Example 1:
 * Input
 * ["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
 * [[], [1], [2], [], [3], []]
 * Output
 * [null, null, null, 1.5, null, 2.0]
 * 
 * Explanation
 * MedianFinder medianFinder = new MedianFinder();
 * medianFinder.addNum(1);    // arr = [1]
 * medianFinder.addNum(2);    // arr = [1, 2]
 * medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
 * medianFinder.addNum(3);    // arr[1, 2, 3]
 * medianFinder.findMedian(); // return 2.0
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class MedianFinder {
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // Add the number to the maxHeap
        lowerHalf.push(num);

        // Rebalance since lowerHalf received a new element.
        // Remove the largest element in the lowerHalf and put it in the upperHalf
        upperHalf.push(lowerHalf.top());
        lowerHalf.pop();

        // Ensure the size constraint is respected after the rebalance.
        // If the constraint is violated, move the smallest element from the upperHalf to the lowerHalf
        if (lowerHalf.size() < upperHalf.size()) {
            lowerHalf.push(upperHalf.top());
            upperHalf.pop();
        }
    }
    
    double findMedian() {
        if (lowerHalf.size() > upperHalf.size())
            return lowerHalf.top();

        return ((double)lowerHalf.top() + upperHalf.top()) * 0.5;
    }

private:
    // Following are the conditions
    // Both the heaps are balanced (or nearly balanced)
    // The max-heap contains all the smaller numbers while the min-heap contains all the larger numbers
    // The max-heap lowerHalf is allowed to store, at worst, one more element more than the min-heap upperHalf.
    //      This gives us the nice property that when the heaps are perfectly balanced, the median can be derived from the tops of both heaps. 
    // Otherwise, the top of the max-heap lo holds the legitimate median.
    priority_queue<int> lowerHalf;  // maxHeap
    priority_queue<int, vector<int>, greater<int>> upperHalf;   // minHeap
};

int main() {
    MedianFinder medianFinder = MedianFinder();
    medianFinder.addNum(1);
    medianFinder.addNum(2);
    cout << "Current median is: " << medianFinder.findMedian() << endl;
    medianFinder.addNum(3);
    cout << "Current median is: " << medianFinder.findMedian() << endl;

    return 0;
}