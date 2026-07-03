class Solution {
public:

    bool isPossible(vector<vector<char>>& board, int row, int col, char num)
    {
        // Check Row
        for (int i = 0; i < 9; i++)
        {
            if (board[row][i] == num)
                return false;
        }

        // Check Column
        for (int i = 0; i < 9; i++)
        {
            if (board[i][col] == num)
                return false;
        }

        // Check 3 x 3 Box
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;

        for (int i = startRow; i < startRow + 3; i++)
        {
            for (int j = startCol; j < startCol + 3; j++)
            {
                if (board[i][j] == num)
                    return false;
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& board)
    {
        // Find first empty cell
        for (int row = 0; row < 9; row++)
        {
            for (int col = 0; col < 9; col++)
            {
                if (board[row][col] == '.')
                {
                    // Try numbers 1 to 9
                    for (char num = '1'; num <= '9'; num++)
                    {
                        if (isPossible(board, row, col, num))
                        {
                            board[row][col] = num;   // Choose

                            if (solve(board))
                                return true;

                            board[row][col] = '.';   // Backtrack
                        }
                    }

                    // No number works
                    return false;
                }
            }
        }

        // Sudoku solved
        return true;
    }

    void solveSudoku(vector<vector<char>>& board)
    {
        solve(board);
    }
};