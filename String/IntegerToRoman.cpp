// Problem: Integer to Roman
// Platform: LeetCode 12
//
// Approach:
// - Use a greedy algorithm.
// - Store Roman numeral values and symbols in descending order.
// - Repeatedly subtract the largest possible value from the number
// and append its corresponding Roman symbol to the answer.
//
// Time Complexity: O(1)
// Space Complexity: O(1)
//Code

class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> roman = {
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"}
        };

        string ans = "";

        for (auto p : roman) {
            while (num >= p.first) {
                ans += p.second;
                num -= p.first;
            }
        }

        return ans;
    }
};
