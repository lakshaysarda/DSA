class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
         if (k == 0) {
            int cnt = 0, ans = 0;
            for (int x : nums) {
                if (x == 1) {
                    cnt++;
                    ans = max(ans, cnt);
                } else {
                    cnt = 0;
                }
            }
            return ans;
        }
        int count =k;
        int n = nums.size();
        int left = 0;
        int right =0;
        int maxi =0;
        queue<pair<int,int>>qu;
        int l =0;
        int r=0;
        

        while(right<n){
        if (nums[right] == 0){
            
            if (count != 0) {
               qu.push({nums[right], right});
                
                count--;
                maxi = max(maxi , right -left+1);
                right++;
            } else{
                
                left = qu.front().second +1;
                qu.pop();
                qu.push({0, right});
                
                
                maxi = max(maxi , right -left+1);
                right ++;

            }
        } 
        else{
            maxi = max(maxi , right -left+1);
                right++;

        }
        }
        return maxi;
    }
};