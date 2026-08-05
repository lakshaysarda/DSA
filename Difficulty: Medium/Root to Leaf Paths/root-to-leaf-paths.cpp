class Solution {
public:

    void solve(Node* root, vector<int>& path, vector<vector<int>>& ans) {

        if(root == NULL)
            return;

        path.push_back(root->data);

        // Leaf node
        if(root->left == NULL && root->right == NULL) {
            ans.push_back(path);
            path.pop_back();
            return;
        }

        solve(root->left, path, ans);
        solve(root->right, path, ans);

        path.pop_back();
    }

    vector<vector<int>> paths(Node* root) {

        vector<vector<int>> ans;
        vector<int> path;

        solve(root, path, ans);

        return ans;
    }
};