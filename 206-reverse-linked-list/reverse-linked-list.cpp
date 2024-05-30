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
    ListNode* reverseList(ListNode* head) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        ListNode* ptr = head,*ptr1 = NULL;
        while(ptr){
            ListNode *newNode = new ListNode(ptr->val,ptr1);
            ptr1 = newNode;
            ptr = ptr->next;
        }
        return ptr1;
    }
};