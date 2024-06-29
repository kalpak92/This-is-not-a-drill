/**
 * Given a m x n binary matrix mat, find the 0-indexed position of the row that contains the maximum count of ones, 
 * and the number of ones in that row.
 * The rows are in increasing order.
 * In case there are multiple rows that have the maximum count of ones, 
 * the row with the smallest row number should be selected.
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
            int idx = getFirstPosition(mat[i], 1);
            int count_ones = (idx == -1) ? 0 : mat[i].size() - idx;

            if (count_ones > max_ones) {
                max_ones = count_ones;
                max_row = i;
            }
        }
        return {max_row, max_ones};
    }

    int getFirstPosition(vector<int>& nums, int target) {
        if (nums.empty())
            return -1;
        
        int first = -1;
        int start = 0;
        int end = nums.size() - 1;

        while (start <= end) {
            int mid = start + ((end - start) / 2);

            if (nums[mid] == target) {
                first = mid;
                end = mid - 1;
            } else if (nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return first;
    }
};