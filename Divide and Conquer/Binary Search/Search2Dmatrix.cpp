/**
 * You are given an m x n integer matrix matrix with the following two properties:
 *      Each row is sorted in non-decreasing order.
 *      The first integer of each row is greater than the last integer of the previous row.
 * 
 * Given an integer target, return true if target is in matrix or false otherwise.
 * You must write a solution in O(log(m * n)) time complexity.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Time Complexity: O(log(m*n))
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int num_rows = matrix.size();
        int num_cols = matrix[0].size();

        int left = 0;
        int right = num_rows * num_cols - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            int row = mid / num_cols;
            int col = mid % num_cols;

            if (matrix[row][col] == target)
                return true;
            else if (matrix[row][col] < target)
                left = mid + 1;
            else 
                right = mid - 1;
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 3;
    cout << boolalpha << sol.searchMatrix(matrix, target) << endl;

    target = 13;
    cout << boolalpha << sol.searchMatrix(matrix, target) << endl;

    return 0;
}