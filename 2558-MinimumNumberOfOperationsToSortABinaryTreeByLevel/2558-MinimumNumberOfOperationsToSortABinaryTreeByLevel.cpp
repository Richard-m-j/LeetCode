// Last updated: 7/24/2025, 8:23:55 AM
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
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        if(!root)
            return 0;
        int res=0;
        q.push(root);
        while(!q.empty()){
            int len = q.size();
            vector<pair<int,int>> level;
            for(int i=0;i<len;i++){
                TreeNode* node = q.front();
                q.pop();
                level.push_back({node->val,i});
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            sort(level.begin(),level.end());
            vector<bool> visited(level.size(),false);
            
            for(int i=0;i<level.size();i++){
                int j = i;
                int depth=0;
                while(!visited[j]){
                    visited[j]=true;
                    depth++;
                    j=level[j].second;
                }
                if(depth)
                    res += depth - 1;
            }
        }
        return res;
    }
};