// Last updated: 7/24/2025, 8:34:18 AM
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
private:
    TreeNode* ptr;
    void helper(TreeNode* root) {
        if (!root)
            return;
        TreeNode* right = root->right;
        ptr->right = root;
        ptr = ptr->right;
        helper(root->left);
        root->left = nullptr;
        helper(right);
    }

public:
    void flatten(TreeNode* root) {
        TreeNode* head = new TreeNode();
        ptr = head;
        helper(root);
    }
};