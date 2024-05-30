/**
 * Given a string s, return the length of the longest substring that contains at most two distinct characters.
 * 
 * Example 1:
 * Input: s = "eceba"
 * Output: 3
 * Explanation: The substring is "ece" which its length is 3.
 * 
 * Example 2:
 * Input: s = "ccaabbb"
 * Output: 5
 * Explanation: The substring is "aabbb" which its length is 5.
 * 
 * Constraints:
 * 1 <= s.length <= 10^5
 * s consists of English letters.
*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if (s.empty())
            return 0;
        
        unordered_map<char, int> char_count;
        int result = 0;
        int left = 0;
        int right = 0;

        while (right < s.size()) {
            char c = s[right];
            char_count[c]++;

            if (char_count.size() <= 2) {
                // candidate found
                result = max(result, right - left + 1);
                right++;
            } else if (char_count.size() > 2) {
                // distinct char count in the window is > k 
                // So slide the window 
                while (char_count.size() > 2) {
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
    cout << s.lengthOfLongestSubstringTwoDistinct("eceba") << endl;
    cout << s.lengthOfLongestSubstringTwoDistinct("ccaabbb") << endl;
    return 0;
}