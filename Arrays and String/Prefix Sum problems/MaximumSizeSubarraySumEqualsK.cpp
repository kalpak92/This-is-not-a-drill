/**
 * Given an integer array nums and an integer k, return the maximum length of a subarraythat sums to k. 
 * If there is not one, return 0 instead.
 * 
 * Example 1:
 * Input: nums = [1,-1,5,-2,3], k = 3
 * Output: 4
 * Explanation: The subarray [1, -1, 5, -2] sums to 3 and is the longest.
 * 
 * Example 2:
 * Input: nums = [-2,-1,2,1], k = 1
 * Output: 2
 * Explanation: The subarray [-1, 2] sums to 1 and is the longest.
 * 
 * Constraints:
 * 1 <= nums.length <= 2 * 10^5
 * -10^4 <= nums[i] <= 10^4
 * -10^9 <= k <= 10^9
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<long long, int> previous_sum_count;   // cumulative sum as key and their corresponding index
        long long running_sum = 0;
        int result = 0;

        /**
         * The initial value of -1 is set for the key 0 in the previous_sum_count map to handle the case 
         * where the subarray with sum equal to k starts from the first element of the array.
         * 
         * If the initial value of -1 wasn't set for the key 0, 
         * this calculation wouldn't work correctly for subarrays starting from the first element. 
         * By setting the initial value to -1, 
         * the length of the subarray is correctly calculated as i - (-1) = i + 1, 
         * which is the correct length since array indices are 0-based.
        */
        previous_sum_count[0] = -1;

        for (int i = 0; i < nums.size(); i++) {
            running_sum += nums[i];

            if (previous_sum_count.contains(running_sum - k)) {
                // Found a subarray of sum == k
                result = max(result, i - previous_sum_count[running_sum - k]);
            }

            if (!previous_sum_count.contains(running_sum))
                // Secondly if the running_sum does not exist in map,
                // Only then update the index.
                // This is because we need to find the longest length, so earlier the index, the better it is.
                previous_sum_count[running_sum] = i;
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, -1, 5, -2, 3};
    int k = 3;
    cout << "Output: " << solution.maxSubArrayLen(nums, k) << endl;

    nums = {-2, -1, 2, 1};
    k = 1;
    cout << "Output: " << solution.maxSubArrayLen(nums, k) << endl;

    return 0;
}