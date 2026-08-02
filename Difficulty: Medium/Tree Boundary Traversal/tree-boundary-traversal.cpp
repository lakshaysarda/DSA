class Solution {
public:

    bool isLeaf(Node* root) {
        return root->left == NULL && root->right == NULL;
    }

    void leftBoundary(Node* root, vector<int>& ans) {
        Node* curr = root->left;

        while (curr) {
            if (!isLeaf(curr))
                ans.push_back(curr->data);

            if (curr->left)
                curr = curr->left;
            else
                curr = curr->right;
        }
    }

    void leafNodes(Node* root, vector<int>& ans) {
        if (root == NULL)
            return;

        if (isLeaf(root)) {
            ans.push_back(root->data);
            return;
        }

        leafNodes(root->left, ans);
        leafNodes(root->right, ans);
    }

    void rightBoundary(Node* root, vector<int>& ans) {
        Node* curr = root->right;
        vector<int> temp;

        while (curr) {
            if (!isLeaf(curr))
                temp.push_back(curr->data);

            if (curr->right)
                curr = curr->right;
            else
                curr = curr->left;
        }

        reverse(temp.begin(), temp.end());

        for (int x : temp)
            ans.push_back(x);
    }

    vector<int> boundaryTraversal(Node *root) {

        vector<int> ans;

        if (root == NULL)
            return ans;

        if (!isLeaf(root))
            ans.push_back(root->data);

        leftBoundary(root, ans);
        leafNodes(root, ans);
        rightBoundary(root, ans);

        return ans;
    }
};