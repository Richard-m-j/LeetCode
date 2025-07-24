// Last updated: 7/24/2025, 8:32:26 AM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right,p,q);
        if(root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left,p,q);
        return root;

    }

};
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
