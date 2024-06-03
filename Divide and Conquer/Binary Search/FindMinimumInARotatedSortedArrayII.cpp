/**
 * Suppose an array of length n sorted in ascending order is rotated between 1 and n times. 
 * 
 * For example, the array nums = [0,1,4,4,5,6,7] might become:
 * [4,5,6,7,0,1,4] if it was rotated 4 times.
 * [0,1,4,4,5,6,7] if it was rotated 7 times.
 * 
 * Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time 
 * results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].
 * 
 * Given the sorted rotated array nums that may contain duplicates, return the minimum element of this array.
 * You must decrease the overall operation steps as much as possible.
 * 
 * Example 1:
 * Input: nums = [1,3,5]
 * Output: 1
 * 
 * Example 2:
 * Input: nums = [2,2,2,0,1]
 * Output: 0
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        
        int left = 0;
        int right = nums.size() - 1;

        int result = INT_MAX;

        while (left <= right) {
            int mid = left + ((right - left) / 2) ;

            // Reduce the search space by shrinking the overall search space
            // when start, mid and end are all equal
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                result = min(result, nums[left]);
                left++;
                right--;
                continue;
            }

            // The sorted half may or may not contain the minimum element
            // Identify the sorted half and take the minimum element from there (the first element)
            // Continue the search in the other half
            if (nums[left] <= nums[mid]) {
                result = min(result, nums[left]);   // left half is sorted and left is the guaranteed minimum in this space
                // continue searching the other half
                left = mid + 1; 
            } else {
                result = min(result, nums[mid]);
                right = mid - 1;
            }
        }
        return result;
    }
};

void printVector(vector<int>& nums) {
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    Solution sol;
    vector<int> nums = {2,2,2,0,1};
    cout << "Minimum element in the array: " << sol.findMin(nums) << endl;

    nums = {1,3,5};
    cout << "Minimum element in the array: " << sol.findMin(nums) << endl;

    return 0;
}