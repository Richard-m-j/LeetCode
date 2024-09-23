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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return nullptr;
        ListNode *fast=head,*slow=head;
        int n=0;
        while(fast->next){
            fast = fast->next;
            n++;
        }
        k = k%(n+1);
        cout<<k;
        fast->next = head;

        for(int i=0;i<n-k;i++){
            slow = slow->next;        
        }
        ListNode* newHead = slow->next;
        slow->next = nullptr;
        return newHead;
    }
};