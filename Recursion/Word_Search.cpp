/*
# 79. Word Search

## Problem
Given an `m x n` grid of characters and a word, determine whether the word exists in the grid.

The word can be constructed from sequentially adjacent cells (up, down, left, right). A cell can only be used once in a single path.

## Approach
- Iterate through every cell of the board.
- Start a DFS whenever the current cell matches the first character of the word.
- During DFS:
  - Check boundary conditions.
  - Verify the current character matches the target character.
  - Mark the current cell as visited.
  - Recursively explore all four directions.
  - Backtrack by unmarking the cell before returning.
- Return `true` if any DFS successfully matches the entire word.

## Time Complexity
- **O(M × N × 3^L)**
  - `M × N` = number of starting cells.
  - `L` = length of the word.
  - After the first move, there are at most 3 choices because the previous cell cannot be revisited.

## Space Complexity
- **O(M × N)** for the visited matrix.
- **O(L)** recursion stack depth.
*/

// Code :-

class Solution {
public:
    bool dfs(int i, int j, int index, vector<vector<int>> &visited, vector<vector<char>> &board, string &word) {

        if (index == word.length())
            return true;
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
            return false;
        if (board[i][j] != word[index])
            return false;
        if (visited[i][j])
            return false;
        visited[i][j] = 1;

        bool found =
            dfs(i - 1, j, index + 1, visited, board, word) ||
            dfs(i + 1, j, index + 1, visited, board, word) ||
            dfs(i, j - 1, index + 1, visited, board, word) ||
            dfs(i, j + 1, index + 1, visited, board, word);
        visited[i][j] = 0;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int rows = board.size();
        int cols = board[0].size();

        vector<vector<int>> visited(rows, vector<int>(cols, 0));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {

                if (board[i][j] == word[0]) {
                    if (dfs(i, j, 0, visited, board, word))
                        return true;
                }
            }
        }

        return false;
    }
};