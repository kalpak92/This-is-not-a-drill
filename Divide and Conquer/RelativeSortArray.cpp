/**
 * Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.
 * Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2. 
 * Elements that do not appear in arr2 should be placed at the end of arr1 in ascending order.
 * 
 * Example 1:
 * Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
 * Output: [2,2,2,1,4,3,3,9,6,7,19]
 * 
 * Example 2:
 * Input: arr1 = [28,6,22,8,44,17], arr2 = [22,28,8,6]
 * Output: [22,28,8,6,17,44]
 * 
 * Constraints:
 * 1 <= arr1.length, arr2.length <= 1000
 * 0 <= arr1[i], arr2[i] <= 1000
 * All the elements of arr2 are distinct.
 * Each arr2[i] is in arr1.
*/

#include <iostream>
#include <vector>
#include <array>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> relativeSortArrayUsingCountingSort(vector<int>& arr1, vector<int>& arr2) {
        array<int, 1001> count;
        for (int num : arr1)
            count[num]++;

        // Place the numbers based on the relative occurrence of it in arr2
        // For each number, ensure placing it until the count of it is == 0
        // idx acts as the insertion pointer
        int idx = 0;
        for (int num : arr2) {
            while (count[num] > 0) {
                arr1[idx] = num;
                idx++;
                count[num]--;
            }
        }

        // All the numbers contained in arr2 has been placed in arr1
        // Now, put the remaining element in arr1
        // Note that, the ascending order criteria is preserved since we traverse it from begin to end
        // For each element, ensure all the occurrences of the number are placed back into arr1

        for (int num = 0; num < count.size(); num++) {
            while (count[num] > 0) {
                arr1[idx] = num;
                idx++;
                count[num]--;
            }
        }
        return arr1;
    }

    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> countOfNum;
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int num : arr1) {
            countOfNum[num]++;
        }

        // Place the numbers based on the relative occurrence of it in arr2
        // For each number, ensure placing it until the count of it is == 0
        // idx acts as the insertion pointer
        int idx = 0;
        for (int num : arr2) {
            while (countOfNum[num] > 0) {
                arr1[idx] = num;
                idx++;
                countOfNum[num]--;
            }
        }

        // Create a minHeap of the remaining numbers that are not in arr2
        // This gets the numbers in ascending order
        for (auto& pair : countOfNum) {
            if (pair.second > 0) {
                // Iterate of the frequency of the numbers
                for (int j = 0; j < pair.second; ++j) {
                    minHeap.push(pair.first);
                }
            }
        }

        while(!minHeap.empty()) {
            arr1[idx++] = minHeap.top();
            minHeap.pop();
        }

        return arr1;
    }
};

void runRelativeSortArray() {
    Solution s;
    vector<tuple<vector<int>, vector<int>, vector<int>>> testCases {
        {{2,3,1,3,2,4,6,7,9,2,19}, {2,1,4,3,9,6}, {2,2,2,1,4,3,3,9,6,7,19}},
        {{28,6,22,8,44,17}, {22,28,8,6}, {22,28,8,6,17,44}}
    };

    for (auto& tc : testCases) {
        vector<int> arr1 = get<0>(tc);
        vector<int> arr2 = get<1>(tc);
        vector<int> expected = get<2>(tc);

        vector<int> result = s.relativeSortArray(arr1, arr2);
        cout << "Result: " << (result == expected ? "PASS": "FAIL") << endl;
    }
}

int main() {
    runRelativeSortArray();
    return 0;
}