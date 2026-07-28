class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        
        int  n= nums.size();

        for ( int i =0 ; i <nums.size();i++) {
        int a =i;

            if (i > 0 && nums[i] == nums[i - 1])
                continue;
           
           int b = i+1 ;
           int c = n-1;

           while ( b < c) {

            if ( nums[a]+nums[b]+nums[c] == 0) {

              ans.push_back({nums[a], nums[b], nums[c]});
               b++;
                c--;
              while ( b<c && nums[b]==nums[b-1]) b++;
               while ( b<c && nums[c]==nums[c+1]) c--;
                

                
               


            } else if ( nums[a]+nums[b]+nums[c]< 0 ){
                b++;

            } else if ( nums[a]+nums[b]+nums[c]> 0 ){
                c--;
           }

            }
        }
    
   
   return ans ;
    
    
    
    }
};