/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    
    }
};
*/

  
   class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {

        vector<pair<int,int>> ans;

        Node* left = head;
        Node* right = head;
        if (head == nullptr) return ans;
    

        while (right->next) {

          right = right ->next;}
          // left->prev != right for even nodes wale case cause usmein it 
          //it will cross fs
          
          
         while (left != right && left ->prev != right){
              int sum =left->data +right->data;
              
              if (sum == target){
                  ans.push_back({left->data , right->data});
                  left = left ->next;
                  right = right ->prev;
              }
              
               else if (sum < target){
                  left = left ->next;
                  
              }
              else{
                  
                  right = right ->prev;
              }
              
             
          }
          return ans ;

            

        

       
    }
};
    