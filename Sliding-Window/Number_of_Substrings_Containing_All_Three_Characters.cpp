// Approach:
// - Use the Sliding Window technique with two pointers.
// - Expand the right pointer and maintain the frequency of 'a', 'b', and 'c'.
// - Once the current window contains all three characters,
//   every substring ending from the current right index to the
//   end of the string is also valid.
// - Add (n - right) to the answer, then shrink the window
//   from the left to find more valid substrings.
// - Continue until the entire string is processed.
//
// Time Complexity: O(n)
// Space Complexity: O(1)

// Code :-

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int left = 0;
        int ans = 0;

        vector<int> arr(3, 0);

        for (int right = 0; right < n; right++) {
            arr[s[right] - 'a']++;

            while (arr[0] > 0 && arr[1] > 0 && arr[2] > 0) {
                ans += (n - right);
                arr[s[left] - 'a']--;
                left++;
            }
        }
        return ans;
    }
};