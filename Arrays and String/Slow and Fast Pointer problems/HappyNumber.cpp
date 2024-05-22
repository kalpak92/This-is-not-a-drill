/**
 * Write an algorithm to determine if a number n is happy.
 * 
 * A happy number is a number defined by the following process:
 * Starting with any positive integer, replace the number by the sum of the squares of its digits.
 * Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
 * Those numbers for which this process ends in 1 are happy.
 * Return true if n is a happy number, and false if not.
 * 
 * Example 1:
 * Input: n = 19
 * Output: true
 * Explanation:
 * 12 + 92 = 82
 * 82 + 22 = 68
 * 62 + 82 = 100
 * 12 + 02 + 02 = 1
 * 
 * Example 2:
 * Input: n = 2
 * Output: false
*/

#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isHappyUsingHashSet(int n) {
        unordered_set<int> seen;

        /**
         * The algorithm is based on the fact that if a number is not happy, it will end up in a cycle.
         * The cycle will have a repeating sequence of numbers.
         * If we keep track of all the numbers that we have seen so far, we can detect the cycle.
         * If the number is happy, it will end up at 1.
        */
        while (n != 1) {
            if (seen.contains(n))
                return false;
            seen.insert(n);
            n = getNext(n);
        }
        return true;
    }

    bool isHappy(int n) {
        /**
         * The algorithm is based on the fact that if a number is not happy, it will end up in a cycle.
         * The cycle will have a repeating sequence of numbers.
         * Use the slow and fast pointer approach to detect the cycle.
         * If the number is happy, it will end up at 1.
        */
        int slow = n;
        int fast = getNext(n);

        while (fast != 1 && fast != slow) {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }

        return fast == 1;

    }
private:
    int getNext(int n) {
        int sum = 0;

        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n = n/10;
        }
        return sum;
    }
};

int main() {
    Solution sol;
    int n = 19;
    cout << "Is " << n << " a happy number? " << boolalpha << sol.isHappy(n) << endl;

    n = 2;
    cout << "Is " << n << " a happy number? " << boolalpha << sol.isHappy(n) << endl;

    return 0;
}