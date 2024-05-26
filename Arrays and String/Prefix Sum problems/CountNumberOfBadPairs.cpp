/**
 * You are given a 0-indexed integer array nums. 
 * A pair of indices (i, j) is a bad pair if i < j and j - i != nums[j] - nums[i].
 * Return the total number of bad pairs in nums.
 * 
 * Example 1:
 * Input: nums = [4,1,3,3]
 * Output: 5
 * Explanation: The pair (0, 1) is a bad pair since 1 - 0 != 1 - 4.
 * The pair (0, 2) is a bad pair since 2 - 0 != 3 - 4, 2 != -1.
 * The pair (0, 3) is a bad pair since 3 - 0 != 3 - 4, 3 != -1.
 * The pair (1, 2) is a bad pair since 2 - 1 != 3 - 1, 1 != 2.
 * The pair (2, 3) is a bad pair since 3 - 2 != 3 - 3, 1 != 0.
 * There are a total of 5 bad pairs, so we return 5.
 * 
 * Example 2:
 * Input: nums = [1,2,3,4,5]
 * Output: 0
 * Explanation: There are no bad pairs.
 * 
 * Constraints:
 * 1 <= nums.length <= 10^5
1 <= nums[i] <= 10^9
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long total_pairs = (nums.size() * (nums.size() - 1))/2;
        unordered_map<int, int> good_pairs;
        long long good_pair_count = 0;

        // j - i = nums[j] - nums[i] creates a good pair 
        // So, j - nums[j] == i - nums[i] makes a good pair
        // Use a map to store {i - nums[i], count}
        for (int i = 0; i < nums.size(); i++) {
            int diff = i - nums[i];

            if (good_pairs.contains(diff)) {    
                // this means there has already existed a prior number with the same difference as i - nums[i]
                // Let's say that to be j - nums[j]
                // Now, that we found another pair {i, nums[i]} with the same diff,
                // We call this 1 good Pair.
                // So add it to good_pair_count.
                good_pair_count += good_pairs[diff];
            }
            good_pairs[diff]++;
        }
        return total_pairs - good_pair_count;
    }
};

int main() {
    Solution solution;

    vector<int> nums = {4, 1, 3, 3};
    cout << solution.countBadPairs(nums) << endl;

    nums = {1, 2, 3, 4, 5};
    cout << solution.countBadPairs(nums) << endl;

    return 0;
}