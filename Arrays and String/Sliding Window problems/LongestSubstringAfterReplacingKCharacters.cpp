/**
 * You are given a string s and an integer k. 
 * You can choose any character of the string and change it to any other uppercase English character. 
 * You can perform this operation at most k times.
 * 
 * Return the length of the longest substring containing the same letter you can get after performing the above operations.
 * 
 * Example 1:
 * Input: s = "ABAB", k = 2
 * Output: 4
 * Explanation: Replace the two 'A's with two 'B's or vice versa.
 * 
 * Example 2:
 * Input: s = "AABABBA", k = 1
 * Output: 4
 * Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
 * The substring "BBBB" has the longest repeating letters, which is 4.
 * 
 * There may exists other ways to achieve this answer too.
 * 
 * Constraints:
 * 1 <= s.length <= 10^5
 * s consists of only uppercase English letters.
 * 0 <= k <= s.length
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> char_count;
        int result = 0;
        int max_char_count = 0;
        int left = 0;
        int right = 0;

        while (right < s.size()) {
            char c = s[right];
            char_count[c]++;

            max_char_count = max(max_char_count, char_count[c]);

            // Window Size + max_char_count > k means we have considered changing more than k characters
            // So slide the window and meet the condition
            while (right - left + 1 - max_char_count > k) {
                char_count[s[left]]--;
                left++;
            }

            result = max(result, right - left + 1);
            right++;
        }
        return result;
    }
};

int main() {
    Solution objCharacterReplacement;
    string s = "AABABBA";
    int k = 1;
    cout << objCharacterReplacement.characterReplacement(s, k) << endl;
    return 0;
}