// Last updated: 7/24/2025, 8:34:07 AM
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
    int res;
public:
    int maxPathSum(TreeNode* root) {
        res = INT_MIN;
        helper(root);
        return res;
    }
    int helper(TreeNode* root){
        if(!root)
            return 0;
        int left = helper(root->left);
        int right = helper(root->right);
        int maxPath = max(max(left,right)+root->val,root->val);
        res = max(res,max(maxPath,left+right+root->val));
        
        return maxPath;
    }
};