// Last updated: 7/24/2025, 8:34:31 AM
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
    bool isSymmetric(TreeNode* root) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        queue<TreeNode*> level;
        level.push(root);
        while (!level.empty()) {
            queue<TreeNode*> nextLevel;
            vector<int> values;
            while (!level.empty()) {
                TreeNode* ptr = level.front();
                level.pop();

                if (!ptr){
                    values.push_back(-101);
                    continue;
                }
                values.push_back(ptr->val);
                nextLevel.push(ptr->left);
                nextLevel.push(ptr->right);
            }
            int n = values.size();
            if (n) {
                int l = 0, r = n - 1;
                while (l <= r) {
                    if(values[l] != values[r])
                        return false;
                    l++;
                    r--;
                }
            }
            level = nextLevel;
        }
        return true;
    }
};