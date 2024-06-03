/**
 * There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).
 * Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) 
 * such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].
 * 
 * Given the array nums after the rotation and an integer target, return true if target is in nums, or false 
 * if it is not in nums.
 * 
 * You must decrease the overall operation steps as much as possible.
 * 
 * Example 1:
 * Input: nums = [2,5,6,0,0,1,2], target = 0
 * Output: true
 * 
 * Example 2:
 * Input: nums = [2,5,6,0,0,1,2], target = 3
 * Output: false
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;

        while (start <= end) {
            int mid = start + ((end - start) / 2);

            if (nums[mid] == target)
                return true;
            
            // Reduce the search space by shrinking the overall search space
            // when start, mid and end are all equal
            if (nums[start] == nums[mid] && nums[mid] == nums[end]) {
                start++;
                end--;
                continue;
            }

            
            if (nums[start] <= nums[mid]) {     // Left half is sorted
                if (nums[start] <= target && target < nums[mid])
                    end = mid - 1;
                else 
                    start = mid + 1;
            } else {
                // right half is sorted
                if (nums[mid] <= target && target <= nums[end])
                    start = mid + 1;
                else
                    end = mid - 1;
            }
        }
        return false;
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
    vector<int> nums = {2,5,6,0,0,1,2};
    int target = 0;

    cout << "Given Array: ";
    printVector(nums);
    cout << "Target: " << target << endl;
    cout << "Is the target element present : " << boolalpha << sol.search(nums, target) << endl;

    target = 3;
    cout << "Given Array: ";
    printVector(nums);
    cout << "Target: " << target << endl;
    cout << "Is the target element present : " << boolalpha << sol.search(nums, target) << endl;

    return 0;
}