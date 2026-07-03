/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* segregate(Node* head) {
        Node* dummy1 = new Node(-1);
        Node* dummy2 = new Node(-1);
        Node* dummy3 = new Node(-1);
        Node*temp = head;
        
        Node*temp1 = dummy1;
        Node*temp2 = dummy2;
        Node*temp3 = dummy3;
        
        while(temp){
            if(temp->data == 0){
                temp1->next=temp;
                temp1=temp1->next;
            } 
             else if(temp->data == 1){
                temp2->next=temp;
                 temp2=temp2->next;
            } 
            else if(temp->data == 2){
                temp3->next=temp;
                 temp3=temp3->next;
            } 
             temp = temp->next;
        } 
        temp1->next = dummy2->next;
        if (dummy2->next != nullptr) 
            temp1->next = dummy2->next;
           else
             temp1->next = dummy3->next;
             temp2->next = dummy3->next;
             temp3->next = nullptr;
            
        return dummy1->next;
        
    }
};