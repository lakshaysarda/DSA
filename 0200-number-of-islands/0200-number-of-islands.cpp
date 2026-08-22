class Solution {
public:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        int n = grid.size();
        int m = grid[0].size();

        if (r < 0 || r >= n || c < 0 || c >= m)
            return;

        if (grid[r][c] != '1')
            return;

        grid[r][c] = '0';  // mark visited

        dfs(grid, r + 1, c);
        dfs(grid, r - 1, c);
        dfs(grid, r, c + 1);
        dfs(grid, r, c - 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == '1') {
                    count++;          // new island found
                    dfs(grid, i, j);  // eliminate entire island
                }
            }
        }

        return count;
    }
};