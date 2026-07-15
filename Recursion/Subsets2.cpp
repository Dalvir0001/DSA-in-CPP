/*
Problem Statement

Given an integer array nums that may contain duplicate elements, return all possible subsets (the power set) without duplicate subsets.

Approach
Sort the array so that duplicate elements are adjacent.
Generate subsets using backtracking.
Skip duplicate elements at the same recursion level using:
if (i > index && arr[i] == arr[i - 1]) continue;

This ensures that duplicate subsets are never generated, eliminating the need for a set.

Complexity
Time Complexity: O(n × 2^n)
Space Complexity: O(n) (excluding the output)
*/

// Code :- 

class Solution {
public:
    void findSubsets(int index, vector<int> temp ,vector<vector<int>> &ans , vector<int> &arr)
    {
        ans.push_back(temp);
        for(int i = index ; i < arr.size() ; i++)
        {
            if(i>index && arr[i]==arr[i-1]) continue;
            temp.push_back(arr[i]);
            findSubsets(i+1, temp , ans , arr);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        findSubsets(0 , temp ,ans , nums);
        return ans;
    }
};