/**
 * Given an integer array nums, return true if any value appears at least twice in the array, 
 * and return false if every element is distinct.
 * 
 * Example 1:
 * Input: nums = [1,2,3,1]
 * Output: true
 * 
 * Example 2:
 * Input: nums = [1,2,3,4]
 * Output: false
 * 
 * Example 3:
 * Input: nums = [1,1,1,3,3,4,3,2,4,2]
 * Output: true
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_map<int, int> map;

        for (auto num : nums)
            map[num]++;

        for (auto elem : map) {
            if (elem.second >= 2)
                return true;
        }
        return false;
        // return nums.size() > unordered_set<int>(nums.begin(), nums.end()).size();
    }
};

int main() {
    vector<vector<int>> testCases = {
        {1, 2, 3, 1},
        {1, 2, 3, 4},
        {1, 1, 1, 3, 3, 4, 3, 2, 4, 2}
    };

    Solution solution;
    for (auto testCase : testCases) {
        cout << boolalpha << solution.containsDuplicate(testCase) << endl;
    }

    return 0;
}