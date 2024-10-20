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
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    void insert(TreeNode* node, int row, int col){
        if(!node)
            return;
        pq.push(make_tuple(col,row,node->val));
        insert(node->left,row+1,col-1);
        insert(node->right,row+1,col+1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        insert(root,0,0);
        vector<vector<int>> res;
        while(!pq.empty()){
            int col = get<0>(pq.top());
            vector<int> column;
            while(!pq.empty() && col ==  get<0>(pq.top())){
                auto point = pq.top();
                pq.pop();
                column.push_back(get<2>(point));
            }
            res.push_back(column);
        }
        return res;
    }
};