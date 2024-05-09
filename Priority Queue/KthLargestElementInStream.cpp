/**
 * Design a class to find the kth largest element in a stream. 
 * 
 * Note that it is the kth largest element in the sorted order, not the kth distinct element.
 * 
 * Implement KthLargest class:
 *      - KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of integers nums.
 *      - int add(int val) Appends the integer val to the stream and returns the element representing the kth largest element in the stream.
 * 
 * Example 1:
 * Input
 * ["KthLargest", "add", "add", "add", "add", "add"]
 * [[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
 * 
 * Output
 * [null, 4, 5, 5, 8, 8]
 * 
 * Explanation
 * KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
 * kthLargest.add(3);   // return 4
 * kthLargest.add(5);   // return 5
 * kthLargest.add(10);  // return 5
 * kthLargest.add(9);   // return 8
 * kthLargest.add(4);   // return 8
 * 
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;

        for (auto& num : nums) {
            minHeap.push(num);

            if (minHeap.size() > k)
                minHeap.pop();
        }
    }
    
    int add(int val) {
        minHeap.push(val);

        if (minHeap.size() > k)
            minHeap.pop();
        
        return  minHeap.top();
    }

private:
    int k;
    priority_queue<int, vector<int>, greater<int>> minHeap;
};

int main() {
    vector<int> nums = {4, 5, 8, 2};
    
    KthLargest kthLargest(3, nums);
    cout << kthLargest.add(3) << endl;
    cout << kthLargest.add(5) << endl;
    cout << kthLargest.add(10) << endl;
    cout << kthLargest.add(9) << endl;
    cout << kthLargest.add(4) << endl;
    cout << kthLargest.add(3) << endl;

    return 0;
}