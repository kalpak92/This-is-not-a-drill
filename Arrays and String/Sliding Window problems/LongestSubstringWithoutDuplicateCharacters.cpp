/**
 * Given a string s, find the length of the longest substring without repeating characters.
 * 
 * Example 1:
 * Input: s = "abcabcbb"
 * Output: 3
 * Explanation: The answer is "abc", with the length of 3.
 * 
 * Example 2:
 * Input: s = "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * 
 * Example 3:
 * Input: s = "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3.
 * Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 * 
 * Constraints:
 * 0 <= s.length <= 5 * 10^4
 * s consists of English letters, digits, symbols and spaces.
*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
            return 0;

        unordered_map<char, int> char_count;
        int result = INT_MIN;
        int left = 0;
        int right = 0;

        while (right < s.size()) {
            char c = s[right];
            char_count[c]++;

            // if the number of characters in the window == size of unordered_map
            // characters are unique
            if (char_count.size() == right - left + 1) {
                result = max(result, right - left + 1);
                right++;
            } else if (char_count.size() < right - left + 1) {
                // Number of unique characters are lesser than the window size 
                // This means there are duplicate characters
                // Slide the window from the left while removing duplicate characters
                while (char_count.size() < right - left + 1) {
                    char_count[s[left]]--;

                    if (char_count[s[left]] == 0)
                        char_count.erase(s[left]);
                    
                    left++;
                }
                right++;
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    cout << s.lengthOfLongestSubstring("abcabcbb") << endl;
    cout << s.lengthOfLongestSubstring("bbbbb") << endl;
    cout << s.lengthOfLongestSubstring("pwwkew") << endl;
    return 0;
}