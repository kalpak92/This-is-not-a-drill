/**
 * You are given an array of integers nums, 
 * there is a sliding window of size k which is moving from the very left of the array to the very right. 
 * You can only see the k numbers in the window. Each time the sliding window moves right by one position.
 * 
 * Return the max sliding window.
 * 
 * Example 1:
 * Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
 * Output: [3,3,5,5,6,7]
 * Explanation: 
 * Window position                Max
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 *  1 [3  -1  -3] 5  3  6  7       3
 *  1  3 [-1  -3  5] 3  6  7       5
 *  1  3  -1 [-3  5  3] 6  7       5
 *  1  3  -1  -3 [5  3  6] 7       6
 *  1  3  -1  -3  5 [3  6  7]      7
 * 
 * Example 2:
 * Input: nums = [1], k = 1
 * Output: [1]
 * 
 * Constraints:
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * 1 <= k <= nums.length
*/

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.empty() || k <= 0)
            return {};
        
        vector<int> result;
        deque<int> deque;

        int left = 0;
        int right = 0;

        while (right < nums.size()) {
            // Ensure the deque invariant
            while (!deque.empty() && nums[right] > deque.back())
                deque.pop_back();
            
            // Add the current element to the deque
            deque.push_back(nums[right]);

            if (right - left + 1 < k) {
                right++;
            } else if (right - left + 1 == k) {
                result.push_back(deque.front());

                // Slide the window
                if (!deque.empty() && nums[left] == deque.front())
                    deque.pop_front();
                
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
    Solution solution;
    
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    printVector(nums);
    // Output: [3,3,5,5,6,7]
    printVector(solution.maxSlidingWindow(nums, k));

    nums = {1};
    k = 1;
    printVector(nums);
    // Output: [1]
    printVector(solution.maxSlidingWindow(nums, k));

    return 0;
}