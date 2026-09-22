/*
    Surrounded Regions

    Approach:
    - Any 'O' connected to the boundary cannot be surrounded.
    - Start DFS from all boundary 'O's and mark them as safe using 'S'.
    - Convert all remaining 'O's to 'X' because they are surrounded.
    - Convert the safe 'S's back to 'O'.

    Time Complexity: O(m * n)
    Space Complexity: O(m * n) in the worst case due to DFS recursion.
*/

// Code :-

class Solution {
public:
    int m, n;

    void dfs(vector<vector<char>>& board, int r, int c) {
        if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] != 'O')
            return;

        board[r][c] = 'S';

        dfs(board, r + 1, c);
        dfs(board, r - 1, c);
        dfs(board, r, c + 1);
        dfs(board, r, c - 1);
    }

    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();

        // Mark boundary-connected O's as safe
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O')
                dfs(board, i, 0);

            if (board[i][n - 1] == 'O')
                dfs(board, i, n - 1);
        }

        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O')
                dfs(board, 0, j);

            if (board[m - 1][j] == 'O')
                dfs(board, m - 1, j);
        }

        // Capture surrounded regions
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == 'S')
                    board[i][j] = 'O';
            }
        }
    }
};