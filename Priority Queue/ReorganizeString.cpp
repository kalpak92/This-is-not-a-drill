/**
 * Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.
 * Return any possible rearrangement of s or return "" if not possible.
 * 
 * Example 1:
 * Input: s = "aab"
 * Output: "aba"
 * 
 * Example 2:
 * Input: s = "aaab"
 * Output: ""
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        if (s.empty())
            return "";

        string result;

        // Create a character frequency store
        vector<int> char_count(26, 0);
        for (char c : s)
            char_count[c - 'a']++;

        // Create a maxHeap and enter characters based on their frequency
        // The max_heap stores a pair of {character, frequency}
        auto comp_char_count = [](pair<char, int> char1, pair<char, int> char2) {
            return char1.second < char2.second;
        };
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(comp_char_count)> max_heap(comp_char_count);
        for (int i = 0; i < 26; i++) {
            if (char_count[i] > 0) {
                auto temp = make_pair(i + 'a', char_count[i]);
                max_heap.push(temp);
            }
        }

        while (!max_heap.empty()) {
            auto temp = max_heap.top(); // get the pair with the highest frequency
            max_heap.pop();

            // if result is empty or the character is not equal to the last character in the result
            if (result.empty() || temp.first != result.back()) {
                result += temp.first;   // add the character
                temp.second--;          // reduce character count

                // if the characters still needs to be accomodated
                if (temp.second != 0)
                    max_heap.push(temp);
            } else {
                // corner case: if there are no more elements in heap, the input string should be invalid
                // because we do not have any other characters that are different than the last character of the result
                if (max_heap.empty())
                    return "";

                // current character in temp is same as the last character in result
                // get the next candidate from the maxHeap
                auto temp2 = max_heap.top();
                max_heap.pop();

                result += temp2.first;
                temp2.second--;
                if (temp2.second != 0)
                    max_heap.push(temp2);

                // also push the first character
                max_heap.push(temp);
            }
        }
        return result;
    }
};

/**
 * The time complexity of the reorganizeString function is O(n log n), where n is the length of the input string s.
 * 
 * Here's why:
 * Counting the frequency of each character in the string takes O(n) time.
 * Building the max heap with the character frequencies takes O(26 log 26) time, 
 * which is essentially O(1) because the number of possible characters is constant.
 * 
 * In the worst case, each character will be pushed into and popped from the heap once, which takes O(n log n) time.
 * Therefore, the overall time complexity is dominated by the heap operations, making it O(n log n).
*/

int main() {
    Solution sol;
    string s = "aab";
    cout << "Current string: " << s << endl;
    cout << "Rearranged string: " << sol.reorganizeString(s) << endl;

    s = "aaab";
    cout << "Current string: " << s << endl;
    cout << "Rearranged string: " << sol.reorganizeString(s) << endl;

    return 0;
}