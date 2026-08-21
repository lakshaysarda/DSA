class Solution {
public:
    vector<int> bfs(vector<vector<int>>& adj) {

        vector<int> visited(adj.size(), 0);
        queue<int> q;
        vector<int> ans;

        visited[0] = 1;
        q.push(0);
        ans.push_back(0);

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            for (int neighbour : adj[node]) {

                if (!visited[neighbour]) {
                    visited[neighbour] = 1;
                    q.push(neighbour);
                    ans.push_back(neighbour);
                }
            }
        }

        return ans;
    }
};