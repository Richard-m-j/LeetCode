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