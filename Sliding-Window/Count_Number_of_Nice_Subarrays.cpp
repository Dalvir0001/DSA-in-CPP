/*
    Count Number of Nice Subarrays

    Approach:
    - Use the Sliding Window + At Most technique.
    - Count the number of subarrays with at most k odd numbers.
    - Count the number of subarrays with at most (k - 1) odd numbers.
    - Their difference gives the number of subarrays with exactly k odd numbers.

    Time Complexity: O(N)
    Space Complexity: O(1)
*/

// Code :-

class Solution {
public:
    int atMost(vector<int>& arr , int k)
    {
        int n = arr.size();
        if(k<0) return 0;
        int left = 0;
        int right = 0;
        int number = 0;
        int cnt = 0;
        while(right<n)
        {
            if(arr[right]%2 != 0)
            {
                number++;
            }
            while(number>k)
            {
                if(arr[left]%2 != 0)
                {
                    number--;
                }
                left++;
            }
            cnt = cnt + (right - left + 1);
            right++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums,k) - atMost(nums,k-1);
    }
};