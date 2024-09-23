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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(right==left)
            return head;
        ListNode* dummy = new ListNode(0,head);
        ListNode* ptr = dummy;
        for(int i=0;i<left-1;i++)
            ptr = ptr->next;

        //reverse
        ListNode* prev = NULL, *end = ptr->next,*next,*curr=ptr->next;
        int len = right - left+1;
        while(len--){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        end->next = next;
        ptr->next = prev;
        return dummy->next;
    }
};