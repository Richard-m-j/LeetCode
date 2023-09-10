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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return root;
        if(root->val == key)
        {
            TreeNode* succ = root->right;
            TreeNode* ptr = root;
        
            while(succ && succ->left)
            {
                ptr = succ;
                succ= succ->left;
            }
            
            if(succ)
            {
                root->val = succ->val;
                search(succ,ptr,succ->val);                
            }
            else
            {
                root = root->left;
            }
        }
        else if(key < root->val)
            search(root->left,root,key);
        else
            search(root->right,root,key);
        return root;       
        
    }
    TreeNode* search(TreeNode* node,TreeNode* parent, int key)
    {
        if(!node)
            return NULL;
        if(key < node->val)
            return search(node->left,node,key);
        if(key > node->val)
            return search(node->right,node,key);
        
        if(node->left && node->right)
        {
            TreeNode* succ = node->right;
            TreeNode* ptr= node;
        
            while(succ && succ->left)
            {
                ptr = succ;
                succ= succ->left;
            }
            node->val = succ->val;
            search(succ,ptr,succ->val);
        }
        else if(!node->left)
        {
            if(parent->left == node)
                parent->left = node->right;
            else
                parent->right = node->right;
        }
        else
        {
            if(parent->left == node)
                parent->left = node->left;
            else
                parent->right = node->left;
        }
        return node;
    }
    
    TreeNode* inorderSuccessor(TreeNode* node)
    {
        TreeNode* ptr=node->right;
        
        while(ptr && ptr->left)
            ptr= ptr->left;
        return ptr;
    }
};