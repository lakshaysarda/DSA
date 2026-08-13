class BSTIterator {
public:
    stack<TreeNode*> st;

    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }

    void pushLeft(TreeNode* root) {
        while (root != NULL) {
            st.push(root);
            root = root->left;
        }
    }

    int next() {
        TreeNode* temp = st.top();
        st.pop();

        if (temp->right != NULL)
            pushLeft(temp->right);

        return temp->val;
    }

    bool hasNext() {
        return !st.empty();
    }
};