class Solution {
public:

    bool dfs(int node, vector<vector<int>>& graph, 
             vector<int>& color) {

        // Check all neighbours
        for (auto neighbour : graph[node]) {

            // Not visited
            if (color[neighbour] == -1) {

                // Give opposite colour
                color[neighbour] = 1 - color[node];

                // Continue DFS
                if (!dfs(neighbour, graph, color))
                    return false;
            }

            // Already visited
            else {
                // Same colour as current node -> not bipartite
                if (color[neighbour] == color[node])
                    return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();

        // -1 means not visited
        vector<int> color(n, -1);

        // Important: graph may be disconnected
        for (int i = 0; i < n; i++) {

            if (color[i] == -1) {

                // Give starting node any colour
                color[i] = 0;

                if (!dfs(i, graph, color))
                    return false;
            }
        }

        return true;
    }
};