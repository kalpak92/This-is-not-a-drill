/**
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * Every close bracket has a corresponding open bracket of the same type.
 * 
 * Example 1:
 * Input: s = "()"
 * Output: true
 * 
 * Example 2:
 * Input: s = "()[]{}"
 * Output: true
 * 
 * Example 3:
 * Input: s = "(]"
 * Output: false
 * 
 * Constraints:
 * 1 <= s.length <= 10^4
 * s consists of parentheses only '()[]{}'.
 */

#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.length() % 2 == 1)
            return false;
        
        stack<char> stack;

        for (int i = 0; i < s.length(); i++) {
            switch(s[i]) {
                case '(' : stack.push(')');
                    break;
                case '{' : stack.push('}');
                    break;
                case '[' : stack.push(']');
                    break;
                case ')' :
                case '}' :
                case ']' :
                    if (stack.empty() || stack.top() != s[i])
                        return false;
                    else
                        stack.pop();
            }
        }
        return stack.empty();
    }
};


int main() {
    Solution s;
    string str = "()";
    cout << "Result: " << s.isValid(str) << endl;

    str = "()[]{}";
    cout << "Result: " << s.isValid(str) << endl;

    str = "(]";
    cout << "Result: " << s.isValid(str) << endl;

    str = "([)]";
    cout << "Result: " << s.isValid(str) << endl;

    str = "{[]}";
    cout << "Result: " << s.isValid(str) << endl;

    str = "(([]){})";
    cout << "Result: " << s.isValid(str) << endl;

    str = "(([]){}){";
    cout << "Result: " << s.isValid(str) << endl;
}
