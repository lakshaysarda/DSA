/*
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    Node* removeLastNode(Node* head) {
        
        Node*temp = head;
       if ( head == nullptr || head-> next == nullptr) return nullptr;
       
       while (temp->next->next != nullptr ){
           temp= temp->next ;
       }
       delete ( temp->next);
       temp->next = nullptr;
       
       return head;
        
        
    }
};