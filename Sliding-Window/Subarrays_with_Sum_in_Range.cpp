/*
Approach:
- Use the "At Most Sliding Window" technique for non-negative arrays.
- Count the number of subarrays with sum at most r.
- Count the number of subarrays with sum at most (l - 1).
- The difference between these two counts gives the number of subarrays
  whose sum lies in the range [l, r].

Time Complexity: O(n)
Space Complexity: O(1)
*/

// Code :-

class Solution {
public:
    int atMost(vector<int>& arr, int limit) {
        if (limit < 0) return 0;

        int left = 0;
        int sum = 0;
        int cnt = 0;

        for (int right = 0; right < arr.size(); right++) {
            sum += arr[right];

            while (sum > limit) {
                sum -= arr[left++];
            }

            cnt += right - left + 1;
        }

        return cnt;
    }

    int countSubarray(vector<int>& arr, int l, int r) {
        return atMost(arr, r) - atMost(arr, l - 1);
    }
};