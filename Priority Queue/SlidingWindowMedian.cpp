/**
 * The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. 
 * So the median is the mean of the two middle values.
 * 
 * For examples, if arr = [2,3,4], the median is 3.
 * For examples, if arr = [1,2,3,4], the median is (2 + 3) / 2 = 2.5.
 * You are given an integer array nums and an integer k. 
 * There is a sliding window of size k which is moving from the very left of the array to the very right. 
 * You can only see the k numbers in the window. Each time the sliding window moves right by one position.
 * 
 * Return the median array for each window in the original array. Answers within 10-5 of the actual value will be accepted.
 * 
 * Example 1:
 * Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
 * Output: [1.00000,-1.00000,-1.00000,3.00000,5.00000,6.00000]
 * 
 * Explanation: 
 * Window position                Median
 * ---------------                -----
 * [1  3  -1] -3  5  3  6  7        1
 *  1 [3  -1  -3] 5  3  6  7       -1
 *  1  3 [-1  -3  5] 3  6  7       -1
 *  1  3  -1 [-3  5  3] 6  7        3
 *  1  3  -1  -3 [5  3  6] 7        5
 *  1  3  -1  -3  5 [3  6  7]       6
 * 
 * Example 2:
 * Input: nums = [1,2,3,4,2,3,1,4,2], k = 3
 * Output: [2.00000,3.00000,3.00000,3.00000,2.00000,3.00000,2.00000]
*/

/**
 * An important thing to notice is the fact that if the two heaps are balanced, 
 * only the top of the heaps are actually needed to find the medians. 
 * This means that as long as we can somehow keep the heaps balanced, 
 * we could also keep some extraneous elements.
 * 
 * Thus, we can use hash-tables to keep track of invalidated elements. 
 * Once they reach the heap tops, we remove them from the heaps. This is the lazy removal technique.
 * 
 * An immediate challenge at this point is balancing the heaps while keeping extraneous elements. 
 * This is done by actually moving some elements to the heap which has extraneous elements, from the other heap. 
 * This cancels out the effect of having extraneous elements and maintains the invariant that the heaps are balanced.


*/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> result;
        priority_queue<int> lowerHalf;  // maxHeap
        priority_queue<int, vector<int>, greater<int>> upperHalf;   // minHeap
        unordered_map<int, int> hash_table;

        int i = 0;

        // initialize the heaps.
        // The max-heap lo is allowed to store, at worst, 
        // one more element more than the min-heap hi. 
        while (i < k) {
            lowerHalf.push(nums[i]);
            i++;
        }
        // Rebalance since lowerHalf received new elements.
        // Remove the largest element in the lowerHalf and put it in the upperHalf.
        // The max-heap lowerHalf is allowed to store, at worst, 
        // one more element more than the min-heap upperHalf.
        for (int j = 0; j < k/2; j++) {
            upperHalf.push(lowerHalf.top());
            lowerHalf.pop();
        }

        while (true) {
            // Get the median of the current window
            result.push_back(k & 1 ? lowerHalf.top() : 
                                ((double)lowerHalf.top() + (double)upperHalf.top()) * 0.5);
            
            if (i >= nums.size())
                break;          // all elements have been processed
            
            // store the outgoing and incoming element for the next window
            int out_num = nums[i - k];
            int in_num = nums[i];
            i++;

            // Calculate the balance factor based on which heap the out_num is flushed.
            // when we are talking about keeping the heaps balanced, the actual sizes of the heaps are irrelevant. 
            // Only the count of valid elements in both heaps matter.
            // balance = 0: Both heaps are balanced or nearly balanced.
            // balance < 0: lo needs more valid elements. Elements from hi are moved to lo.
            // balance > 0: hi needs more valid elements. Elements from lo are moved to hi.
            int balance = 0;

            // if the out_num is present in lowerHalf, 
            // we need to move some elements from upperHalf 
            // to cancel out the effect of having the extraneouos element
            if (out_num <= lowerHalf.top())
                balance += -1; 
            else
                balance += 1;
            hash_table[out_num]++;          // track the deleted number in a map to delete later

            // Update the balance factor based on which heap the in_num is put
            // If in_num is less than or equal to the top element of lo, 
            // then it can be inserted to lo. 
            // However this unbalances hi (hi has lesser valid elements now). 
            // Hence balance is incremented.
            if (!lowerHalf.empty() && in_num <= lowerHalf.top()) {
                balance++;
                lowerHalf.push(in_num);
            } else {
                balance--;
                upperHalf.push(in_num);
            }

            // Now, we need to Rebalance the heaps based on the final balance factor
            if (balance < 0) {
                lowerHalf.push(upperHalf.top());
                upperHalf.pop();
                balance++;
            }

            if (balance > 0) {
                upperHalf.push(lowerHalf.top());
                lowerHalf.pop();
                balance--;
            }

            // Now delete the numbers that are not part of the current window.
            // Once an invalid element reaches either of the heap tops, 
            // we remove them and decrement their counts in the hash_table table.
            while (hash_table[lowerHalf.top()]) {
                hash_table[lowerHalf.top()]--;
                lowerHalf.pop();
            }

            while (!upperHalf.empty() && hash_table[upperHalf.top()]) {
                hash_table[upperHalf.top()]--;
                upperHalf.pop();
            }
        }
        return result;
    }
};

template <typename T>
void printResult(const vector<T>& result) {
    for (const auto& r : result) {
        cout << r << " ";
    }
    cout << endl;
}

int main() {
    Solution s;
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    cout << "Given array: ";
    printResult(nums);
    cout << "Sliding window size: " << k << endl;
    vector<double> result = s.medianSlidingWindow(nums, k);
    cout << "Median array: ";
    printResult(result);

    return 0;
}