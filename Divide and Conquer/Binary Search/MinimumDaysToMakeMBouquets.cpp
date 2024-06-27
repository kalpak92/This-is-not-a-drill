/**
 * You are given an integer array bloomDay, an integer m and an integer k.
 * You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.
 * 
 * The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.
 * 
 * Return the minimum number of days you need to wait to be able to make m bouquets from the garden. 
 * If it is impossible to make m bouquets return -1.
 * 
 * Example 1:
 * Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
 * Output: 3
 * Explanation: Let us see what happened in the first three days. x means flower bloomed and _ means flower did not bloom in the garden.
 * We need 3 bouquets each should contain 1 flower.
 * After day 1: [x, _, _, _, _]   // we can only make one bouquet.
 * After day 2: [x, _, _, _, x]   // we can only make two bouquets.
 * After day 3: [x, _, x, _, x]   // we can make 3 bouquets. The answer is 3.
 * 
 * Example 2:
 * Input: bloomDay = [1,10,3,10,2], m = 3, k = 2
 * Output: -1
 * Explanation: We need 3 bouquets each has 2 flowers, that means we need 6 flowers. 
 * We only have 5 flowers so it is impossible to get the needed bouquets and we return -1.
 * 
 * Example 3:
 * Input: bloomDay = [7,7,7,7,12,7,7], m = 2, k = 3
 * Output: 12
 * Explanation: We need 2 bouquets each should have 3 flowers.
 * Here is the garden after the 7 and 12 days:
 * After day 7: [x, x, x, x, _, x, x]
 * We can make one bouquet of the first three flowers that bloomed. 
 * We cannot make another bouquet from the last three flowers that bloomed because they are not adjacent.
 * After day 12: [x, x, x, x, x, x, x]
 * It is obvious that we can make two bouquets in different ways.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long  total_flowers_needed = m * 1LL * k * 1LL; // number of bouquets * number of adjacent flowers
        
        if (total_flowers_needed > bloomDay.size())
            return -1;
        
        int min_bloom = get_min_bloom(bloomDay);
        int max_bloom = get_max_bloom(bloomDay);

        int left = min_bloom;
        int right = max_bloom;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (is_possible(bloomDay, mid, m, k)) {
                // mid is a candidate, but we need the minimum days
                // so eliminate the right search space
                right = mid - 1;
            } else {
                // mid is not a candidate
                // eliminate the left search space and keep searching for candidate in the right half
                left = mid + 1;
            }
        }
        return left;
    }

private:
    bool is_possible(const vector<int>& bloomDay, int days, int m, int k) {
        int count_adjacent_flowers = 0;
        int count_of_bouquets = 0;

        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= days)        // candidate flower for the bouquet since it blooms within the candidate days
                count_adjacent_flowers++;
            else {
                // current flower is not a candidate as it needs more time to bloom
                // check if we can create a bouquet using the previous flowers.
                count_of_bouquets += count_adjacent_flowers / k;
                
                // reset the flower count and keep searching for next candidates
                count_adjacent_flowers = 0;
            }
        }

        // in the end, the last group of flowers needs to be considered too.
        count_of_bouquets += count_adjacent_flowers / k;

        // Compute if the candidate days is enough to create m bouquets each of k flowers
        if (count_of_bouquets >= m)
            return true;
        else
            return false;
    }

    int get_max_bloom(const vector<int>& bloomDay) {
        int result = INT_MIN;

        for (int bloom : bloomDay) {
            result = max(result, bloom);
        }

        return result;
    }

    int get_min_bloom(const vector<int>& bloomDay) {
        int result = INT_MAX;

        for (int bloom : bloomDay) {
            result = min(result, bloom);
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<int> bloomDay = {1,10,3,10,2};
    int m = 3;
    int k = 1;

    cout << s.minDays(bloomDay, m, k) << endl;

    bloomDay = {1,10,3,10,2};
    m = 3;
    k = 2;

    cout << s.minDays(bloomDay, m, k) << endl;

    bloomDay = {7,7,7,7,12,7,7};
    m = 2;
    k = 3;

    cout << s.minDays(bloomDay, m, k) << endl;

    return 0;
}