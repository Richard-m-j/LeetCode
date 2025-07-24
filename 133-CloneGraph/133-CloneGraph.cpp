// Last updated: 7/24/2025, 8:33:55 AM
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    unordered_map<int,Node*> mp;
    set<int> visited;
public:
    Node* cloneGraph(Node* node) {
        if(!node)
            return node;
        Node *newNode;
        if(!mp.count(node->val)){
            mp[node->val] = new Node(node->val);
        }
        newNode = mp[node->val];
        visited.insert(node->val);
        for(auto neighbor: node->neighbors){
            if(!visited.count(neighbor->val)){
                newNode->neighbors.push_back(cloneGraph(neighbor));
            }
            else {
                newNode->neighbors.push_back(mp[neighbor->val]);
            }
        }
        return newNode;
    }
};