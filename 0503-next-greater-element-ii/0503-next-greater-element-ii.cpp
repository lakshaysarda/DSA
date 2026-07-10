class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
       vector<int> nge(nums.size(), -1);
        int n =nums.size();
        for ( int i =0 ; i < nums.size() ; i ++ ){

            for ( int j = i+1; j<= i+n-1 ; j++){
                int ind = j%n;
                if (nums[ind] > nums[i]){
                    nge[i] = nums[ind];
                    break;
                    } 
            }
        }
        return nge;
    }
};