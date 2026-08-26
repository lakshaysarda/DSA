class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(V);

        // Create adjacency list
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }
        
        // make a queue and satrt doing bfs traverssal
        //make a vector to maek the indegree
        
      ;
        vector<int>ans;
        
        
         vector<int> ind(V, 0);
          for (int u = 0; u < V; u++) {
              for (int v : adj[u]) {
                  ind[v]++;
              }
          }
        
        
        queue<int>q;
        // ismein humne sabse pehle 0 wala banda dundhna hai 
        for ( int i =0 ; i<V;i++){
            if (ind[i]==0){
                q.push(i);
                
            }
        }
        
        while (!q.empty()){
            // then humein yeh undone krna hai unko nikal and then unke connectors ko indone kro 
            int node = q.front();
            q.pop();
            for( int i =0 ; i < adj[node].size();i++){
                ind[adj[node][i]]--;
                
                if ( ind[adj[node][i]] ==0 )q.push(adj[node][i]);
               
            } 
            ans.push_back(node);
            
            
        }
        return ans ;
        
        
    }
    
};