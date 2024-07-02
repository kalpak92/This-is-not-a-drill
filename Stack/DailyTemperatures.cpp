/**
 * Given an array of integers temperatures represents the daily temperatures, 
 * return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. 
 * 
 * If there is no future day for which this is possible, keep answer[i] == 0 instead.
 * 
 * Example 1:
 * Input: temperatures = [73,74,75,71,69,72,76,73]
 * Output: [1,1,4,2,1,1,0,0]
 * 
 * Example 2:
 * Input: temperatures = [30,40,50,60]
 * Output: [1,1,1,0]
 * 
 * Example 3:
 * Input: temperatures = [30,60,90]
 * Output: [1,1,0]
 * 
 * Constraints:
 * 1 <= temperatures.length <= 10^5
 * 30 <= temperatures[i] <= 100
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        stack<int> decreasing_stack;

        for (int i = 0; i < temperatures.size(); i++) {
            while(!decreasing_stack.empty() && temperatures[i] > temperatures[decreasing_stack.top()]) {
                // result has the distance between the NGE and the element itself.
                // current element is the NGE for the element in the stack.
                // so, i - decreasing_stack.top() gives the time to wait for warmer temperature.
                result[decreasing_stack.top()] = i - decreasing_stack.top();
                decreasing_stack.pop();
            }

            decreasing_stack.push(i);
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> temperatures = {73,74,75,71,69,72,76,73};
    vector<int> result = s.dailyTemperatures(temperatures);
    cout << "Output: ";
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << endl;

    temperatures = {30,40,50,60};
    result = s.dailyTemperatures(temperatures);
    cout << "Output: ";
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << endl;

    temperatures = {30,60,90};
    result = s.dailyTemperatures(temperatures);
    cout << "Output: ";
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << endl;

    return 0;
}