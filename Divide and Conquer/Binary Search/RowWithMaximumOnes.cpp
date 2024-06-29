/**
 * Given a m x n binary matrix mat, find the 0-indexed position of the row that contains the maximum count of ones, 
 * and the number of ones in that row.
 * 
 * In case there are multiple rows that have the maximum count of ones, 
 * the row with the smallest row number should be selected.
 * 
 * Return an array containing the index of the row, and the number of ones in it.
 * 
 * Example 1:
 * Input: mat = [[0,1],[1,0]]
 * Output: [0,1]
 * Explanation: Both rows have the same number of 1's. So we return the index of the smaller row, 0, 
 * and the maximum count of ones (1). So, the answer is [0,1]. 
 * 
 * Example 2:
 * Input: mat = [[0,0,0],[0,1,1]]
 * Output: [1,2]
 * Explanation: The row indexed 1 has the maximum count of ones (2). So we return its index, 1, and the count. 
 * So, the answer is [1,2].
 * 
 * Example 3:
 * Input: mat = [[0,0],[1,1],[0,0]]
 * Output: [1,2]
 * Explanation: The row indexed 1 has the maximum count of ones (2). So the answer is [1,2].
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int max_row = 0;
        int max_ones = 0;

        for (int i = 0; i < mat.size(); i++) {
            int count_ones = 0;
            for (int j = 0; j < mat[i].size(); j++) {
                if (mat[i][j] == 1)
                    count_ones++;
            }
            if (count_ones > max_ones) {
                max_ones = count_ones;
                max_row = i;
            }
        }
        return {max_row, max_ones};
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat = {{0,1},{1,0}};
    vector<int> result = sol.rowAndMaximumOnes(mat);
    cout << result[0] << " " << result[1] << endl;

    mat = {{0,0,0},{0,1,1}};
    result = sol.rowAndMaximumOnes(mat);
    cout << result[0] << " " << result[1] << endl;

    mat = {{0,0},{1,1},{0,0}};
    result = sol.rowAndMaximumOnes(mat);
    cout << result[0] << " " << result[1] << endl;

    return 0;
}