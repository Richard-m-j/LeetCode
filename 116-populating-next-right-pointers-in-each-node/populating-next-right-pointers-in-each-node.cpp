/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
int speedUp = []{
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
class Solution {
public:
    Node* connect(Node* root) {
        //perform bfs
        if(!root)
            return root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            queue<Node*> q1;
            Node *prev = new Node();
            while(!q.empty()){
                Node *ptr = q.front();
                q.pop();
                prev->next = ptr;
                // cout<<ptr->val<<" ";
                prev = ptr;
                if(ptr->left){
                    q1.push(ptr->left);
                    q1.push(ptr->right);
                }
            }
            prev->next = nullptr;
            q = q1;
        }
        return root;
    }
};