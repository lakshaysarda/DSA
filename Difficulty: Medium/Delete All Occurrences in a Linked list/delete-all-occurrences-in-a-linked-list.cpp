class Solution {
public:
    Node* deleteAllOccurances(Node* head, int x) {

        // Delete nodes from the beginning
        while (head && head->data == x) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        Node* curr = head;

        while (curr && curr->next) {

            if (curr->next->data == x) {

                Node* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;

            } else {
                curr = curr->next;
            }
        }

        return head;
    }
};