/*
## Count Binary Strings

### Approach
- Use recursion to generate all binary strings of length `n`.
- Always place `0`.
- Place `1` only if the previous character is not `1`.
- Count every valid string of length `n`.

### Time Complexity
- O(2^n)

### Space Complexity
- O(n)
*/

// Code :-

class Solution {
public:
    void solve(bool prevOne, int n, string curr, int &count) {
        if (curr.length() == n) {
            count++;
            return;
        }
        solve(false, n, curr + '0', count);
        if (!prevOne) {
            solve(true, n, curr + '1', count);
        }
    }
    int countStrings(int n) {
        int count = 0;
        solve(false, n, "", count);
        return count;
    }
};