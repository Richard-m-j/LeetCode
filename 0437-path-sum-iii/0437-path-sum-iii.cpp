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
    int pathSum(TreeNode* root, int targetSum) {
        hash[0] = 1;
        recCount(root,targetSum,0);
        return count;

    }
    void recCount(TreeNode* root, int targetSum, long pathSum )
    {
        if(!root)
            return;
        
        long currentSum = pathSum + root->val;
        long x = currentSum - targetSum;

        if(hash.find(x) != hash.end())
            count+= hash[x];
        hash[currentSum]++;

        recCount(root->left,targetSum,currentSum);
        recCount(root->right,targetSum,currentSum);
        hash[currentSum]--;        
    }
private:
    int count = 0;
    unordered_map<long,int> hash;
};