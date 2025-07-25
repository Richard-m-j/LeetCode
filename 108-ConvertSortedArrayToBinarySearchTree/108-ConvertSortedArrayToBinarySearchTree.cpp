// Last updated: 7/24/2025, 8:34:24 AM
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
private:
    TreeNode* danc(vector<int>& nums, int l, int r) {
        if (l > r)
            return NULL;

        int m = (l + r) / 2;
        TreeNode* root = new TreeNode(nums[m]);

        root->left = danc(nums, l, m - 1);
        root->right = danc(nums, m + 1, r);

        return root;
    }

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return danc(nums, 0, nums.size() - 1);
    }
};