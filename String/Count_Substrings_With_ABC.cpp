/*
Problem: Count Substrings with a, b and c

Approach: Sliding Window
Time Complexity: O(n)
Space Complexity: O(1)

Idea:
Expand the window until it contains at least one 'a', 'b', and 'c'.
For every valid window, add (n - j) because all extensions of the
current window are also valid. Then shrink the window from the left.
*/

//Code

class Solution {
  public:
    int countSubstring(string &s) {
        int n=s.size();
        int ans=0;
        int i=0 , j=0;
        int ca=0; int cb=0; int cc=0;
       while(j<n)
       {
           if(s[j]=='a') { ca++; } 
           else if(s[j]=='b') { cb++; } 
           else if(s[j]=='c') { cc++; }
           while(ca>0&&cb>0&&cc>0) 
           { ans+=n-j; 
              if(s[i]=='a') { ca--; } 
           else if(s[i]=='b') { cb--; } 
           else if(s[i]=='c') { cc--; }
              i++;
           }
           j++;
       }
        return ans;
    }
};
