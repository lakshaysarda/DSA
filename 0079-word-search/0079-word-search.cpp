class Solution {
public:

    bool solve(int curr, int i, int j,
               vector<vector<char>>& board,
               string& word,
               vector<vector<bool>>& visited) {

        // Entire word matched
        if (curr == word.length() - 1)
            return true;

        // Move Up
        if (i - 1 >= 0 &&
            board[i - 1][j] == word[curr + 1] &&
            !visited[i - 1][j]) {

            visited[i - 1][j] = true;

            bool ans = solve(curr + 1, i - 1, j, board, word, visited);

            if (ans)
                return true;

            visited[i - 1][j] = false;
        }

        // Move Left
        if (j - 1 >= 0 &&
            board[i][j - 1] == word[curr + 1] &&
            !visited[i][j - 1]) {

            visited[i][j - 1] = true;

            bool ans = solve(curr + 1, i, j - 1, board, word, visited);

            if (ans)
                return true;

            visited[i][j - 1] = false;
        }

        // Move Down
        if (i + 1 < board.size() &&
            board[i + 1][j] == word[curr + 1] &&
            !visited[i + 1][j]) {

            visited[i + 1][j] = true;

            bool ans = solve(curr + 1, i + 1, j, board, word, visited);

            if (ans)
                return true;

            visited[i + 1][j] = false;
        }

        // Move Right
        if (j + 1 < board[0].size() &&
            board[i][j + 1] == word[curr + 1] &&
            !visited[i][j + 1]) {

            visited[i][j + 1] = true;

            bool ans = solve(curr + 1, i, j + 1, board, word, visited);

            if (ans)
                return true;

            visited[i][j + 1] = false;
        }

        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {

        int rows = board.size();
        int cols = board[0].size();

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for (int i = 0; i < rows; i++) {

            for (int j = 0; j < cols; j++) {

                if (board[i][j] == word[0]) {

                    visited[i][j] = true;

                    bool ans = solve(0, i, j, board, word, visited);

                    if (ans)
                        return true;

                    visited[i][j] = false;
                }
            }
        }

        return false;
    }
};