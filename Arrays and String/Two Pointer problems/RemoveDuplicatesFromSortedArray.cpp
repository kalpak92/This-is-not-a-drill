/**
 * Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. 
 * The relative order of the elements should be kept the same. Then return the number of unique elements in nums.
 * 
 * Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:
 * Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. 
 * The remaining elements of nums are not important as well as the size of nums.
 * Return k.
 * 
 * Example 1:
 * Input: nums = [1,1,2]
 * Output: 2, nums = [1,2,_]
 * Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
 * It does not matter what you leave beyond the returned k (hence they are underscores).
 * 
 * Example 2:
 * Input: nums = [0,0,1,1,1,2,2,3,3,4]
 * Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
 * Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
 * It does not matter what you leave beyond the returned k (hence they are underscores).
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Given array is sorted
        // If k elements are unique
        // We need to update the first k elements

        // For in-place update
        // Use the Two Pointers approach
            // FirstIdx : Update the value in the given array
            // SecondIdx : Reads data from the array

        // Start both indexes from 1.
        // Check if the previous element is different from the current element
            // If so : Update the array at FirstIdx and increment FirstIdx

        int insertIdx = 1;

        for(int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1])
            {
                // This means nums[i] is an unique element.
                // Put nums[i] at position insertIdx
                // Then increment insertIdx
                nums[insertIdx] = nums[i];
                insertIdx++;
            }
        }
        return insertIdx;   // insertidx acts as the tracker for the length of the array with unique elements
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
    Solution sol;
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    cout << "Original Array: ";
    printArray(nums);
    int k = sol.removeDuplicates(nums);
    cout << "Array with unique elements: ";
    printArrayWithUniqueElements(nums, k);
    cout << "Number of unique elements: " << k << endl;

    return 0;
}