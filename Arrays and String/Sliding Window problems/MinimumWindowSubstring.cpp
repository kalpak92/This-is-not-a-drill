/**
 * Given two strings s and t of lengths m and n respectively, 
 * return the minimum window substring of s such that every character in t (including duplicates) is included in the window. 
 * If there is no such substring, return the empty string "".
 * 
 * The testcases will be generated such that the answer is unique.
 * 
 * Example 1:
 * Input: s = "ADOBECODEBANC", t = "ABC"
 * Output: "BANC"
 * Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
 * 
 * Example 2:
 * Input: s = "a", t = "a"
 * Output: "a"
 * Explanation: The entire string s is the minimum window.
 * 
 * Example 3:
 * Input: s = "a", t = "aa"
 * Output: ""
 * Explanation: Both 'a's from t must be included in the window.
 * Since the largest window of s only has one 'a', return empty string.
 * 
 * Constraints:
 * m == s.length
 * n == t.length
 * 1 <= m, n <= 10^5
 * s and t consist of uppercase and lowercase English letters.
 * Follow up: Could you find an algorithm that runs in O(m + n) time?
*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size())
            return "";

        unordered_map<char, int> char_count;
        for (char c : t)
            char_count[c]++;
        
        int distinct_char_count = char_count.size();

        int left = 0;
        int right = 0;
        int result_len = INT_MAX;
        int start_idx = 0;
        string result = "";

        while (right < s.size()) {
            char c = s[right];
            if (char_count.contains(c)) {
                char_count[c]--;

                if (char_count[c] == 0)
                    distinct_char_count--;
            }
            right++;

            // Candidate Window found
            while (distinct_char_count == 0) {
                // Update the result
                // If the current window is smaller than the result window
                if (right - left < result_len) {
                    result_len = right - left;
                    start_idx = left;
                }

                // Shrink the window
                char temp = s[left];
                if (char_count.contains(temp)) {
                    char_count[temp]++;

                    if (char_count[temp] > 0)
                        distinct_char_count++;
                }
                left++;
                // Continue checking if the window is still valid
            }
        }
        return result_len == INT_MAX ? "" : s.substr(start_idx, result_len);
    }
};

int main() {
    Solution s;
    string s1 = "ADOBECODEBANC";
    string t1 = "ABC";
    cout << s.minWindow(s1, t1) << endl;

    string s2 = "a";
    string t2 = "a";
    cout << s.minWindow(s2, t2) << endl;

    string s3 = "a";
    string t3 = "aa";
    cout << s.minWindow(s3, t3) << endl;
    return 0;
}