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
        ListNode* ptr = head;
        for(int i=0;i<k;i++)
            if(!ptr)
                return head;
            else
                ptr = ptr->next;
        
        ListNode *prev = nullptr;
        ptr = head;
        for(int i=0;i<k;i++){
            ListNode *nxt = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = nxt;
        }
        head->next = reverseKGroup(ptr,k);
        return prev;
    }
};