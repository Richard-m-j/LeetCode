/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        ListNode* fast = head;
        ListNode* slow = head;
        if(fast && fast->next && fast->next->next && fast == fast->next->next)
            return fast;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast) {
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};