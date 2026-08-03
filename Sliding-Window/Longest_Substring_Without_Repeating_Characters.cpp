/*
Approach:
- Use a sliding window with two pointers (left and right).
- Maintain an array `freq` where freq[c] stores the last index at which
  character `c` was seen.
- As we iterate with `right`, if the current character was previously seen
  within the current window (freq[s[right]] >= left), move `left` to
  freq[s[right]] + 1 to remove the duplicate.
- Update the current window length and the maximum length.
- Store the current index as the latest occurrence of the character.

Time Complexity: O(n)
- Each character is processed exactly once.

Space Complexity: O(1)
- Fixed-size array of 256 elements for ASCII characters.
*/

// Code :-

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left = 0;
        int right = 0;
        vector<int> freq(256, -1);
        int maxLength = 0;
        int len = 0;
        while(right<n)
        {
            if(freq[s[right]]!=-1)
            {
                if(freq[s[right]]>=left)
                {
                    left = freq[s[right]]+1;
                }
            }
            len = right - left + 1;
            maxLength = max(maxLength,len);
            freq[s[right]] = right;
            right++;
        }
        return maxLength;
    }
};