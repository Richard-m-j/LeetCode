// Last updated: 7/24/2025, 8:24:01 AM
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
    unordered_map<int,int> mp;
    int maxHeight = 0;
    void leftToRight(TreeNode* root, int height){
        if(!root)
            return;
        mp[root->val] = maxHeight;
        maxHeight = max(maxHeight,height);
        leftToRight(root->left,height+1);
        leftToRight(root->right,height+1);
    }
    void rightToLeft(TreeNode* root, int height){
        if(!root)
            return;
        mp[root->val] = max(mp[root->val],maxHeight);
        maxHeight = max(maxHeight,height);
        rightToLeft(root->right,height+1);
        rightToLeft(root->left,height+1);
    }
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        leftToRight(root,0);
        maxHeight = 0;
        rightToLeft(root,0);
        vector<int> res;
        for(auto q: queries)
            res.push_back(mp[q]);
        return res;
    }
};