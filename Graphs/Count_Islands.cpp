// Problem: Count the number of islands in a grid.
// An island is formed by connecting 'L' cells in all 8 directions.
//
// Approach:
// - Traverse the entire grid.
// - Whenever an unvisited land cell 'L' is found, it represents a new island.
// - Use BFS to visit all connected land cells.
// - Check all 8 possible directions for each cell.
//
// Time Complexity: O(n * m)
// Space Complexity: O(n * m)

// Code :-

class Solution {
  public:
    void bfs(int i, int j, vector<vector<char>>& grid,
             vector<vector<int>>& vis)
    {
        queue<pair<int,int>> q;

        int n = grid.size();
        int m = grid[0].size();

        q.push({i, j});
        vis[i][j] = 1;

        while(!q.empty())
        {
            auto ele = q.front();
            q.pop();

            int r = ele.first;
            int c = ele.second;

            // Check all 8 directions
            for(int rn = -1; rn <= 1; rn++)
            {
                for(int cn = -1; cn <= 1; cn++)
                {
                    int row = r + rn;
                    int col = c + cn;

                    if(row >= 0 && row < n &&
                       col >= 0 && col < m &&
                       grid[row][col] == 'L' &&
                       !vis[row][col])
                    {
                        q.push({row, col});
                        vis[row][col] = 1;
                    }
                }
            }
        }
    }

    int countIslands(vector<vector<char>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        int count = 0;

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 'L' && !vis[i][j])
                {
                    bfs(i, j, grid, vis);
                    count++;
                }
            }
        }

        return count;
    }
};