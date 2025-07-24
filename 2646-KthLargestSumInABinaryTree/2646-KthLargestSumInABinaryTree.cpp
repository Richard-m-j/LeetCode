// Last updated: 7/24/2025, 8:23:37 AM
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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        priority_queue<long long,vector<long long>,greater<long long>> pq;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            queue<TreeNode*> q1;
            long long level = 0;
            while(!q.empty()){
                TreeNode *node = q.front();
                q.pop();
                level += node->val;
                if(node->left)
                    q1.push(node->left);
                if(node->right)
                    q1.push(node->right);
            }
            q = q1;
            if(pq.size()<k || level > pq.top()){
                pq.push(level);
            }
            if(pq.size()>k)
                pq.pop();
        }
        if(pq.size() != k)
            return -1;

        return pq.top();;
    }
};