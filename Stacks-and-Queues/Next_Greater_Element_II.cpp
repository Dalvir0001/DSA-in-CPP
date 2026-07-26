/*
# 503. Next Greater Element II

## Problem
Given a circular integer array `nums`, return the next greater number for every element. If it doesn't exist, return `-1`.

## Approach
- Use a **monotonic decreasing stack** to keep track of potential next greater elements.
- Traverse the array **twice from right to left** (`2 * n - 1` to `0`) to simulate the circular nature.
- Remove all elements from the stack that are smaller than or equal to the current element.
- During the second half of the traversal (`i < n`), store the top of the stack as the answer.
- Push the current element onto the stack.

## Complexity
- **Time:** O(n)
- **Space:** O(n)

## Concepts Used
- Stack
- Monotonic Stack
- Circular Array
*/

// Code :-

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,-1);
        stack<int> st;
        for(int i = 2*n-1 ; i>=0 ; i--)
        {
            while(!st.empty() && st.top()<=nums[i%n])
            {
                st.pop();
            }
            if(i<n)
            {
                ans[i] = st.empty()?-1:st.top();
            }
            st.push(nums[i%n]);
        }
        return ans;
    }
};