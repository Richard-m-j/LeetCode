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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<int> temp;
        ListNode *head = NULL;

        auto merge2 = [](ListNode *list1, ListNode *list2){
            if(!list1)
                return list2;
            if(!list2)
                return list1;
            ListNode *head = new ListNode();
            ListNode *ptr = head;
            while(list1 && list2){
                if(list1->val <= list2->val){
                    ptr->next = list1;
                    list1 = list1->next;
                }
                else{
                    ptr->next = list2;
                    list2 = list2->next;
                }
                ptr = ptr->next;
            }
            if(list1)
                ptr->next = list1;
            else
                ptr->next = list2;

            return head->next;
        };
        for(auto& list: lists){
            head = merge2(head,list);
        }
        
        return head;
    }
};