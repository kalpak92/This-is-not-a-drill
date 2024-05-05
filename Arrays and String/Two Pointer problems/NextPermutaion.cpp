/**
 * A permutation of an array of integers is an arrangement of its members into a sequence or linear order.
 * 
 * For example, for arr = [1,2,3], the following are all the permutations of arr: 
 *      [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
 * The next permutation of an array of integers is the next lexicographically greater permutation of its integer. 
 * 
 * More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, 
 * then the next permutation of that array is the permutation that follows it in the sorted container. 
 * 
 * If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).
 * For example, the next permutation of arr = [1,2,3] is [1,3,2].
 * Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
 * While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
 * Given an array of integers nums, find the next permutation of nums.
 * 
 * The replacement must be in place and use only constant extra memory.
*/

#include <iostream>
#include <vector>

using namespace std;

// Refer : https://www.nayuki.io/page/next-lexicographical-permutation-algorithm

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // The key observation in this algorithm is that when we want to compute the next permutation, 
        // we must “increase” the sequence as little as possible. 
        // Just like when we count up using numbers, we try to modify the rightmost elements and leave the left side unchanged.
        
        // Make pivot the element just before the peak
        int pivot = indexOfLastPeak(nums) - 1;

        // The pivot is necessarily less than the head of the suffix.
        // If there is no such element – i.e. the entire sequence is non-increasing – then this is already the last permutation.
        // So some element in the suffix is greater than the pivot. 
        // If we swap the pivot with the smallest element in the suffix that is greater than the pivot, then the prefix is minimally increased.

        if (pivot != -1) {
            int smallestElementGreaterThanPivotInSuffix = lastIndexOfGreater(nums, nums[pivot]);

            // swap the pivot with the smallest element in the suffix that is greater than the pivot, 
            // then the prefix is minimally increased.
            swap(nums, pivot, smallestElementGreaterThanPivotInSuffix);
        }

        // Finally, we sort the suffix in non-decreasing (i.e. weakly increasing) order because we increased the prefix, so we want to make the new suffix as low as possible. 
        // In fact, we can avoid sorting and simply reverse the suffix, because the replaced element respects the weakly decreasing order.
        sortSuffix(nums, pivot+1);
    }

private:
    // Find the longest non-increasing suffix.
    // This suffix is already the highest permutation, 
    // so we can’t make a next permutation just by modifying it – we need to modify some element(s) to the left of it. 
    int indexOfLastPeak(const vector<int>& nums) {
        for (int i = nums.size() - 1; i > 0; i--) {
            if (nums[i - 1] < nums[i])  // Check if index i is the peak
                return i;
        }
        return 0;
    }

    // Find the Smallest element in the suffix array that is greater than the pivot element
    int lastIndexOfGreater(const vector<int>& nums, int threshold) {
        for (int i = nums.size() - 1; i > 0; i--) {
            if (nums[i] > threshold)    // Smallest element in the suffix that is greater than the pivot
                return i;
        }
        return -1;  // Nothing like that exists. Return -1.
    }


    void swap(vector<int>& nums, int pivot, int smallestElementGreaterThanPivotInSuffix) {
        int temp = nums[pivot];
        nums[pivot] = nums[smallestElementGreaterThanPivotInSuffix];
        nums[smallestElementGreaterThanPivotInSuffix] = temp;
    }

    void sortSuffix(vector<int>& nums, int startIndex) {
        int endIndex = nums.size() - 1;
        
        while (startIndex < endIndex) {
            swap(nums, startIndex, endIndex);
            startIndex++;
            endIndex--;
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
    Solution solution;

    vector<int> test1 = {1, 2, 3};
    cout << "The next of : ";
    printVector(test1);
    solution.nextPermutation(test1);
    printVector(test1);

    vector<int> test2 = {1, 3, 2};
    cout << "The next of : ";
    printVector(test2);
    solution.nextPermutation(test2);
    printVector(test2);

    vector<int> test3 = {3, 2, 1};
    cout << "The next of : ";
    printVector(test3);
    solution.nextPermutation(test3);
    printVector(test3);

    return 0;
}