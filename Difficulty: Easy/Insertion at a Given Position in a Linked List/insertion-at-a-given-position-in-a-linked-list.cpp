/*
class Node {
  public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/

class Solution {
  public:
    Node *insertPos(Node *head, int pos, int val) {
       
        Node* yes = new Node(val);
        
        Node*temp = head;
       
         if (pos == 1) {
            yes->next = head;
            return yes;
        } int count =1;

        
        while (temp&& count <pos-1){
            count ++;
            temp= temp->next;}
            
            if ( temp == nullptr ){
                
                return head ;
                
            }
           yes->next=temp->next;
           temp->next=yes;
            
        
        return head;
    }
};