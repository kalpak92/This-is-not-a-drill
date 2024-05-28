/**
 * You are given an integer array nums and an integer k. 
 * Find the maximum subarray sum of all the subarrays of nums that meet the following conditions:
 *      The length of the subarray is k, and
 *      All the elements of the subarray are distinct.
 * 
 * Return the maximum subarray sum of all the subarrays that meet the conditions. 
 * If no subarray meets the conditions, return 0.
 * 
 * A subarray is a contiguous non-empty sequence of elements within an array.
 * 
 * Example 1:
 * Input: nums = [1,5,4,2,9,9,9], k = 3
 * Output: 15
 * Explanation: The subarrays of nums with length 3 are:
 *  - [1,5,4] which meets the requirements and has a sum of 10.
 *  - [5,4,2] which meets the requirements and has a sum of 11.
 *  - [4,2,9] which meets the requirements and has a sum of 15.
 *  - [2,9,9] which does not meet the requirements because the element 9 is repeated.
 *  - [9,9,9] which does not meet the requirements because the element 9 is repeated.
 * 
 * We return 15 because it is the maximum subarray sum of all the subarrays that meet the conditions
 * 
 * Example 2:
 * Input: nums = [4,4,4], k = 3
 * Output: 0
 * Explanation: The subarrays of nums with length 3 are:
 * - [4,4,4] which does not meet the requirements because the element 4 is repeated.
 * We return 0 because no subarrays meet the conditions.
 * 
 * Constraints:
 * 1 <= k <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^5
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long result = 0;                       // We return 0 when no subarrays meet the conditions.
        unordered_map<int, int> window_elements;
        long long window_sum = 0;

        // First K elements
        for (int i = 0; i < k; i++) {
            window_sum += nums[i];
            window_elements[nums[i]]++;
        }
        
        // If the number of elements in the map == K
        // This means that the elements are distinct for the first window
        // window_sum becomes a candidate answer
        if (window_elements.size() == k)
            result = window_sum;

        for (int i = k; i < nums.size(); i++) {
            window_sum += nums[i] - nums[i - k];

            window_elements[nums[i]]++;
            window_elements[nums[i - k]]--;
            if (window_elements[nums[i - k]] == 0)
                window_elements.erase(nums[i - k]);
            
            if (window_elements.size() == k)
                result = max(result, window_sum);
        }
        return result;
    }
};

void printVector(vector<int>& nums) {
    for (int num : nums)
        cout << num << " ";
    cout << endl;
}

int main() {
    Solution sol;
    vector<int> nums = {1,5,4,2,9,9,9};
    int k = 3;
    printVector(nums);
    cout << sol.maximumSubarraySum(nums, k) << endl;

    nums = {4,4,4};
    k = 3;
    printVector(nums);
    cout << sol.maximumSubarraySum(nums, k) << endl;
}