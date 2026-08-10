

class Solution {
public:
    int findMaxFork(Node* root, int x) {
        
        if (root == NULL)
            return -1;
        
        if (root->data == x)
            return root->data;
        
        if (root->data > x)
            return findMaxFork(root->left, x);
        
        // root->data < x
        int ans = findMaxFork(root->right, x);
        
        if (ans != -1)
            return ans;
        
        return root->data;
    }
};