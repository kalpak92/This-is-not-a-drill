/**
 * Given a string, find the length of the longest substring in it with no more than K distinct characters.
 * 
 * Example 1:
 * Input: String="araaci", K=2
 * Output: 4
 * Explanation: The longest substring with no more than '2' distinct characters is "araa".
 * 
 * Example 2:
 * Input: String="araaci", K=1
 * Output: 2
 * Explanation: The longest substring with no more than '1' distinct characters is "aa".
 * 
 * Example 3:
 * Input: String="cbbebi", K=3
 * Output: 5
 * Explanation: The longest substrings with no more than '3' distinct characters are "cbbeb" & "bbebi".
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestSubstringWithKDistinctCharacters(string s, int k) {
        if (s.empty() || k <= 0)
            return 0;

        int result = INT_MIN;
        unordered_map<char, int> char_count;
        int left = 0;
        int right = 0;

        while (right < s.size()) {
            char c = s[right];
            char_count[c]++;

            if (char_count.size() < k ) {
                right++;
            } else if (char_count.size() == k) {
                result = max(result, right - left + 1);
                right++;
            } else {
                while (char_count.size() > k) {
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
    Solution sol;
    string s = "araaci";
    cout << "Given string: " << s << endl;
    cout << "The longest substring with no more than 2 distinct characters is: " << sol.longestSubstringWithKDistinctCharacters(s, 2) << endl;

    s = "araaci";
    cout << "Given string: " << s << endl;
    cout << "The longest substring with no more than 1 distinct characters is: " << sol.longestSubstringWithKDistinctCharacters(s, 1) << endl;

    s = "cbbebi";
    cout << "Given string: " << s << endl;
    cout << "The longest substring with no more than 3 distinct characters is: " << sol.longestSubstringWithKDistinctCharacters(s, 3) << endl;

    return 0;
}