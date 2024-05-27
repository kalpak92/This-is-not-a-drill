/**
 * Given an array of positive integers nums, 
 * remove the smallest subarray (possibly empty) such that the sum of the remaining elements is divisible by p. 
 * It is not allowed to remove the whole array.
 * 
 * Return the length of the smallest subarray that you need to remove, or -1 if it's impossible.
 * 
 * A subarray is defined as a contiguous block of elements in the array.
 * 
 * Example 1:
 * Input: nums = [3,1,4,2], p = 6
 * Output: 1
 * Explanation: The sum of the elements in nums is 10, which is not divisible by 6. 
 * We can remove the subarray [4], and the sum of the remaining elements is 6, which is divisible by 6.
 * 
 * Example 2:
 * Input: nums = [6,3,5,2], p = 9
 * Output: 2
 * Explanation: We cannot remove a single element to get a sum divisible by 9. 
 * The best way is to remove the subarray [5,2], leaving us with [6,3] with sum 9.
 * 
 * Example 3:
 * Input: nums = [1,2,3], p = 3
 * Output: 0
 * Explanation: Here the sum is 6. which is already divisible by 3. 
 * Thus we do not need to remove anything.
 * 
 * Constraints:
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^9
 * 1 <= p <= 10^9
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        // Calculate the total_sum for the given array.
        // If the total_sum % p yields a remainder, 
        // that means we need to find the shortest subarray whose modulus with p yields target. 
        // Removing that subarray would then make the array of positive integers divisible by p.
        long long total_sum = 0;
        for (int num : nums)
            total_sum += num;

        int target = total_sum % p; 
        
        // If total_sum is already divisible by p, then there is no need to remove a subarray.
        if (target == 0) {
            return 0;
        }

        unordered_map<int, int> previous_sum_length;
        previous_sum_length[0] = -1;

        long long running_sum = 0;
        int result = nums.size();
        
        for (int i = 0; i < nums.size(); i++) {
            running_sum += nums[i];
            running_sum = running_sum % p;              // We are only interested in prefix_sum % p, so do the same for the running_sum
            int want = (running_sum - target + p) % p;  // Add p to handle negative modulus

            // When we find [running_sum - target] in the map
            // it means that there is a previous_sum such that running_sum - previous_sum = target
            if (previous_sum_length.contains(want)) {
                result = min(result, i - previous_sum_length[want]);
            }

            previous_sum_length[running_sum] = i;
        }
        return result == nums.size() ? -1 : result;
    }
};

int main() {
    Solution s;
    vector<vector<int>> testCases = {
        {3,1,4,2},
        {6,3,5,2},
        {1,2,3}
    };
    vector<int> ps = {6, 9, 3};

    for (int i = 0; i < testCases.size(); i++)
        cout << s.minSubarray(testCases[i], ps[i]) << endl;

    return 0;
}