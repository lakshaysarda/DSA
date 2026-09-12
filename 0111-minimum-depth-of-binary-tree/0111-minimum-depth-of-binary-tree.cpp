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
   //create a function to tell if ekk line type hai kya yeh tree 
    bool checkright(TreeNode* root){

        if ( root == NULL) return true;
        if (root->left == NULL && root->right != NULL){
             return checkright(root->right);
        }
        return false;
    }   

    bool checkleft(TreeNode* root){

        if ( root == NULL) return true;

        if (root->right == NULL && root->left != NULL){
             return checkleft(root->left);
        }
        return false;
    }

    int minDepth(TreeNode* root) {
        // har jagah se return minimum 
        if (root == NULL) return 0;
        

       if (checkleft(root) ){
           
           return 1+ minDepth(root->left);

        } 

        if (checkright(root) ){
           

           return 1+ minDepth(root->right);

        }
        
            if (root == NULL) return 0;

            if (root->left == NULL) {
            return 1 + minDepth(root->right);
        }

        if (root->right == NULL) {
            return 1 + minDepth(root->left);
        }


        int left = minDepth(root->left);
        int right = minDepth(root->right);
        
        return 1 + min(left,right);
        


       
    }
};