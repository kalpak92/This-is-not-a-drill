/**
 * Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).
 * 
 * Return the running sum of nums.
 * 
 * Example 1:
 * Input: nums = [1,2,3,4]
 * Output: [1,3,6,10]
 * Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].
 * 
 * Example 2:
 * Input: nums = [1,1,1,1,1]
 * Output: [1,2,3,4,5]
 * Explanation: Running sum is obtained as follows: [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1].
 * 
 * Example 3:
 * Input: nums = [3,1,2,10,1]
 * Output: [3,4,6,16,17]
 * 
 * Constraints:
 * 1 <= nums.length <= 1000
 * -10^6 <= nums[i] <= 10^6
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        if (nums.empty())
            return {};

        vector<int> result(nums.size());
        result[0] = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            result[i] = result[i - 1] + nums[i];
        }

        return result;
    }
};

void printVector(const vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 4};
    vector<int> result = solution.runningSum(nums);
    printVector(result);

    nums = {1, 1, 1, 1, 1};
    result = solution.runningSum(nums);
    printVector(result);

    nums = {3, 1, 2, 10, 1};
    result = solution.runningSum(nums);
    printVector(result);

    return 0;
}