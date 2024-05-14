/**
 * Design an algorithm to encode a list of strings to a string. 
 * The encoded string is then sent over the network and is decoded back to the original list of strings.
 * 
 * Machine 1 (sender) has the function:
 * string encode(vector<string> strs) {
 *      // ... your code
 *      return encoded_string;
 * }
 * 
 * Machine 2 (receiver) has the function:
 * vector<string> decode(string s) {
 *      //... your code
 *      return strs;
 * }
 * 
 * So Machine 1 does:
 * string encoded_string = encode(strs);
 * 
 * and Machine 2 does:
 * vector<string> strs2 = decode(encoded_string);
 * strs2 in Machine 2 should be the same as strs in Machine 1.
 * 
 * Implement the encode and decode methods.
 * 
 * You are not allowed to solve the problem using any serialize methods (such as eval).
 * 
 * Example 1:
 * Input: dummy_input = ["Hello","World"]
 * Output: ["Hello","World"]
 * Explanation:
 * Machine 1:
 * Codec encoder = new Codec();
 * String msg = encoder.encode(strs);
 * Machine 1 ---msg---> Machine 2
 * 
 * Machine 2:
 * Codec decoder = new Codec();
 * String[] strs = decoder.decode(msg);
 * 
 * Example 2:
 * Input: dummy_input = [""]
 * Output: [""]
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encodedStr = "";

        for (const string& str : strs) {
            int strLength = str.size();
            encodedStr += to_string(strLength) + "@" + str;
        }
        return encodedStr;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> result;
        
        while (!s.empty()) {
            int pos = s.find_first_of("@");
            int subStringLength = stoi(s.substr(0, pos));   // Extract the length of the substring
            result.push_back(s.substr(pos + 1, subStringLength));   // Extract the substring

            s = s.substr(pos + 1 + subStringLength);    // Update the string to beyond the current substring
        }
        return result;
    }
};

int main() {
    Codec codec;
    vector<string> strs = {"Hello", "World"};
    string encodedStr = codec.encode(strs);
    vector<string> decodedStr = codec.decode(encodedStr);

    cout << "Encoded String: " << encodedStr << endl;
    cout << "Decoded String: ";
    for (const string& str : decodedStr) {
        cout << str << " ";
    }
    cout << endl;

    strs = {"@"};
    encodedStr = codec.encode(strs);
    decodedStr = codec.decode(encodedStr);

    cout << "Encoded String: " << encodedStr << endl;
    cout << "Decoded String: ";
    for (const string& str : decodedStr) {
        cout << str << " ";
    }
    cout << endl;

    return 0;
}

