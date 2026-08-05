class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<long long , int> maps;
        


        for ( int i =0 ; i< nums.size() ; i++) {
        
        int rem = target - nums[i];
        if (maps.find(rem)  != maps.end()) {
       
        return {maps[rem],i}; // this is alot to learn as we can return like this in a vector i dont need a temp vector to stotre values and then return 
        } 
        maps[nums[i]]  =i;
        } return {};
    }
};