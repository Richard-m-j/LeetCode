class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        if(!head || !head->next)
            return head;

        ListNode *odd =head;
        ListNode *even = head->next;
        ListNode *evenHead = even;

        while(even && even->next)
        {
            odd->next=even->next;
            odd=odd->next;
            even->next=odd->next;
            even=even->next;
        }

        odd->next=evenHead;
        return head;
    }
};