class Solution {
public:

    void solve(vector<int>& nums ,vector<vector<int>>&ans , int index ,vector<int>yes){

     // base case
     if ( index == nums.size()) {
     ans.push_back(yes);
     return;
     }

        yes.push_back(nums[index]);
        solve(nums , ans , index +1 , yes);

        //track back
        yes.pop_back();
        solve(nums , ans , index +1 , yes);

        



    }
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>>ans;
        int index =0;
        vector<int>yes;

        solve(nums  , ans , 0 , yes);
        return ans ;
        
    }
};