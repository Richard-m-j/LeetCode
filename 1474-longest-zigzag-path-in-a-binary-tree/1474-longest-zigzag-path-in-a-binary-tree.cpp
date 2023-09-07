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
 //root -> tryl, tryr, solvl.left, solvr.right; solvl -> tryl, root.left, solvr.right
class Solution {
public:
    int longestZigZag(TreeNode* root) {
        if(!root)
            return 0;
        int ans = max(max(max(tryLeft(root->left), tryRight(root->right)), longestLeft(root->left)), longestRight(root->right));
        root->left = NULL;
        root->right = NULL;
        return ans;
    }
    int tryLeft(TreeNode* node) {
        if(!node)
            return 0;
        return 1 + tryRight(node->right);
    }
    int tryRight(TreeNode* node) {
        if(!node)
            return 0;
        return 1 + tryLeft(node->left);
    }
    int longestLeft(TreeNode* node) {
        if(!node)
            return 0;
        return max(max(tryLeft(node->left), longestZigZag(node->left)), longestRight(node->right));
    }
    int longestRight(TreeNode* node) {
        if(!node)
            return 0;
        return max(max(tryRight(node->right), longestLeft(node->left)), longestZigZag(node->right));
    }
};