/*
    Problem: Minimum Window Substring
    Approach:
    - Sliding Window + Frequency Array
    - Store the frequency of all characters in the target string.
    - Expand the right pointer to include characters in the current window.
    - Once all required characters are matched, shrink the window from the left
      while maintaining validity to obtain the minimum-length substring.
    - Track the smallest valid window throughout the traversal.

    Time Complexity: O(n)
    Space Complexity: O(1)   // Frequency array of fixed size (128)
*/

// Code :-

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";

        vector<int> freq(128, 0);
        for (char ch : t)
            freq[ch]++;

        int left = 0;
        int count = 0;

        int minLen = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.size(); right++) {
            if (freq[s[right]] > 0)
                count++;

            freq[s[right]]--;
            while (count == t.size()) {

                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                freq[s[left]]++;
                if (freq[s[left]] > 0)
                    count--;

                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};