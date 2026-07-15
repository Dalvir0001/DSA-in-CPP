/*
    Problem: Combination Sum III (LeetCode 216)

    Approach:
    - Use backtracking to generate all possible combinations.
    - Start choosing numbers from 'start' to 9 to avoid duplicates.
    - Keep track of:
        • Remaining numbers to pick (k)
        • Current sum
        • Current combination
    - If the sum equals n and exactly k numbers are chosen,
      store the combination.
    - Backtrack to explore all valid possibilities.

    Time Complexity: O(C(9, k))
    Space Complexity: O(k) (excluding the output)

    Author: Dalvir Singh
*/

class Solution {
public:
    void solve(int start, int k, int sum, int n,
               vector<int>& temp, vector<vector<int>>& ans) {

        if (sum == n && k == 0) {
            ans.push_back(temp);
            return;
        }

        if (sum > n || k == 0)
            return;

        for (int i = start; i <= 9; i++) {
            temp.push_back(i);
            solve(i + 1, k - 1, sum + i, n, temp, ans);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;

        solve(1, k, 0, n, temp, ans);

        return ans;
    }
};