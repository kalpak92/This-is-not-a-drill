/**
 * Given an integer array nums sorted in non-decreasing order, remove some duplicates in-place such that each unique element appears at most twice. 
 * The relative order of the elements should be kept the same.
 * 
 * Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. 
 * It does not matter what you leave beyond the first k elements.
 * 
 * Return k after placing the final result in the first k slots of nums.
 * Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.
 * 
 * Example 1:
 * Input: nums = [1,1,1,2,2,3]
 * Output: 5, nums = [1,1,2,2,3,_]
 * Explanation: Your function should return k = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
 * It does not matter what you leave beyond the returned k (hence they are underscores).
 * 
 * Example 2:
 * Input: nums = [0,0,1,1,1,1,2,3,3]
 * Output: 7, nums = [0,0,1,1,2,3,3,_,_]
 * Explanation: Your function should return k = 7, with the first seven elements of nums being 0, 0, 1, 1, 2, 3 and 3 respectively.
 * 
 * Constraints:
 * 1 <= nums.length <= 3 * 10^4
 * -10^4 <= nums[i] <= 10^4
 * nums is sorted in non-decreasing order.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 3)
            return nums.size();

        // Here insertIdx is the slow pointer and duplicateCount tracks the window size (which can be 2 at max)
        int insertIdx = 1;
        int duplicateCount = 1; // Track the count of a particular element . Minimum set to 1

        for (int i = 1; i < nums.size(); i++) {
            // Keep incrementing duplicateCount
            if (nums[i] == nums [i - 1])
                duplicateCount++;
            else
                duplicateCount = 1;  // reset duplicateCount since a new element has been found

            // For the first 2 cases, i and insertIdx progresses at the same rate.
            // When count is >2, then we progress i, but insertIdx remains as is.
            // On further reset of duplicateCount, because a new element is found, 
            // Move nums[i] to nums[insertIdx] and increment insertIdx.
            if (duplicateCount <= 2) {
                nums[insertIdx] = nums[i];
                insertIdx++;
            }
        }
        return insertIdx;
    }
};

void printArray(const vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

void printArrayWithUniqueElements(const vector<int>& nums, int k) {
    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main() {
    Solution s;
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    cout << "Original Array: ";
    printArray(nums);
    int k = s.removeDuplicates(nums);
    cout << "Array with unique elements: ";
    printArrayWithUniqueElements(nums, k);

    nums = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    cout << "Original Array: ";
    printArray(nums);
    k = s.removeDuplicates(nums);
    cout << "Array with unique elements: ";
    printArrayWithUniqueElements(nums, k);

    return 0;
}