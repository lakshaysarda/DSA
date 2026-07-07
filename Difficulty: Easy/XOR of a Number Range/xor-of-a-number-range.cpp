class Solution {
  public:
          int  solve (int n ){
                if ( n%4 == 1) return 1;
                if ( n%4 == 2) return n+1;
        if ( n%4 == 3) return 0 ;
        if ( n%4 == 0) return n;

          }
    int findXOR(int l, int r) {
        // logic is to find from 1 to r and then from 1 to l-1 and then xor both 
      int ans = solve (r)^solve(l-1);
      return ans ;
        
    }
};