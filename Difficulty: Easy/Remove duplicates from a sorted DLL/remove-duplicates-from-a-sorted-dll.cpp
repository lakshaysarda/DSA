/* Structure of a link list node
class Node {
  public:
    int data;
    Node* next;
    Node* prev;
    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};
*/
class Solution {
  public:
    Node* removeDuplicates(Node* headRef) {

        Node* temp = headRef;

        while (temp && temp->next) {

            if (temp->data == temp->next->data) {

                Node* dup = temp->next;

                temp->next = dup->next;

                if (dup->next)
                    dup->next->prev = temp;

                delete dup;
            }
            else {
                temp = temp->next;
            }
        }

        return headRef;
    }
};