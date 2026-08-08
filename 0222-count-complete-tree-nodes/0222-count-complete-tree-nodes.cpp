class Solution {
public:

    int leftHeight(TreeNode* root) {
        int h = 0;

        while (root != NULL) {
            h++;
            root = root->left;
        }

        return h;
    }

    int rightHeight(TreeNode* root) {
        int h = 0;

        while (root != NULL) {
            h++;
            root = root->right;
        }

        return h;
    }

    int countNodes(TreeNode* root) {

        if (root == NULL)
            return 0;

        int left = leftHeight(root);
        int right = rightHeight(root);

        // Perfect subtree
        if (left == right) {
            return (1 << left) - 1;
        }

        // Not perfect, so count recursively
        return 1 + countNodes(root->left)
                 + countNodes(root->right);
    }
};