/**
 * Implement pow(x, n), which calculates x raised to the power n (i.e., x^n).
 * 
 * Example 1:
 * Input: x = 2.00000, n = 10
 * Output: 1024.00000
 * 
 * Example 2:
 * Input: x = 2.10000, n = 3
 * Output: 9.26100
 * 
 * Example 3:
 * Input: x = 2.00000, n = -2
 * Output: 0.25000
 * Explanation: 2^(-2) = 1/2^2 = 1/4 = 0.25
 * 
 * Constraints:
 * -100.0 < x < 100.0
 * -2^31 <= n <= 2^31-
 * n is an integer.
 * Either x is not zero or n > 0.
 * -10^4 <= x^n <= 10^4
 */

#include <iostream>

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1;

        long long num = n;  // prevents overflows
        if (num < 0) {
            num = -1 * num;
            x = 1.0 / x;
        }

        // Binary Exponentiation
        num = labs(n);
        double result = 1;
        while (num) {
            if (num % 2 == 1) {
                // If n is odd, we multiply result with 'x' and reduce n by 1
                result *= x;
            }

            // Square 'x' and reduce 'n' by half since x^n == (x^2)^(n/2)
            x *= x;
            num = num / 2; // n >> 1 is equivalent to num / 2
        }
        return result;
    }
};

int main() {
    Solution sol;
    double x = 2.00000;
    int n = 10;
    std::cout << "Power of " << x << " raised to " << n << " is: " << sol.myPow(x, n) << std::endl;

    x = 2.10000;
    n = 3;
    std::cout << "Power of " << x << " raised to " << n << " is: " << sol.myPow(x, n) << std::endl;

    x = 2.00000;
    n = -2;
    std::cout << "Power of " << x << " raised to " << n << " is: " << sol.myPow(x, n) << std::endl;

    return 0;
}