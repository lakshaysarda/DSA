class Solution {
public:
    string removeOuterParentheses(string s) {
        int count =0;
        string ans="";

        for ( int i =0 ; i < s.size() ;i++){
            if (s[i] == '('){
            //check cond first then inc count
            if (count ==0){
                count ++;

            } else {
                ans.push_back(s[i]);
                count++;
            }

            } else{
                count --;
                if (count >0){
                    ans.push_back(s[i]);
                } 

            }
        }
        return ans ;
        
    }
};