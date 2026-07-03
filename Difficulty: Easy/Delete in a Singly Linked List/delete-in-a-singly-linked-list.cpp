/*
class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};
*/
class Solution {
public:
    Node* deleteNode(Node* head, int x) {

        if (head == nullptr)
            return nullptr;

        if (x == 1) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        Node* temp = head;

        for (int i = 1; i < x - 1; i++) {
            temp = temp->next;
        }

        Node* delNode = temp->next;
        temp->next = temp->next->next;

        delete delNode;

        return head;
    }
};