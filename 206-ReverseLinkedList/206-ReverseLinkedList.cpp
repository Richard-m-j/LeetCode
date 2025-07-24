// Last updated: 7/24/2025, 8:32:57 AM
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

        ListNode * prev = NULL;
        ListNode * node = head;

        while(node){
            cout<<node->val<<" ";
            ListNode *temp = node->next;
            node->next = prev;
            prev = node;
            node = temp;
        }
        return prev;
    }
};