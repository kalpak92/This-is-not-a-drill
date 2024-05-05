/**
 * Given an integer array nums sorted in non-decreasing order, 
 * return an array of the squares of each number sorted in non-decreasing order.
 * 
 * Example 1:
 * Input: nums = [-4,-1,0,3,10]
 * Output: [0,1,9,16,100]
 * Explanation: After squaring, the array becomes [16,1,0,9,100].
 * After sorting, it becomes [0,1,9,16,100].
 * 
 * Example 2:
 * Input: nums = [-7,-3,2,3,11]
 * Output: [4,9,9,49,121]
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> sortedSquaresUnoptimized(vector<int>& nums) {
        vector<int> result;
        for (int i : nums) {
            result.push_back(i * i);
        }

        sort(result.begin(), result.end());
        return result;
    }

    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size());

        int left = 0;
        int right = nums.size() - 1;

        // Move right to left and put Max(abs(nums[left])^2, abs(nums[right]^2))
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (abs(nums[left]) > abs(nums[right])) {
                result[i] = nums[left] * nums[left];
                left++;
            } else {
                result[i] = nums[right] * nums[right];
                right--;
            }
        }
        return result;
    }
};

void printVector(const vector<int>& nums) {
    for (int i : nums) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    Solution solution;

    vector<int> test1 = {-4, -1, 0, 3, 10};
    cout << "Test case 1: " << endl;
    printVector(test1);
    printVector(solution.sortedSquares(test1));

    vector<int> test2 = {-7, -3, 2, 3, 11};
    cout << "Test case 2: " << endl;
    printVector(test2);
    printVector(solution.sortedSquares(test2));

    return 0;
}