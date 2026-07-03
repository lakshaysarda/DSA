class Solution {
  public:
   int bs (vector<vector<int>> &mat ,int r , int tar ){
       
       int l= 0 ;
       int n = mat[0].size();
       int h = n-1;
       int ans =n;
       while ( l<=h){
           int mid = (l+h)/2;
           
           if ( mat[r][mid] > tar ) {
               ans = mid ;
               h = mid -1;
           }
           else if ( mat[r][mid] <= tar ){
             l=mid+1;           }
       } 
       return ans ;
       
       
   }
  int yes(vector<vector<int>> &mat , int mid ) {
      int n = mat.size();
      int m = mat[0].size();
      
     int ans =0;
      for ( int i =0 ; i < n ; i++){
     ans += bs(mat , i, mid);
     
  }
  return ans ;}
  
  
    int median(vector<vector<int>> &mat) {
         int n = mat.size();
      int m = mat[0].size();
      int k = (m*n)/2;
       
        int l = INT_MAX;
         int h = INT_MIN;

        for (auto &row : mat) {
         for (int x : row) {
        l = min(l, x);
        h = max(h, x);
       }
         }
        int ans =-1;
        
        while ( l<=h ){
            int mid = (l+h)/2;
            
            if (yes(mat , mid ) > k ){
                h = mid -1;
                ans = mid;
            } else {
                l = mid +1;
            }
        } 
        return ans ;
    }
};
