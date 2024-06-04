/**
 * You are given a sorted array consisting of only integers where every element appears exactly twice, 
 * except for one element which appears exactly once.
 * 
 * Return the single element that appears only once.
 * 
 * Your solution must run in O(log n) time and O(1) space.
 * 
 * Example 1:
 * Input: nums = [1,1,2,3,3,4,4,8,8]
 * Output: 2
 * 
 * Example 2:
 * Input: nums = [3,3,7,7,10,11,11]
 * Output: 10
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int result = -1;

        if (nums.size() == 1)
            return nums[0];
        
        if (nums[0] != nums[1])
            return nums[0];
        
        if (nums[nums.size() - 1] != nums[nums.size() - 2])
            return nums[nums.size() - 1];

        // The search space is trimmed
        int left = 1;
        int right = nums.size() - 2;

        while (left <= right) {
            int mid = left + ((right - left) / 2);

            // Check if mid is the candidate
            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
                return nums[mid];
            
            // Choose which part to eliminate
            // If mid is odd and nums in mid and mid - 1 are equal -> Then we are on the left half and candidate is on the right
            // If mid is even and nums in mid and mid +1 are equal -> Then we are on the left half and candidate is on the right
            if ((mid % 2 == 1 && nums[mid] == nums[mid - 1]) || (mid % 2 == 0 && nums[mid] == nums[mid + 1])) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> input = {1,1,2,3,3,4,4,8,8};
    cout << "Result: " << s.singleNonDuplicate(input) << endl;
    return 0;
}