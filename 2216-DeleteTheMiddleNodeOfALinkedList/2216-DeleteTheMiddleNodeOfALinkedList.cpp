// Last updated: 7/24/2025, 8:24:58 AM
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
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        if(head==NULL||head->next==NULL)
            return NULL;
        ListNode *mid=head;
        ListNode *ptr=head;

        int n=0;

        ptr=ptr->next;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
            n++;
            if(n%2==0)
                mid=mid->next;
        }
        
        mid->next=mid->next->next;
        return head;
    }
};