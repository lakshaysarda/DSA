class Solution {
public:

    int height(TreeNode* root) {

        if (root == NULL)
            return 0;

        return 1 + max(height(root->left), height(root->right));
    }

    void solve(TreeNode* root, int &d) {

        if (root == NULL)
            return;

        int left_h = height(root->left);
        int right_h = height(root->right);

        d = max(d, left_h + right_h);

        solve(root->left, d);
        solve(root->right, d);
    }

    int diameterOfBinaryTree(TreeNode* root) {

        int d = 0;

        solve(root, d);

        return d;
    }
};