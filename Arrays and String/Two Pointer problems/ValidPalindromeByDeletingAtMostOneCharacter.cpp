/**
 * Given a string s, return true if the s can be palindrome after deleting at most one character from it.
 * 
 * Example 1:
 * Input: s = "aba"
 * Output: true
 * 
 * Example 2:
 * Input: s = "abca"
 * Output: true
 * Explanation: You could delete the character 'c'.
 * 
 * Example 3:
 * Input: s = "abc"
 * Output: false
 * 
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while(left < right) {
            // If the characters do not match
            // Check if string is validPalindrome by removing from either end
            // Return True, if either yields success
            if (s[left] != s[right]) {
                return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
            }
            
            // Continue incrmenting and decrementing the pointers from either end since the character matches
            left++;
            right--;
        }
        return true;
    }

private:
    // Check for isPalindrome within a given range
    bool isPalindrome(string s, int i, int j) {
        while(i < j) {
            if(s[i] != s[j])
                return false;
            
            i++;
            j--;
        }
        return true;
    }
};

void printResult(bool result) {
    cout << (result ? "true" : "false") << endl;
}

int main() {
    Solution s;
    string str = "aba";
    printResult(s.validPalindrome(str));

    str = "abca";
    printResult(s.validPalindrome(str));

    str = "abc";
    printResult(s.validPalindrome(str));
}