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
            if(ptr->val == INT_MIN)
                return true;
            ptr->val = INT_MIN;
            ptr = ptr->next;
        }
        return false;
    }
};