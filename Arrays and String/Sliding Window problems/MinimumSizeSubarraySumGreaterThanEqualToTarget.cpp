/**
 * Given an array of positive integers nums and a positive integer target, 
 * return the minimal length of a subarray whose sum is greater than or equal to target. 
 * If there is no such subarray, return 0 instead.
 * 
 * Example 1:
 * Input: target = 7, nums = [2,3,1,2,4,3]
 * Output: 2
 * Explanation: The subarray [4,3] has the minimal length under the problem constraint.
 * 
 * Example 2:
 * Input: target = 4, nums = [1,4,4]
 * Output: 1
 * 
 * Example 3:
 * Input: target = 11, nums = [1,1,1,1,1,1,1,1]
 * Output: 0
 * 
 * Constraints:
 * 1 <= target <= 10^9
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^4
 * 
 * Follow up: If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log(n)).
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if (nums.empty())
            return 0;

        int result = INT_MAX;
        int window_sum = 0;
        int left = 0;
        int right = 0;

        while (right < nums.size()) {
            window_sum += nums[right];

            if (window_sum < target)
                right++;                        // Keep adding. Since criteria is not met
            else if (window_sum >= target) {
                while (window_sum >= target) {  // Decision making step
                    // Important to note that we need to perform the check for minimum window inside the while loop for the best window and not outside, 
                    // since we are interested in a lower bound
                    result = min(result, right - left + 1);

                    window_sum -= nums[left];
                    left++;
                }
                right++;
            }
        }
        return result == INT_MAX ? 0 : result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2,3,1,2,4,3};
    int target = 7;

    cout << sol.minSubArrayLen(target, nums) << endl;

    return 0;
}