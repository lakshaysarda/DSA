class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {

        if(root == NULL)
            return 0;

        long long maxi = 0;

        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while(!q.empty()) {

            int size = q.size();

            long long minIndex = q.front().second;
            long long first, last;

            for(int i = 0; i < size; i++) {

                TreeNode* node = q.front().first;
                long long currIndex = q.front().second - minIndex;

                q.pop();

                if(i == 0)
                    first = currIndex;

                if(i == size - 1)
                    last = currIndex;

                if(node->left)
                    q.push({node->left, 2 * currIndex + 1});

                if(node->right)
                    q.push({node->right, 2 * currIndex + 2});
            }

            maxi = max(maxi, last - first + 1);
        }

        return (int)maxi;
    }
};