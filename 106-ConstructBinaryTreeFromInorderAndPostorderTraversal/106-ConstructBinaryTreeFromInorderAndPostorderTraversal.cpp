// Last updated: 7/24/2025, 8:34:25 AM
int speedUp = []{
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
    
    TreeNode* helper(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd) {
        if (inStart > inEnd || postStart > postEnd)
            return nullptr;
        
        int rootVal = postorder[postEnd];
        TreeNode* root = new TreeNode(rootVal);
        
        int i = inStart;
        for (; i <= inEnd; i++) {
            if (inorder[i] == rootVal) 
                break;
        }
        
        int leftSize = i - inStart;
        root->left = helper(inorder, inStart, i - 1, postorder, postStart, postStart + leftSize - 1);
        root->right = helper(inorder, i + 1, inEnd, postorder, postStart + leftSize, postEnd - 1);
        
        return root;
    }
};