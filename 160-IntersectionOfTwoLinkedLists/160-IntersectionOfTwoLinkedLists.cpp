// Last updated: 7/24/2025, 8:33:28 AM
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
int findLength(ListNode* head){
    int n=0;
    ListNode* ptr = head;
    while(ptr){
        n++;
        ptr = ptr->next;
    }
    return n;
}
ListNode *findInterSection(ListNode *headA, ListNode *headB, int k){
    ListNode *ptr = headA;
    while(k){
        ptr = ptr->next;
        k--;
    }

    ListNode *ptr1 = ptr, *ptr2 = headB;
    while(ptr1 && ptr2 && ptr1 != ptr2){
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return ptr1;
}
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // find lengths
        int n = findLength(headA);
        int m = findLength(headB);

        if(n>m)
            return findInterSection(headA,headB,n-m);
        return findInterSection(headB,headA,m-n);
    }
};