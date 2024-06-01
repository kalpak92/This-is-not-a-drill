/**
 * Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
 * In other words, return true if one of s1's permutations is the substring of s2.
 * 
 * Example 1:
 * Input: s1 = "ab", s2 = "eidbaooo"
 * Output: true
 * Explanation: s2 contains one permutation of s1 ("ba").
 * 
 * Example 2:
 * Input: s1 = "ab", s2 = "eidboaoo"
 * Output: false
 * 
 * Constraints:
 * 1 <= s1.length, s2.length <= 10^4
 * s1 and s2 consist of lowercase English letters.
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> result;

        if (s1.size() > s2.size())
            return false;
        
        unordered_map<char, int> char_count;
        for (char c : s1) {
            char_count[c]++;
        }

        int left = 0;
        int right = 0;
        int counter = char_count.size();        // Track distinct characters in the s1

        while (right < s2.size()) {
            // Check if character pointed by right is a candidate character
            // If so, reduce its count in the map.
            // If the char_count is 0, decrement counter since we dont need to count that character anymore.
            char c = s2[right];

            if (char_count.contains(c)) {
                char_count[c]--;
                
                if (char_count[c] == 0)
                    counter--;
            }
            right++;

            while (counter == 0) {                  // Anagram critera reached
                // If window size is same as the size of string p
                // Then left points to the start index of the substring
                if (right - left == s1.size())
                    return true;

                // Slide the window.
                // If left is a candidate character
                // Then increment its count in the map.
                // Also, ensure to increment counter iff char_count[temp] > 0.
                char temp = s2[left];
                if (char_count.contains(temp)) {
                    char_count[temp]++;

                    if (char_count[temp] > 0)
                        counter++;
                }

                left++;
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    string s1 = "ab";
    string s2 = "eidbaooo";
    cout << boolalpha << s.checkInclusion(s1, s2) << endl;
}