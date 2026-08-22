class Solution {
  public:

      bool bfs(int start, vector<int>& vis, vector<vector<int>>& adj) {

          queue<pair<int,int>> q;

          q.push({start, -1});
          vis[start] = 1;

          while (!q.empty()) {

              int node = q.front().first;
              int parent = q.front().second;
              q.pop();

              for (auto neighbour : adj[node]) {

                  if (!vis[neighbour]) {

                      vis[neighbour] = 1;
                      q.push({neighbour, node});
                  }

                  else if (neighbour != parent) {
                      return true;
                  }
              }
          }

          return false;
      }

      bool isCycle(int V, vector<vector<int>>& edges) {

          // Create adjacency list
          vector<vector<int>> adj(V);

          for (auto edge : edges) {

              int u = edge[0];
              int v = edge[1];

              adj[u].push_back(v);
              adj[v].push_back(u);
          }

          // Visited array
          vector<int> vis(V, 0);

          // Multiple components
          for (int i = 0; i < V; i++) {

              if (!vis[i]) {

                  if (bfs(i, vis, adj))
                      return true;
              }
          }

          return false;
      }
  };