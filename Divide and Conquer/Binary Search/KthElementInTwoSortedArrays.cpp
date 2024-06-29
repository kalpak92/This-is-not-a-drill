/**
 * You're given two sorted arrays 'arr1' and 'arr2' of size 'n' and 'm' respectively and an element 'k'.
 * 
 * Find the element that would be at the 'kth' position of the combined sorted array.
 * Position 'k' is given according to 1 - based indexing, but arrays 'arr1' and 'arr2' are using 0 - based indexing.
 * 
 * For example :
 * Input: 'arr1' = [2, 3, 45], 'arr2' = [4, 6, 7, 8] and 'k' = 4
 * Output: 6
 * Explanation: The merged array will be [2, 3, 4, 6, 7, 8, 45]. 
 * The element at position '4' of this array is 6. Hence we return 6.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int kthElement(vector<int> &nums1, vector<int>& nums2, int k){
        // We will only partition on the smaller array.
        if (nums1.size() > nums2.size())
            return kthElement(nums2, nums1, k);

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
            // should be k.
            // The mid of nums2 will be
            int partition_y = k - partition_x;

            // We want the maximums of the left half to be lesser than the minimums of the right half
            // Use the sorted constraint to calculate that
            int max_left_x = (partition_x == 0) ? INT_MIN : nums1[partition_x - 1];
            int max_left_y = (partition_y == 0) ? INT_MIN : nums2[partition_y - 1];

            int min_right_x = (partition_x == size1) ? INT_MAX : nums1[partition_x];
            int min_right_y = (partition_y == size2) ? INT_MAX : nums2[partition_y];

            // Check if max_left_x <= min_right_y and max_left_y <= min_right_x
            if (max_left_x <= min_right_y && max_left_y <= min_right_x) {
                // return the kth element which is the maximum of the left half
                return max(max_left_x, max_left_y);
            } else if (max_left_x > min_right_y)
                // Candidate partition is too large.
                // Eliminate the right search space. (since the array is sorted)
                right = partition_x - 1;
            else
                left = partition_x + 1;
        }
        throw invalid_argument("...");
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {2, 3, 45};
    vector<int> nums2 = {4, 6, 7, 8};
    int k = 4;
    cout << "Given : [2, 3, 45], [4, 6, 7, 8] and k = 4\n";
    cout << sol.kthElement(nums1, nums2, k) << endl;

    nums1 = {1, 2};
    nums2 = {3, 4};
    k = 2;
    cout << "Given : [1, 2], [3, 4] and k = 2\n";
    cout << sol.kthElement(nums1, nums2, k) << endl;

    nums1 = {1, 3};
    nums2 = {2};
    k = 2;
    cout << "Given : [1, 3], [2] and k = 2\n";
    cout << sol.kthElement(nums1, nums2, k) << endl;

    return 0;
}