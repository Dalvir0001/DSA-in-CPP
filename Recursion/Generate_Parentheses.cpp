/*
## 22. Generate Parentheses

### Approach
- Use recursion with backtracking.
- Keep track of the number of opening and closing parentheses used.
- Add '(' if the number of opening parentheses is less than `n`.
- Add ')' only if the number of closing parentheses is less than the number of opening parentheses.
- When the current string reaches length `2 * n`, add it to the result.

### Time Complexity
- O(Cn), where Cn is the nth Catalan number (number of valid combinations).

### Space Complexity
- O(n) for the recursion stack (excluding the output).
*/

// Code :-

class Solution {
public:
    void solve(int open , int close , int n , string curr , vector<string> &ans)
    {
        if(curr.length() == 2*n)
        {
            ans.push_back(curr);
            return;
        }
        if(open<n)
        {
            solve(open+1 , close , n , curr+'(' , ans);
        }
        if(close<open)
        {
            solve(open , close+1 , n , curr+')', ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(0,0,n,"",ans);
        return ans;
    }
};