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
    vector<int> nums;
public:
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        int res = abs(nums[0] - nums[1]);
        for(int i=1;i<nums.size()-1;i++){
            res = min(res, abs(nums[i] - nums[i+1]));
            // cout<<nums[i]<<" ";
        }
        return res;
    }
    void inorder(TreeNode* root){
        if(!root)
            return;
        inorder(root->left);
        nums.push_back(root->val);
        inorder(root->right);
    }
};