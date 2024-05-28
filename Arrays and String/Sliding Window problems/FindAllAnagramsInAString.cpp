/**
 * Given two strings s and p, return an array of all the start indices of p's anagrams in s. 
 * You may return the answer in any order.
 * 
 * An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
 * typically using all the original letters exactly once.
 * 
 * Example 1:
 * Input: s = "cbaebabacd", p = "abc"
 * Output: [0,6]
 * Explanation:
 * The substring with start index = 0 is "cba", which is an anagram of "abc".
 * The substring with start index = 6 is "bac", which is an anagram of "abc".
 * 
 * Example 2:
 * Input: s = "abab", p = "ab"
 * Output: [0,1,2]
 * Explanation:
 * The substring with start index = 0 is "ab", which is an anagram of "ab".
 * The substring with start index = 1 is "ba", which is an anagram of "ab".
 * The substring with start index = 2 is "ab", which is an anagram of "ab".
 * 
 * Constraints:
 * 1 <= s.length, p.length <= 3 * 10^4
 * s and p consist of lowercase English letters.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;

        if (p.size() > s.size())
            return {};
        
        unordered_map<char, int> char_count;
        for (char c : p) {
            char_count[c]++;
        }

        int left = 0;
        int right = 0;
        int counter = char_count.size();        // Track distinct characters in the substring

        while (right < s.size()) {
            // Check if character pointed by right is a candidate character
            // If so, reduce its count in the map.
            // If the char_count is 0, decrement counter since we dont need to count that character anymore.
            char c = s[right];

            if (char_count.contains(c)) {
                char_count[c]--;
                
                if (char_count[c] == 0)
                    counter--;
            }
            right++;

            while (counter == 0) {                  // Anagram critera reached
                // If window size is same as the size of string p
                // Then left points to the start index of the substring
                if (right - left == p.size())
                    result.push_back(left);

                // Slide the window.
                // If left is a candidate character
                // Then increment its count in the map.
                // Also, ensure to increment counter iff char_count[temp] > 0.
                char temp = s[left];
                if (char_count.contains(temp)) {
                    char_count[temp]++;

                    if (char_count[temp] > 0)
                        counter++;
                }

                left++;
            }
        }
        return result;
    }
};

void printVector(const vector<int>& nums) {
    for (int num : nums)
        cout << num << " ";
    cout << endl;
}

int main() {
    Solution sol;
    string s = "cbaebabacd";
    string p = "abc";
    printVector(sol.findAnagrams(s, p));        // Output: [0,6]

    s = "abab";
    p = "ab";
    printVector(sol.findAnagrams(s, p));        // Output: [0,1,2]

    return 0;
}