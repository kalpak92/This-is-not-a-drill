/**
 * Given an array of strings words and an integer k, return the k most frequent strings.
 * Return the answer sorted by the frequency from highest to lowest. 
 * Sort the words with the same frequency by their lexicographical order.
 * 
 * Example 1:
 * Input: words = ["i","love","leetcode","i","love","coding"], k = 2
 * Output: ["i","love"]
 * 
 * Explanation: "i" and "love" are the two most frequent words.
 * Note that "i" comes before "love" due to a lower alphabetical order.
 * 
 * Example 2:
 * Input: words = ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
 * Output: ["the","is","sunny","day"]
 * Explanation: "the", "is", "sunny" and "day" are the four most frequent words, 
 * with the number of occurrence being 4, 3, 2 and 1 respectively.
*/

#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> result(k);
        unordered_map<string, int> wordFrequency;
        for (string& word : words)
            wordFrequency[word]++;

        /**
         * This lambda function takes two strings n1 and n2 as input and returns true
         * if n1 should be considered "greater than" n2 in the context of the priority queue, 
         * and false otherwise.
        */
        auto compare = [&wordFrequency](const string& n1, const string& n2) {
            /**
             * The function first checks if the frequencies of n1 and n2 in wordFrequency are equal. 
             * If they are, it returns true if n1 is lexicographically less than n2, and false otherwise. 
             * This means that if two words have the same frequency, 
             * the one that comes first in lexicographical order is considered "greater".
            */
            if (wordFrequency[n1] == wordFrequency[n2]) // Same Frequency
                return n1 < n2;    
            
            /**
             * If the frequencies of n1 and n2 are not equal, 
             * the function returns true if the frequency of n1 is greater than the frequency of n2, and false otherwise. 
             * This means that words with higher frequencies are considered "greater".
            */
            return wordFrequency[n1] > wordFrequency[n2];
        };
        // creates a priority queue of strings, using a vector of strings as the underlying container, 
        // and the compare lambda function as the comparison function.
        priority_queue<string, vector<string>, decltype(compare)> minHeap(compare);

        for (auto& elem : wordFrequency) {
            minHeap.push(elem.first);

            if (minHeap.size() > k) 
                minHeap.pop();
        }

        while (!minHeap.empty()) {
            k--;
            result[k]= minHeap.top();
            minHeap.pop();
        }
        return result;
    }
};

void printVector(vector<string>& words) {
    for (string& word : words)
        cout << word << " ";
    cout << endl;
}

int main() {
    Solution sol;
    vector<string> words = {"i", "love", "leetcode", "i", "love", "coding"};
    int k = 2;

    cout << "Example 1: " << endl;
    cout << "Input: ";
    printVector(words);
    vector<string> result = sol.topKFrequent(words, k);
    cout << "Output: The top " << k << " frequent words are: ";
    printVector(result);

    words = {"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"};
    k = 4;

    cout << "Example 2: " << endl;
    cout << "Input: ";
    printVector(words);
    cout << "Output: The top " << k << " frequent words are: ";
    result = sol.topKFrequent(words, k);
    for (string& word : result)
        cout << word << " ";
    cout << endl;

    return 0;
}

