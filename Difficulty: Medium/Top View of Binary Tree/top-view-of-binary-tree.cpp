class Solution {
  public:
    vector<int> topView(Node *root) {
        
        vector<int> ans;
        
        if(root == NULL)
            return ans;
            
        map<int, int> mp;                  // Horizontal Distance -> Node Value
        queue<pair<Node*, int>> q;         // Node, Horizontal Distance
        
        q.push({root, 0});
        
        while(!q.empty()) {
            
            Node* curr = q.front().first;
            int hd = q.front().second;
            q.pop();
            
            // Store only the first node at each horizontal distance
            if(mp.find(hd) == mp.end()) {
                mp[hd] = curr->data;
            }
            
            if(curr->left) {
                q.push({curr->left, hd - 1});
            }
            
            if(curr->right) {
                q.push({curr->right, hd + 1});
            }
        }
        
        for(auto it : mp) {
            ans.push_back(it.second);
        }
        
        return ans;
    }
};