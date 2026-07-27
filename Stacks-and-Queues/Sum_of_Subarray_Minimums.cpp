/*
Approach:
- Used Monotonic Increasing Stacks to find the Previous Smaller Element (PSE)
  and Next Smaller Element (NSE) for every array element.
- Calculated the number of subarrays where each element acts as the minimum
  using:
      left = i - PSE[i]
      right = NSE[i] - i
- Computed each element's contribution as:
      arr[i] * left * right
- Summed all contributions modulo 1e9 + 7.

Time Complexity: O(n)
Space Complexity: O(n)
*/

// Code :-

class Solution {
public:
    const int MOD = 1e9 + 7;

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

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        vector<int> nse = solveNSE(arr);
        vector<int> pse = solvePSE(arr);

        long long total = 0;

        for (int i = 0; i < n; i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;

            total = (total + (1LL * arr[i] * left % MOD) * right % MOD) % MOD;
        }

        return total;
    }
};