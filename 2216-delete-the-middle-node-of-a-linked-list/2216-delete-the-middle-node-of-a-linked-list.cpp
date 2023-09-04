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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *mid;
        ListNode *ptr;
        ptr=head;
        mid=head;
        int n=0;
        int midIndex=0;
        ptr=ptr->next;
        if(ptr==NULL)
            return NULL;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
            n++;
            if(n%2==0)
            {
                midIndex++;
                mid=mid->next;
            }
        }
        
            mid->next=mid->next->next;
        return head;
    }
};