/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};*/

class Solution {
  public: int maxi = INT_MIN;
          int mini = INT_MAX;
  
    int findMax(Node *root) {
        if ( root == NULL ) return 0  ;
        
        
        
        
        int left = findMax(root->left);
      int right = findMax(root->right);

     return max(root->data, max(left, right));
        
        
        
    }

    int findMin(Node *root) {
        
           if ( root == NULL ) return INT_MAX;
        
        
        
        
        int left = findMin(root->left);
      int right = findMin(root->right);

     return min(root->data, min(left, right));
    }
};