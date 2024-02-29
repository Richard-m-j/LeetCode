class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;

        while (!q.empty()) {
            int size = q.size();
            int prevValue = (level % 2 == 0) ? INT_MIN : INT_MAX;

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();

                if ((level % 2 == 0 &&
                     (node->val % 2 == 0 || node->val <= prevValue)) ||
                    (level % 2 == 1 &&
                     (node->val % 2 == 1 || node->val >= prevValue)))
                    return false;

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);

                prevValue = node->val;
            }
            ++level;
        }
        return true;
    }
};
