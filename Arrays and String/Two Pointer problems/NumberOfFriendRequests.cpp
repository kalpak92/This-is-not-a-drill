/**
 * There are n persons on a social media website. 
 * You are given an integer array ages where ages[i] is the age of the ith person.
 * 
 * A Person x will not send a friend request to a person y (x != y) if any of the following conditions is true:
 *      age[y] <= 0.5 * age[x] + 7
 *      age[y] > age[x]
 *      age[y] > 100 && age[x] < 100
 * 
 * Otherwise, x will send a friend request to y.
 * 
 * Note that if x sends a request to y, y will not necessarily send a request to x. 
 * Also, a person will not send a friend request to themself.
 * 
 * Return the total number of friend requests made.
 * 
 * Example 1:
 * Input: ages = [16,16]
 * Output: 2
 * Explanation: 2 people friend request each other.
 * 
 * Example 2:
 * Input: ages = [16,17,18]
 * Output: 2
 * Explanation: Friend requests are made 17 -> 16, 18 -> 17.
 * 
 * Example 3:
 * Input: ages = [20,30,100,110,120]
 * Output: 3
 * Explanation: Friend requests are made 110 -> 100, 120 -> 110, 120 -> 100.
 * 
 * Constraints:
 * n == ages.length
 * 1 <= n <= 2 * 10^4
 * 1 <= ages[i] <= 120
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numFriendRequestsI(vector<int>& ages) {
        // Given possible range of age []0, 120]
        int countPerAges[121] = {};
        int result = 0;

        for (auto age : ages) {
            countPerAges[age] += 1;
        }

        // 1st Rule :   Age of x needs to be atleast 15.
        //              People can make request to younger people older than 0.5 * age[i] + 7.
        // If the age is same, then number of requests is age[i] * (age[i] - 1)
        // If the age is different, then number of requests are age[i] * age[j];
        for (int i = 15; i <= 120; i++) {
            for (int j = 0.5 * i + 8; j <= i; j++)
                result += countPerAges[j] * (countPerAges[i] - (i == j));
        }
        return result;
    }

    int numFriendRequests(vector<int>& ages) {
        // Given x will not send a request to y if :
        // age[y] <= 0.5 * age[x] + 7
        // age[y] > age[x]
        // 
        // This can be reversed to:
        // age[y] > 0.5 * age[x] + 7
        // age[y] < age[x]
        //
        // This means : 0.5 * age[x] + 7 < age[y] < age[x]

        // Minimum of x that holds the equation
        // x > 0.5x + 7 => 0.5x > 7 => x > 14
        // So, the Minimum of x is 15

        // countPerAges -> How many people in a particular age group
        // count = sumInAge[i] - sumInAge[i / 2 + 7] : This gives the number of requests that can be sent from this age
        // There could be multiple people so, need to multiply count * countPerAges[i]
        // Account for not sending the request to itself
        // count * countPerAges[i] - countPerAges[i]

        int result = 0;
        int countPerAges[121] = {}; // count of number of people for a particular age
        int slidingSumInAge[121] = {};     // number of people in this bracket and below

        for (int age : ages) {
            countPerAges[age]++;
        }

        for (int i = 1; i <= 120; i++) {
            slidingSumInAge[i] = countPerAges[i] + slidingSumInAge[i - 1];
        }

        for (int i = 15; i <= 120; i++) {
            if (countPerAges[i] == 0)
                continue;
            int numFriendRequests = slidingSumInAge[i] - slidingSumInAge[i/2 + 7];      // how many requests can be sent from this age satifying the condition

            result += numFriendRequests * countPerAges[i] - countPerAges[i];            // calculate the request while subtracting the fact that it cannot send a request to itself
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> ages = {16, 16};
    cout << "Number of requests : " <<  solution.numFriendRequests(ages) << endl;

    ages = {16, 17, 18};
    cout << "Number of requests : " << solution.numFriendRequests(ages) << endl;

    ages = {20, 30, 100, 110, 120};
    cout << "Number of requests : " << solution.numFriendRequests(ages) << endl;

    return 0;
}