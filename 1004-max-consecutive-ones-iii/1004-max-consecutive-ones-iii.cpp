class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, zeros = 0, maxi = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == 0) zeros++;      // expand window, track zero count
            
            while (zeros > k) {                  // window has too many zeros
                if (nums[left] == 0) zeros--;    // uncount the zero we're kicking out
                left++;                          // shrink from the left
            }
            
            maxi = max(maxi, right - left + 1);  // window [left, right] is valid
        }
        
        return maxi;
    }
};