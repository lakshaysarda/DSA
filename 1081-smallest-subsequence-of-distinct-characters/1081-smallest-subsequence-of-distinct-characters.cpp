class Solution {
public:
    string smallestSubsequence(string s) {

        unordered_map<char,int> last;

        for(int i = 0; i < s.size(); i++)
            last[s[i]] = i;

        stack<char> st;
        unordered_set<char> vis;

        for(int i = 0; i < s.size(); i++) {

            char ch = s[i];

            if(vis.count(ch))
                continue;

            while(!st.empty() &&
                  ch < st.top() &&
                  last[st.top()] > i)
            {
                vis.erase(st.top());
                st.pop();
            }

            st.push(ch);
            vis.insert(ch);
        }

        string ans;

        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};