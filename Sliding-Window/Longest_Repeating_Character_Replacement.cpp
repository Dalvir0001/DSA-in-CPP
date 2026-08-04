/*
Approach:
- Use a sliding window and maintain the frequency of characters in the current window.
- Track the maximum frequency of any character seen in the window.
- If the number of characters to replace (window length - max frequency) exceeds k,
  shrink the window from the left.
- Keep updating the maximum valid window length.

Time Complexity: O(n)
Space Complexity: O(1)
*/

// Code :-

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int maxLen = 0;
        int left = 0;
        int right = 0;
        int maxFreq = 0;
        vector<int> freq(26,0);
        while(right<n)
        {
            freq[s[right]-'A']++;
            maxFreq = max(maxFreq, freq[s[right]-'A']);
           if((right - left + 1) - maxFreq > k) {
                freq[s[left]-'A']--;
                left++;
            }
            if((right - left + 1) - maxFreq <= k){
            maxLen = max(maxLen, right - left + 1);
            right++;
            }
        }
        return maxLen;
    }
};