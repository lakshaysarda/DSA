class Solution {
public:

    void dfs(int r, int c, int oldColor, int newColor,
             vector<vector<int>>& image) {

        int n = image.size();
        int m = image[0].size();

        // Out of bounds
        if (r < 0 || r >= n || c < 0 || c >= m)
            return;

        // Only fill cells having the original color
        if (image[r][c] != oldColor)
            return;

        image[r][c] = newColor;

        // Down
        dfs(r + 1, c, oldColor, newColor, image);

        // Up
        dfs(r - 1, c, oldColor, newColor, image);

        // Right
        dfs(r, c + 1, oldColor, newColor, image);

        // Left
        dfs(r, c - 1, oldColor, newColor, image);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                   int sr, int sc, int color) {

        int oldColor = image[sr][sc];

        // Important edge case
        if (oldColor == color)
            return image;

        dfs(sr, sc, oldColor, color, image);

        return image;
    }
};