/**
 * Given a binary array nums and an integer k, 
 * return the maximum number of consecutive 1's in the array if you can flip at most k 0's.
 * 
 * Example 1:
 * Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
 * Output: 6
 * 
 * Explanation: [1,1,1,0,0,1,1,1,1,1,1]
 * Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
 * 
 * Example 2:
 * Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
 * Output: 10
 * Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
 * Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
 * 
 * Constraints:
 * 1 <= nums.length <= 10^5
 * nums[i] is either 0 or 1.
 * 0 <= k <= nums.length
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int result = 0;
        int zero_count = 0;
        int left = 0;
        int right = 0;

        while (right < nums.size()) {
            // number is zero, so increase zero_count
            if (nums[right] == 0)
                zero_count++;

            if (zero_count <= k) {
                result = max(result, right - left + 1);
                right++;
            } else if (zero_count > k) {
                // Condition violated since zero_count > k
                if (nums[left] == 0)
                    zero_count--;

                // slide the window
                left++;
                right++;
            }            
        }
        return result;
    }
};