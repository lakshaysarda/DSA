class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int>ans;
        int n = digits.size();
        int d =n;
        int last =0;
        int rem =1;
        int sum =0;
        for ( int i = digits.size()-1 ; i >=0 ;i--){
          
            sum = digits[i]+rem;

            if (sum >9) {last = sum%10; rem = sum/10;
            ans.push_back(last);
            } 
            else{
                last = sum ;
                rem =0;
                ans.push_back(last);

            }
            
            
        }

        if (rem >0) ans.push_back(rem);
         reverse(ans.begin() , ans.end());
         return ans ;

    }
};