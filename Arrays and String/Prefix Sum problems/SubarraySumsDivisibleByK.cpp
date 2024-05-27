/**
 * Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.
 * A subarray is a contiguous part of an array.
 * 
 * Example 1:
 * Input: nums = [4,5,0,-2,-3,1], k = 5
 * Output: 7
 * Explanation: There are 7 subarrays with a sum divisible by k = 5:
 * [4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
 * 
 * Example 2:
 * Input: nums = [5], k = 9
 * Output: 0
 * 
 * Constraints:
 * 1 <= nums.length <= 3 * 10^4
 * -10^4 <= nums[i] <= 10^4
 * 2 <= k <= 10^4
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int result = 0;
        int running_sum = 0;
        unordered_map<int, int> mod_counter;
        // The first time we meet a subarray with remainder 0 is a candidate
        // To ensure, we add it to the result, we initialize the mod_counter with 1 for remainder 0.
        mod_counter[0] = 1;

        for (int i = 0; i < nums.size(); i++) {
            running_sum += nums[i];

            int remainder = running_sum % k;
            if (remainder < 0)
                remainder += k;
            
            // If we have seen the remainder in the past
            // Then the subarray between that position and current_position is a candidate
            if (mod_counter.contains(remainder))
                result += mod_counter[remainder];

            mod_counter[remainder]++;
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<vector<int>> testCases = {
        {4,5,0,-2,-3,1},
        {5}
    };
    vector<int> ks = {5, 9};

    for (int i = 0; i < testCases.size(); i++)
        cout << s.subarraysDivByK(testCases[i], ks[i]) << endl;

    return 0;
}