// Last updated: 7/24/2025, 8:28:30 AM
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
const static auto fast = [] {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    // int rangeSumBST (TreeNode* root, int low, int high)
    // {
    //     if(root == NULL)
    //         return 0;
    //     int sum = 0;
    //     int left = rangeSumBST(root->left,low,high);
    //     int right = rangeSumBST(root->right,low,high);
    //     if(left>=low && left <= high)
    //         sum += left;
    //     if(right>=low && right <= high)
    //         sum += right;
    //     if(root->val>=low && root->val <= high)
    //         sum += root->val;
    //     return sum;
    // }
    int rangeSumBST (TreeNode* root, int low, int high)
    {
        traversal(root,low,high);
        return sum;

    }
    void traversal(TreeNode* root, int low, int high)
    {
        if(root == NULL)
            return;

        if(root->val>=low && root->val <= high)
            sum += root->val;
        if(root->val>low)
            traversal(root->left,low,high);
        if(root->val <high)
            traversal(root->right,low,high);
    }
private:
    int sum = 0;
};