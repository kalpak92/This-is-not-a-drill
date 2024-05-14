/**
 * Determine if a 9 x 9 Sudoku board is valid. 
 * Only the filled cells need to be validated according to the following rules:
 *      Each row must contain the digits 1-9 without repetition.
 *      Each column must contain the digits 1-9 without repetition.
 *      Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
 * 
 * Note:
 *      A Sudoku board (partially filled) could be valid but is not necessarily solvable.
 *      Only the filled cells need to be validated according to the mentioned rules.
 * 
 * Input: board = 
 * [["5","3",".",".","7",".",".",".","."]
 * ,["6",".",".","1","9","5",".",".","."]
 * ,[".","9","8",".",".",".",".","6","."]
 * ,["8",".",".",".","6",".",".",".","3"]
 * ,["4",".",".","8",".","3",".",".","1"]
 * ,["7",".",".",".","2",".",".",".","6"]
 * ,[".","6",".",".",".",".","2","8","."]
 * ,[".",".",".","4","1","9",".",".","5"]
 * ,[".",".",".",".","8",".",".","7","9"]]
 * 
 * Output: true
 * 
 * Example 2:
 * Input: board = 
 * [["8","3",".",".","7",".",".",".","."]
 * ,["6",".",".","1","9","5",".",".","."]
 * ,[".","9","8",".",".",".",".","6","."]
 * ,["8",".",".",".","6",".",".",".","3"]
 * ,["4",".",".","8",".","3",".",".","1"]
 * ,["7",".",".",".","2",".",".",".","6"]
 * ,[".","6",".",".",".",".","2","8","."]
 * ,[".",".",".","4","1","9",".",".","5"]
 * ,[".",".",".",".","8",".",".","7","9"]]
 * Output: false
 * Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. 
 * Since there are two 8's in the top left 3x3 sub-box, it is invalid.
 * 
*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int N = 9;

        // hashset to record the status
        unordered_set<char> rows[N];
        unordered_set<char> cols[N];
        unordered_set<char> boxes[N];

        // Iterate over each (row, col) in the sudoku
        for (int row = 0; row < N; row++) {
            for (int col = 0; col < N; col++) {
                char val = board[row][col];

                // check if the position is filled with number
                if (val == '.') 
                    continue;
                
                // check if the number exists in the hash set for the current row, col or box.
                // If so, return false.
                // Else, update the corresponding set.

                // check the row
                if (rows[row].find(val) != rows[row].end())
                    return false;
                
                rows[row].insert(val);

                // check the column
                if (cols[col].find(val) != cols[col].end())
                    return false;
                
                cols[col].insert(val);

                // check the box
                int idx = (row / 3) * 3 + (col / 3);
                if (boxes[idx].find(val) != boxes[idx].end())
                    return false;

                boxes[idx].insert(val);
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    cout << boolalpha << sol.isValidSudoku(board) << endl;

    return 0;
}