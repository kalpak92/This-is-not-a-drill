/**
 * Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. 
 * If target exists, then return its index. Otherwise, return -1.
 * 
 * You must write an algorithm with O(log n) runtime complexity.
 * 
 * Example 1:
 * Input: nums = [-1,0,3,5,9,12], target = 9
 * Output: 4
 * Explanation: 9 exists in nums and its index is 4
 * 
 * Example 2:
 * Input: nums = [-1,0,3,5,9,12], target = 2
 * Output: -1
 * Explanation: 2 does not exist in nums so return -1
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;

        while (start <= end) {
            int mid = start + ((end - start) / 2);

            if (nums[mid] == target)
                return mid;
            
            if (nums[mid] < target)
                start = mid + 1;
            else
                end = mid - 1;
        }
        return -1;
    }

    int searchUsingBuiltIn(vector<int>& nums, int target) {
        // Intersection point
        // upper_bound  returns an iterator pointing to the first element in the range that is greater than target.
        // To convert this iterator to a numerical index, we subtract the begin iterator from it. 
        // This is because the begin iterator points to the first element in the container, 
        // so subtracting it from another iterator gives the number of elements between them, 
        // which is the numerical index of the element pointed to by the second iterator.
        int idx = upper_bound(nums.begin(), nums.end(), target) - nums.begin();

        // Check if the previous element is equal to target
        if (idx > 0 && nums[idx - 1] == target) {
            return idx - 1;
        } else {
            return -1;
        }
    }
};

int main() {
    Solution objSearch;
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;
    cout << "Index of target: " << objSearch.search(nums, target) << endl;
    cout << "Index of target using built-in: " << objSearch.searchUsingBuiltIn(nums, target) << endl;
    return 0;
}