// Last updated: 8/24/2025, 3:46:38 PM
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
    int res=0;
    int dfs(TreeNode* node, int pathSum){
        if(!node)
            return 0;
        int leftSum = dfs(node->left, pathSum + node->val);
        int rightSum = dfs(node->right, pathSum + node->val);
        res = max({res,leftSum+rightSum + node->val,node->val,leftSum+node->val,rightSum+node->val});
        return max({leftSum+node->val,rightSum+node->val, node->val});
    }
public:
    int maxPathSum(TreeNode* root) {
        // int path=root;
        res = root->val;
        dfs(root,0);
        return res;
    }
};