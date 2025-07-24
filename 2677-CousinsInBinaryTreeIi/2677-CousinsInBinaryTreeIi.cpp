// Last updated: 7/24/2025, 8:23:34 AM
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
    TreeNode* replaceValueInTree(TreeNode* root) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        
        root->val = 0;
        queue<TreeNode*> q;
        q.push(root);
        vector<long long> levelSums;
        while(!q.empty()){
            queue<TreeNode*> q1;
            long long level = 0;
            while(!q.empty()){
                TreeNode *node = q.front();
                level += node->val;
                q.pop();
                if(node->left)
                    q1.push(node->left);
                if(node->right)
                    q1.push(node->right);
            }
            q = q1;
            levelSums.push_back(level);
        }
        levelSums.push_back(0);
        int levelNum = 1;
        q.push(root);
        while(!q.empty()){
            queue<TreeNode*> q1;
            while(!q.empty()){
                TreeNode *node = q.front();
                int siblingSum = 0;
                q.pop();
                if(node->left){
                    q1.push(node->left);
                    siblingSum += node->left->val;
                }
                if(node->right){
                    q1.push(node->right);
                    siblingSum += node->right->val;
                }
                int NodeVal = levelSums[levelNum] - siblingSum > 0? levelSums[levelNum] - siblingSum : 0;
                if(node->left){
                    node->left->val = NodeVal;
                }
                if(node->right){
                    node->right->val = NodeVal;
                }
            }
            levelNum++;
            q = q1;
        }
        return root;
    }
};