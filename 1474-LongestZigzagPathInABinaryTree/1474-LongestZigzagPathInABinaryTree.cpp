// Last updated: 7/24/2025, 8:27:07 AM
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
    int longestZigZag(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr); 
        if(!root)
            return 0;
        recHelper(root->left, 0, 1);
        recHelper(root->right, 1, 1);
        return ans;
    }
private:
    void recHelper(TreeNode* node,bool side,int length)
    {
        if(!node)
            return;
        ans = max(ans, length);
        recHelper(node->left,0,side ? length + 1 : 1);
        recHelper(node->right,1,!side ? length + 1 : 1);
    }

    int ans = 0;
};