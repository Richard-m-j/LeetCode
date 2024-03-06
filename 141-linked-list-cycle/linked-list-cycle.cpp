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