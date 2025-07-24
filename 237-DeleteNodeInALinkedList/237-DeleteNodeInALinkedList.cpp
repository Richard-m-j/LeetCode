// Last updated: 7/24/2025, 8:32:23 AM
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int speedUp = []{
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};