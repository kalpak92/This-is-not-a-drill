/**
 * A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.
 * 
 * Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, 
 * find any peak element mat[i][j] and return the length 2 array [i,j].
 * You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.
 * 
 * You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.
 * 
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int num_rows = mat.size();
        int num_cols = mat[0].size();

        int left = 0;
        int right = num_cols - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // Get the max element from the given column
            int max_row_index = get_max_index(mat, mid);

            // Store the left and the right elements around the max_row_index element
            int left_elem =  mid - 1 >= 0 ? mat[max_row_index][mid - 1] : -1;
            int right_elem = mid + 1 < num_cols ? mat[max_row_index][mid + 1] : -1;

            // Check for peak. We already know the max element in the column so no need to check in that column
            if (mat[max_row_index][mid] > left_elem && mat[max_row_index][mid] > right_elem) {
                return {max_row_index, mid};
            } else if (mat[max_row_index][mid] < left_elem)
                // peak is on the left
                // eliminate right search space
                right = mid - 1;
            else
                left = mid + 1;
        }
        return {-1, -1};
    }

private:
    int get_max_index(vector<vector<int>>& mat, int column) {
        int max_val = -1;
        int index = -1;
        
        for (int i = 0; i < mat.size(); i++) {
            if (mat[i][column] > max_val) {
                max_val = mat[i][column];
                index = i;
            }
        }
        return index;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat = {{1,4},{3,2}};
    vector<int> result = sol.findPeakGrid(mat);
    cout << result[0] << " " << result[1] << endl;

    mat = {{10,20,15},{21,30,14},{7,16,32}};
    result = sol.findPeakGrid(mat);
    cout << result[0] << " " << result[1] << endl;

    return 0;
}