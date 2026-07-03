/*
class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = prev = nullptr;
    }
};
*/

class Solution {
  public:
    Node *insertAtPos(Node *head, int p, int x) {
        Node* yes = new Node(x);
        if ( head == nullptr)  return nullptr;
        Node*temp = head;
        Node*back = nullptr;
        
        
            int count =0;
            while ( temp && count<= p) {
                count++;
                back= temp;
                temp= temp->next;
            }
            if (temp == nullptr){
                back->next = yes;
                yes->prev = back;
                return head;
                
            } 
            back->next = yes;
            yes->next = temp;
            
            
            temp->prev = yes;
            yes->prev = back;
            return head;
            
        }
        
    
};