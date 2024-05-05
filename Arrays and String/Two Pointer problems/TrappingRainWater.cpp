/**
 * Given n non-negative integers representing an elevation map where the width of each bar is 1, 
 * compute how much water it can trap after raining.
 * 
 * Example 1:
 * Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 * Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
 * In this case, 6 units of rain water (blue section) are being trapped.
 * 
 * Example 2:
 * Input: height = [4,2,0,3,2,5]
 * Output: 9
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trapUsingExtraSpace(vector<int>& height) {
        if (height.empty())
            return 0;

        vector<int> maxLeft(height.size());
        vector<int> maxRight(height.size());
        vector<int> waterContent(height.size());

        int result = 0;

        // Find the maximum height of the bar from the left end upto index i.
        maxLeft[0] = height[0];
        for(int i = 1; i < height.size(); i++) {
            maxLeft[i] = max(maxLeft[i - 1], height[i]);
        }

        // Find the maximum height of the bar from the right end upto index i.
        maxRight[height.size() - 1] = height[height.size() - 1];
        for(int i = height.size() - 2; i >= 0; i--)
            maxRight[i] = max(maxRight[i + 1], height[i]);

        // Calculate the water held at each position by taking the minimum of the maxLeft and maxRight at that position.
        for(int i = 0; i < height.size(); i++) {
            waterContent[i] = min(maxLeft[i], maxRight[i]) - height[i];
        }

        for(int water : waterContent)
            result += water;

        return result;

    }

    int trapOptimized(vector<int>& height) {
        if (height.empty())
            return 0;

        int left = 0;
        int right = height.size() - 1;

        int maxLeft = 0;
        int maxRight = 0;

        int result = 0;

        while (left < right) {
            if (height[left] < height[right]) {     // Water can fill up everything from left to right if there's nothing in between
                // Current elevation is greater than the previous maximum
                // Water cannot occupy that point at all.
                if (height[left] >= maxLeft) {
                    // Found a new maxLeft
                    // Update it and carry on to see how much water we can fill from point onwards.
                    maxLeft = height[left];
                } else {
                    // If this is not the maximum, then we can fill the current point with water upto the previous maximum.
                    // We subtract the height[left] from maxLeft, as that is the elevation from the ground.
                    result += maxLeft - height[left];
                }
                left++;
            } else {    // If the height at left is NOT GREATER than the height at right, we cannot fill from left to right without overflowing.
                if (height[right] >= maxRight) {
                    // Similarly we've found a height greater than maxRight, and cannot fill it whatsoever, 
                    // but everything before is optimally filled
                    maxRight = height[right];
                } else {
                    // We can fill the current point with water upto the previous maximum.
                    result += maxRight - height[right];
                }
                right--;
            }
        }
        return result;
    }
};

int main() {
    Solution solution;

    vector<int> test1 = {0,1,0,2,1,0,1,3,2,1,2,1};
    // cout << solution.trapUsingExtraSpace(test1) << endl;
    cout << solution.trapOptimized(test1) << endl;

    vector<int> test2 = {4,2,0,3,2,5};
    // cout << solution.trapUsingExtraSpace(test2) << endl;
    cout << solution.trapOptimized(test2) << endl;

    return 0;
}