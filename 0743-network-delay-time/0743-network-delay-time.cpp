class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n + 1];

        for (auto it : times) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
        }

        vector<int> dist(n + 1, 1e9);

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int time = it.first;
            int node = it.second;

            for (auto edge : adj[node]) {
                int adjNode = edge.first;
                int wt = edge.second;

                if (time + wt < dist[adjNode]) {
                    dist[adjNode] = time + wt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        int ans = 0;

        for (int i = 1; i <= n; i++) {
            if (dist[i] == 1e9)
                return -1;

            ans = max(ans, dist[i]);
        }

        return ans;
    }
};