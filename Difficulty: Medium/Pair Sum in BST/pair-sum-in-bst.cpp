class Solution {
public:

    void inorder(Node* root, vector<int>& ans) {

        if(root == NULL)
            return;

        inorder(root->left, ans);

        ans.push_back(root->data);

        inorder(root->right, ans);
    }

    bool findTarget(Node *root, int target) {

        vector<int> ans;
        inorder(root, ans);

        unordered_map<int,int> mpp;

        for(int i = 0; i < ans.size(); i++) {
            mpp[ans[i]]++;
        }

        for(int i = 0; i < ans.size(); i++) {

            mpp[ans[i]]--;

            if(mpp.find(target - ans[i]) != mpp.end() &&
               mpp[target - ans[i]] > 0) {
                return true;
            }
        }

        return false;
    }
};