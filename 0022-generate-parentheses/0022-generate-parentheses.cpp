class Solution {
public:

    void solve(int open, int close, int n, string s, vector<string>& ans) {

        // Base case: string length becomes 2*n
        if (s.length() == 2 * n) {
            ans.push_back(s);
            return;
        }

        // We can place '(' if we still have some left
        if (open < n) {
            solve(open + 1, close, n, s + '(', ans);
        }

        // We can place ')' only if there are more '(' than ')'
        if (close < open) {
            solve(open, close + 1, n, s + ')', ans);
        }
    }

    vector<string> generateParenthesis(int n) {

        vector<string> ans;

        solve(0, 0, n, "", ans);

        return ans;
    }
};