/**
 * The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.
 * You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.
 * 
 * For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. 
 * If there is no next greater element, then the answer for this query is -1.
 * 
 * Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.
 * 
 * Example 1:
 * Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
 * Output: [-1,3,-1]
 * 
 * Explanation: The next greater element for each value of nums1 is as follows:
 *      - 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
 *      - 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
 *      - 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
 * 
 * Example 2:
 * Input: nums1 = [2,4], nums2 = [1,2,3,4]
 * Output: [3,-1]
 * 
 * Explanation: The next greater element for each value of nums1 is as follows:
 *      - 2 is underlined in nums2 = [1,2,3,4]. The next greater element is 3.
 *      - 4 is underlined in nums2 = [1,2,3,4]. There is no next greater element, so the answer is -1.
 * 
 * Constraints:
 * 1 <= nums1.length <= nums2.length <= 1000
 * 0 <= nums1[i], nums2[i] <= 10^4
 * All integers in nums1 and nums2 are unique.
 * All the integers of nums1 also appear in nums2.
 */

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> decreasing_stack;
        unordered_map<int, int> map;
        vector<int> result(nums1.size(), -1);

        for (int i = 0; i < nums2.size(); i++) {
            while(!decreasing_stack.empty() && nums2[i] > decreasing_stack.top()) {
                // num2[i] is greater than the top element of the stack which breaks the stack invariant.
                // This also means nums2[i] is the NGE for all elements in the stack which are lesser than nums2[i].
                // Store that into the map<previous_element, nums2[i]>
                map[decreasing_stack.top()] = nums2[i];
                decreasing_stack.pop();
            }

            decreasing_stack.push(nums2[i]);
        }

        // We have a map that has the key-value mapping for <number, NGE of num> from nums2.
        // Given that nums1 is a subset of nums2.
        // Check if candidate exists in the map and add accordingly
        for (int i = 0; i < nums1.size(); i++) {
            if (map.contains(nums1[i]))
                result[i] = map[nums1[i]];
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    vector<int> result = s.nextGreaterElement(nums1, nums2);
    cout << "Output: ";
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << endl;

    nums1 = {2, 4};
    nums2 = {1, 2, 3, 4};
    result = s.nextGreaterElement(nums1, nums2);
    cout << "Output: ";
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << endl;

    return 0;
}