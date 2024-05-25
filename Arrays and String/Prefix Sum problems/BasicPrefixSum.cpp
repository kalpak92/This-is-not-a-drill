/**
 * C++ program to find the prefix sum of an array
 */

#include <iostream>
#include <vector>

using namespace std;

class PrefixSum {
public:
    vector<int> calculatePrefixSum(const vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }

        vector<int> prefixSum(nums.size());
        prefixSum[0] = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }

        return prefixSum;
    }
};

void printVector(const vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    PrefixSum prefixSum;
    vector<int> nums = {10, 20, 10, 5, 15};
    cout << "Given array: ";
    printVector(nums);
    vector<int> result = prefixSum.calculatePrefixSum(nums);
    cout << "Prefix sum array: ";
    printVector(result);
    return 0;
}