// Last updated: 7/24/2025, 8:34:40 AM
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
private: 
    void inorder(TreeNode* root, vector<int>& visited){
        if(!root)
            return;
        inorder(root->left,visited);
        visited.push_back(root->val);
        inorder(root->right,visited);
    }
public:
    bool isValidBST(TreeNode* root) {
        vector<int> visited;
        inorder(root,visited);
        for(int i=0;i<visited.size()-1;i++)
            if(visited[i]>=visited[i+1])
                return false;
        return true;        
    }
};