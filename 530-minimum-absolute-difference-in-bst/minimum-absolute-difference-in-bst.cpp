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
int speedUp = []{
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
class Solution {
private:
    int res = INT_MAX;
    int prev = -1;
public:
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return res;
    }
    void inorder(TreeNode* root){
        if(!root)
            return;
        inorder(root->left);
        if(prev!=-1)
            res = min(res,abs(root->val - prev));
        prev = root->val;
        inorder(root->right);
    }
};