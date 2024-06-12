/**
 * You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.
 * Return the index of the peak element.
 * 
 * Your task is to solve it in O(log(n)) time complexity.
 * 
 * Example 1:
 * Input: arr = [0,1,0]
 * Output: 1
 * 
 * Example 2:
 * Input: arr = [0,2,1,0]
 * Output: 1
 * 
 * Example 3:
 * Input: arr = [0,10,5,2]
 * Output: 1
 * 
 * Constraints:
 * 3 <= arr.length <= 10^5
 * 0 <= arr[i] <= 10^6
 * 
 * arr is guaranteed to be a mountain array.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        if (arr.size() == 1)
            return arr[0];

        int size_of_arr = arr.size();

        if (arr[0] > arr[1])
            return 0;
        
        if (arr[size_of_arr - 1] > arr[size_of_arr - 2])
            return size_of_arr - 1;
        
        int left = 1;
        int right = arr.size() - 2;

        while (left <= right) {
            int mid = left + ((right - left) / 2);

            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
                return mid;
            else if (arr[mid] < arr[mid + 1]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<int> arr = {0, 2, 1, 0};
    cout << s.peakIndexInMountainArray(arr) << endl;
    return 0;
}