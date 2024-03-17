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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> res;
        if (!root)
            return {};
        s.push(root);
        while (!s.empty()) {
            TreeNode* ptr = s.top();
            s.pop();
            cout<<ptr->val<<" ";
            if (!ptr->left && !ptr->right){
                res.push_back(ptr->val);
                continue;
            }
            if (ptr->right) {
                s.push(ptr->right);
                ptr->right = NULL;
            }
            TreeNode* left = ptr->left;
            ptr->left = NULL;
            s.push(ptr);
            if (left) {
                s.push(left);
            }
        }
        return res;
    }
};