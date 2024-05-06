/**
 * Given an array of strings strs, group the anagrams together. You can return the answer in any order.
 * 
 * An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
 * typically using all the original letters exactly once.
 * 
 * Example 1:
 * Input: strs = ["eat","tea","tan","ate","nat","bat"]
 * Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
 * 
 * Example 2:
 * Input: strs = [""]
 * Output: [[""]]
 * 
 * Example 3:
 * Input: strs = ["a"]
 * Output: [["a"]]
 * 
 * Constraints:
 * 1 <= strs.length <= 10^4
 * 0 <= strs[i].length <= 100
 * strs[i] consists of lowercase English letters.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <array>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // store the hash of a string
        unordered_map<string, vector<string>> mapOfHashToString;
        vector<vector<string>> result;

        for (const auto& str : strs) {
            // Create a counter to count the frequency of each character
            // Initially, set all to zero by default
            array<int, 26> counter;
            counter.fill(0);
      
            for (auto chr : str) {
                counter[chr - 'a']++;
            }

            // Create a mapString.
            string tempHash;
            for (int j = 0; j < counter.size(); j++) {
                if (counter[j] != 0) {
                    tempHash += string(counter[j], j + 'a');
                }
            }

            // Insert the same into mapOfHashToString with tempHash as key
            // Values get grouped for the same key
            mapOfHashToString[tempHash].push_back(str);
        }

        // Get the grouped grouped anagrams from mapOfHashToString
        result.reserve(mapOfHashToString.size());   // avoid reallocation
        for (auto& elem : mapOfHashToString) {
            result.push_back(std::move(elem.second));   // std::move transfers the ownership instead of copy
        }

        return result;

    }
};

void printVector(const vector<string>& strs) {
    for (const string& str : strs) {
        cout << str << " ";
    }
    cout << endl;
}

void printVector(const vector<vector<string>>& strs) {
    for (const auto& str : strs) {
        printVector(str);
    }
    cout << endl;
}

int main() {
    Solution solution;

    vector<vector<string>> testCases = {
        {"eat", "tea", "tan", "ate", "nat", "bat"},
        {""},
        {"a"}
    };

    for (auto testCase : testCases) {
        cout << "Test case: " << endl;
        printVector(testCase);
        cout << "Grouped Anagrams: " << endl;
        printVector(solution.groupAnagrams(testCase));
    }

    return 0;
}