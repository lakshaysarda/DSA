class Solution {
  public:
    int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
      // edge ke matrix se humein adj banana hai 
     vector<vector<int>> adj(V);


      for ( auto x : edges){
        
              int u=x[0];
              int v=x[1];
              adj[u].push_back(v);
              adj[v].push_back(u);
          
      }
      /// ismein we gonna  be making a queue asn storing the source start point 
      
      queue<pair<int,int>>q ;
      vector<int>nums(V,INT_MAX);
      // updating teh source ka source se distance as 0
      nums[src]=0;
      
      
      
      q.push({src,0});
      
      while(!q.empty()){
          int node = q.front().first;
          int d = q.front().second;
          q.pop();
          
          for ( int i : adj[node]){
              int nd = d+1;
             
            
              if(nums[i] == INT_MAX) {
                                       nums[i] = nd;
                                       q.push({i, nd});
                                   }
          }
      }
      
      
      
      
      if(nums[dest] == INT_MAX)
          return -1;

      
      
        int ans = nums[dest];
        
        return ans;
    }
};
