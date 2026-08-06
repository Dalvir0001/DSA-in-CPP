/*
    Subarrays with K Different Integers

    Approach:
    - Use the Sliding Window + At Most technique.
    - Count the number of subarrays with at most k distinct integers.
    - Count the number of subarrays with at most (k - 1) distinct integers.
    - The difference between these two counts gives the number of
      subarrays with exactly k distinct integers.

    Time Complexity: O(N)
    Space Complexity: O(K)
*/

// Code :-

class Solution {
public:
    int atMost(vector<int>& arr , int k)
    {
        if(k<0) return 0;
        int n = arr.size();
        unordered_map<int,int> mpp;
        int left = 0;
        int right = 0;
        int cnt = 0;
        while(right<n)
        {
            mpp[arr[right]]++;
            while(mpp.size() > k)
            {
                mpp[arr[left]]--;
                if(mpp[arr[left]] == 0) mpp.erase(arr[left]);
                left++;
            }
            cnt += right - left + 1;
            right++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums,k) - atMost(nums,k-1);
    }
};