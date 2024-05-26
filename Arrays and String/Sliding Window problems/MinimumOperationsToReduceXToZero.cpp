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
#include <unordered_map>

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

    int minOperationsUsingPrefixSum(vector<int>& nums, int x) {
        // Need to find a maximum length subarray of value total_sum - x.
        int total_sum = -x;
        for (int num : nums)
            total_sum += num;
        
        // Since all elements are positive, we have to take all of them
        if (total_sum == 0)
            return nums.size();
        
        unordered_map<int, int> previous_sum_count;
        previous_sum_count[0] = -1;

        int running_sum = 0;
        int result = INT_MIN;

        for (int i = 0;i < nums.size(); i++) {
            running_sum += nums[i];

            // Check if there is a candidate in the map for running_sum - target
            if (previous_sum_count.contains(running_sum - total_sum))
                result = max(result, i - previous_sum_count[running_sum - total_sum]);
            
            if (!previous_sum_count.contains(running_sum))
                previous_sum_count[running_sum] = i;
        }
        return result != INT_MIN ? nums.size() - result : -1;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 1, 4, 2, 3};
    int x = 5;
    cout << solution.minOperations(nums, x) << endl;

    nums = {5, 6, 7, 8, 9};
    x = 4;
    cout << solution.minOperations(nums, x) << endl;

    nums = {3, 2, 20, 1, 1, 3};
    x = 10;
    cout << solution.minOperations(nums, x) << endl;

    return 0;
}

