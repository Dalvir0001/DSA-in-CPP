/*
Approach:
1. Traverse s1 and greedily match characters of s2.
2. Once the complete subsequence is matched, record the ending index.
3. Traverse backward to find the earliest possible starting index
   while still preserving the subsequence.
4. Update the minimum window if the current one is smaller.
5. Resume searching for the next possible window.

Time Complexity: O(n * m)
Space Complexity: O(1)
*/

// Code :-

class Solution {
  public:
    string minWindow(string& s1, string& s2) {
        int n = s1.size();
        int m = s2.size();
        int right = 0;
        int minLen = INT_MAX;
        int start = -1;
        while(right<n)
        {
            int left = 0;
            while(right < n)
            {
                if(s1[right] == s2[left])
                {
                    left++;
                }
                if(left == m) break;
                right++;
            }
            if(right == n) break;
            
            int end = right;
            left = m-1;
            while(left>=0)
            {
                if(s1[right] == s2[left])
                left--;
                right--;
            }
            right++;
            int len = end - right + 1;
            
            if(len<minLen)
            {
                minLen = len;
                start = right;
            }
            right++;
        }
        if(start == -1) return "";
        return s1.substr(start , minLen);
    }
};
