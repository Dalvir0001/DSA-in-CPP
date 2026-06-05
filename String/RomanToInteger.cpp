// Problem: Roman to Integer
// Platform: LeetCode 13
//
// Approach:
// - Store Roman symbols and their values in an unordered_map.
// - Traverse the string from left to right.
// - If the current symbol has a smaller value than the next symbol,
//   subtract it; otherwise, add it.
//
// Time Complexity: O(n)
// Space Complexity: O(1)


//Code

class Solution {
  public:
    int romanToDecimal(string &s) {
        int n=s.size();
        int ans=0;
        unordered_map<char,int> mpp = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        for(int i=0 ; i<n-1 ; i++)
        {
            if(mpp[s[i]]>=mpp[s[i+1]])
            {
                ans+=mpp[s[i]];
            }
            else{
                ans-=mpp[s[i]];
            }
        }
        ans+=mpp[s[n-1]];
        return ans;
    }
    
};
