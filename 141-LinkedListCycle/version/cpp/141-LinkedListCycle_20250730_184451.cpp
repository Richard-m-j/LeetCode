// Last updated: 7/30/2025, 6:44:51 PM
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
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        ListNode *slow = head, *fast = head->next;
        while(fast && fast->next){
            if(fast==slow)
                return true;
            fast = fast->next->next;
            slow = slow->next;
        }
        return false;
    }
};