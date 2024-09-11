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
int speedUp = []{
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* before, *after = head;
        ListNode *prev = nullptr;
        ListNode* dummy = new ListNode(0);
        before = dummy;
        while(true){
            ListNode* ptr = after;
            for(int i=0;i<k;i++)
                if(!ptr)
                    return dummy->next;
                else
                    ptr = ptr->next;
            ptr = after;
            prev = before;
            for(int i=0;i<k;i++){
                ListNode *nxt = ptr->next;
                ptr->next = prev;
                prev = ptr;
                ptr = nxt;
            }
            after->next = ptr;
            before->next = prev;
            before = after;
            after = ptr;
        }
        return nullptr;
    }
};