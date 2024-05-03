/**
 * Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.
 * Return the sum of the three integers.
 * 
 * You may assume that each input would have exactly one solution.
 * 
 * Example 1:
 * Input: nums = [-1,2,1,-4], target = 1
 * Output: 2
 * Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 * 
 * Example 2:
 * Input: nums = [0,0,0], target = 1
 * Output: 0
 * Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(begin(nums), end(nums));

        // Initialize the result to the base case
        int result = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < nums.size() - 2; i++) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                int left = i + 1;
                int right = nums.size() - 1;

                while (left < right) {
                    int runningSum = nums[i] + nums[left] + nums[right];

                    if (runningSum == target)
                        return runningSum; // Best case Solution
                    else if (runningSum < target) {
                        // Remove duplicates before incrementing the left pointer
                        while (left < right && nums[left] == nums[left + 1])
                            left++;
                        left++;
                    } else {
                        // Remove duplicates before decrementing the right pointer
                        while (left < right && nums[right] == nums[right - 1])
                            right--;
                        right--;
                    }

                    // Check which is closer to the target and update accordingly
                    if (abs(target - runningSum) < abs(target - result)) {
                        // RunningSum is closer to target than result
                        result = runningSum;
                    }
                }
            }
        }
        return result;
    }
};

int main() {
    Solution solution;

    vector<int> test1 = {-1, 2, 1, -4};
    int target1 = 1;
    cout << solution.threeSumClosest(test1, target1) << endl;

    vector<int> test2 = {0, 0, 0};
    int target2 = 1;
    cout << solution.threeSumClosest(test2, target2) << endl;

    return 0;
}