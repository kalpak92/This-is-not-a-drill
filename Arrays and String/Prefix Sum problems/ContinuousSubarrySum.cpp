/**
 * Given an integer array nums and an integer k, 
 * return true if nums has a good subarray or false otherwise.
 * 
 * A good subarray is a subarray where:
 *      its length is at least two, and
 *      the sum of the elements of the subarray is a multiple of k.
 * 
 * Note that:
 * A subarray is a contiguous part of the array.
 * An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.
 * 
 * Example 1:
 * Input: nums = [23,2,4,6,7], k = 6
 * Output: true
 * Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up to 6.
 * 
 * Example 2:
 * Input: nums = [23,2,6,4,7], k = 6
 * Output: true
 * Explanation: [23, 2, 6, 4, 7] is an continuous subarray of size 5 whose elements sum up to 42.
 * 42 is a multiple of 6 because 42 = 7 * 6 and 7 is an integer.
 * 
 * Example 3:
 * Input: nums = [23,2,6,4,7], k = 13
 * Output: false
 * 
 * Constraints:
 * 1 <= nums.length <= 10^5
 * 0 <= nums[i] <= 10^9
 * 0 <= sum(nums[i]) <= 2^31 - 1
 * 1 <= k <= 2^31 - 1
*/


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size() < 2)
            return false;

        unordered_map<int, int> prefix_sum_mod;
        prefix_sum_mod[0] = -1;
        int running_sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            running_sum += nums[i];
            if (k != 0)
                running_sum %= k;

            // subarray [b - a] % k = 0 
            // --> (b % k - a % k) % k = 0 
            // --> b % k - a % k = 0
            // --> b % k == a % k
            // running_sum % k already seen before which mean the subarray is divisible by k
            if (prefix_sum_mod.contains(running_sum)) {
                // Validates the length of the subarray is atleast 2.
                if (i - prefix_sum_mod[running_sum] > 1)
                    return true;
            } else {
                prefix_sum_mod[running_sum] = i;    // store the prefix_sum_mod_k and its corresponding index
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<vector<int>> testCases = {
        {23,2,4,6,7},
        {23,2,6,4,7},
        {23,2,6,4,7}
    };
    vector<int> ks = {6, 6, 13};

    for (int i = 0; i < testCases.size(); i++)
        cout << s.checkSubarraySum(testCases[i], ks[i]) << endl;

    return 0;
}