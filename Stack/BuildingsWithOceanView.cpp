/**
 * There are n buildings in a line. You are given an integer array heights of size n that represents the heights of the buildings in the line.
 * 
 * The ocean is to the right of the buildings. 
 * A building has an ocean view if the building can see the ocean without obstructions. 
 * Formally, a building has an ocean view if all the buildings to its right have a smaller height.
 * 
 * Return a list of indices (0-indexed) of buildings that have an ocean view, sorted in increasing order.
 * 
 * Example 1:
 * Input: heights = [4,2,3,1]
 * Output: [0,2,3]
 * Explanation: Building 1 (0-indexed) does not have an ocean view because building 2 is taller.
 * 
 * Example 2:
 * Input: heights = [4,3,2,1]
 * Output: [0,1,2,3]
 * Explanation: All the buildings have an ocean view.
 * 
 * Example 3:
 * Input: heights = [1,3,2,4]
 * Output: [3]
 * Explanation: Only building 3 has an ocean view.
 * 
 * Constraints:
 * 1 <= heights.length <= 10^5
 * 1 <= heights[i] <= 10^9
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> next_greater_element(heights.size(), -1);
        stack<int> decreasing_stack;

        for (int i = 0; i < heights.size(); i++) {
            while(!decreasing_stack.empty() && heights[i] >= heights[decreasing_stack.top()]) {
                next_greater_element[decreasing_stack.top()] = heights[i];
                decreasing_stack.pop();
            }
            decreasing_stack.push(i);
        }

        vector<int> result;
        for (int i = 0; i < next_greater_element.size(); i++) {
            if (next_greater_element[i] == -1)
                result.push_back(i);
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> heights = {4, 2, 3, 1};
    vector<int> result = s.findBuildings(heights);
    cout << "Output: ";
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << endl;

    heights = {4, 3, 2, 1};
    result = s.findBuildings(heights);
    cout << "Output: ";
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << endl;

    heights = {1, 3, 2, 4};
    result = s.findBuildings(heights);
    cout << "Output: ";
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << endl;
    return 0;
}