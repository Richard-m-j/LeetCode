// Last updated: 7/24/2025, 8:34:55 AM
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
    ListNode* deleteDuplicates(ListNode* head) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        ListNode* dummy = new ListNode(101,head);
        ListNode* ptr = head;
        ListNode* prev = dummy;
        while(prev->next){
            ptr = prev->next;
            int value = ptr->val;
            int count = 0;
            while(ptr && ptr->val == value){
                ptr = ptr->next;
                count++;
            }
            // cout<<value<<" "<<count<<endl;
            if(count>1)
                prev->next = ptr;
            else
                prev = prev->next;
        }
        return dummy->next;
    }
};