/*
Approach:
- Use a sliding window with an unordered_map to keep track of the frequency
  of each fruit type in the current window.
- Expand the window by moving the right pointer.
- If the window contains more than two distinct fruit types, shrink it
  from the left until only two types remain.
- Update the maximum window size after every valid window.

Time Complexity: O(n)
Space Complexity: O(1)   // O(3) in practice, O(k) in general where k is the number of distinct fruits
*/

// Code :-

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int left = 0;
        int right = 0;
        int len = 0;
        int maxlen = 0;
        unordered_map<int,int> mpp;
        while (right < n) {
        mpp[fruits[right]]++;

        while (mpp.size() > 2) {
            mpp[fruits[left]]--;
            if (mpp[fruits[left]] == 0)
                mpp.erase(fruits[left]);
            left++;
        }
        maxlen = max(maxlen, right - left + 1);
        right++;
    }
        return maxlen;
    }
};