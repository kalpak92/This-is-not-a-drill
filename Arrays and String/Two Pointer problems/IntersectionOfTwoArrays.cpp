/**
 * Given two integer arrays nums1 and nums2, return an array of their intersection. 
 * Each element in the result must be unique and you may return the result in any order.
 * 
 * Example 1:
 * Input: nums1 = [1,2,2,1], nums2 = [2,2]
 * Output: [2]
 * 
 * Example 2:
 * Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * Output: [9,4]
 * Explanation: [4,9] is also accepted.
 * 
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> intersectionUsingTwoPointers(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> setOfNumbers;

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i = 0;
        int j = 0;
        vector<int> result;

        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j])
                i++;
            else if (nums1[i] > nums2[j])
                j++;
            else {
                setOfNumbers.insert(nums1[i]);
                i++;
                j++;
            }
        }
        
        for (auto element : setOfNumbers) {
            result.push_back(element);
        }
        return result;
    }

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> setOfNumbers;
        vector<int> result;

        for (int elem : nums1)
            setOfNumbers.insert(elem);
            
        for (int elem : nums2) {
            // if (setOfNumbers.contains(elem)) {
            //     setOfNumbers.erase(elem);
            //     result.push_back(elem);
            // }
            // Erase returns : Number of elements removed (0 or 1).
            if (setOfNumbers.erase(elem) > 0)
                result.push_back(elem);
        }
        return result;
    }
};

void printVector(const vector<int>& nums) {
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    Solution solution;

    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};

    cout << "Intersection of the two arrays: ";
    printVector(solution.intersection(nums1, nums2));

    vector<int> nums3 = {4, 9, 5};
    vector<int> nums4 = {9, 4, 9, 8, 4};

    cout << "Intersection of the two arrays: ";
    printVector(solution.intersection(nums3, nums4));

    return 0;
}