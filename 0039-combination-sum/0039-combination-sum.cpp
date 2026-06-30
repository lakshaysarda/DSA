class Solution {
public: void solve ( vector<int>& nums, int target ,vector<vector<int>> &ans , int index , vector<int>&answ ) { 
    int n = nums.size();
if ( index == n  ){
    if(target ==0)  
    ans.push_back(answ);
    return ;
    
}

if (nums[index] <= target ){
answ.push_back(nums[index]);
solve ( nums, target - nums[index], ans , index ,answ );
answ.pop_back();
}

solve ( nums, target , ans , index+1 ,answ);

}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>answ;
        vector<vector<int>>ans;


         solve ( candidates , target , ans , 0 ,answ );
         return ans;
        
    }
};