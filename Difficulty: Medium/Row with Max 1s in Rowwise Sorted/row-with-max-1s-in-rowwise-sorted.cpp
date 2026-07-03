class Solution {
  public:
       int binary(vector<vector<int>> &arr  , int r) {
           
           int low = 0 ;
           int high = arr[0].size() - 1;
           int index = -1;
           int n = arr.size();
           int mid = -1;
           
           
           while ( low<= high ) {
               int mid = (low+high)/2;
               
                if (arr[r][mid] == 1) {
                   index = mid ;
                   high = mid -1;
                   
               }
               
               else if (arr[r][mid] == 0){
                 low = mid +1;
               }
               
               
           }
          int m = arr[0].size();
          if ( index ==-1) return -1;
            return m - index;
       }
  
    int rowWithMax1s(vector<vector<int>> &arr) {
        int index =-1;
        int maxi = 0;
        
        
        for ( int i =0 ; i < arr.size() ; i ++) {
            
            if (binary(arr  ,  i) > maxi ){
                maxi = binary(arr  ,  i);
                index = i ;
            }
        }
        return index ;
    }
};