class Solution {
  public:
    int nthRoot(int n, int m) {
    
        
        int l =0;
        int h=m ;
        int mid =-1;
        int ans=-1;
        
        
        while (l<=h){
            
             mid = (l+h)/2;
             long long sq = 1;
             for ( int i =0 ; i < n ; i++){
                 sq = sq * mid ;
                  if (sq > m) break;
             }
             
             
            if ( sq== m ) {
            return mid;
                
            }
            
           else if ( sq < m){ 
               l=mid +1 ;
             
               
           }
            
            else{ 
                h=mid-1;
                
            }
        }
        return -1 ;
        
    }
};
 