/*
    Problem: Pow(x, n)
    Platform: LeetCode
    Problem No.: 50
    Topic: Recursion, Binary Exponentiation
    Difficulty: Medium

    Approach:
    - Use recursion with binary exponentiation.
    - Recursively calculate x^(n/2).
    - If n is even, return half * half.
    - If n is odd, return half * half * x.
    - Handle negative powers by converting x to 1/x.

    Time Complexity: O(log n)
    Space Complexity: O(log n)
*/

// Code :-

class Solution {
public:
    double myPow(double x, int n) {
        long long power = n;

        if (power < 0) {
            x = 1 / x;
            power = -power;
        }

        return powerFunction(x, power);
    }

    double powerFunction(double x, long long n) {
        if (n == 0)
            return 1;

        double half = powerFunction(x, n / 2);

        if (n % 2 == 0)
            return half * half;

        return half * half * x;
    }
};
