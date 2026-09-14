class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n];

        for (auto it : roads) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        vector<long long> dist(n, 1e18);
        vector<int> ways(n, 0);

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        dist[0] = 0;
        ways[0] = 1;

        pq.push({0, 0});

        int mod = 1e9 + 7;

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            long long d = it.first;
            int node = it.second;

            for (auto edge : adj[node]) {
                int adjNode = edge.first;
                int wt = edge.second;

                if (d + wt < dist[adjNode]) {
                    dist[adjNode] = d + wt;

                    ways[adjNode] = ways[node];

                    pq.push({dist[adjNode], adjNode});
                }
                else if (d + wt == dist[adjNode]) {
                    ways[adjNode] =
                        (ways[adjNode] + ways[node]) % mod;
                }
            }
        }

        return ways[n - 1];
    }
};