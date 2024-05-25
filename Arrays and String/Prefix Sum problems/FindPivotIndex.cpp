/**
 * Given an array of integers nums, calculate the pivot index of this array.
 * The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.
 * If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. 
 * This also applies to the right edge of the array.
 * 
 * Return the leftmost pivot index. If no such index exists, return -1.
 * 
 * Example 1:
 * Input: nums = [1,7,3,6,5,6]
 * Output: 3
 * Explanation:
 * The pivot index is 3.
 * Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
 * Right sum = nums[4] + nums[5] = 5 + 6 = 11
 * 
 * Example 2:
 * Input: nums = [1,2,3]
 * Output: -1
 * Explanation:
 * There is no index that satisfies the conditions in the problem statement.
 * 
 * Example 3:
 * Input: nums = [2,1,-1]
 * Output: 0
 * Explanation:
 * The pivot index is 0.
 * Left sum = 0 (no elements to the left of index 0)
 * Right sum = nums[1] + nums[2] = 1 + -1 = 0
 * 
 * Constraints:
 * 1 <= nums.length <= 10^4
 * -1000 <= nums[i] <= 1000
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if (nums.empty())
            return -1;
        
        int right_sum = 0;
        int left_sum = 0;

        // Initially, right_sum is the sum of all elements
        // left_sum is set to zero.
        for (int num : nums)
            right_sum += num;
        
        for (int i = 0; i < nums.size(); i++) {
            // for each element, subtract the current element from the right_sum
            // check if it is equal to the left_sum or not.
            right_sum -= nums[i];

            if (right_sum == left_sum)
                return i;
            
            // add the number to the left_sum
            left_sum += nums[i];
        }
        return -1;
    }
};

int main() {
    Solution solution;
    
    vector<int> nums = {1, 7, 3, 6, 5, 6};
    cout << solution.pivotIndex(nums) << endl;

    nums = {1, 2, 3};
    cout << solution.pivotIndex(nums) << endl;

    nums = {2, 1, -1};
    cout << solution.pivotIndex(nums) << endl;

    return 0;
}