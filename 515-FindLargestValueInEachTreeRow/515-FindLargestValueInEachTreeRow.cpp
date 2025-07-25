// Last updated: 7/24/2025, 8:30:36 AM
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q;
        if(!root)
            return {};
        q.push(root);
        while(!q.empty()){
            int len = q.size();
            int rowMax = INT_MIN;
            for(int i=0;i<len;i++){
                auto node = q.front();
                q.pop();
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
                if(node->val>rowMax)
                    rowMax=node->val;
            }
            res.push_back(rowMax);
        }
        return res;
    }
};