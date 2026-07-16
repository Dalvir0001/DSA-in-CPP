/*
Problem: 17. Letter Combinations of a Phone Number
Platform: LeetCode
Difficulty: Medium

Approach:
- Use Backtracking (DFS).
- Maintain a mapping from digits ('2'-'9') to their corresponding letters.
- At each digit, iterate through all possible letters.
- Add one letter to the current combination, recurse for the next digit,
  and backtrack by removing the last added letter.

Time Complexity: O(4^N * N)
Space Complexity: O(N) (excluding output)
*/

// Code :-

class Solution {
public:
    unordered_map<char, string> mpp = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    void solve(int index, string &digits, string &temp, vector<string> &ans) {
        if (index == digits.size()) {
            ans.push_back(temp);
            return;
        }

        string letters = mpp[digits[index]];

        for (char ch : letters) {
            temp.push_back(ch);          
            solve(index + 1, digits, temp, ans); 
            temp.pop_back();             
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;

        if (digits.empty())
            return ans;

        string temp;
        solve(0, digits, temp, ans);

        return ans;
    }
};