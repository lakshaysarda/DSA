class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        int ans_s = -1;

       if ( num[n-1] %2 == 1 ) return num;

        if ( num[n-1] %2 == 0 ) {
            for ( int i =n-1 ; i >=0 ; i --){

                if (num[i]%2 == 1){
                    ans_s = i;
                    break;
                }

            }
        } if ( ans_s == -1 ) return "";

        string ans = "";
        for ( int i =0 ; i <= ans_s ; i++ ){
            ans += num[i];
        }
        return ans ;

    }
};