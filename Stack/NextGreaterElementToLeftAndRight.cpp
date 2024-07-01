/**
 * Given an array of integers, find the next greater element to the right and left for every element in the array.
 * If the next greater element is not found, return -1.
 * 
 * Example 1:
 * Input:   [2, 1, 2, 4, 3]
 * Output:  The next greater elements to the right are [4, 2, 4, -1, -1]
 *          The next greater elements to the left are [-1, 2, -1, -1, 4]
 * 
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElementToRight(const vector<int>& nums) {
        vector<int> result(nums.size(), -1);
        stack<int> decreasing_stack;

        for (int i = 0; i < nums.size(); i++) {
            while (!decreasing_stack.empty() && nums[i] >= nums[decreasing_stack.top()]) {
                // currrent element is greater than the top of the stack.
                result[decreasing_stack.top()] = nums[i];
                decreasing_stack.pop();
            }
            decreasing_stack.push(i);
        }
        return result;
    }

    vector<int> nextGreaterElementToLeft(const vector<int>& nums) {
        vector<int> result(nums.size(), -1);
        stack<int> decreasing_stack;

        for (int i = 0; i < nums.size(); i++) {
            while (!decreasing_stack.empty() && nums[i] >= nums[decreasing_stack.top()]) {
                // currrent element is greater than the top of the stack.
                decreasing_stack.pop();
            }
        
            if (!decreasing_stack.empty())
                result[i] = nums[decreasing_stack.top()];
        
            decreasing_stack.push(i);
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {2, 1, 2, 4, 3};
    cout << "Input: ";
    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";
    
    cout << "Next Greater Element to the Right: " << endl;
    vector<int> result = s.nextGreaterElementToRight(nums);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << endl;

    cout << "Next Greater Element to the Left: " << endl;
    result = s.nextGreaterElementToLeft(nums);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << endl;
    return 0;
}