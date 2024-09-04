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
    unordered_map<int,int> mp;
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder,int l1,int r1, int l2, int r2){
        if(l1>r1||l2>r2)
            return nullptr;
        int m = mp[preorder[l1]];
        int len = m - l2;
        TreeNode* root = new TreeNode(preorder[l1]);
        root->left = helper(preorder,inorder,l1+1,l1+len,l2,m-1);
        root->right = helper(preorder,inorder,l1 + len + 1,r1,m+1,r2);

        return root;

    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++)
            mp[inorder[i]] = i;
        return helper(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
    }
};