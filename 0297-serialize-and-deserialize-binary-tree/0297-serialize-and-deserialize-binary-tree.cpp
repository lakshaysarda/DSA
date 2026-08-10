class Codec {
public:

    // Serialize
    string serialize(TreeNode* root) {

        if (root == NULL)
            return "";

        string ans = "";

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {

            TreeNode* node = q.front();
            q.pop();

            if (node == NULL) {
                ans += "null,";
                continue;
            }

            ans += to_string(node->val) + ",";

            q.push(node->left);
            q.push(node->right);
        }

        return ans;
    }


    // Deserialize
    TreeNode* deserialize(string data) {

        if (data == "")
            return NULL;

        stringstream ss(data);
        string s;

        getline(ss, s, ',');

        TreeNode* root = new TreeNode(stoi(s));

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {

            TreeNode* node = q.front();
            q.pop();

            // left child
            getline(ss, s, ',');

            if (s != "null") {
                node->left = new TreeNode(stoi(s));
                q.push(node->left);
            }

            // right child
            getline(ss, s, ',');

            if (s != "null") {
                node->right = new TreeNode(stoi(s));
                q.push(node->right);
            }
        }

        return root;
    }
};