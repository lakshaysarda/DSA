class Solution {
public:

    TreeNode* build(vector<int>& preorder,
                    int preStart,
                    int preEnd,
                    vector<int>& inorder,
                    int inStart,
                    int inEnd) {

        if (preStart > preEnd || inStart > inEnd)
            return NULL;

        // First element of preorder = root
        int rootValue = preorder[preStart];

        TreeNode* root = new TreeNode(rootValue);

        // Find root in inorder
        int rootIndex = inStart;

        while (inorder[rootIndex] != rootValue)
            rootIndex++;

        // Number of nodes in left subtree
        int leftSize = rootIndex - inStart;

        // Build left subtree
        root->left = build(
            preorder,
            preStart + 1,
            preStart + leftSize,
            inorder,
            inStart,
            rootIndex - 1
        );

        // Build right subtree
        root->right = build(
            preorder,
            preStart + leftSize + 1,
            preEnd,
            inorder,
            rootIndex + 1,
            inEnd
        );

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        return build(
            preorder,
            0,
            preorder.size() - 1,
            inorder,
            0,
            inorder.size() - 1
        );
    }
};