/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void markParents(TreeNode* root,
                     unordered_map<TreeNode*, TreeNode*>& parent) {

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }

            if (node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }
    }

    TreeNode* findTarget(TreeNode* root, int start) {
        if (root == nullptr)
            return nullptr;

        if (root->val == start)
            return root;

        TreeNode* left = findTarget(root->left, start);
        if (left)
            return left;

        return findTarget(root->right, start);
    }

    int amountOfTime(TreeNode* root, int start) {

        unordered_map<TreeNode*, TreeNode*> parent;
        markParents(root, parent);

        TreeNode* target = findTarget(root, start);

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;

        q.push(target);
        visited[target] = true;

        int time = 0;

        while (!q.empty()) {

            int size = q.size();
            bool burned = false;

            while (size--) {

                TreeNode* node = q.front();
                q.pop();

                if (node->left && !visited[node->left]) {
                    visited[node->left] = true;
                    q.push(node->left);
                    burned = true;
                }

                if (node->right && !visited[node->right]) {
                    visited[node->right] = true;
                    q.push(node->right);
                    burned = true;
                }

                if (parent.count(node) && !visited[parent[node]]) {
                    visited[parent[node]] = true;
                    q.push(parent[node]);
                    burned = true;
                }
            }

            if (burned)
                time++;
        }

        return time;
    }
};