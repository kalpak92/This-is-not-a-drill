/**
 * Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.
 * A subarray is a contiguous part of the array.
 * 
 * Example 1:
 * Input: nums = [1,0,1,0,1], goal = 2
 * Output: 4
 * Explanation: The 4 subarrays are bolded and underlined below:
 * [1,0,1,0,1]
 * [1,0,1,0,1]
 * [1,0,1,0,1]
 * [1,0,1,0,1]
 * 
 * Example 2:
 * Input: nums = [0,0,0,0,0], goal = 0
 * Output: 15
 * 
 * Constraints:
 * 1 <= nums.length <= 3 * 10^4
 * nums[i] is either 0 or 1.
 * 0 <= goal <= nums.length
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // Count of prefixSum.
        // The map stores {prefixSum, frequency}.
        unordered_map<int, int> odd_number_count;

        int running_sum = 0;
        int result = 0;
        odd_number_count[0] = 1;

        for (int i = 0; i < nums.size(); i++) {
            running_sum += nums[i];
            // Check if there is a subarray with sum == goal.
            // running_sum - prefixSum = goal <-- Expected
            // We check if running_sum - goal exists in the map.
            if (odd_number_count.contains(running_sum - goal))
                result += odd_number_count[running_sum - goal];
            
            odd_number_count[running_sum]++;
        }
        return result;
    }
};

int main() {
    Solution solution;

    vector<int> nums = {1, 0, 1, 0, 1};
    int goal = 2;
    cout << solution.numSubarraysWithSum(nums, goal) << endl;

    nums = {0, 0, 0, 0, 0};
    goal = 0;
    cout << solution.numSubarraysWithSum(nums, goal) << endl;

    return 0;
}