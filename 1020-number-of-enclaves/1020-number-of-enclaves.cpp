class Solution {
public:
    void dfs(vector<vector<int>>& grid, int r, int c) {
        int n = grid.size();
        int m = grid[0].size();

        if (r < 0 || r >= n || c < 0 || c >= m)
            return;

        if (grid[r][c] != 1)
            return;

        // Mark boundary-connected land
        grid[r][c] = -1;

        dfs(grid, r + 1, c); // down
        dfs(grid, r - 1, c); // up
        dfs(grid, r, c + 1); // right
        dfs(grid, r, c - 1); // left
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // DFS from first and last column
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1)
                dfs(grid, i, 0);

            if (grid[i][m - 1] == 1)
                dfs(grid, i, m - 1);
        }

        // DFS from first and last row
        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 1)
                dfs(grid, 0, j);

            if (grid[n - 1][j] == 1)
                dfs(grid, n - 1, j);
        }

        // Count remaining 1s
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1)
                    count++;
            }
        }

        return count;
    }
};