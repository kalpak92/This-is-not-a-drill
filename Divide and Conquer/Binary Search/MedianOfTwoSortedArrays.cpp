/**
 * Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
 * 
 * The overall run time complexity should be O(log (m+n)).
 * 
 * Example 1:
 * Input: nums1 = [1,3], nums2 = [2]
 * Output: 2.00000
 * Explanation: merged array = [1,2,3] and median is 2.
 * 
 * Example 2:
 * Input: nums1 = [1,2], nums2 = [3,4]
 * Output: 2.50000
 * Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    double findMedianSortedArraysBruteForce(vector<int>& nums1, vector<int>& nums2) {
        // Merge the arrays into a single sorted arrays
        vector<int> arr;
        for (int num : nums1)
            arr.push_back(num);

        for (int num: nums2)
            arr.push_back(num);

        sort(arr.begin(), arr.end());

        int total_size = arr.size();
        if (total_size % 2 == 1)
            return static_cast<double>(arr[total_size / 2]);
        else {
            int m = arr[total_size / 2 - 1];
            int n = arr[total_size / 2];
            return (static_cast<double>(m) + static_cast<double>(n)) / 2.0;
        }
    }

    // Time Complexity: O(log(min(m, n)))
    // Let m be the size of array nums1 and n be the size of array nums2.
    // We perform a binary search over the smaller array of size min(m,n).

    // Space Complexity: O(1)
    // We only use constant extra space.
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // We will only partition on the smaller array.
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int size1 = nums1.size();
        int size2 = nums2.size();

        // We focus on finding the correct partition for nums1
        // The other partition for nums2 can be mathematically found
        int left = 0;
        int right = size1;

        while (left <= right) {
            // compute the mid from nums1
            int partition_x = left + (right - left)/2;

            // The number of elements on the left half of both the arrays
            // is half of the total number of elements
            int total_left_half = (size1 + size2 + 1) / 2;
            // The mid of nums2 will be
            int partition_y = total_left_half - partition_x;
            
            // We want the maximums of the left half to be lesser than the minimums of the right half
            // Use the sorted constraint to calculate that
            int max_left_x = (partition_x == 0) ? INT_MIN : nums1[partition_x - 1];
            int max_left_y = (partition_y == 0) ? INT_MIN : nums2[partition_y - 1];

            int min_right_x = (partition_x == size1) ? INT_MAX : nums1[partition_x];
            int min_right_y = (partition_y == size2) ? INT_MAX : nums2[partition_y];

            // Check if max_left_x <= min_right_y and max_left_y <= min_right_x
            if (max_left_x <= min_right_y && max_left_y <= min_right_x) {
                if ((size1 + size2) % 2 == 0)
                    return ((double)max(max_left_x, max_left_y) + min(min_right_x, min_right_y)) / 2.0;
                else 
                    return ((double)max(max_left_x, max_left_y));
            } else if (max_left_x > min_right_y)
                // Candidate partition is too large.
                // Eliminate the right search space. (since the array is sorted)
                right = partition_x - 1;
            else
                left = partition_x + 1;
        }
        throw invalid_argument("invalid_argument");
    }
};


int main() {
    Solution sol;
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << sol.findMedianSortedArraysBruteForce(nums1, nums2) << endl;

    nums1 = {1, 2};
    nums2 = {3, 4};
    cout << sol.findMedianSortedArraysBruteForce(nums1, nums2) << endl;

    nums1 = {1, 3};
    nums2 = {2};
    cout << sol.findMedianSortedArrays(nums1, nums2) << endl;

    nums1 = {1, 2};
    nums2 = {3, 4};
    cout << sol.findMedianSortedArrays(nums1, nums2) << endl;

    return 0;
}