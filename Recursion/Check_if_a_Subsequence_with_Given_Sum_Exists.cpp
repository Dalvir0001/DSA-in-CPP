/*
# Check if a Subsequence with Given Sum Exists

## Problem
Given an array `arr` and an integer `k`, determine whether there exists a subsequence whose sum is exactly `k`.

## Approach
- Use recursion to explore all possible subsequences.
- At each index, we have two choices:
  1. Include the current element in the sum.
  2. Exclude the current element.
- If the current sum becomes equal to `k`, return `true`.
- If all elements are processed or the sum exceeds `k` (valid for non-negative arrays), return `false`.

## Algorithm
1. Start from index `0` with sum `0`.
2. Include the current element and recurse.
3. Exclude the current element and recurse.
4. If either recursive call returns `true`, a valid subsequence exists.

## Complexity
- **Time Complexity:** `O(2^n)`
- **Space Complexity:** `O(n)` (recursion stack)
*/

// Code :-

class Solution {
  public:
    bool solve(int index, int sum, vector<int>& arr, int k) {
    if (sum == k)
        return true;

    if (index == arr.size() || sum > k)
        return false;

    return solve(index + 1, sum + arr[index], arr, k) ||
           solve(index + 1, sum, arr, k);
}
    bool checkSubsequenceSum(vector<int>& arr, int k) {
        return solve(0 ,0 , arr , k);
    }
};