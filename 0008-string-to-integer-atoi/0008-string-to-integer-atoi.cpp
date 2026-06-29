class Solution {
public:
    int myAtoi(string s) {
int i =0;
int n = s.size();
        
        while ( i < n && s[i] == ' ' ){
            i++;
        }
        //leading zeroes 
        

         int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-')
                sign = -1;
            i++;
        }

        

        

     long long num = 0;

        // Read digits
        while (i < n && isdigit(s[i])) {

            if (!isdigit(s[i]))
    break;

            num = num * 10 + (s[i] - '0');

            // Handle overflow
            if (sign * num > INT_MAX)
                return INT_MAX;

            if (sign * num < INT_MIN)
                return INT_MIN;

            i++;
        }

        return sign * num;
    }

       
};