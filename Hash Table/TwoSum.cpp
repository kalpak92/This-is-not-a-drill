/**
 * Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 * 
 * You can return the answer in any order.
 * 
 * Example 1:
 * Input: nums = [2,7,11,15], target = 9
 * Output: [0,1]
 * Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
 * 
 * Example 2:
 * Input: nums = [3,2,4], target = 6
 * Output: [1,2]
 * Example 3:
 * 
 * Input: nums = [3,3], target = 6
 * Output: [0,1]
 * 
 * Constraints:
 * 2 <= nums.length <= 104
 * -109 <= nums[i] <= 109
 * -109 <= target <= 109
 * 
 * Only one valid answer exists.
 * Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?
*/

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSumBruteForce(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if(nums[i] + nums[j] == target)
                    return {i, j};
            }
        }
        return {};
    }

    vector<int> twoSumDoublePass(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        int size = nums.size();

        // build the hash table
        for (int i = 0; i < size; i++) {
            map[nums[i]] = i;
        }

        // Find the complement match for the target
        for (int i = 0; i < size; i++) {
            int complement = target - nums[i];

            if (map.count(complement) && map[complement] != i)
                return {i, map[complement]};
        }

        return {};
    }

    auto twoSumOptimized(vector<int> &nums, int target) -> vector<int>
    {
        unordered_map<int, int> map; // Stores number as key and index as value
        int size = nums.size();

        for (int i = 0; i < size; i++) {
            int complement = target - nums[i];  // we need to check for the other half of the target
            // Check if the complement exists
            // Returns the number of elements with key that compares equal to the specified argument key, which is either ​0​ or 1 since this container does not allow duplicates.
            if (map.count(complement)) {
                return {map[complement], i};    // Gotcha. Return the complement's index and the current index
            }
            map[nums[i]] = i;   // Continue, while preserving the current details in the map for future use.
        }

        return {};
    }
};

std::string vectorToString(const std::vector<int>& result) {
    std::string resultStr = "[";
    for (int i = 0; i < result.size(); i++) {
        resultStr += std::to_string(result[i]);
        if (i != result.size() - 1) {
            resultStr += ", ";
        }
    }
    resultStr += "]";
    return resultStr;
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    Solution s;
    vector<int> result = s.twoSumBruteForce(nums, target);
        
    cout << vectorToString(result) << endl;

    result = s.twoSumDoublePass(nums, target);
    cout << vectorToString(result) << endl;

    result = s.twoSumOptimized(nums, target);
    cout << vectorToString(result) << endl;
}