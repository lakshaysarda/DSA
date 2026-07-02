class Solution {
public:

    vector<vector<string>> ans;

    // Checks whether we can place a queen at (row, col)
    bool isSafe(vector<string> &board, int row, int col, int n) {

        // Check upper side of the same column
        int r = row;
        while (r >= 0) {
            if (board[r][col] == 'Q')
                return false;
            r--;
        }

        // Check upper-left diagonal
        r = row;
        int c = col;
        while (r >= 0 && c >= 0) {
            if (board[r][c] == 'Q')
                return false;
            r--;
            c--;
        }

        // Check upper-right diagonal
        r = row;
        c = col;
        while (r >= 0 && c < n) {
            if (board[r][c] == 'Q')
                return false;
            r--;
            c++;
        }

        // Safe position
        return true;
    }

    void solve(vector<string> &board, int row, int n) {

        // Base case
        if (row == n) {
            ans.push_back(board);
            return;
        }

        // Try placing queen in every column of current row
        for (int col = 0; col < n; col++) {

            if (isSafe(board, row, col, n)) {

                // Place queen
                board[row][col] = 'Q';

                // Move to next row
                solve(board, row + 1, n);

                // Backtrack
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<string> board;

        // Initially every row contains only '.'
        for (int i = 0; i < n; i++) {
            board.push_back(string(n, '.'));
        }

        solve(board, 0, n);

        return ans;
    }
};