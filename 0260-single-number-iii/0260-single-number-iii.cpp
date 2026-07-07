class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int>ans;
        long long n =0;
        for ( int x : nums){
             n= n^x;
        }
        // unset righmost set bit 
        // ismien humne yeh jo kra usko wapas dekho and isse hua yeh ki sirf right most wala bacha hai and ab hum bucket problem m ghus gaye hai 
        long long a =( n&(n-1))^n;
        // a is the right most set bit 
        int first =0;
        int second =0;

        for ( int x:nums){
            if (x&a) first ^=x;

            else second^=x;

        } 
        return {first , second};
        
    }
};