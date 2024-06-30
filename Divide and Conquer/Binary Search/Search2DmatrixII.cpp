/**
 * Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. 
 * This matrix has the following properties:
 *      Integers in each row are sorted in ascending from left to right.
 *      Integers in each column are sorted in ascending from top to bottom.
 * 
 * Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
 * Output: true
 * 
 * Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
 * Output: false
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0;
        int col = matrix[row].size() - 1;

        while (row >= 0 && row < matrix.size() && col >= 0 && col < matrix[0].size()) {
            if (matrix[row][col] == target)
                return true;
            else if (matrix[row][col] > target)
                // current element is greater than target
                // All elements in the column below will also be greater
                // So eliminate that search space
                col--;
            else
                // current element is lesser than target
                // All element in the row left of it will also be lesser
                // Eliminate that search space.
                row++;
        }
        return false;    
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {{1,4,7,11,15},
                                   {2,5,8,12,19},
                                   {3,6,9,16,22},
                                   {10,13,14,17,24},
                                   {18,21,23,26,30}};
    int target = 5;
    cout << boolalpha << sol.searchMatrix(matrix, target) << endl;

    target = 20;
    cout << boolalpha << sol.searchMatrix(matrix, target) << endl;

    return 0;
}