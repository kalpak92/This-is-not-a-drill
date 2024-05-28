/**
 * Given an array of integers and a number k, find the maximum sum of a subarray of size k. 
 * 
 * Examples: 
 * Input  : arr[] = {100, 200, 300, 400},  k = 2
 * Output : 700
 * 
 * Input  : arr[] = {1, 4, 2, 10, 23, 3, 1, 0, 20}, k = 4 
 * Output : 39
 * Explanation: We get maximum sum by adding subarray {4, 2, 10, 23} of size 4.
 * 
 * Input  : arr[] = {2, 3}, k = 3
 * Output : Invalid
 * Explanation: There is no subarray of size 3 as size of whole array is 2. 
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSumSubarraySizeKUnoptimized(vector<int>& nums, int k) {
        int result = INT_MIN;;

        for (int i = 0; i < nums.size() - k + 1; i++) {
            int current_sum = 0;
            for (int j = 0; j < k; j++) {
                current_sum += nums[i + j];
            }
            result = max(result, current_sum);
        }
        return result;
    }

    int maxSumSubarraySizeK(vector<int>& nums, int k) {
        int result = INT_MIN;
        int window_sum = 0;

        for (int i = 0; i < k; i++) {
            window_sum += nums[i];
        }

        result = window_sum;

        for (int i = k; i < nums.size(); i++) {
            window_sum += nums[i] - nums[i - k];
            result = max(result, window_sum);
        }

        return result;
    }
};

void printVector(vector<int>& nums) {
    for (int num : nums)
        cout << num << " ";
    cout << endl;
}

int main() {
    Solution sol;
    vector<int> nums = {100, 200, 300, 400};
    int k = 2;
    printVector(nums);
    cout << sol.maxSumSubarraySizeKUnoptimized(nums, k) << endl;
    cout << sol.maxSumSubarraySizeK(nums, k) << endl;

    nums = {1, 4, 2, 10, 23, 3, 1, 0, 20};
    k = 4;
    printVector(nums);
    cout << sol.maxSumSubarraySizeKUnoptimized(nums, k) << endl;
    cout << sol.maxSumSubarraySizeK(nums, k) << endl;
    return 0;
}