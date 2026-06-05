/*
LeetCode 8 - String to Integer (atoi)

Problem:
Convert a string to a 32-bit signed integer (similar to the atoi function).

Approach:
- Skip leading whitespaces.
- Check for '+' or '-' sign.
- Extract consecutive digits.
- Handle overflow and underflow using INT_MAX and INT_MIN.
- Return the final integer.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        
        while (i < n && s[i] == ' ') i++;
        
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }
        
        long ans = 0;
        while (i < n && s[i]>='0' &&s[i]<='9') {
            ans = ans * 10 + (s[i] - '0');
            
            if (sign * ans >= INT_MAX) return INT_MAX;
            if (sign * ans <= INT_MIN) return INT_MIN;
            
            i++;
        }
        
        return sign * ans;
    }
};
