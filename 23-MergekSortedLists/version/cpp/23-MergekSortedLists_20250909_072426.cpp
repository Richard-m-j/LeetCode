// Last updated: 9/9/2025, 7:24:26 AM
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
        priority_queue<pair<int,ListNode *>,vector<pair<int,ListNode *>>,greater<>> pq;
        ListNode *dummy = new ListNode();
        ListNode *prev = dummy;
        for(auto& list: lists){
            if(list)
                pq.push({list->val,list});
        }
        while(!pq.empty()){
            ListNode* ptr = pq.top().second;
            pq.pop();
            if(ptr->next){
                pq.push({ptr->next->val,ptr->next});
            }
            prev->next = ptr;
            prev = prev->next;
        }
        return dummy->next;
    }
};