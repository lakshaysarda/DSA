class Solution {
  public:

    void solve(int idx, string &s, string &temp, vector<string> &ans) {

        if (idx == s.size()) {
            ans.push_back(temp);
            return;
        }

        // Take
        temp.push_back(s[idx]);
        solve(idx + 1, s, temp, ans);

        // Backtrack
        temp.pop_back();

        // Don't take
        solve(idx + 1, s, temp, ans);
    }

    vector<string> powerSet(string s) {

        vector<string> ans;
        string temp = "";

        solve(0, s, temp, ans);

        return ans;
    }
};