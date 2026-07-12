/*
# All Subsequences of a String

## Problem
Given a string `s`, generate all possible subsequences (including the empty subsequence) and return them in lexicographical order.

## Approach
- Use recursion with backtracking.
- For each character, we have two choices:
  1. Include the current character.
  2. Exclude the current character.
- When the index reaches the end of the string, store the current subsequence.
- Finally, sort all generated subsequences in lexicographical order.

## Algorithm
1. Start from index `0`.
2. Include the current character and recurse.
3. Backtrack by removing the last character.
4. Exclude the current character and recurse.
5. Store each subsequence when `index == s.length()`.
6. Sort the answer and return it.

## Complexity
- Time Complexity: **O(2ⁿ × n)**
- Space Complexity: **O(2ⁿ × n)** (including the output)
*/

// Code :-

class Solution {
  public:
    void solve(int index , string curr , string &s ,vector<string> &ans)
    {
        if (index == s.length()) {
        ans.push_back(curr);
        return;
        }
        solve(index+1 , curr + s[index] , s , ans);
        solve(index+1 , curr , s , ans);
    }
    vector<string> powerSet(string &s) {
        vector<string> ans;
        solve(0,"",s,ans);
        sort(ans.begin() , ans.end());
        return ans;
    }
};