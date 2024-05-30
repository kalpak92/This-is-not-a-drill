/**
 * Given a string s and an integer k, return the length of the longest substring of s that contains at most k distinct characters.
 * 
 * Example 1:
 * Input: s = "eceba", k = 2
 * Output: 3
 * Explanation: The substring is "ece" with length 3.
 * 
 * Example 2:
 * Input: s = "aa", k = 1
 * Output: 2
 * Explanation: The substring is "aa" with length 2.
 * 
 * Constraints:
 * 1 <= s.length <= 5 * 10^4
 * 0 <= k <= 50
*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (s.empty())
            return 0;
        
        unordered_map<char, int> char_count;
        int result = 0;
        int left = 0;
        int right = 0;

        while (right < s.size()) {
            char c = s[right];
            char_count[c]++;

            if (char_count.size() <= k) {
                // candidate found
                result = max(result, right - left + 1);
                right++;
            } else if (char_count.size() > k) {
                // distinct char count in the window is > k 
                // So slide the window 
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
    string s = "eceba";
    int k = 2;

    cout << sol.lengthOfLongestSubstringKDistinct(s, k) << endl;

    s = "aa";
    k = 1;

    cout << sol.lengthOfLongestSubstringKDistinct(s, k) << endl;

    return 0;
}
