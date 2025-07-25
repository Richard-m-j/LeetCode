// Last updated: 7/24/2025, 8:33:49 AM
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
        ios::sync_with_stdio(0);
        ListNode *ptr = head;
        while(ptr){
            if(ptr->val == 100001)
                return true;
            ptr->val = 100001;
            ptr = ptr->next;
        }
        return false;
    }
};