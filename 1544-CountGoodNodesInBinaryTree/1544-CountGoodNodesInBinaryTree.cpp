// Last updated: 7/24/2025, 8:26:45 AM
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
    int traversal(TreeNode* root, int maxVal) {
        if (!root)
            return 0;
        if (root->val >= maxVal)
            return 1 + traversal(root->left, root->val) +
                   traversal(root->right, root->val);
        else
            return traversal(root->left, maxVal) +
                   traversal(root->right, maxVal);
    }

public:
    int goodNodes(TreeNode* root) {
        return traversal(root, root->val);
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();