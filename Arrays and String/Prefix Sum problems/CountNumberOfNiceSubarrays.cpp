/**
 * Given an array of integers nums and an integer k. 
 * A continuous subarray is called nice if there are k odd numbers on it.
 * 
 * Return the number of nice sub-arrays.
 * 
 * Example 1:
 * Input: nums = [1,1,2,1,1], k = 3
 * Output: 2
 * Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
 * 
 * Example 2:
 * Input: nums = [2,4,6], k = 1
 * Output: 0
 * Explanation: There is no odd numbers in the array.
 * 
 * Example 3:
 * Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
 * Output: 16
 * 
 * Constraints:
 * 1 <= nums.length <= 50000
 * 1 <= nums[i] <= 10^5
 * 1 <= k <= nums.length
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // Count the number of subarrays that contains K odd numbers.
        // running_sum is 1 if the number is odd, else 0.
        // The map stores the count of odd numbers encountered till position i.
        unordered_map<int, int> odd_number_count;

        int running_sum = 0;
        int result = 0;
        odd_number_count[0] = 1;

        for (int i = 0; i < nums.size(); i++) {
            running_sum += (nums[i] % 2 == 1) ? 1 : 0;
            // Check if there is a subarray with k odd numbers.
            // running_sum - prefixSum = k <-- Expected
            // We check if running_sum - k exists in the map.
            if (odd_number_count.contains(running_sum - k))
                result += odd_number_count[running_sum - k];
            
            odd_number_count[running_sum]++;
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 1, 2, 1, 1};
    int k = 3;
    cout << solution.numberOfSubarrays(nums, k) << endl;

    nums = {2, 4, 6};
    k = 1;
    cout << solution.numberOfSubarrays(nums, k) << endl;

    nums = {2, 2, 2, 1, 2, 2, 1, 2, 2, 2};
    k = 2;
    cout << solution.numberOfSubarrays(nums, k) << endl;

    return 0;
}