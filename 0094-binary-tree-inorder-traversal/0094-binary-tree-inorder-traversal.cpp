class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> ans;

        TreeNode* curr = root;

        while (curr != NULL) {

            // Case 1: No left child
            if (curr->left == NULL) {

                ans.push_back(curr->val);

                curr = curr->right;
            }

            // Case 2: Left child exists
            else {

                // Find predecessor
                TreeNode* prev = curr->left;

                while (prev->right != NULL && prev->right != curr) {
                    prev = prev->right;
                }

                // First time visiting curr
                if (prev->right == NULL) {

                    // Create thread
                    prev->right = curr;

                    // Go to left subtree
                    curr = curr->left;
                }

                // Second time visiting curr
                else {

                    // Remove thread
                    prev->right = NULL;

                    // NOW visit curr
                    ans.push_back(curr->val);

                    // Go right
                    curr = curr->right;
                }
            }
        }

        return ans;
    }
};