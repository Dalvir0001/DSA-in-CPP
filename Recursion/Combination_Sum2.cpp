/*
Problem
Given a collection of candidate numbers (candidates) and a target value (target), find all unique combinations where the chosen numbers sum to the target.
Each number in the array may be used at most once in each combination.

Approach
Sort the input array to bring duplicate values together.
Use backtracking to generate all possible combinations.

Skip duplicate elements at the same recursion level using:

if (i > index && arr[i] == arr[i - 1]) continue;
Stop exploring further when the current element exceeds the remaining target since the array is sorted.
Backtrack after each recursive call to explore other possibilities.
Algorithm
Sort the array.
Start backtracking from index 0.
For each element:
Skip duplicates.
If the element is greater than the remaining target, stop exploring.
Include the element and recurse for the remaining target.
Remove the element (backtrack).
Store the combination whenever the remaining target becomes 0.
Time Complexity
Worst Case: O(2ⁿ)
Space Complexity
O(n) (excluding the output), where n is the recursion depth.
*/

// Code :-

class Solution {
public:
      void solve(int index , int target , vector<int>& temp , vector<int>& arr ,vector<vector<int>> &ans)
    {
        if(target == 0)
        {
            ans.push_back(temp);
            return;
        }
        for(int i = index ; i < arr.size() ; i++)
        {
            if(i>index && arr[i] == arr[i-1]) continue;
            if(arr[i] > target) break;
            temp.push_back(arr[i]);
            solve(i + 1 , target - arr[i] ,temp , arr , ans  );
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin() , candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0 , target , temp , candidates , ans );
        return ans;
    }
};