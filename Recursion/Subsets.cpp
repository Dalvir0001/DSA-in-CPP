/*
Problem

Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets.

Approach

This solution uses recursion and backtracking.

For each element, there are two choices:

Include the current element in the subset.
Exclude the current element from the subset.

The recursion explores both possibilities for every index. When all elements have been processed, the current subset is added to the answer.

Algorithm
Start recursion from index 0.
Include the current element and recurse.
Backtrack by removing the element.
Exclude the current element and recurse.
When index == n, store the current subset.
Time Complexity
O(n × 2ⁿ)

There are 2ⁿ subsets, and each subset can contain up to n elements.

Space Complexity
O(n) (excluding the output), due to the recursion stack.
Output space is O(n × 2ⁿ).
*/

// Code :-

class Solution {
public:
    void findSubsets(int index, int n, vector<int>& temp,
                     vector<vector<int>>& ans, vector<int>& arr) {
        if (index == n) {
            ans.push_back(temp);
            return;
        }

        temp.push_back(arr[index]);
        findSubsets(index + 1, n, temp, ans, arr);

        temp.pop_back();
        findSubsets(index + 1, n, temp, ans, arr);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        findSubsets(0, nums.size(), temp, ans, nums);
        return ans;
    }
};