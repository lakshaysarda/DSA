class Solution {
public:
    int mySqrt(int x) {
        long long l = 1;
        long long  h = x;
        long long ans =0;


        while(l<=h){
            long long mid = (l + h) / 2;
            long long v = mid*mid;

            if (v <= x){
                ans = mid;
                l = mid+1;
            }
              else
              { 
             h = mid -1;}}
            
        
        return ans ;
    }
};