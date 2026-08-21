class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        // we will create a grid in which we are gonna make another grid in which we gonna mark eveeyrbpdy whose rotten as rotten 

        int n = grid.size();
        int m = grid[0].size();
        int maxi = 0;
        
        
        queue<pair<vector<int>,int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // to find the first start 
        for ( int i =0 ; i < n ;i++){

            for (int j =0 ; j<m ;j++){
                if (grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
            }
        }

        
        while(!q.empty()){
            
        

        int r=q.front().first[0];
        int c=q.front().first[1];
        int t=q.front().second;
        maxi = max(maxi , t);
        q.pop();


        // search for their neighbours in the array 
        

        if (r+1 < n && grid[r+1][c] ==1 && vis[r+1][c]==0 ){
            q.push({{r+1,c},t+1});
            vis[r+1][c]=2;

        }   

        if (r-1 >=0 && grid[r-1][c] ==1 && vis[r-1][c]==0){
            q.push({{r-1,c},t+1});
            vis[r-1][c]=2;

        }  

        if (c+1 < m && grid[r][c+1] ==1 && vis[r][c+1]==0){
            q.push({{r,c+1},t+1});
            vis[r][c+1]=2;

        }  

        if (c-1 >=0 && grid[r][c-1] ==1 && vis[r][c-1]==0){
            q.push({{r,c-1},t+1});
            vis[r][c-1]=2;

        }
        }
        
        // check for if any visited then return -1

        for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
        if(grid[i][j] == 1 && vis[i][j] == 0)
            return -1;
    }
}
return maxi;
        

        

        


    }
};