class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left = 0;
        int right =0;
        int maxi = 0;
        unordered_map<int,int>mpp;

        while ( right < n) {
            if ( mpp.find(s[right]) == mpp.end()){
                 
               
               
              
            } else{
                if(mpp[s[right]] >= left ){
                left = mpp[s[right]] +1;
                
                }

            }
            maxi = max(maxi ,right-left+1);
            
            mpp[s[right]]=right;
                right++;
        }
        return maxi;
    }
};