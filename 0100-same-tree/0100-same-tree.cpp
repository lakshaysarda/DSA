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
    bool solve (TreeNode* p, TreeNode* q){
       
         // Both are NULL
        if (p == NULL && q == NULL)
            return true;

        // One is NULL
        if (p == NULL || q == NULL)
            return false;

        // Values differ
        if (p->val != q->val)
            return false;
       

        bool left = solve ( p->left,  q->left);
        bool right = solve ( p->right,  q->right);

        if ( left == true && right == true){
            return true;
        }
        return false;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {

        return solve (p,q);
    }
};