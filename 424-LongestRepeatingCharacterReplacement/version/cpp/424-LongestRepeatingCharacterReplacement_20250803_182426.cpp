// Last updated: 8/3/2025, 6:24:26 PM
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
    void reorderList(ListNode* head) {
        if(!head || !head->next)
            return;
        ListNode *fast = head, *mid = head,*prev;
        while (fast && fast->next) {
            fast = fast->next->next;
            prev=mid;
            mid = mid->next;
        }
        prev->next = nullptr;
        // reverse second half
        ListNode *curr = mid;
        prev = nullptr;
        while (curr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }       

        ListNode *l1 = head, *l2 = prev;
        while(l1){
            ListNode *temp1 = l1->next, *temp2 = l2->next;
            l1->next = l2;
            if(temp1){
                l2->next = temp1;
            }
            l2=temp2;
            l1 = temp1;
        }
    }
};