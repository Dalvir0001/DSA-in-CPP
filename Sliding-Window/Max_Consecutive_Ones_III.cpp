/*
Approach: Sliding Window (Two Pointers)

Intuition:
- Maintain a window [left, right] that contains at most k zeroes.
- Expand the window by moving the right pointer.
- If the number of zeroes exceeds k, shrink the window from the left
  until it becomes valid again.
- Update the maximum window length whenever the window is valid.

Algorithm:
1. Traverse the array using the right pointer.
2. Count zeroes inside the current window.
3. If zeroes > k, move the left pointer and reduce the zero count when
   a zero leaves the window.
4. The current valid window length is (right - left + 1).
5. Keep track of the maximum window length.

Time Complexity: O(n)
- Each element is visited at most twice (once by left and once by right).

Space Complexity: O(1)
- Only constant extra space is used.
*/

// Code :-

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int curr = 0;
        int maxLength = 0;
        int zeroes = 0;
        while(right<n)
        {
            if(nums[right] == 0) zeroes++;
            if(zeroes>k)
            {
                if(nums[left]==0) zeroes--;
                left++;
            }
            if(zeroes<=k){
                curr = right - left + 1;
                maxLength = max(curr,maxLength);
            }
            right++;
        }
        return maxLength;
    }
};