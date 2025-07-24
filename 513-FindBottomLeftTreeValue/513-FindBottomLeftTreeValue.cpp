// Last updated: 7/24/2025, 8:30:37 AM
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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q1;
        int ans = root->val;
        q1.push(root);
        while(!q1.empty()){
            queue<TreeNode*> q2;
            ans = (q1.front())->val;
            while(!q1.empty()){
                TreeNode * left = (q1.front())->left;
                TreeNode * right = (q1.front())->right;
                if(left)
                    q2.push(left);
                if(right)
                    q2.push(right);
                q1.pop();
            }
            q1 = q2;
        }
        return ans;
    }
};