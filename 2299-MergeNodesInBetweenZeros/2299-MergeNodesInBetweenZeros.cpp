// Last updated: 7/24/2025, 8:24:41 AM
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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *ptr = head->next;
        ListNode *head1 = new ListNode();
        ListNode *ptr1 = head1; 
        while(ptr){
            int sum = 0;
            // ptr = ptr->next;
            while(ptr && ptr->val != 0){
                sum += ptr->val;
                ptr = ptr->next;
            }
            ptr1->next = new ListNode(sum);
            ptr1 = ptr1->next;
            ptr = ptr->next;
        }
        return head1->next;
    }
};