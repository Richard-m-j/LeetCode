// Last updated: 7/24/2025, 8:28:57 AM
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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector <int> leaf1,leaf2;
        preorder(root1,&leaf1);
        preorder(root2,&leaf2);
        int n1=leaf1.size();
        int n2=leaf2.size();
        if(n1!=n2)
            return false;
        for(int i=0;i<n1;i++)
            if(leaf1[i]!=leaf2[i])
                return false;
        return true;
        
    }
private:
    void preorder(TreeNode* root, vector <int> * leaves)
    {
        if(root == NULL)
            return;
        if(root->left == NULL && root->right == NULL)
        {
            (*leaves).push_back(root->val);
            return;
        }
        preorder(root->left,leaves);
        preorder(root->right,leaves);
    }

};