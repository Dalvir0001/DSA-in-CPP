/*
Problem: Word Break
Platform: GeeksforGeeks / LeetCode

Approach:
- Pure Recursion (Backtracking)
- At each index, try every word in the dictionary.
- If a word matches, recursively solve the remaining string.

Time Complexity: Exponential (Worst Case)
Space Complexity: O(n) // Recursion stack

Note:
This solution is implemented using recursion only.
*/

// Code :-

class Solution {
public:
    bool solve(int index , string &s, vector<string>& dict)
    {
        if(index == s.size()) return true;

        for(string &word : dict)
        {
            int len = word.size();
            if(index+len <=s.size() && s.substr(index, len) == word)
            {
                if(solve(index+len , s , dict))
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        return solve(0,s,wordDict);
    }
};