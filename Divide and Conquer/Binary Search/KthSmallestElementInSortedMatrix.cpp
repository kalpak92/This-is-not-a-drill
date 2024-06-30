/**
 * Given an n x n matrix where each of the rows and columns is sorted in ascending order, 
 * return the kth smallest element in the matrix.
 * 
 * Note that it is the kth smallest element in the sorted order, not the kth distinct element.
 * 
 * You must find a solution with a memory complexity better than O(n^2).
 * 
 * Example 1:
 * Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
 * Output: 13
 * Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13
 * 
 * Example 2:
 * Input: matrix = [[-5]], k = 1
 * Output: -5
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int result = -1;

        // Search Space : Min and Max for the array
        int left = matrix[0][0];
        int right = matrix[matrix.size() - 1][matrix.size() - 1];

        while (left <= right) {
            int mid = left + (right - left)/2;

            // The number of elements less than mid is greater than k
            // so keep that element and search the left side for a better candidate.
            // count = k, it means that there are k elements less than or equal to mid in the matrix, 
            // but we don't know whether the element we need is equal to mid.
            if (countLessOrEqual(matrix, mid) >= k) {
                result = mid;
                // eliminate the right search space
                right = mid - 1;
            } else
                left = mid + 1;
        }
        return result;        
    }

private:
    int countLessOrEqual(vector<vector<int>>& matrix, int x) {
        int count = 0;
        int col = matrix[0].size() - 1; // start with the rightmost column

        for (int row = 0; row < matrix.size(); row++) {
            while (col >= 0 && matrix[row][col] > x)  
                // decrease column until matrix[row][col] <= x
                col--;

            count += (col + 1);     // number of elements that are <= x for a given row.
        }
        return count;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {{1,5,9},{10,11,13},{12,13,15}};
    int k = 8;
    cout << sol.kthSmallest(matrix, k) << endl;

    matrix = {{-5}};
    k = 1;
    cout << sol.kthSmallest(matrix, k) << endl;

    return 0;
}