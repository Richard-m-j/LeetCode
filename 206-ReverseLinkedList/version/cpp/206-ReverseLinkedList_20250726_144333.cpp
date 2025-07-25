// Last updated: 7/26/2025, 2:43:33 PM
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
    ListNode* reverseList(ListNode* head) {
        if(!head)
            return head;
        ListNode *prev = nullptr;
        ListNode *current = head;
        ListNode *next = head->next;
        while(current){
            ListNode *temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
        }
        return prev;
    }
};