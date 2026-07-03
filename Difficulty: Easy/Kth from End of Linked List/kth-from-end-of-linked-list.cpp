/* Node Structure
class Node {
  public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
}; */

class Solution {
public:
    int getKthFromLast(Node* head, int k) {

        int len = 0;
        Node* temp = head;

        while (temp) {
            len++;
            temp = temp->next;
        }

        if (k > len)
            return -1;

        temp = head;

        for (int i = 0; i < len - k; i++) {
            temp = temp->next;
        }

        return temp->data;
    }
};