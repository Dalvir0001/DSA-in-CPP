/*
    Problem: 01 Matrix

    Approach:
    Use Multi-Source BFS.

    - Put all cells containing 0 into the queue initially.
    - Their distance is already 0.
    - Expand in all 4 directions.
    - For every unvisited cell, its distance is the current
      cell's distance + 1.

    Time Complexity: O(m * n)
    Space Complexity: O(m * n)
*/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> dist(n, vector<int>(m, -1));
        queue<pair<int, int>> q;

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        // Add all 0s as starting points
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        // Multi-source BFS
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nrow = i + drow[k];
                int ncol = j + dcol[k];

                if (nrow >= 0 && nrow < n &&
                    ncol >= 0 && ncol < m &&
                    dist[nrow][ncol] == -1) {

                    dist[nrow][ncol] = dist[i][j] + 1;
                    q.push({nrow, ncol});
                }
            }
        }

        return dist;
    }
};