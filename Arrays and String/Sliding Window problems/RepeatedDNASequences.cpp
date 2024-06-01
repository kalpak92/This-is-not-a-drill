/**
 * The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.
 * For example, "ACGAATTCCG" is a DNA sequence.
 * 
 * When studying DNA, it is useful to identify repeated sequences within the DNA.
 * Given a string s that represents a DNA sequence, 
 * return all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule. 
 * You may return the answer in any order.
 * 
 * Example 1:
 * Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
 * Output: ["AAAAACCCCC","CCCCCAAAAA"]
 * 
 * Example 2:
 * Input: s = "AAAAAAAAAAAAA"
 * Output: ["AAAAAAAAAA"]
 * 
 * Constraints:
 * 1 <= s.length <= 10^5
 * s[i] is either 'A', 'C', 'G', or 'T'.
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> sequence_count;
        vector<string> result;

        // No valid sequence
        if (s.size() < 10)
            return result;
        
        // window size is 10
        // [i, i+10]
        // use the map to store sequence count
        for (int i = 0; i < s.size() - 9; i++) {
            sequence_count[s.substr(i, 10)]++;
        }

        // Get all sequences with count > 1
        for (const auto& [seq, count] : sequence_count) {
            if (count > 1)
                result.push_back(seq);
        }
        return result;
    }
};

int main() {
    Solution objRepeatedDNASequences;
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    vector<string> result = objRepeatedDNASequences.findRepeatedDnaSequences(s);
    for (string seq : result)
        cout << seq << " ";
    return 0;
}