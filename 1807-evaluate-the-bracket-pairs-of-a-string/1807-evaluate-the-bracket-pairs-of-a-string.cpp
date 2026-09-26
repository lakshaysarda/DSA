class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {

        unordered_map<string, string> mpp;

        // store key -> value
        for (int i = 0; i < knowledge.size(); i++) {
            mpp[knowledge[i][0]] = knowledge[i][1];
        }

        string ans = "";
        int i = 0;

        while (i < s.size()) {

            if (s[i] == '(') {

                i++;              // skip '('
                string w = "";

                while (s[i] != ')') {
                    w += s[i];
                    i++;
                }

                // w is the key
                if (mpp.find(w) != mpp.end()) {
                    ans += mpp[w];
                }
                else {
                    ans += "?";
                }

                i++;              // skip ')'
            }
            else {
                ans += s[i];
                i++;
            }
        }

        return ans;
    }
};