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
    TreeNode* reverseOddLevels(TreeNode* root) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        if(!root)
            return root;
        queue<TreeNode*> q;
        q.push(root);
        bool flip=false;
        while(!q.empty()){
            vector<TreeNode*> level;
            int len = q.size();
            for(int i=0;i<len;i++){
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node);
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            if(flip){
                int l=0,r=level.size()-1;
                while(l<r){
                    swap(level[l++]->val,level[r--]->val);
                }
            }
            flip = !flip;
        }
        return root;
    }
};