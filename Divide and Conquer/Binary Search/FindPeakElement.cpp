/**
 * A peak element is an element that is strictly greater than its neighbors.
 * Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.
 * 
 * You may imagine that nums[-1] = nums[n] = -∞. 
 * In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.
 * 
 * You must write an algorithm that runs in O(log n) time.
 * 
 * Example 1:
 * Input: nums = [1,2,3,1]
 * Output: 2
 * Explanation: 3 is a peak element and your function should return the index number 2.
 * 
 * Example 2:
 * Input: nums = [1,2,1,3,5,6,4]
 * Output: 5
 * Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.
 * 
 * Constraints:
 * 1 <= nums.length <= 1000
 * -2^31 <= nums[i] <= 2^31 - 1
 * nums[i] != nums[i + 1] for all valid i.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1)
            return 0;
        
        int size_of_nums = nums.size();

        if (nums[0] > nums[1])
            return 0;
        
        if (nums[size_of_nums - 1] > nums[size_of_nums - 2])
            return size_of_nums - 1;
        
        int left = 1;
        int right = size_of_nums - 2;

        while (left <= right) {
            int mid = left + ((right - left) / 2);

            // Check if mid is the candidate
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
                return mid;
            else if (nums[mid] > nums[mid - 1]) {
                // mid belongs to a locally increasing segment
                // peak will be on the right
                left = mid + 1;
            } else if (nums[mid] > nums[mid + 1]) {
                // mid belongs to a locally decreasing segment
                // peak will be on the left
                right = mid - 1;
            } else {
                // This is a valley
                // Can go either side. Choosing to eliminate left.
                left = mid + 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3, 1};
    cout << "Peak element index: " << s.findPeakElement(nums) << endl;
    return 0;
}