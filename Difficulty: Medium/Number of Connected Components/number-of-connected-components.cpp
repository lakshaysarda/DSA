class Solution {
  public: 
    void dfs(int node ,vector<vector<int>>&adj,vector<int>&visited){
            visited[node]=1;
            
            for ( int i : adj[node]){
                if (!visited[i]){
                    dfs(i,adj,visited);
                }
            }
        }
    int countConnected(int V, vector<vector<int>>& edges) {
        int prov =0;
        vector<int>visited(V,0);
        
        
        
        // 2d array to an adj list 
        
        vector<vector<int>> adj(V);

        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);  // for undirected graph
        } 
        
        for ( int i = 0 ; i <V ;i++ ){
            if (!visited[i]){
                dfs(i,adj,visited);
                prov ++;
            }
            
        }
        
        return prov;
        
        
        
    }
};