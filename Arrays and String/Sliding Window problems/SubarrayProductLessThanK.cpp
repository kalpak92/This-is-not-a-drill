/**
 * Given an array of integers nums and an integer k, 
 * return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.
 * 
 * Example 1:
 * Input: nums = [10,5,2,6], k = 100
 * Output: 8
 * Explanation: The 8 subarrays that have product less than 100 are:
 * [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
 * Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.
 * 
 * Example 2:
 * Input: nums = [1,2,3], k = 0
 * Output: 0
 * 
 * Constraints:
 * 1 <= nums.length <= 3 * 10^4
 * 1 <= nums[i] <= 1000
 * 0 <= k <= 10^6
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (nums.empty())
            return 0;
        
        int result = 0;
        int product = 1;

        int left = 0;
        int right = 0;

        while (right < nums.size()) {
            product *= nums[right];

            // If the product is greater than k
            // Shrink the window
            while (left <= right && product >= k) {
                product /= nums[left];
                left++;
            }
            // product is < k 
            // So the current window is a candidate
            // 
            result += right - left + 1;
            right++;
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {10,5,2,6};
    int k = 100;

    cout << sol.numSubarrayProductLessThanK(nums, k) << endl;

    nums = {1,2,3};
    k = 0;

    cout << sol.numSubarrayProductLessThanK(nums, k) << endl;

    return 0;
}