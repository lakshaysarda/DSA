class Solution {
public:
    int m, n;

    int dp[105][105][205];

    bool solve(int i, int j, int open, vector<vector<char>>& grid) {

        if (open < 0)
            return false;

        if (i == m - 1 && j == n - 1)
            return open == 0;

        if (dp[i][j][open] != -1)
            return dp[i][j][open];

        bool right = false;
        bool down = false;

        if (j + 1 < n) {
            if (grid[i][j + 1] == '(')
                right = solve(i, j + 1, open + 1, grid);
            else
                right = solve(i, j + 1, open - 1, grid);
        }

        if (i + 1 < m) {
            if (grid[i + 1][j] == '(')
                down = solve(i + 1, j, open + 1, grid);
            else
                down = solve(i + 1, j, open - 1, grid);
        }

        return dp[i][j][open] = right || down;
    }

    bool hasValidPath(vector<vector<char>>& grid) {

        m = grid.size();
        n = grid[0].size();

        if ((m + n - 1) % 2 != 0)
            return false;

        memset(dp, -1, sizeof(dp));

        int open = 0;

        if (grid[0][0] == '(')
            open++;
        else
            open--;

        return solve(0, 0, open, grid);
    }
};