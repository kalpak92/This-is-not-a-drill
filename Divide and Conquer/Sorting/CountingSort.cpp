/**
 * Counting Sort
*/


#include <iostream>
#include <vector>
#include <array>

using namespace std;

/**
 * Let's take the array [4, 2, 2, 8, 3, 3, 1] as an example.
 * 
 * 1. Find the maximum element in the array. In this case, the maximum element is 8.
 * 2. Create a count array to store the count of each element. The count array will be of size maxElement + 1.
 * 3. Store the count of each element in the count array.
 *      count = [0, 1, 2, 2, 1, 0, 0, 0, 1]
 * 4. Update the count array to store the prefix sum of the count of elements.
 *      count = [0, 1, 3, 5, 6, 6, 6, 6, 7]
 * 5. Create a result array to store the sorted elements.
 * 6. Traverse the array from right to left and place the elements in the result array based on the count array.
 * 7. Decrement the count of the element in the count array.
 * 
 * The detailed process is as follows:
 * i = 6, arr[i] = 1, count[1] = 1, result[0] = 1, count[1] = 0
 * i = 5, arr[i] = 3, count[3] = 5, result[4] = 3, count[3] = 4
 * i = 4, arr[i] = 3, count[3] = 4, result[3] = 3, count[3] = 3
 * i = 3, arr[i] = 8, count[8] = 7, result[6] = 8, count[8] = 6
 * i = 2, arr[i] = 2, count[2] = 3, result[2] = 2, count[2] = 2
 * i = 1, arr[i] = 2, count[2] = 2, result[1] = 2, count[2] = 1
 * i = 0, arr[i] = 4, count[4] = 6, result[5] = 4, count[4] = 5
 * 
*/

class Solution {
public:
    vector<int> countingSort(vector<int>& arr) {
        // Find the maximum element in the array
        int maxElement = *max_element(arr.begin(), arr.end());

        // Create a count array to store the count of each element
        vector<int> count(maxElement + 1, 0);

        // Store the count of each element
        for (int num : arr) {
            count[num]++;
        }

        // Update the count array to store the prefix sum of the count of elements.
        // The prefix sum of the count array is calculated to transform these frequencies into positions.
        // After the prefix sum is calculated, 
        // count[i] is the position where the element i should be places in the sorted output array.
        for (int i = 1; i < count.size(); i++) {
            count[i] += count[i - 1];
        }

        // Create a result array to store the sorted elements
        vector<int> result(arr.size());
        for (int i = arr.size() - 1; i >= 0; i--) {
            // When placeing the element in the result array, 
            // we substract by 1 from the count[arr[i]] to get the correct 0-based index.
            result[count[arr[i]] - 1] = arr[i];
            // We decrement count[arr[i]] to ensure that the next occurrence of the same element
            // is placed at the previous position.
            count[arr[i]]--;
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};
    vector<int> result = sol.countingSort(arr);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}