/**
 * Given an m x n matrix grid containing an odd number of integers where each row is sorted in non-decreasing order, 
 * return the median of the matrix.
 * 
 * You must solve the problem in less than O(m * n) time complexity.
 * 
 * Example 1:
 * Input: grid = [[1,1,2],[2,3,3],[1,3,4]]
 * Output: 2
 * Explanation: The elements of the matrix in sorted order are 1,1,1,2,2,3,3,3,4. The median is 2.
 * 
 * Example 2:
 * Input: grid = [[1,1,3,3,4]]
 * Output: 3
 * Explanation: The elements of the matrix in sorted order are 1,1,3,3,4. The median is 3.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int matrixMedian(vector<vector<int>>& grid) {
        vector<int> min_max = get_min_and_max_element_in_grid(grid);
        int left = min_max[0];
        int right = min_max[1];

        int num_of_elements = grid.size() * grid[0].size();
        int median_index = num_of_elements / 2;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int count_less_or_equal = countLessOrEqual(grid, mid);

            // count is <= median_index, search partition index in the right search space
            // eliminate the left search space
            if (count_less_or_equal <= median_index)
                left = mid + 1;
            else
                right = mid - 1;
        }
        // left will point to the median when right and left overlaps since we are looking for the first element > median_index
        return left;
    }

private:
    int countLessOrEqual(vector<vector<int>>& matrix, int x) {
        int count = 0;

        for (int row = 0; row < matrix.size(); row++) {
            count += upperBound(matrix[row], x);
        }
        return count;
    }

    // Function to find the count of elements less than or equal to 'num' in a sorted vector 'arr'
    int upperBound(vector<int>& arr, int num)
    {
        // Use the upper_bound function to find the position of 'num' in the sorted vector
        int count  = upper_bound(arr.begin(), arr.end(), num) - arr.begin();
        return count;
    }

    vector<int> get_min_and_max_element_in_grid(const vector<vector<int>>& grid) {
        int min_elem = INT_MAX;
        int max_elem = INT_MIN;
        int num_cols = grid[0].size();

        for (int i = 0; i < grid.size(); i++) {
            min_elem = min(min_elem, grid[i][0]);               // smallest is always the 1st element in the row
            max_elem = max(max_elem, grid[i][num_cols - 1]);    // largest is always the last element in the row
        }

        return {min_elem, max_elem};
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {{1,1,2},{2,3,3},{1,3,4}};
    cout << sol.matrixMedian(grid) << endl;

    grid = {{1,1,3,3,4}};
    cout << sol.matrixMedian(grid) << endl;

    return 0;
}