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
    vector<double> averageOfLevels(TreeNode* root) {
        if(!root)
            return {};
        vector<double> res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            queue<TreeNode*> q1;
            long long levelSum = 0;
            int level = 0;
            while(!q.empty()){
                TreeNode* ptr = q.front();
                q.pop();
                levelSum += ptr->val;
                level++;
                if(ptr->left)
                    q1.push(ptr->left);
                if(ptr->right)
                    q1.push(ptr->right);
            }
            q = q1;
            res.push_back(levelSum/(double)level);
        }
        return res;
    }
};