/*
Problem: Palindromic Partitioning (GFG)

Approach:
- Pure Recursion
- Try every possible palindrome substring starting from the current index.
- Recursively solve the remaining string.
- Return the minimum number of palindrome partitions.
- Final answer = partitions - 1 (cuts = partitions - 1).

Time Complexity: Exponential (approximately O(2^n * n))
Space Complexity: O(n) (recursion stack)

Note:
This recursive solution demonstrates the brute-force approach and may result
in TLE for large inputs. Memoization and DP optimize it to O(n²).
*/

// Code :-

class Solution {
     bool isPalindrome(int i, int j,string &s) {
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int solve(int i ,int n , string &s)
    {
        if(i == n) return 0;
        int minCost = INT_MAX;
        for(int j = i ; j < n ; j++)
        {
            if(isPalindrome(i , j , s))
            {
                int cost = 1 + solve(j+1 , n , s);
                minCost = min(minCost , cost);
            }
        }
        return minCost;
    }
  public:
    int palPartition(string &s) {
        int n = s.size();
        return solve(0 ,n ,s)-1;
    }
};