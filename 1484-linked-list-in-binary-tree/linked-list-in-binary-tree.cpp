/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
int speedUp = []{
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
class Solution {
private:
    bool helper(ListNode* head, TreeNode* root) {
        if(!head)
            return true;
        if(!root)
            return false;
        if(root->val == head->val)
            return helper(head->next,root->left) || helper(head->next,root->right); 
        return false; 
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!head)
            return true;
        if(!root)
            return false;
        if(root->val == head->val)
            if(helper(head->next,root->left) || helper(head->next,root->right))
                return true; 
        return isSubPath(head,root->left) || isSubPath(head,root->right); 
    }
};