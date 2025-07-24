// Last updated: 7/24/2025, 8:32:35 AM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) { 
        vector<int> visited;
        inorder(root, visited);
        return visited[k-1]; 
    }
    void inorder(TreeNode* root, vector<int>& visited) {

        if (!root)
            return;
        inorder(root->left, visited);
        visited.push_back(root->val);
        inorder(root->right, visited);

    }
};