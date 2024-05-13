/**
 * Given an array of n elements, where each element is at most k away from its target position, devise an algorithm that sorts in O(n log k) time.
 *
 * For example, let us consider k is 2, an element at index 7 in the sorted array, can be at indexes 5, 6, 7, 8, 9 in the given array.
 *
 * Examples:
 * Input : arr[] = {6, 5, 3, 2, 8, 10, 9}
 *             k = 3
 * Output : arr[] = {2, 3, 5, 6, 8, 9, 10}
 *
 * Input : arr[] = {10, 9, 8, 7, 4, 70, 60, 50}
 *          k = 4
 * Output : arr[] = {4, 7, 8, 9, 10, 50, 60, 70}
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> sortKSortedArray(vector<int>& nums, int k) {
        vector<int> result;
        priority_queue<int, vector<int>, greater<int>> minHeap;

        /**
         * The idea is to create a min heap of size k+1 and insert the first k+1 elements into the heap.
        */
        for (int i = 0; i <= k; i++) {
            minHeap.push(nums[i]);
        }

        /**
         * Then, one by one remove the min element from the heap, and add the next element from the array.
         * In the end, the heap will have the k+1 elements in sorted order.
        */
        for (int i = k + 1; i < nums.size(); i++) {
            result.push_back(minHeap.top());
            minHeap.pop();
            minHeap.push(nums[i]);
        }

        // Now, the heap contains the k+1 elements in sorted order.
        // Pop the remaining elements from the heap and add them to the result.
        while (!minHeap.empty()) {
            result.push_back(minHeap.top());
            minHeap.pop();
        }

        return result;
    }
};

// Time Complexity: O(n log k) : 
//      O(n) to insert the first k+1 elements into the heap and 
//      O((n - (k+1) log k) to insert the remaining elements into the heap.
// Space Complexity: O(k) : The size of the heap is k+1.

void printVector(const vector<int>& nums) {
    for (const int& num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    Solution solution;
    vector<int> nums = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;

    cout << "Original array: ";
    printVector(nums);
    cout << "Sorted array with k = " << k << ": ";
    printVector(solution.sortKSortedArray(nums, k));

    return 0;
}