// Problem: Flood Fill
//
// Approach:
// - Store the original color of the starting cell.
// - Use DFS to visit all connected cells having the original color.
// - For each cell, check its 4 adjacent directions.
// - Change each valid cell to the new color.
//
// Time Complexity: O(n * m)
// Space Complexity: O(n * m) in the worst case due to recursion.

// Code :-

class Solution {
public:

    void dfs(vector<vector<int>>& image, int r, int c,
             int original, int color)
    {
        image[r][c] = color;

        int n = image.size();
        int m = image[0].size();
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr >= 0 && nr < n &&
               nc >= 0 && nc < m &&
               image[nr][nc] == original)
            {
                dfs(image, nr, nc, original, color);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                   int sr, int sc, int color)
    {
        int original = image[sr][sc];
        if(original == color)
            return image;

        dfs(image, sr, sc, original, color);

        return image;
    }
};