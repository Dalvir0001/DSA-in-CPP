/*
## Problem
Given a string `s` consisting only of the characters `'a'`, `'b'`, and `'c'`, return the number of substrings containing at least one occurrence of each character.

## Approach (Sliding Window)
- Use two pointers (`left` and `right`) to maintain a sliding window.
- Expand the window by moving the `right` pointer and keep track of character frequencies.
- Whenever the current window contains at least one `'a'`, `'b'`, and `'c'`, all substrings starting from the current `left` and ending at `right` or beyond are valid.
- Add `(n - right)` to the answer.
- Shrink the window from the left to find more valid substrings.

## Algorithm
1. Initialize two pointers `left` and `right`.
2. Expand the window by moving `right`.
3. Store the frequency of each character in a hash map.
4. While the window contains all three characters:
   - Add `(n - right)` to the answer.
   - Remove the leftmost character from the window.
   - Move `left` forward.
5. Return the total count.

## Time Complexity
- **O(n)**

## Space Complexity
- **O(1)** (The hash map stores frequencies of only three characters.)
  */

// Code :-

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int left = 0;
        int ans = 0;

        unordered_map<char, int> mpp;

        for (int right = 0; right < n; right++) {
            mpp[s[right]]++;

            while (mpp['a'] > 0 && mpp['b'] > 0 && mpp['c'] > 0) {
                ans += (n - right);
                mpp[s[left]]--;

                if (mpp[s[left]] == 0)
                    mpp.erase(s[left]);

                left++;
            }
        }

        return ans;
    }
};
