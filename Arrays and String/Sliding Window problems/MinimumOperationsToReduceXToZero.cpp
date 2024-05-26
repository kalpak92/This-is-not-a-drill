/**
 * You are given an integer array nums and an integer x. 
 * In one operation, you can either remove the leftmost or the rightmost element from the array nums and subtract its value from x. '
 * Note that this modifies the array for future operations.
 * 
 * Return the minimum number of operations to reduce x to exactly 0 if it is possible, otherwise, return -1.
 * 
 * Example 1:
 * Input: nums = [1,1,4,2,3], x = 5
 * Output: 2
 * Explanation: The optimal solution is to remove the last two elements to reduce x to zero.
 * 
 * Example 2:
 * Input: nums = [5,6,7,8,9], x = 4
 * Output: -1
 * 
 * Example 3:
 * Input: nums = [3,2,20,1,1,3], x = 10
 * Output: 5
 * Explanation: The optimal solution is to remove the last three elements and the first two elements (5 operations in total) to reduce x to zero.
 * 
 * Constraints:
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^4
 * 1 <= x <= 10^9
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        // The number of elements removed equals n minus the number of elements that aren't removed.
        // Therefore, to find the minimum number of elements to remove, 
        // we can find the maximum number of elements to not remove!

        // So, instead of trying to find the minimum number of operations, why don't we focus on finding the longest subarray in the middle. 
        // One main thing to note is that our subarray should sum to sum - x (where sum is the sum of all elements in our array).
        // If the sum of the outer elements equals x, then we're looking for a middle sum of sum - x. 
        // Once we find the max_length of the subarray with sum == sum - x
        // Then return nums.size() - max_length for minimum operations
        int total = 0;
        for (int num : nums)
            total += num;
        
        int max_length = INT_MIN;
        int left = 0;
        int current_sum = 0;

        for (int right = 0; right < nums.size(); right++) {
            current_sum += nums[right];                         // increment right until current_sum > window_sum (sum - x)
            
            while (current_sum > total -x && left <= right) {
                // current_sum exceeded window_sum
                // subtract from the left and move left 1 step
                current_sum -= nums[left];
                left++;
            }

            // Update max_length if and only if current_sum == window_sum (sum - x)
            if (current_sum == total - x)
                max_length = max(max_length, right - left + 1);
        }
        return max_length != INT_MIN ? nums.size() - max_length : -1;

    }
};

