/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        
        Node *newHead = new Node(0);
        Node *ptr1 = newHead;
        unordered_map<Node*,Node*> mp;
        mp[nullptr] = nullptr;
        for(Node *ptr = head;ptr;ptr = ptr->next){
            if(mp.count(ptr)){
                ptr1->next = mp[ptr];
            }
            else{
                ptr1->next = new Node(ptr->val);
                mp[ptr] = ptr1->next;
            }
            if(!mp.count(ptr->random)){
                Node* newRandom = new Node(ptr->random->val);
                mp[ptr->random] = newRandom;
            }
            ptr1->next->random = mp[ptr->random];
            ptr1 = ptr1->next;
            // cout<<ptr1->next->val<<" ";
        }
        return newHead->next;
    }
};