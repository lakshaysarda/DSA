class Solution {
  public:

      void dfs(int node, vector<vector<int>>& adj, 
               vector<int>& vis, stack<int>& st) {

          vis[node] = 1;

          for (auto neighbour : adj[node]) {
              if (!vis[neighbour]) {
                  dfs(neighbour, adj, vis, st);
              }
          }

          // Push after visiting all neighbours
          st.push(node);
      }

      vector<int> topoSort(int V, vector<vector<int>>& edges) {

          vector<vector<int>> adj(V);

          // Create adjacency list
          for (auto edge : edges) {
              adj[edge[0]].push_back(edge[1]);
          }

          vector<int> vis(V, 0);
          stack<int> st;

          // DFS from every node
          for (int i = 0; i < V; i++) {
              if (!vis[i]) {
                  dfs(i, adj, vis, st);
              }
          }

          vector<int> ans;

          while (!st.empty()) {
              ans.push_back(st.top());
              st.pop();
          }

          return ans;
      }
  };