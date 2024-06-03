/**
 * Given an array of integers nums sorted in non-decreasing order, 
 * find the starting and ending position of a given target value.
 * 
 * If target is not found in the array, return [-1, -1].
 * You must write an algorithm with O(log n) runtime complexity.
 * 
 * Example 1:
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 * 
 * Example 2:
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 * 
 * Example 3:
 * Input: nums = [], target = 0
 * Output: [-1,-1]
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = getFirstPosition(nums, target);

        if (first == -1)
            return {-1, -1};
        
        int last = getLastPosition(nums, target);
        return {first, last};

    }

private:
    int getFirstPosition(vector<int>& nums, int target) {
        if (nums.empty())
            return -1;
        
        int first = -1;
        int start = 0;
        int end = nums.size() - 1;

        while (start <= end) {
            int mid = start + ((end - start) / 2);

            if (nums[mid] == target) {
                first = mid;
                end = mid - 1;
            } else if (nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return first;
    }

    int getLastPosition(vector<int>& nums, int target) {
        if (nums.empty())
            return -1;
        
        int last = -1;
        int start = 0;
        int end = nums.size() - 1;

        while (start <= end) {
            int mid = start + ((end - start) / 2);

            if (nums[mid] == target) {
                last = mid;
                start = mid + 1;
            } else if (nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return last;
    }
};

int main() {
    Solution objSearch;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    vector<int> result = objSearch.searchRange(nums, target);
    cout << "[" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}