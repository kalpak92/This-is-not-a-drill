/**
 * Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
 * The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
 * 
 * You must write an algorithm that runs in O(n) time and without using the division operation.
 * 
 * Example 1:
 * Input: nums = [1,2,3,4]
 * Output: [24,12,8,6]
 * 
 * Example 2:
 * Input: nums = [-1,1,0,-3,3]
 * Output: [0,0,9,0,0]
 * 
 * Constraints:
 * 2 <= nums.length <= 10^5
 * -30 <= nums[i] <= 30
 * The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
 * 
 * Follow up: Can you solve the problem in O(1) extra space complexity? 
 * (The output array does not count as extra space for space complexity analysis.)
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        /**
        * {              1,         a[0],    a[0]*a[1],    a[0]*a[1]*a[2],  }
        * { a[1]*a[2]*a[3],    a[2]*a[3],         a[3],                 1,  }
        */
        vector<int> result(nums.size());

        result[0] = 1;
        // Find the product of all the elements to the left of the current element
        for (int i = 1; i < nums.size(); i++) {
            result[i] = result[i - 1] * nums[i - 1];
        }

        int right = 1;
        // Find the product of all the elements to the right of the current element
        // right is the product of all the elements to the right of the current element
        // Initially, right is 1 since there are no elements to the right of the last element
        for (int i = nums.size() - 1; i >= 0; i--) {
            result[i] = result[i] * right;
            right = right * nums[i];
        }
        return result;
    }

    /**
     * Here, we loop through the array twice to find the product of all the elements except the current element.
    */
    vector<int> productExceptSelfNaive(vector<int>& nums) { 
        vector<int> result(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            int product = 1;
            for (int j = 0; j < nums.size(); j++) {
                if (i == j)
                    continue;
                product *= nums[j];
            }
            result.push_back(product);
        }
        return result;
    }

    /**
     * Here, we find the product of all the elements in the array and 
     * then divide it by the current element to get the product of all the elements except the current element.
    */
    vector<int> productExceptSelfByDividingProduct(vector<int>& nums) { 
        vector<int> result(nums.size());
        int product = 1;

        for (int num : nums)
            product *= num;

        for (int i = 0; i < nums.size(); i++) {
            result[i] = product / nums[i];          // Voila : What about nums[i] == 0
        }

        return result;
    }

    /**
     * Here, we find the product of all the elements to the left of the current element and
     * the product of all the elements to the right of the current element.
     * The product of all the elements except the current element is the product of the left and right product.
     * This is dynamic programming.
    */
    vector<int> productExceptSelfSpaceUnoptimized(vector<int>& nums) {
        vector<int> result(nums.size());
        vector<int> leftProduct(nums.size());
        vector<int> rightProdcut(nums.size());

        leftProduct[0] = 1;
        for (int i = 1; i < nums.size(); i++) {
            leftProduct[i] = leftProduct[i - 1] * nums[i];
        }

        rightProdcut[nums.size() - 1] = 1;
        for (int i = nums.size() -2; i >= 0; i--) {
            rightProdcut[i] = rightProdcut[i + 1] * nums[i];
        }

        for (int i = 0; i < nums.size(); i++) {
            result[i] = leftProduct[i] * rightProdcut[i];
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4};
    vector<int> result = sol.productExceptSelf(nums);

    cout << "Product of all the elements except the current element: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}