/**
 * Given an integer array nums and an integer k, 
 * return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.
 * 
 * Example 1:
 * Input: nums = [1,2,3,1], k = 3
 * Output: true
 * 
 * Example 2:
 * Input: nums = [1,0,1,1], k = 1
 * Output: true
 * 
 * Example 3:
 * Input: nums = [1,2,3,1,2,3], k = 2
 * Output: false
 * 
 * Constraints:
 * 1 <= nums.length <= 10^5
 * -109 <= nums[i] <= 10^9
 * 0 <= k <= 10^5
*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> numbers;

        for (int i = 0 ; i < nums.size(); i++) {
            if (numbers.contains(nums[i]))
                return true;
            
            numbers.insert(nums[i]);

            if (numbers.size() > k) {
                numbers.erase(nums[i - k]);
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,2,3,1};
    int k = 3;

    cout << sol.containsNearbyDuplicate(nums, k) << endl;

    nums = {1,0,1,1};
    k = 1;

    cout << sol.containsNearbyDuplicate(nums, k) << endl;

    nums = {1,2,3,1,2,3};
    k = 2;

    cout << sol.containsNearbyDuplicate(nums, k) << endl;

    return 0;
}