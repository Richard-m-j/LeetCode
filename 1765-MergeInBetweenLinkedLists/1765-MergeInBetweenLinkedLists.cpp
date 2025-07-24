// Last updated: 7/24/2025, 8:26:08 AM
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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        b -= a - 2;
        ListNode* head = list1;
        while(--a){
            list1 = list1->next;
        }
        ListNode* ptr = list1;
        while(b){
            ptr = ptr->next;
            b--;
        }
        list1->next = list2;
        while(list2->next){
            list2 = list2->next;
        }
        list2->next = ptr;
        return head;
    }
};