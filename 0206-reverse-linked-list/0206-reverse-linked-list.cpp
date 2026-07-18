class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        stack<int> yes;
        ListNode* temp = head;

        while (temp) {
            yes.push(temp->val);
            temp = temp->next;
        }

        ListNode* dummy = new ListNode(-1);
        temp = dummy;

        while (!yes.empty()) {
            temp->next = new ListNode(yes.top());
            yes.pop();
            temp = temp->next;
        }

        return dummy->next;
    }
};