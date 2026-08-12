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
       TreeNode* minimum(TreeNode* root){
        while (root->left){
            root=root->left;
        }
        return root;

}
       TreeNode* deleteNode(TreeNode* root, int key) {

        // we will make the code as finding the target and then performing and giving calls for the the right of the root and the left of the root

        if ( root == NULL) return NULL;

        if ( root->val < key){
           root->right= deleteNode(root->right,key);
        } 
        else if ( root->val > key){
           root->left= deleteNode(root->left,key);
        } 

        else{
            // if the target has no child 

            if (root->left ==NULL && root->right ==NULL){
                delete root;
                return NULL;
            }

            // if only left child 

            if (root->right ==NULL){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            } 

            // pnly right child

             if (root->left ==NULL){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } 

            // both child present 
            else{

                root->val = minimum(root->right)->val;
                root->right = deleteNode(root->right , root->val);



            }
        }

        
        return root;
    }
};