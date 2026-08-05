// Problem: Longest Substring with Exactly K Distinct Characters
// Algorithm:
// 1. Use a sliding window with two pointers.
// 2. Maintain character frequencies using a vector.
// 3. Expand the window until distinct characters exceed k.
// 4. Shrink the window until distinct characters become <= k.
// 5. Update the answer whenever the window contains exactly k distinct characters.
//
// Time Complexity: O(N)
// Space Complexity: O(1)

// Code :-

class Solution {
public:
    int longestKSubstr(string &s, int k) {
        vector<int> freq(256, 0);

        int left = 0;
        int distinct = 0;
        int maxLen = -1;

        for (int right = 0; right < s.size(); right++) {
            if (freq[s[right]] == 0)
                distinct++;

            freq[s[right]]++;

            while (distinct > k) {
                freq[s[left]]--;

                if (freq[s[left]] == 0)
                    distinct--;

                left++;
            }

            if (distinct == k)
                maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};