/**
 * Given an array of n integers nums and an integer target, 
 * find the number of index triplets i, j, k with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.
 * 
 * Example 1:
 * Input: nums = [-2,0,1,3], target = 2
 * Output: 2
 * Explanation: Because there are two triplets which sums are less than 2:
 * [-2,0,1]
 * [-2,0,3]
 * 
 * Example 2:
 * Input: nums = [], target = 0
 * Output: 0
 * 
 * Example 3:
 * Input: nums = [0], target = 0
 * Output: 0
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        // If there are no triplets
        // return preemptively
        if (nums.size() < 3)
            return 0;

        sort(begin(nums), end(nums));
        int result = 0;

        for (int i = 0; i < nums.size() - 2; i++) {
            int left = i + 1;
            int right = nums.size() - 1;
            
            while (left < right) {
                // Check for the condition
                if (nums[i] + nums[left] + nums[right] < target) {
                    // Candidate found
                    // All numbers within (left, right) will be < target since the array is sorted
                    // Add it to the result
                    result += right - left;
                    left ++;    // increment left and check again
                } else {
                    // triplet is > target.
                    right--;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution solution;

    vector<int> nums = {-2, 0, 1, 3};
    int target = 2;

    cout << solution.threeSumSmaller(nums, target) << endl;

    nums = {};
    target = 0;
    cout << solution.threeSumSmaller(nums, target) << endl;

    nums = {0};
    target = 0;
    cout << solution.threeSumSmaller(nums, target) << endl;

    return 0;
}