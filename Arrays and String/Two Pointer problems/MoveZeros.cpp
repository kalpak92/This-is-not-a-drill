/**
 * Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
 * 
 * Note that you must do this in-place without making a copy of the array.
 * 
 * Example 1:
 * Input: nums = [0,1,0,3,12]
 * Output: [1,3,12,0,0]
 * 
 * Example 2:
 * Input: nums = [0]
 * Output: [0]
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.empty())
            return;
            
        int zeroWindowSize = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0)
                zeroWindowSize++;
            else if (zeroWindowSize > 0) {
                // number is not a zero and we have a prior zeroSize
                // swap the number in place
                int temp = nums[i];
                nums[i] = 0;
                nums[i - zeroWindowSize] = temp;
            }
        }
    }
};

void printVector(const vector<int>& nums) {
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    cout << "Test 1:" << endl;
    vector<int> nums = {0, 1, 0, 3, 12};
    printVector(nums);
    Solution solution;
    solution.moveZeroes(nums);
    printVector(nums);
    cout << endl;

    cout << "Test 2:" << endl;
    vector<int> nums2 = {0};
    printVector(nums2);
    solution.moveZeroes(nums2);
    printVector(nums2);
}