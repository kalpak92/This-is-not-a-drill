/**
 * You are given an integer array height of length n. 
 * There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
 * 
 * Find two lines that together with the x-axis form a container, such that the container contains the most water.
 * Return the maximum amount of water a container can store.
 * 
 * Notice that you may not slant the container.
 * 
 * Example 1:
 * Input: height = [1,8,6,2,5,4,8,3,7]
 * Output: 49
 * Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. 
 * In this case, the max area of water (blue section) the container can contain is 49.
 * 
 * Example 2:
 * Input: height = [1,1]
 * Output: 1
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = -1; 
        int left = 0;
        int right = height.size() - 1;

        while (left < right) {
            // Compute the area of the rectangle
            // height is the minimum of the two
            // breadth is the distance between the two
            int area = min(height[left], height[right]) * (right - left);
            maxArea = max(maxArea, area);   // update the maximum area accordingly

            if (height[left] < height[right])
                left++;
            else                // this is the == and > case.
                right--;
        }
        return maxArea;
    }
};

int main() {
    Solution solution;

    vector<int> test1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "The max area is : " << solution.maxArea(test1) << endl;

    vector<int> test2 = {1, 1};
    cout << "The max area is : " << solution.maxArea(test2) << endl;

    return 0;
}