class Solution {
public:
    string findOrder(vector<string> &words) {
        int n = words.size();

        vector<vector<int>> adj(26);
        vector<int> indegree(26, 0);
        vector<int> present(26, 0);
        bool edge[26][26] = {};

        for(auto &word : words) {
            for(char c : word)
                present[c - 'a'] = 1;
        }

        for(int i = 0; i < n - 1; i++) {
            string s1 = words[i];
            string s2 = words[i + 1];

            int len = min(s1.size(), s2.size());
            bool found = false;

            for(int j = 0; j < len; j++) {
                if(s1[j] != s2[j]) {
                    int u = s1[j] - 'a';
                    int v = s2[j] - 'a';

                    if(!edge[u][v]) {
                        adj[u].push_back(v);
                        indegree[v]++;
                        edge[u][v] = true;
                    }

                    found = true;
                    break;
                }
            }

            if(!found && s1.size() > s2.size())
                return "";
        }

        queue<int> q;

        for(int i = 0; i < 26; i++) {
            if(present[i] && indegree[i] == 0)
                q.push(i);
        }

        string ans;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            ans += char(node + 'a');

            for(int it : adj[node]) {
                indegree[it]--;

                if(indegree[it] == 0)
                    q.push(it);
            }
        }

        int total = 0;

        for(int i = 0; i < 26; i++)
            total += present[i];

        if(ans.size() != total)
            return "";

        return ans;
    }
};