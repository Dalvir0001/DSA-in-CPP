// Problem: Rotting Oranges
// Approach: Multi-Source BFS
//
// Explanation:
// Add all initially rotten oranges to the queue with time = 0.
// Then perform BFS from all rotten oranges simultaneously.
// For every rotten orange, check its 4 adjacent cells.
// If an adjacent cell contains a fresh orange, make it rotten,
// add it to the queue with time + 1, and count it.
//
// At the end, if all fresh oranges have become rotten,
// return the maximum time taken. Otherwise, return -1.
//
// Time Complexity: O(N * M)
// Space Complexity: O(N * M)

class Solution { 
public: 
    int orangesRotting(vector<vector<int>>& grid) { 
        int n = grid.size(); 
        int m = grid[0].size(); 
 
        queue<pair<pair<int, int>, int>> q; 
        vector<vector<int>> vis(n, vector<int>(m, 0)); 
 
        int cntFresh = 0; 

        for (int i = 0; i < n; i++) { 
            for (int j = 0; j < m; j++) { 
                if (grid[i][j] == 2) { 
                    q.push({{i, j}, 0}); 
                    vis[i][j] = 2; 
                } 

                if (grid[i][j] == 1) { 
                    cntFresh++; 
                } 
            } 
        } 
 
        int tm = 0; 
        int cnt = 0; 
 
        int drow[] = {-1, 0, 1, 0}; 
        int dcol[] = {0, 1, 0, -1}; 
 
        while (!q.empty()) { 
            int r = q.front().first.first; 
            int c = q.front().first.second; 
            int t = q.front().second; 
 
            q.pop(); 
 
            tm = max(tm, t); 
 
            for (int i = 0; i < 4; i++) { 
                int nrow = r + drow[i]; 
                int ncol = c + dcol[i]; 
 
                if (nrow >= 0 && nrow < n && 
                    ncol >= 0 && ncol < m && 
                    grid[nrow][ncol] == 1 && 
                    vis[nrow][ncol] == 0) { 
 
                    q.push({{nrow, ncol}, t + 1}); 
 
                    vis[nrow][ncol] = 2; 
                    cnt++; 
                } 
            } 
        } 
 
        if (cnt != cntFresh) 
            return -1; 
 
        return tm; 
    } 
};