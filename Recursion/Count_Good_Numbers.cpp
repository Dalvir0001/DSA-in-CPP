/*
Approach:
- Even indices can contain 5 possible digits: {0, 2, 4, 6, 8}.
- Odd indices can contain 4 possible prime digits: {2, 3, 5, 7}.
- Number of even positions = (n + 1) / 2.
- Number of odd positions = n / 2.
- Answer = 5^(even positions) * 4^(odd positions) mod (1e9 + 7).
- Binary exponentiation is used to compute powers efficiently in O(log n).
*/

class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long power(long long a, long long b) {
        if (b == 0) return 1;

        long long half = power(a, b / 2);
        half = (half * half) % MOD;

        if (b % 2)
            half = (half * a) % MOD;

        return half;
    }

    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2;
        long long odd = n / 2;

        return (power(5, even) * power(4, odd)) % MOD;
    }
};