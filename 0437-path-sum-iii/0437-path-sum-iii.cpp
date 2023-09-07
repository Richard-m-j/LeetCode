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
    int count = 0;
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long,int> hash;
        hash[0] = 1;
        recCount(root,hash,targetSum,0);
        return count;

    }
    void recCount(TreeNode* root, unordered_map<long,int>& hash,int targetSum, long pathSum )
    {
        if(!root)
            return;
        
        long currentSum = pathSum + root->val;
        long x = currentSum - targetSum;

        if(hash.find(x) != hash.end())
            count+= hash[x];
        hash[currentSum]++;
        if(root->left)
            recCount(root->left,hash,targetSum,currentSum);
        if(root->right)
            recCount(root->right,hash,targetSum,currentSum);
        hash[currentSum]--;        
    }
};