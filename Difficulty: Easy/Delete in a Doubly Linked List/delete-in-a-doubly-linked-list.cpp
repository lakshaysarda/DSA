/* Structure of Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/

class Solution {
  public:
    Node* delPos(Node* head, int x) {
        // code here
        if ( head == nullptr) return head ; 
        Node*temp = head; 
        if ( x ==1 ){ 
            head=head->next; 
            if(head) head->prev = nullptr; 
            delete temp; 
            return head; }
            int count =1; 
            while (temp && count < x)
            { count ++; temp= temp->next; } 
            if (temp == nullptr) return head; 
            temp->prev->next = temp->next; 
            if(temp->next)temp->next->prev=temp->prev; delete temp; 
        return head;           
    }
    
};