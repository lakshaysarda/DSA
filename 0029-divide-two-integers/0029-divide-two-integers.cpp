class Solution {
public:
    int divide(int dividend, int divisor) {
        
        // abhi only for positive 
        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);

        int sum =0;
        if (divisor == dividend) return 1;
        
        long long ans =0;

       bool sign = true;

if ((dividend < 0 && divisor > 0) ||
    (dividend > 0 && divisor < 0))
{
    sign = false;
}

        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        while ( n >=d ){
            int cnt =0;
            while ( n >= (d<< cnt)){
                cnt ++;
            } 

            ans += (1LL<<(cnt-1));
            n=n-(d<<(cnt-1));
        } 
        if (sign == false) return -ans;
        return ans ;




    }
};