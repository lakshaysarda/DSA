class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int left =0;
        int right =0;
        
        int ans =0;
        
        map<char,int>mpp;

        while (right <n){
             mpp[s[right]]++;
          if (mpp.size()== 3 ){
            if (mpp['a']>=1 && mpp['b']>=1 && mpp['c']>=1){
             
              

               while(mpp['a']>=1 && mpp['b']>=1 && mpp['c']>=1){
                   ans += (n-right);
                    mpp[s[left]]--;
                    left++;
                }
                right++;
            }  else{
                right++;
            }
          } else{
            right++;
          }
        }
        return ans ;
        
    }
};