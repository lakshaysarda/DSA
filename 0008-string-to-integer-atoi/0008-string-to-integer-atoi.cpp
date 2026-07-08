class Solution {
public:

    long long digitmaker(string &s, int i, long long ans, bool negative) {

        // Stop if end of string or current character is not a digit
        if (i == s.size() || !isdigit(s[i]))
            return ans;

        // Check overflow before adding the next digit
        if (!negative) {
            if (ans > (INT_MAX - (s[i] - '0')) / 10)
                return INT_MAX;
        } else {
            if (ans > (-(long long)INT_MIN - (s[i] - '0')) / 10)
                return -(long long)INT_MIN;
        }

        ans = ans * 10 + (s[i] - '0');

        return digitmaker(s, i + 1, ans, negative);
    }

    int myAtoi(string s) {

        int i = 0;

        // Skip leading spaces
        while (i < s.size() && s[i] == ' ')
            i++;

        // Empty string after spaces
        if (i == s.size())
            return 0;

        bool negative = false;

        // Check sign
        if (s[i] == '+' || s[i] == '-') {
            if (s[i] == '-')
                negative = true;
            i++;
        }

        // First character after sign must be a digit
        if (i == s.size() || !isdigit(s[i]))
            return 0;

        long long ans = digitmaker(s, i, 0, negative);

        if (negative) {
            if (ans == -(long long)INT_MIN)
                return INT_MIN;
            return -ans;
        }

        if (ans == INT_MAX)
            return INT_MAX;

        return ans;
    }
};