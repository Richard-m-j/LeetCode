// Last updated: 7/24/2025, 8:34:19 AM
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
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)
            return false;
        targetSum -= root->val;

        if(!root->left && !root->right && targetSum==0)
            return true;
        // cout<<root->val<<"-"<<targetSum<<endl;
        
        return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
    }
};