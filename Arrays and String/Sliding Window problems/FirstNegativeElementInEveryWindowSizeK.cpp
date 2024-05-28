/**
 * Given an array and a positive integer k, find the first negative integer for each window(contiguous subarray) of size k. 
 * If a window does not contain a negative integer, then print 0 for that window.
 * 
 * Examples:
 * Input : arr[] = {-8, 2, 3, -6, 10}, k = 2
 * Output : -8 0 -6 -6
 * 
 * First negative integer for each window of size k
 *      {-8, 2} = -8
 *      {2, 3} = 0 (does not contain a negative integer)
 *      {3, -6} = -6
 *      {-6, 10} = -6
 * 
 * Input : arr[] = {12, -1, -7, 8, -15, 30, 16, 28} , k = 3
 * Output : -1 -1 -7 -15 -15 0
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> firstNegativeIntegerInEveryWindowSizeK(vector<int>& nums, int k) {
        vector<int> result;
        queue<int> queue;

        int left = 0;
        int right = 0;

        while (right < nums.size()) {
            if (nums[right] < 0)
                queue.push(nums[right]);        // Add negative numbers to the queue
            
            if (right -left + 1 < k) {
                right++;
            } else if (right - left + 1 == k) {
                if (queue.empty()) {
                    result.push_back(0);        // If the queue is empty, then there are no negative numbers in the window
                } else {
                    result.push_back(queue.front());

                    if (nums[left] == queue.front())    // If the left element is the same as the front of the queue, then pop the front
                        queue.pop();
                }
                left++;
                right++;
            }
        }
        return result;
    }
};

void printVector(const vector<int>& nums) {
    for (int num : nums)
        cout << num << " ";
    cout << endl;
}

int main() {
    Solution sol;
    vector<int> nums = {-8, 2, 3, -6, 10};
    int k = 2;
    printVector(nums);
    cout << "First negative integer in every window size " << k << " is: ";
    printVector(sol.firstNegativeIntegerInEveryWindowSizeK(nums, k));

    nums = {12, -1, -7, 8, -15, 30, 16, 28};
    k = 3;
    printVector(nums);
    cout << "First negative integer in every window size " << k << " is: ";
    printVector(sol.firstNegativeIntegerInEveryWindowSizeK(nums, k));

    return 0;
}