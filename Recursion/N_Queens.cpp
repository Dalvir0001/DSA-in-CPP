/*
## Problem
Given an integer `n`, place `n` queens on an `n × n` chessboard such that no two queens attack each other.

Return all distinct valid board configurations.

## Approach
- Place one queen in each row using recursion.
- For every row, try placing a queen in each column.
- Before placing a queen, check whether:
  - The column is free.
  - The main diagonal (`row - col + n - 1`) is free.
  - The anti-diagonal (`row + col`) is free.
- If the position is safe:
  - Place the queen.
  - Recursively solve for the next row.
  - Backtrack by removing the queen and unmarking the column and diagonals.
- Store the board when all `n` queens have been successfully placed.

## Time Complexity
- **O(N!)**
  - In the worst case, each row tries multiple columns, leading to factorial growth.

## Space Complexity
- **O(N²)** for storing the board.
- **O(N)** recursion stack.
- **O(N)** for column tracking.
- **O(2N−1)** for each diagonal tracking array.
*/

// Code :-

class Solution {
public:
    vector<vector<string>> ans;
    vector<string> board;
    vector<int> col, diag1, diag2;

    void solve(int row, int n) {
        if (row == n) {
            ans.push_back(board);
            return;
        }
        for (int j = 0; j < n; j++) {
            if (col[j] || diag1[row - j + n - 1] || diag2[row + j])
                continue;
            board[row][j] = 'Q';
            col[j] = 1;
            diag1[row - j + n - 1] = 1;
            diag2[row + j] = 1;
            solve(row + 1, n);
            board[row][j] = '.';
            col[j] = 0;
            diag1[row - j + n - 1] = 0;
            diag2[row + j] = 0;
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        board = vector<string>(n, string(n, '.'));

        col = vector<int>(n, 0);
        diag1 = vector<int>(2 * n - 1, 0);
        diag2 = vector<int>(2 * n - 1, 0);

        solve(0, n);

        return ans;
    }
};