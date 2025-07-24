// Last updated: 7/24/2025, 8:34:38 AM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if (!root)
            return res;
        q.push(root);
        while (!q.empty()) {
            queue<TreeNode*> q1;
            vector<int> level;
            while (!q.empty()) {
                TreeNode* node = q.front();
                level.push_back(node->val);
                q.pop();
                if (node->left)
                    q1.push(node->left);
                if (node->right)
                    q1.push(node->right);
            }
            res.push_back(level);
            q = q1;
        }
        return res;
    }
};