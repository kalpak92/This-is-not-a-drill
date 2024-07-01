/**
 * Given a string s of '(' , ')' and lowercase English characters.
 * 
 * Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) 
 * so that the resulting parentheses string is valid and return any valid string.
 * 
 * Formally, a parentheses string is valid if and only if:
 *      It is the empty string, contains only lowercase characters, or
 *      It can be written as AB (A concatenated with B), where A and B are valid strings, or
 *      It can be written as (A), where A is a valid string.
 * 
 * Example 1:
 * Input: s = "lee(t(c)o)de)"
 * Output: "lee(t(c)o)de"
 * Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
 * 
 * Example 2:
 * Input: s = "a)b(c)d"
 * Output: "ab(c)d"
 * 
 * Example 3:
 * Input: s = "))(("
 * Output: ""
 * Explanation: An empty string is also valid.
 */

#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    // Time Complexity : O(n)
    // Space Complexity : O(n)
    string minRemoveToMakeValidExtraSpace(string s) {
        stack<int> stack;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(')
                stack.push(i);          // push index open parenthesis to the stack
            if (s[i] == ')') {
                if (!stack.empty())
                    stack.pop();        // matching '(' exists. Pop that.
                else
                    s[i] = '*';         // mark the char with a placeholder for removal.
            }
        }

        // Now that stack has the indices of '(' that never had a corresponding ')'.
        // Mark those indices with a placeholder.
        while (!stack.empty()) {
            s[stack.top()] = '*';
            stack.pop();
        }

        s.erase(remove(s.begin(), s.end(), '*'), s.end());
        return s;
    }

    // Time Complexity : O(n)
    // Space Complexity : O(1)
    string minRemoveToMakeValidOptimized(string s) {
        int count = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                count++;
            else if (s[i] == ')') {
                if (count == 0)
                    s[i] = '*';
                else
                    count--;    // count is positive, which means '(' counterpart exists
            }
        }

        count = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == ')')
                count++;
            else if (s[i] == '(') {
                if (count == 0)
                    s[i] = '*';
                else
                    count--;    // count is positive, which means ')' counterpart exists
            }
        }

        s.erase(remove(s.begin(), s.end(), '*'), s.end());
        return s;
    }
};

int main() {
    Solution s;
    string str = "lee(t(c)o)de)";
    cout << "Result: " << s.minRemoveToMakeValidExtraSpace(str) << endl;
    cout << "Result: " << s.minRemoveToMakeValidOptimized(str) << endl;

    str = "a)b(c)d";
    cout << "Result: " << s.minRemoveToMakeValidExtraSpace(str) << endl;
    cout << "Result: " << s.minRemoveToMakeValidOptimized(str) << endl;

    str = "))((";
    cout << "Result: " << s.minRemoveToMakeValidExtraSpace(str) << endl;
    cout << "Result: " << s.minRemoveToMakeValidOptimized(str) << endl;

    return 0;
}