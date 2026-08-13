class Solution {
public:
    vector<Node*> findPreSuc(Node* root, int key) {

        Node* pre = NULL;
        Node* suc = NULL;

        Node* curr = root;

        while (curr != NULL) {

            if (curr->data == key) {

                // Find predecessor
                if (curr->left != NULL) {
                    Node* temp = curr->left;

                    while (temp->right != NULL)
                        temp = temp->right;

                    pre = temp;
                }

                // Find successor
                if (curr->right != NULL) {
                    Node* temp = curr->right;

                    while (temp->left != NULL)
                        temp = temp->left;

                    suc = temp;
                }

                break;
            }

            else if (curr->data < key) {
                pre = curr;
                curr = curr->right;
            }

            else {
                suc = curr;
                curr = curr->left;
            }
        }

        return {pre, suc};
    }
};