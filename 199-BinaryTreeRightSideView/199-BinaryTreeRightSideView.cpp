// Last updated: 7/24/2025, 8:33:07 AM
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
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return {};
        queue<TreeNode*> q1;
        q1.push(root);
        vector<int> res;
        while(!q1.empty()){
            TreeNode* right = q1.back();
            res.push_back(right->val);
            queue<TreeNode*> q2;
            while(!q1.empty()){
                TreeNode *node = q1.front();
                q1.pop();
                if(node->left)
                    q2.push(node->left);
                if(node->right)
                    q2.push(node->right);
            }
            q1 = q2;
        }
        return res;
    }
};