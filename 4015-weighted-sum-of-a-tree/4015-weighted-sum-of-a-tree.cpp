

class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();
        // if parent array is given then how to find the root array and make a tree

   
          vector<vector<int>> children(n);

        for (int i = 1; i < n; i++) {
            
            children[parent[i]].push_back(i);
        }

           vector<int> depth(n);

        
        depth[0] = 1;

        queue<int> q;
        q.push(0);

 int h = 1;

       
          while (!q.empty()) {

            int node = q.front();
            q.pop();

              h = max(h, depth[node]);

            for (int i : children[node]) {
                depth[i] = depth[node] + 1;
                q.push(i);
            }
        }

      
         

        long long ans = 0;

        for (int i = 0; i < n; i++) {

            int multiplier = h - depth[i] + 1;

            ans += 1LL * nums[i] * multiplier;
        }

        return ans;
    }
};