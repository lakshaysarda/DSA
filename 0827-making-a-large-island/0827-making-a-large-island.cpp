class Solution {
public:
    vector<int> parent, size;

    int findUPar(int node) {
        if (node == parent[node])
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }

    int largestIsland(vector<vector<int>>& grid) {

        int n = grid.size();
        int total = n * n;

        parent.resize(total);
        size.resize(total, 1);

        for (int i = 0; i < total; i++)
            parent[i] = i;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        // Step 1: Connect all existing 1s
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {

                if (grid[r][c] == 0)
                    continue;

                int node = r * n + c;

                for (int k = 0; k < 4; k++) {

                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if (nr >= 0 && nr < n &&
                        nc >= 0 && nc < n &&
                        grid[nr][nc] == 1) {

                        int adjNode = nr * n + nc;

                        unionBySize(node, adjNode);
                    }
                }
            }
        }

        int ans = 0;

        // Step 2: Try changing every 0 into 1
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {

                if (grid[r][c] == 1)
                    continue;

                set<int> components;

                for (int k = 0; k < 4; k++) {

                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if (nr >= 0 && nr < n &&
                        nc >= 0 && nc < n &&
                        grid[nr][nc] == 1) {

                        int adjNode = nr * n + nc;

                        components.insert(findUPar(adjNode));
                    }
                }

                int totalSize = 1;

                for (auto it : components) {
                    totalSize += size[it];
                }

                ans = max(ans, totalSize);
            }
        }

        // If grid is already all 1s
                bool allOne = true;

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 0) {
                    allOne = false;
                    break;
                }
            }
        }

        if (allOne)
            return size[findUPar(0)];

        return ans;
        return ans;
    }
};