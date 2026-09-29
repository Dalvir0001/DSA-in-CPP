// Approach:
// Perform DFS from all boundary cells containing 1.
// All land cells connected to the boundary cannot be enclaves,
// so we mark them as visited.
// Finally, count the remaining unvisited land cells.
// Time: O(n * m)
// Space: O(n * m)

// Code :-

class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<int>>& grid, int delrow[], int delcol[])
    {
        vis[row][col] = 1;

        int n = grid.size();
        int m = grid[0].size();

        for(int i=0; i<4 ; i++)
        {
            int nRow = row + delrow[i];
            int nCol = col + delcol[i];

            if(nRow<n && nRow>=0 && nCol<m && nCol>=0 && !vis[nRow][nCol] && grid[nRow][nCol] == 1)
            {
                dfs(nRow,nCol,vis,grid,delrow,delcol);
            }
        }

    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        vector<vector<int>> vis(n, vector<int>(m,0));

        for(int i=0 ; i<m ; i++)
        {
            if(grid[0][i] == 1 && !vis[0][i])
            {
                dfs(0, i, vis, grid, delrow, delcol);
            }
            if(grid[n-1][i] == 1 && !vis[n-1][i])
            {
                dfs(n-1, i, vis, grid, delrow, delcol);
            }
        }


        for(int i=0 ; i<n ; i++)
        {
            if(grid[i][0] == 1 && !vis[i][0])
            {
                dfs(i, 0, vis, grid, delrow, delcol);
            }
            if(grid[i][m-1] == 1 && !vis[i][m-1])
            {
                dfs(i, m-1, vis, grid, delrow, delcol);
            }
        }

        int ans = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == 1 && !vis[i][j])
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};