/*
Problem: Rat in a Maze
Platform: GeeksforGeeks
Difficulty: Medium

Approach:
- Use Backtracking (DFS).
- Explore all possible paths.
- Mark cells as visited while exploring.
- Backtrack by unmarking the cell after all recursive calls.
- Store all valid paths and sort them lexicographically.

Time Complexity: O(4^(N*N)) in the worst case
Space Complexity: O(N*N)
*/

// Code :-

class Solution {
  public:
    void solve(int n , int r , int c , string &str , vector<string> &ans ,vector<vector<int>> &visited )
    {
        if(r == n-1 && c == n-1)
        {
            ans.push_back(str);
            return;
        }
        if(r < 0 || c < 0 || r==n || c==n || visited[r][c] == 0 ) return;
        
        visited[r][c] = 0;
        
        str.push_back('R');
        solve(n , r , c+1 , str , ans , visited);
        str.pop_back();
        
        str.push_back('D');
        solve(n , r+1 , c , str , ans , visited);
        str.pop_back();
        
        str.push_back('U');
        solve(n , r-1 , c , str , ans , visited);
        str.pop_back();
        
        str.push_back('L');
        solve(n , r , c-1 , str , ans , visited);
        str.pop_back();
        visited[r][c] = 1;
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        vector<string> ans;
        vector<vector<int>> visited = maze;
        string str;
        if(maze[0][0] == 0 || maze[n-1][n-1] == 0) return ans;
        solve( n , 0 , 0 ,str,ans , visited);
        sort(ans.begin(),ans.end());
        return ans;
    }
};