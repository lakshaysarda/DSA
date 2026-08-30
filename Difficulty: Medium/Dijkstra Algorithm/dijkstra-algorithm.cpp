class Solution {
  public:
      vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {

          vector<vector<pair<int,int>>> adj(V);

          for(auto it : edges) {
              int u = it[0];
              int v = it[1];
              int wt = it[2];

              adj[u].push_back({v, wt});
              adj[v].push_back({u, wt});
          }

          priority_queue<pair<int,int>,
                         vector<pair<int,int>>,
                         greater<pair<int,int>>> pq;

          vector<int> dist(V, INT_MAX);

          dist[src] = 0;
          pq.push({0, src});

          while(!pq.empty()) {

              int d = pq.top().first;
              int node = pq.top().second;
              pq.pop();

              for(auto it : adj[node]) {

                  int v = it.first;
                  int wt = it.second;

                  if(d + wt < dist[v]) {
                      dist[v] = d + wt;
                      pq.push({dist[v], v});
                  }
              }
          }

          return dist;
      }
  };