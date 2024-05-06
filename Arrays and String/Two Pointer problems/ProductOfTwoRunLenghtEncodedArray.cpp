/**
 * Run-length encoding is a compression algorithm that allows for an integer array nums with many segments of consecutive repeated numbers to be represented by a (generally smaller) 2D array encoded. 
 * Each encoded[i] = [vali, freqi] describes the ith segment of repeated numbers in nums where vali is the value that is repeated freqi times.
 * 
 * For example, nums = [1,1,1,2,2,2,2,2] is represented by the run-length encoded array encoded = [[1,3],[2,5]]. 
 * Another way to read this is "three 1's followed by five 2's".
 * The product of two run-length encoded arrays encoded1 and encoded2 can be calculated using the following steps:
 * 
 * Expand both encoded1 and encoded2 into the full arrays nums1 and nums2 respectively.
 * Create a new array prodNums of length nums1.length and set prodNums[i] = nums1[i] * nums2[i].
 * Compress prodNums into a run-length encoded array and return it.
 * You are given two run-length encoded arrays encoded1 and encoded2 representing full arrays nums1 and nums2 respectively. 
 * Both nums1 and nums2 have the same length. 
 * Each encoded1[i] = [vali, freqi] describes the ith segment of nums1, and each encoded2[j] = [valj, freqj] describes the jth segment of nums2.
 * 
 * Return the product of encoded1 and encoded2.
 * Note: Compression should be done such that the run-length encoded array has the minimum possible length.
 * 
 * Example 1:
 * Input: encoded1 = [[1,3],[2,3]], encoded2 = [[6,3],[3,3]]
 * Output: [[6,6]]
 * Explanation: encoded1 expands to [1,1,1,2,2,2] and encoded2 expands to [6,6,6,3,3,3].
 * prodNums = [6,6,6,6,6,6], which is compressed into the run-length encoded array [[6,6]].
 * 
 * Example 2:
 * Input: encoded1 = [[1,3],[2,1],[3,2]], encoded2 = [[2,3],[3,3]]
 * Output: [[2,3],[6,1],[9,2]]
 * Explanation: encoded1 expands to [1,1,1,2,3,3] and encoded2 expands to [2,2,2,3,3,3].
 * prodNums = [2,2,2,6,9,9], which is compressed into the run-length encoded array [[2,3],[6,1],[9,2]].
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> findRLEArray(vector<vector<int>>& encoded1, vector<vector<int>>& encoded2) {
        vector<vector<int>> result;

        int encoded1Idx = 0;
        int encoded2Idx = 0;

        while (encoded1Idx < encoded1.size() && encoded2Idx < encoded2.size()) {
            vector<int> pair1 = encoded1[encoded1Idx];
            vector<int> pair2 = encoded2[encoded2Idx];

            // Calculate the product and candidate frequency
            int product = pair1[0] * pair2[0];
            int frequency = min(pair1[1], pair2[1]);

            // Subtract the frequency from the current pair
            // Make sure to make the change in the original array
            // Otherwise the frequency will be lost after the current iteration
            encoded1[encoded1Idx][1] -= frequency;
            encoded2[encoded2Idx][1] -= frequency;

            // Move the pointers if the frequency is 0
            if (pair1[1] == 0)
                encoded1Idx++;
            if (pair2[1] == 0)
                encoded2Idx++;
            
            // Append only if the result is empty or the current product is different than the last product
            if (result.empty() || result.back()[0] != product) {
                // Append a vector encoded with the product and its frequency
                vector<int> temp{product, frequency};
                result.emplace_back(temp);
            } else {
                // result is not empty
                // Last element in result has the same product
                // So, we need to update the frequency
                result.back()[1] += frequency;
            }
        }
        return result;
    }
};

void printVectorOfVector(const vector<vector<int>>& encoded) {
    for (const vector<int>& pair : encoded) {
        cout << "[" << pair[0] << ", " << pair[1] << "] ";
    }
    cout << endl;
}

int main() {
    Solution solution;
    vector<vector<int>> encoded1 = {{1, 3}, {2, 3}};
    vector<vector<int>> encoded2 = {{6, 3}, {3, 3}};
    cout << "Test case 1: " << endl;
    printVectorOfVector(encoded1);
    printVectorOfVector(encoded2);
    vector<vector<int>> result = solution.findRLEArray(encoded1, encoded2);
    cout << "Result: ";
    printVectorOfVector(result);
    cout << endl;

    vector<vector<int>> encoded3 = {{1, 3}, {2, 1}, {3, 2}};
    vector<vector<int>> encoded4 = {{2, 3}, {3, 3}};
    cout << "Test case 2: " << endl;
    printVectorOfVector(encoded3);
    printVectorOfVector(encoded4);
    vector<vector<int>> result2 = solution.findRLEArray(encoded3, encoded4);
    cout << "Result: ";
    printVectorOfVector(result2);
    cout << endl;

    vector<vector<int>> encoded5 = {{2,2},{5,5},{1,5},{2,5},{4,2},{5,3},{1,2},{4,3},{3,2},{2,3}};
    vector<vector<int>> encoded6 = {{1,1},{4,1},{3,3},{5,3},{1,4},{5,1},{4,1},{5,3},{3,5},{2,1},{1,2},{3,1},{2,1},{4,3},{3,1},{2,1}};
    cout << "Test case 3: " << endl;
    printVectorOfVector(encoded5);
    printVectorOfVector(encoded6);
    vector<vector<int>> result3 = solution.findRLEArray(encoded5, encoded6);
    cout << "Result: ";
    printVectorOfVector(result3);
    cout << endl;

    return 0;
}