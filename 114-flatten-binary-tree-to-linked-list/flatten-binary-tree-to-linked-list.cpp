/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode *ptr;
    void helper(TreeNode* root){
        if(!root)
            return;
        TreeNode *right = root->right;
        TreeNode *left = root->left;
        ptr->right = root;
        ptr = ptr->right;
        root->left = nullptr;
        helper(left);
        helper(right);
    }
public:
    void flatten(TreeNode* root) {
        TreeNode* head = new TreeNode();
        ptr = head;
        helper(root);
    }
};