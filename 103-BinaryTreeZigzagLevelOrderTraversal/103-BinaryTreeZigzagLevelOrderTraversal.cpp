// Last updated: 7/24/2025, 8:34:28 AM
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
            return {};
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        bool dir = true;
        while(!q.empty()){
            queue<TreeNode*> q1;
            vector<int> level;
            while(!q.empty()){
                TreeNode * ptr = q.front();
                q.pop();
                level.push_back(ptr->val);
                if(ptr->left)
                    q1.push(ptr->left);
                if(ptr->right)
                    q1.push(ptr->right);
            }
            if(!dir){
                int l=0,r=level.size()-1;
                while(l<r)
                    swap(level[l++],level[r--]);
            }
            res.push_back(level);
            q=q1;
            dir = !dir;
        }
        return res;
    }
};