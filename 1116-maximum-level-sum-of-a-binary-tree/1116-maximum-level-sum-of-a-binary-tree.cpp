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
    int maxLevelSum(TreeNode* root) {
        vector <TreeNode* > Queue;
        Queue.push_back(root);
        vector <TreeNode* >& queue = Queue;
        int maxLevel = 1;
        int level = 1;
        int maxLevelSum = root->val;
        while(!Queue.empty())
        {
            int levelSum = 0;
            vector <TreeNode* > nextQueue;
            for(TreeNode* node: Queue)
            {
                if(node->left)
                    nextQueue.push_back(node->left);
                if(node->right)
                    nextQueue.push_back(node->right);
                levelSum += node->val;
            }
            if(levelSum > maxLevelSum)
            {
                maxLevelSum = levelSum;
                maxLevel = level;
            }
            level++;
            queue = nextQueue;
        }
        return maxLevel;
    }
};