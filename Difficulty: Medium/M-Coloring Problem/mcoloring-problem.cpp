class Solution {
public:

    bool isSafe(int node, int col,
                vector<int> &color,
                vector<vector<int>> &adj)
    {
        for (int neighbour : adj[node])
        {
            if (color[neighbour] == col)
                return false;
        }

        return true;
    }

    bool solve(int node,
               int V,
               int m,
               vector<int> &color,
               vector<vector<int>> &adj)
    {
        // Base Case
        if (node == V)
            return true;

        // Try every color
        for (int col = 1; col <= m; col++)
        {
            if (isSafe(node, col, color, adj))
            {
                color[node] = col;      // Choose

                if (solve(node + 1, V, m, color, adj))
                    return true;

                color[node] = 0;        // Backtrack
            }
        }

        return false;
    }

    bool graphColoring(int V, vector<vector<int>> &edges, int m)
    {
        vector<vector<int>> adj(V);

        // Convert edge list to adjacency list
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> color(V, 0);

        return solve(0, V, m, color, adj);
    }
};