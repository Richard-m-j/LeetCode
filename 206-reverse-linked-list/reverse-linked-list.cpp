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
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        stack<ListNode*> s;
        if(!head)
            return NULL;
        while(head){
            s.push(head);
            head = head->next;
        }
        head = s.top();
        s.pop();
        ListNode* ptr = head;
        while(!s.empty()){
            ptr->next = s.top();
            s.pop();
            ptr = ptr->next;
        }
        ptr->next = NULL;
        return head;
    }
};