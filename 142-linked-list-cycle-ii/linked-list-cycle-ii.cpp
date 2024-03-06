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
        ListNode* fast = head;
        ListNode* slow = head;
        if(fast && fast->next && fast->next->next && fast == fast->next->next)
            return fast;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)
                break;
        }
        if(fast && fast->next){
            ListNode* ptr = head;
            while(ptr != fast){
                ptr = ptr->next;
                fast = fast->next;
            }
            return ptr;
        }
        return NULL;
    }
};