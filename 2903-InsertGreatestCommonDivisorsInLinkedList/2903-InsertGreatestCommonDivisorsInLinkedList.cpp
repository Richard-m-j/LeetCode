// Last updated: 7/24/2025, 8:23:04 AM
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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head->next)
            return head;
        ListNode * ptr = head;
        while(ptr->next){
            ListNode* ptr1 = ptr->next;
            ptr->next = new ListNode(__gcd(ptr->val,ptr1->val));
            ptr->next->next = ptr1;
            ptr = ptr1;
        }
        return head;
    }
};