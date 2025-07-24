// Last updated: 7/24/2025, 8:34:41 AM
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        stack<TreeNode*> s1,s2;
        if(p==NULL && q == NULL)
            return true;
        else if(p==NULL || q == NULL || p->val != q->val)
            return false;
        s1.push(p);
        s2.push(q);

        for(;!s1.empty() && !s2.empty();){
            TreeNode * p1 = s1.top();s1.pop();
            TreeNode * p2 = s2.top();s2.pop();

            if(p1 == NULL && p2 == NULL)
                continue;
            else if(p1 == NULL || p2 == NULL)
                return false;
            if(p1->val != p2->val)
                return false;
            s1.push(p1->left);
            s1.push(p1->right);
            s2.push(p2->left);
            s2.push(p2->right);
        }
        if(!s1.empty() || !s2.empty())
            return false;
        return true;
    }
};