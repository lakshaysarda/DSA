class Solution {
public:

    bool dfs(int node, int parent, vector<int>& vis,
             vector<vector<int>>& adj) {

        vis[node] = 1;

        for (auto neighbour : adj[node]) {

            if (!vis[neighbour]) {

                if (dfs(neighbour, node, vis, adj))
                    return true;
            }

            else if (neighbour != parent) {
                return true;
            }
        }

        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {

        vector<vector<int>> adj(V);

        // Build adjacency list
        for (auto edge : edges) {

            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(V, 0);

        // Handle multiple components
        for (int i = 0; i < V; i++) {

            if (!vis[i]) {

                if (dfs(i, -1, vis, adj))
                    return true;
            }
        }

        return false;
    }
};