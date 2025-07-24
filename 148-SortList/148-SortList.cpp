// Last updated: 7/24/2025, 8:33:37 AM
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
int speedUp = []{
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
class Solution {
private:
    ListNode* merge(ListNode* head1, ListNode* head2){
        if(!head1) return head2;
        if(!head2) return head1;

        if(head1->val < head2->val){
            head1->next = merge(head1->next,head2);
            return head1;
        }
        head2->next = merge(head1,head2->next);
        return head2;
    }
    ListNode* middle(ListNode*head){
        ListNode*fast=head,*slow=head,*prev=nullptr;
        while(fast && fast->next){
            prev = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        if(prev)
            prev->next = nullptr;
        return slow;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
            return head;

        ListNode* mid = middle(head);
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);

        return merge(left,right);
    }
};