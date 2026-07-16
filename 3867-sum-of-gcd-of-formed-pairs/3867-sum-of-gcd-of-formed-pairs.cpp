class Solution {
public:
  int gcd ( int a , int b ){
    if ( b==0) return a ;

    return gcd(b,(a%b));
  }
    long long gcdSum(vector<int>& nums) {
        int maxi = INT_MIN;
        vector<int>ans;

        for ( int i =0 ; i < nums.size() ;i++){
            maxi = max ( maxi , nums[i]);
            ans.push_back(gcd(maxi,nums[i]));
        }

        sort(ans.begin(),ans.end());
        int l=0 ;
        int r=ans.size()-1;
        long long sum =0;
        while(l<r){
        sum += gcd(ans[r] , ans[l]);
        l++;
        r--;
        }
         
 return sum ;
        }
        
    
};