/**
 * Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
 * There is only one repeated number in nums, return this repeated number.
 * 
 * You must solve the problem without modifying the array nums and uses only constant extra space.
 * 
 * Example 1:
 * Input: nums = [1,3,4,2,2]
 * Output: 2
 * 
 * Example 2:
 * Input: nums = [3,1,3,4,2]
 * Output: 3
 * 
 * Example 3:
 * Input: nums = [3,3,3,3,3]
 * Output: 3
 * 
 * Constraints:
 * 1 <= n <= 10^5
 * nums.length == n + 1
 * 1 <= nums[i] <= n
 * All the integers in nums appear only once except for precisely one integer which appears two or more times.
 * 
 * Follow up:
 * How can we prove that at least one duplicate number must exist in nums?
 * Can you solve the problem in linear runtime complexity?
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        // Cycle detection
        // nums[fast]:          This gets the value at the index pointed to by fast. 
        //                      This is equivalent to moving one step in the array.
        // nums[nums[fast]]:    This gets the value at the index pointed to by the value obtained from the first step. 
        //                      This is equivalent to moving another step in the array.
        // The algorithm is based on the assumption that there is a cycle in the sequence defined by the array indices and the values in the array.
        // The array values are in the range [1,n] and the array indices are in the range [0,n].
        // This helps in using the array values as valid indices to traverse the array.
        do {
            slow = nums[slow];          // move one step
            fast = nums[nums[fast]];    // move two steps
        } while (slow != fast);

        // find the "start" point in the cycle
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];  // move one step
            fast = nums[fast];  // move one step
        }

        return fast;
    }
};

void printArray(vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    Solution solution;
    
    vector<int> nums1 = {1, 3, 4, 2, 2};
    printArray(nums1);
    cout << "The duplicate number is: " << solution.findDuplicate(nums1) << endl;

    vector<int> nums2 = {3, 1, 3, 4, 2};
    printArray(nums2);
    cout << "The duplicate number is: " << solution.findDuplicate(nums2) << endl;

    vector<int> nums3 = {3, 3, 3, 3, 3};
    printArray(nums3);
    cout << "The duplicate number is: " << solution.findDuplicate(nums3) << endl;

    return 0;
}