/**
 * Given an array of integers nums and an integer threshold, 
 * we will choose a positive integer divisor, divide all the array by it, and sum the division's result. 
 * 
 * Find the smallest divisor such that the result mentioned above is less than or equal to threshold.
 * 
 * Each result of the division is rounded to the nearest integer greater than or equal to that element. 
 * (For example: 7/3 = 3 and 10/2 = 5).
 * 
 * The test cases are generated so that there will be an answer.
 * 
 * Example 1:
 * Input: nums = [1,2,5,9], threshold = 6
 * Output: 5
 * Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1. 
 * If the divisor is 4 we can get a sum of 7 (1+1+2+3) and if the divisor is 5 the sum will be 5 (1+1+1+2). 
 * 
 * Example 2:
 * Input: nums = [44,22,33,11,1], threshold = 5
 * Output: 44
 */


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        // search space is from 1 to max element in the nums array
        int left = 1;
        int right = get_max_num(nums);

        while (left <= right) {
            int mid = left + (right - left)/2;

            if (get_division_total(nums, mid) <= threshold) {
                // candidate divisor is less than threshold
                // eliminate the right search space
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

private:
    int get_division_total(const vector<int>& nums, int divisor) {
        int result = 0;

        // divide each number by the divisor and add the ceil quotient
        for (int num : nums) {
            result += ceil((double)num / (double)divisor);
        }
        return result;
    }

    int get_max_num(const vector<int>& nums) {
        int result = INT_MIN;

        for (int num : nums) {
            result = max(result, num);
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,2,5,9};
    int threshold = 6;

    cout << "Input: nums = [1,2,5,9], threshold = 6" << endl;
    cout << "Smallest Divisor: " << s.smallestDivisor(nums, threshold) << endl;

    nums = {44,22,33,11,1};
    threshold = 5;

    cout << "Input: nums = [44,22,33,11,1], threshold = 5" << endl;
    cout << "Smallest Divisor: " << s.smallestDivisor(nums, threshold) << endl;

    return 0;
}