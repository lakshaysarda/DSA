class Solution {
public:

    void dfs(int node, vector<vector<int>>& adj,
             vector<int>& visited, vector<int>& ans) {

        visited[node] = 1;
        ans.push_back(node);

        for (int neighbour : adj[node]) {

            if (!visited[neighbour]) {
                dfs(neighbour, adj, visited, ans);
            }
        }
    }

    vector<int> dfs(vector<vector<int>>& adj) {

        // Zero-based indexing
        vector<int> visited(adj.size(), 0);

        vector<int> ans;

        dfs(0, adj, visited, ans);

        return ans;
    }
};