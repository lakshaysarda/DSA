/* Structure of a Tree Node
class Node {
public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    bool isSumProperty(Node *root) {
        
        if ( root == NULL ) return true;
        if(root->left == NULL && root->right == NULL)
        return true;
        int child =0;
        
        if (root->left){
            child+= root->left->data;
        } 
        if (root->right){
            child+= root->right->data;
        }
        
        if ( child != root->data ){
            return false;
            
        } if ( child == root->data ){
        
        
        
        if (isSumProperty(root->left) && isSumProperty(root->right))
        return true;
            
        }
        
        
        
        
        return false;
        
        
        
        
    }
};