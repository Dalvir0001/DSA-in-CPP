/*
    Problem: Sudoku Solver
    Platform: LeetCode
    Difficulty: Hard

    Approach:
    1. Traverse the Sudoku board to find an empty cell ('.').
    2. Try placing digits from '1' to '9'.
    3. Check if placing the digit is valid by ensuring:
       - It does not exist in the same row.
       - It does not exist in the same column.
       - It does not exist in the corresponding 3x3 subgrid.
    4. If the placement is valid, recursively solve the remaining board.
    5. If no digit leads to a solution, backtrack by resetting the cell.

    Time Complexity: O(9^(Empty Cells)) (Worst Case)
    Space Complexity: O(Empty Cells) (Recursion Stack)
*/

// Code :-

class Solution {
public:
    bool isSafe(int row , int col , char c , vector<vector<char>>& board)
    {
        for(int i=0; i<9 ; i++)
        {
            if(board[i][col] == c) return false;
            if(board[row][i] == c) return false;
            if(board[3*(row/3)+i/3][3*(col/3)+i%3] == c) return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board)
    {
        for(int i=0 ; i<9 ; i++)
        {
            for(int j=0 ; j<9 ; j++)
            {
                if(board[i][j] == '.')
                {
                    for(char k = '1' ; k<= '9' ; k++){
                        if(isSafe(i , j ,k, board))
                        {
                            board[i][j] = k;
                            if(solve(board))
                            {
                                return true;
                            }
                            else
                            {
                                board[i][j]  ='.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};