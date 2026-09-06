class Solution {
  public:
    int shortestPath(vector<vector<int>> &mat, vector<int> &src, vector<int> &dest) {

        int n = mat.size();
        int m = mat[0].size();

        // If source or destination is blocked
        if (mat[src[0]][src[1]] == 0 || mat[dest[0]][dest[1]] == 0)
            return -1;

        queue<pair<int, pair<int, int>>> q;

        // distance, {row, col}
        q.push({0, {src[0], src[1]}});

        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[src[0]][src[1]] = 0;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while (!q.empty()) {

            auto it = q.front();
            q.pop();

            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;

            // Destination reached
            if (r == dest[0] && c == dest[1])
                return dis;

            for (int i = 0; i < 4; i++) {

                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < m &&
                    mat[nr][nc] == 1 &&
                    dis + 1 < dist[nr][nc]) {

                    dist[nr][nc] = dis + 1;
                    q.push({dis + 1, {nr, nc}});
                }
            }
        }

        return -1;
    }
};