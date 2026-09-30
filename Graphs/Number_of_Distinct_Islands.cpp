// Number of Distinct Islands
// Approach: DFS + Relative Coordinates
// Time Complexity: O(N * M * log K)
// Space Complexity: O(N * M)

// Code :-

class Solution {
  public:
    void dfs(int row, int col, int baserow, int basecol,
             vector<vector<char>>& grid,
             vector<vector<int>>& vis,
             vector<pair<int,int>>& shape)
    {
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        vis[row][col] = 1;

        int n = grid.size();
        int m = grid[0].size();

        // Store coordinates relative to the starting cell
        shape.push_back({row - baserow, col - basecol});

        for(int i = 0; i < 4; i++)
        {
            int nRow = row + delrow[i];
            int nCol = col + delcol[i];

            if(nRow < n && nRow >= 0 &&
               nCol < m && nCol >= 0 &&
               !vis[nRow][nCol] &&
               grid[nRow][nCol] == 'L')
            {
                dfs(nRow, nCol, baserow, basecol, grid, vis, shape);
            }
        }
    }

    int countDistinctIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        set<vector<pair<int,int>>> st;

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 'L' && !vis[i][j])
                {
                    vector<pair<int,int>> shape;

                    dfs(i, j, i, j, grid, vis, shape);

                    // Store only unique island shapes
                    st.insert(shape);
                }
            }
        }

        return st.size();
    }
};