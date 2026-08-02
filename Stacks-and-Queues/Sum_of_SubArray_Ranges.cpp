/*
Sum of Subarray Ranges

Approach:
- Every element contributes as both the maximum and the minimum
  in different subarrays.
- Compute:
      Answer = Sum(Max Contributions) - Sum(Min Contributions)
- Use monotonic stacks to find:
    1. Previous Greater Element (PGE)
    2. Next Greater Element (NGE)
    3. Previous Smaller Element (PSE)
    4. Next Smaller Element (NSE)
- Contribution:
      nums[i] * leftChoices * rightChoices

Time Complexity: O(n)
Space Complexity: O(n)
*/

// Code :-

class Solution {
public:
     vector<int> solvePGE(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n, n);
        stack<int> st;

        for (int i = 0; i <n; i++) {
            while (!st.empty() && arr[st.top()] <= arr[i])
                st.pop();

            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return ans;
    }
     vector<int> solveNGE(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n, n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] < arr[i])
                st.pop();

            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return ans;
    }
     vector<int> solveNSE(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n, n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();

            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return ans;
    }

    vector<int> solvePSE(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return ans;
    }
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> nse;
        vector<int> pse;
        vector<int> nge;
        vector<int> pge;
        nse = solveNSE(nums);
        pse = solvePSE(nums);
        nge = solveNGE(nums);
        pge = solvePGE(nums);
        long long maxSum = 0, minSum = 0;
        for(int i=0 ; i<n ; i++)
        {
            int left = i - pge[i];
            int right = nge[i] - i;
            maxSum += 1ll * left * right * nums[i];
        }
        for(int i=0 ; i<n ; i++)
        {
            int left = i - pse[i];
            int right = nse[i] - i;
            minSum += 1ll * left * right * nums[i];
        }
        return maxSum - minSum;
    }
};