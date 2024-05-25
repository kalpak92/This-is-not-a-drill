/**
 * Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
 * A subarray is a contiguous non-empty sequence of elements within an array.
 * 
 * Example 1:
 * Input: nums = [1,1,1], k = 2
 * Output: 2
 * 
 * Example 2:
 * Input: nums = [1,2,3], k = 3
 * Output: 2
 * 
 * Constraints:
 * 1 <= nums.length <= 2 * 10^4
 * -1000 <= nums[i] <= 1000
 * -10^7 <= k <= 10^7
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySumUnoptimized(vector<int>& nums, int k) {
        int count = 0;
        vector<int> prefix_sum(nums.size() + 1);
        prefix_sum[0] = 0;

        // Calculate the prefix sum
        // The prefix sum at i is the sum of all the elements from 0 to array at index i.
        // However, we also need to consider the case where the subarray start from the first element of nums.
        // In that case, we need prefix sum for the element before the first element as well, which is naturally 0.
        // Hence, we initialize prefix_sum[0] = 0.
        for (int i = 1; i < prefix_sum.size(); i++) {
            prefix_sum[i] = prefix_sum[i- 1] + nums[i - 1]; // nums[i - 1] because the prefix sum is 1-indexed
        }

        for (int start = 0; start < nums.size(); start++) {
            for (int end = start + 1; end <= nums.size(); end++) {
                // Check if the subarray from [start, end] is equal to k
                if (prefix_sum[end] - prefix_sum[start] == k)
                    count++;
            }
        }
        return count;
    }

    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> previous_sum_count;
        int running_sum = 0;
        int result = 0;

        previous_sum_count[0] = 1;  // handle the case where the subarray that sums to k start at the first element of the array
        for (int i = 0; i < nums.size(); i++) {
            running_sum += nums[i];
            if (previous_sum_count.contains(running_sum - k))
                /**
                 * [key, value] = [sum, number of times the sum has been encountered so far]
                 * When we find [running_sum - k] in the map
                 * it means that there is a previous_sum such that running_sum - previous_sum = k
                 * 
                 * However, there could be multiple such previous sums.
                 * Hence, we need to consider all the previous sums that satisfy the condition and add them to the result.                 * 
                */
                result += previous_sum_count[running_sum - k];
            
            previous_sum_count[running_sum]++;
        }
        return result;
    }
};