/**
 * A conveyor belt has packages that must be shipped from one port to another within days days.
 * The ith package on the conveyor belt has a weight of weights[i]. 
 * Each day, we load the ship with packages on the conveyor belt (in the order given by weights).
 * We may not load more weight than the maximum weight capacity of the ship.
 * 
 * Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.
 * 
 * Example 1:
 * Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
 * Output: 15
 * Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
 * 1st day: 1, 2, 3, 4, 5
 * 2nd day: 6, 7
 * 3rd day: 8
 * 4th day: 9
 * 5th day: 10
 * 
 * Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts like 
 * (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.
 * 
 * Example 2:
 * Input: weights = [3,2,2,4,1,4], days = 3
 * Output: 6
 * Explanation: A ship capacity of 6 is the minimum to ship all the packages in 3 days like this:
 * 1st day: 3, 2
 * 2nd day: 2, 4
 * 3rd day: 1, 4
 * 
 * Example 3:
 * Input: weights = [1,2,3,1,1], days = 4
 * Output: 3
 * Explanation:
 * 1st day: 1
 * 2nd day: 2
 * 3rd day: 3
 * 4th day: 1, 1
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = get_max_weight(weights);
        int right = get_total_weight(weights);

        while (left <= right) {
            int mid = left + (right - left)/2;
            
            if (can_ship_within_days(weights, mid, days)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

private:
    bool can_ship_within_days(const vector<int>& weights, int max_capacity, int given_days) {
        int num_days = 1;
        int total_weight = 0;

        for (int weight: weights) {
            if (total_weight + weight > max_capacity) {
                total_weight = weight;
                num_days += 1;
            } else {
                total_weight += weight;
            }
        }

        if (num_days <= given_days)
            return true;
        else 
            return false;
    }

    int get_max_weight(const vector<int>& weights) {
        int result = INT_MIN;

        for (int weight : weights) {
            result = max(result, weight);
        }
        return result;
    }

    int get_total_weight(const vector<int>& weights) {
        int result = 0;
        for (int weight : weights) {
            result += weight;
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    int days = 5;

    cout << "Weights: [1,2,3,4,5,6,7,8,9,10], Days: 5" << endl;
    cout << "Least Capacity: " << s.shipWithinDays(weights, days) << endl;

    weights = {3,2,2,4,1,4};
    days = 3;

    cout << "Weights: [3,2,2,4,1,4], Days: 3" << endl;
    cout << "Least Capacity: " << s.shipWithinDays(weights, days) << endl;

    weights = {1,2,3,1,1};
    days = 4;

    cout << "Weights: [1,2,3,1,1], Days: 4" << endl;
    cout << "Least Capacity: " << s.shipWithinDays(weights, days) << endl;

    return 0;
}