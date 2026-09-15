class Solution {
public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(V);

        for (auto e : edges) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        vector<int> vis(V, 0);

        pq.push({0, 0});

        int ans = 0;

        while (!pq.empty()) {
            auto [wt, node] = pq.top();
            pq.pop();

            if (vis[node]) continue;

            vis[node] = 1;
            ans += wt;

            for (auto it : adj[node]) {
                int next = it.first;
                int edgeWt = it.second;

                if (!vis[next]) {
                    pq.push({edgeWt, next});
                }
            }
        }

        return ans;
    }
};