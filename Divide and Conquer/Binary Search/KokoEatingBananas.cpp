/**
 * Koko loves to eat bananas. 
 * There are n piles of bananas, the ith pile has piles[i] bananas. 
 * The guards have gone and will come back in h hours.
 * 
 * Koko can decide her bananas-per-hour eating speed of k. 
 * Each hour, she chooses some pile of bananas and eats k bananas from that pile. 
 * If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.
 * 
 * Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
 * 
 * Return the minimum integer k such that she can eat all the bananas within h hours.
 * 
 * Example 1:
 * Input: piles = [3,6,7,11], h = 8
 * Output: 4
 * 
 * Example 2:
 * Input: piles = [30,11,23,4,20], h = 5
 * Output: 30
 * 
 * Example 3:
 * Input: piles = [30,11,23,4,20], h = 6
 * Output: 23
 * 
 * Constraints:
 * 1 <= piles.length <= 104
 * piles.length <= h <= 109
 * 1 <= piles[i] <= 109
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = get_max_piles(piles);

        while (left <= right) {
            int mid = left + ((right - left) / 2);

            long hours = get_total_hours_for_given_rate(piles, mid);

            if (hours <= h)
                right = mid - 1;
            else 
                left = mid + 1;
        }
        return left;
    }

private:
    long get_total_hours_for_given_rate(const vector<int>& piles, int rate) {
        long result = 0;

        for (int pile : piles) {
            result += ceil((double)pile / (double)rate);
        }
        return result;
    }
    int get_max_piles(const vector<int>& piles) {
        int result = INT_MIN;
        
        for (int pile : piles) {
            result = max(result, pile);
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> piles = {3,6,7,11};
    cout << s.minEatingSpeed(piles, 8) << endl;
    piles = {30,11,23,4,20};
    cout << s.minEatingSpeed(piles, 5) << endl;
    piles = {30,11,23,4,20};
    cout << s.minEatingSpeed(piles, 6) << endl;
    return 0;
}