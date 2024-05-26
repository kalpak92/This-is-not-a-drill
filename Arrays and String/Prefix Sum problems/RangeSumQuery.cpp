/**
 * Given an integer array nums, handle multiple queries of the following type:
 * 
 * Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
 * 
 * Implement the NumArray class:
 * NumArray(int[] nums) Initializes the object with the integer array nums.
 * int sumRange(int left, int right) 
 *      Returns the sum of the elements of nums between indices left and right inclusive 
 *      (i.e. nums[left] + nums[left + 1] + ... + nums[right]).
 * 
 * Example 1:
 * Input
 * ["NumArray", "sumRange", "sumRange", "sumRange"]
 * [[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
 * Output
 * [null, 1, -1, -3]
 * 
 * Explanation
 * NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
 * numArray.sumRange(0, 2); // return (-2) + 0 + 3 = 1
 * numArray.sumRange(2, 5); // return 3 + (-5) + 2 + (-1) = -1
 * numArray.sumRange(0, 5); // return (-2) + 0 + 3 + (-5) + 2 + (-1) = -3
 * 
 * Constraints:
 * 1 <= nums.length <= 10^4
 * -10^5 <= nums[i] <= 10^5
 * 0 <= left <= right < nums.length
 * At most 10^4 calls will be made to sumRange.
*/

#include <iostream>
#include <vector>

using namespace std;

class NumArray {
public:
    NumArray(vector<int>& nums) {
        prefix_sum.push_back(0);    // The first element has nothing on the left as its prefix_sum

        for (int num : nums) {
            prefix_sum.push_back(prefix_sum.back() + num);
        }
    }
    
    int sumRange(int left, int right) {
        return prefix_sum[right + 1] - prefix_sum[left];    // since prefix_sum is 1-indexed
    }

private:
    vector<int> prefix_sum;
};

int main() {
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    cout << "Given array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    
    NumArray numArray(nums);
    cout << numArray.sumRange(0, 2) << endl;    // Output: 1
    cout << numArray.sumRange(2, 5) << endl;    // Output: -1
    cout << numArray.sumRange(0, 5) << endl;    // Output: -3
    return 0;
}