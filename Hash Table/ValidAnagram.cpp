/**
 * Given two strings s and t, return true if t is an anagram of s, and false otherwise.
 * An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
 * typically using all the original letters exactly once.
 * 
 * Example 1:
 * Input: s = "anagram", t = "nagaram"
 * Output: true
 * 
 * Example 2:
 * Input: s = "rat", t = "car"
 * Output: false
 * 
*/

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mapCharCount;  // Can use a character array of size 26 too
        
        // Build the character map
        for (char chr : s) {
            mapCharCount[chr]++;
        }

        // Use the character map and remove character count
        for (char chr : t) {
            mapCharCount[chr]--;
        }

        // Check if there's any character with non-zero frequency
        for (auto elem : mapCharCount) {
            if (elem.second != 0)
                return false;
        }
        return true;
    }
};

int main() {
    vector<pair<string, string>> testCases = {
        {"anagram", "nagaram"},
        {"rat", "car"}
    };

    Solution solution;
    for (auto testCase : testCases) {
        cout << boolalpha << solution.isAnagram(testCase.first, testCase.second) << endl;
    }

    return 0;
}