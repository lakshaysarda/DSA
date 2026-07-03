/* Structure of doubly linked list node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
       
       if (head == nullptr || head->next ==nullptr) return head;
       
       Node*prev = nullptr;
       Node*current=head;
       
       while(current){
           
           prev = current->prev;
           current->prev=current->next;
           current->next=prev;
           current=current->prev;
           
       }
       return prev->prev;
        
    }
};