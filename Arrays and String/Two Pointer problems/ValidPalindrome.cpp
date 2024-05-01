/**
 * A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. 
 * Alphanumeric characters include letters and numbers.
 * 
 * Given a string s, return true if it is a palindrome, or false otherwise.
 * 
 * Example 1:
 * Input: s = "A man, a plan, a canal: Panama"
 * Output: true
 * Explanation: "amanaplanacanalpanama" is a palindrome.
 * 
 * Example 2:
 * Input: s = "race a car"
 * Output: false
 * Explanation: "raceacar" is not a palindrome.
 * 
 * Example 3:
 * Input: s = " "
 * Output: true
 * Explanation: s is an empty string "" after removing non-alphanumeric characters.
 * Since an empty string reads the same forward and backward, it is a palindrome.
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty())
            return true;

        // Start traversing from both ends
        int left = 0;
        int right = s.size() - 1;

        while(left < right) {
            // Ignore non-alphanumeric characters by continuing to traverse further.
            // Check for left < right invariant; otherwise it will increase beyond the length of the string
            while(left < right && !isalnum(s[left]))
                left++;

            while(left < right && !isalnum(s[right]))
                right--;

            // Palindrome condition violated.
            if(tolower(s[left]) != tolower(s[right]))
                return false;
            
            left++;
            right--;
        }
        return true;
    }
};

void printResult(bool result) {
    cout << (result ? "true" : "false") << endl;
}

int main() {
    Solution s;
    string str = "A man, a plan, a canal: Panama";
    printResult(s.isPalindrome(str));

    str = "race a car";
    printResult(s.isPalindrome(str));

    str = " ";
    printResult(s.isPalindrome(str));
}