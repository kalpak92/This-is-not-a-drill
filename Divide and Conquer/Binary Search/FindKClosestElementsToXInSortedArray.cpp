/**
 * Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. 
 * The result should also be sorted in ascending order.
 * 
 * An integer a is closer to x than an integer b if:
 * |a - x| < |b - x|, or
 * |a - x| == |b - x| and a < b
 * 
 * Example 1:
 * Input: arr = [1,2,3,4,5], k = 4, x = 3
 * Output: [1,2,3,4]
 * 
 * Example 2:
 * Input: arr = [1,2,3,4,5], k = 4, x = -1
 * Output: [1,2,3,4]
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> result;

        // base case
        if (arr.size() == k)
            return vector<int>(arr.begin(), arr.begin() + k);

        // Binary Search to find the closest element.
        // The main idea is to find out the lower bound for the result of size k.
        // Initially, the numbers between [left, right] are candidates.
        // left == 0 and right == arr.size() - 1 - k. ( We do a '-k' to prevent out of bounds in the check)
        // Now,
        // If (x - arr[mid] > arr[mid + k] - x) is used to compare arr[mid] and arr[mid + k] with respect to x
        //      If arr[mid + k] is closer to x than arr[mid], 
        //      then arr[mid], arr[mid - 1], arr[mid - 2] ... can never be the candidate list since it is even further out.
        //      So, eliminate the left search space.
        // Else,
        //     arr[mid] is closer to x than arr[mid + k]
        //     Then, arr[mid + 1], arr[mid + 2], ... arr[mid + k] can never be in the candidate.
        //     Eliminate the right search space. 
        int left = 0;
        int right = arr.size() - 1 - k;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // x - A[mid] > A[mid + k] - x, need to move window go right
            // -------A[mid]------------------x---A[mid + k]----------
            // -------A[mid]---------------------A[mid + k]----x------
            if ((x - arr[mid]) > (arr[mid + k] - x))
                left = mid + 1;
            else 
            // x - A[mid] < A[mid + k] - x, need to move window go left
            // -------x----A[mid]-----------------A[mid + k]----------
            // -------A[mid]----x-----------------A[mid + k]----------
                right = mid - 1;
        }

        // Left now points to the start of the candidate.
        // Include k elements from left, and return
        return vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    int x = 3;

    vector<int> result = sol.findClosestElements(arr, k, x);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    arr = {1, 2, 3, 4, 5};
    k = 4;
    x = -1;

    result = sol.findClosestElements(arr, k, x);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    arr = {0,1,2,2,2,3,6,8,8,9};
    k = 5;
    x = 9;
    result = sol.findClosestElements(arr, k, x);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}