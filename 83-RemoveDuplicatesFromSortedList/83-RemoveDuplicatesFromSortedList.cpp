// Last updated: 7/24/2025, 8:34:54 AM
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
            return head;
        ListNode *ptr = head->next;
        ListNode *prev = head;

        while(ptr){
            if(prev->val == ptr->val)
                prev->next = ptr->next;
            else
                prev = ptr;
            ptr = ptr->next;
        }
        return head;
    }
};