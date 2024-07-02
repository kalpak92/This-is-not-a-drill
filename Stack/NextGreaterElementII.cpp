/**
 * Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), 
 * return the next greater number for every element in nums.
 * 
 * The next greater number of a number x is the first greater number to its traversing-order next in the array, 
 * which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.
 * 
 * Example 1:
 * Input: nums = [1,2,1]
 * Output: [2,-1,2]
 * Explanation: The first 1's next greater number is 2; 
 * 
 * The number 2 can't find next greater number. 
 * The second 1's next greater number needs to search circularly, which is also 2.
 * 
 * Example 2:
 * Input: nums = [1,2,3,4,3]
 * Output: [2,3,4,-1,4]
 * 
 * Constraints:
 * 1 <= nums.length <= 10^4
 * -10^9 <= nums[i] <= 10^9
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // Initialize the result vector with -1.
        vector<int> result(nums.size(), -1);
        stack<int> decreasing_stack;

        // Need to adhere to the constraint for circular array.
        // Loop the array to twice the size and use the % operator for correct indexing
        for (int i = 0; i < nums.size() * 2; i++) {
            while (!decreasing_stack.empty() && nums[i % nums.size()] > nums[decreasing_stack.top()]) {
                // Need to remove elements from the stack to maintain the invariant.
                // However, current nums[i] is the NGE for top element of the stack.
                // Store that in the result.
                result[decreasing_stack.top()] = nums[i % nums.size()];
                decreasing_stack.pop();
            }

            decreasing_stack.push(i % nums.size());     // store the correct index in the stack
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 1};
    vector<int> result = s.nextGreaterElements(nums);
    cout << "Output: ";
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << endl;

    nums = {1, 2, 3, 4, 3};
    result = s.nextGreaterElements(nums);
    cout << "Output: ";
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << endl;

    return 0;
}