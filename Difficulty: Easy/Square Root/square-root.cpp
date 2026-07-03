class Solution {
  public:
    int floorSqrt(int n) {
        
        int l =0;
        int h=n ;
        int mid =-1;
        int ans=-1;
        
        
        while (l<=h){
            
             mid = (l+h)/2;
             long long sq = 1LL * mid * mid;
             
            if ( sq== n ) {ans = mid ; 
            return ans ;
                
            }
            
           else if ( sq < n){ 
               l=mid +1 ;
               ans = mid ;
               
           }
            
            else{ 
                h=mid-1;
                
            }
        }
        return ans ;
        
    }
};