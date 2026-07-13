/*
Problem : Combination Sum

Approach:
- Use Backtracking (Recursion).
- At each index, we have two choices:
  1. Include the current element and stay at the same index
     because an element can be used unlimited times.
  2. Exclude the current element and move to the next index.
- Whenever the current sum becomes equal to the target,
  store the current combination.
- Stop recursion if the sum exceeds the target or all elements
  have been considered.

Time Complexity: Exponential (depends on the number of valid combinations)
Space Complexity: O(target) (excluding the output)
*/

// Code :-

class Solution {
public:
    void solve(int sum ,int index , int target , vector<int>& temp , vector<int>& candidates ,vector<vector<int>> &ans)
    {
        if(sum == target)
        {
            ans.push_back(temp);
            return;
        }
        if(sum>target || index == candidates.size())
        return;

        temp.push_back(candidates[index]);
        sum += candidates[index];
        solve(sum ,index , target , temp , candidates , ans);

        sum -= candidates[index];
        temp.pop_back();

        solve(sum ,index+1 , target , temp , candidates , ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0 ,0 , target , temp , candidates , ans );
        return ans;
    }
};