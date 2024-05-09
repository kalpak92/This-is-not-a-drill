/**
 * Given an integer array nums and an integer k, return the k most frequent elements. 
 * You may return the answer in any order.
 * 
 * Example 1:
 * Input: nums = [1,1,1,2,2,3], k = 2
 * Output: [1,2]
 * 
 * Example 2:
 * Input: nums = [1], k = 1
 * Output: [1]
*/

#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequentUsingHeap(vector<int>& nums, int k) {
        // base case
        if (nums.size() == k) {
            return nums;
        }

        // Create a hashmap of element and its frequency
        unordered_map<int , int> frequencyMap;
        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        // Create a minHeap from the frequencyMap
        // Use a lambda to compare the elements based on the frequency
        auto compare = [&frequencyMap](int n1, int n2) {
            return frequencyMap[n1] > frequencyMap[n2];
        };
        priority_queue<int, vector<int>, decltype(compare)> minHeap(compare);
        vector<int> result;

        for (auto& num : nums)
            frequencyMap[num]++;

        for (auto& elem : frequencyMap) {
            minHeap.push(elem.first);       // 

            if (minHeap.size() > k)
                minHeap.pop();
        }

        while (!minHeap.empty()) {
            result.emplace_back(minHeap.top());
            minHeap.pop();
        }

        return result;
    }

    vector<int> topKFrequentUsingQuickSelect(vector<int>& nums, int k) {
        // base case
        if (nums.size() == k) {
            return nums;
        }

        // Create a hashmap of element and its frequency
        unordered_map<int , int> frequencyMap;
        for (auto& num : nums)
            frequencyMap[num]++;

        // Create a vector of vector to store the number and its frequency
        vector<vector<int>> numberAndCount;
        vector<int> result;
        int index = 0;

        for (auto& elem : frequencyMap) {
            numberAndCount.push_back({elem.first, elem.second});
        }
                
        int left = 0;
        int right = numberAndCount.size() - 1;

        while (true) {
            int pivotIndex = partition(numberAndCount, left, right);

            if (pivotIndex == k - 1) {
                break;
            }

            if(pivotIndex < k - 1)
                left = pivotIndex + 1;
            else
                right = pivotIndex - 1;
        }

        // Copy the k elements to the result
        for(int i = 0; i < k && i < numberAndCount.size(); i++) {
            result[i] = numberAndCount[i][0];
        }

        return result; 
    }

private:
    int partition(vector<vector<int>>& nums, int start, int end) {
        int pivot = nums[end][1]; // pivot is the frequency
        int pivotIndex = start;

        for (int i = start; i < end; i++) {     
            // note that pivot is set to nums[end] and we run the loop till nums[end] - 1
            if (nums[i][1] >= pivot) {
                // Candidate nums[i][1] is greater than pivot
                // So swap and move it ahead (which is the pivotIndex)
                swap(nums[i], nums[pivotIndex]);
                pivotIndex++;
            }
        }
        // all elements to the left of pivotIndex are greater than pivot
        // swap nums[pivotIndex] with pivot to put pivot at the correct place
        swap(nums[pivotIndex], nums[end]);
        return pivotIndex;                  // nums is partitioned at this index
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    vector<int> result = sol.topKFrequentUsingHeap(nums, k);
    for (auto& num : result)
        cout << num << " ";
    cout << endl;

    nums = {1};
    k = 1;

    result = sol.topKFrequentUsingQuickSelect(nums, k);
    for (auto& num : result)
        cout << num << " ";
    cout << endl;

    return 0;
}