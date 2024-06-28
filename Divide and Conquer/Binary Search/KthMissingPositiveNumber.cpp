/**
 * Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.
 * Return the kth positive integer that is missing from this array.
 * 
 * Example 1:
 * Input: arr = [2,3,4,7,11], k = 5
 * Output: 9
 * Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.
 * 
 * Example 2:
 * Input: arr = [1,2,3,4], k = 2
 * Output: 6
 * Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findKthPositiveBruteForce(vector<int>& arr, int k) {
        // Number of missing elements between to integers
        // arr[i + 1] - arr[i] - 1

        // 
        if (k <= arr[0] - 1)
            return k;
        
        // decrease k by the number of positive integers which are missing before the array starts
        k -= arr[0] - 1;

        for (int i = 0; i < arr.size() - 1; i++) {
            int count_missing_numbers = arr[i + 1] - arr[i] - 1;  // numbers missing between arr[i] and arr[i + 1]

            if (k <= count_missing_numbers) {
                // this means the missing number is between arr[i] and arr[i + 1]
                return arr[i] + k;
            }

            // continue while reducing k by the count_missing_numbers
            k -= count_missing_numbers;
        }

        // the number of missing number is greater than arr[arr.size() - 1]
        return arr[arr.size() - 1] + k;
    }

    int findKthPositive(vector<int>& arr, int k) {
        // Number of missing elements between to integers
        // arr[i + 1] - (arr[i] + 1)

        int left = 0;
        int right = arr.size() - 1;

        while (left <= right) {
            int mid = left + (right - left)/2;
            // mid + 1 since given arr is an array of positive integers and indexing is 0 based.
            // Originally (mid + 1) numbers should have been there.
            // The delta between the current and (mid + 1) says the count_missing_numbers
            int count_missing_numbers = arr[mid] - (mid + 1);

            if (count_missing_numbers < k) {
                // eliminate left search space
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        // At the end, left = right + 1
        // The kth missing number is in between arr[right] and arr[left].
        // The number of missing integers before arr[right] = arr[right] - (right + 1).
        // So, the number to return is
        // arr[right] + k - missing integers before arr[right]
        // arr[right] + k - arr[right] + (right + 1)
        // right + 1 + k
        // Since, left = right + 1, we return left + k;
        return left + k;
    }
};


int main() {
    Solution sol;
    vector<int> arr = {2,3,4,7,11};
    int k = 5;

    cout << "Kth missing positive number: " << sol.findKthPositive(arr, k) << endl;

    arr = {1,2,3,4};
    k = 2;

    cout << "Kth missing positive number: " << sol.findKthPositive(arr, k) << endl;

    return 0;
}