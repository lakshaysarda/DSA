class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {

        vector<int> ans;

        stack<TreeNode*> st;

        TreeNode* curr = root;
        TreeNode* lastVisited = nullptr;

        while (curr != nullptr || !st.empty()) {

            // Go to leftmost node
            while (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }

            TreeNode* node = st.top();

            // If right child exists and hasn't been processed
            if (node->right != nullptr && lastVisited != node->right) {

                curr = node->right;
            }
            else {

                ans.push_back(node->val);
                lastVisited = node;
                st.pop();
            }
        }

        return ans;
    }
};