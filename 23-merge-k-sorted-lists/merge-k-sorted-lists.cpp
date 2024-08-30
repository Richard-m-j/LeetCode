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
        for(auto& list: lists){
            ListNode* ptr = list;
            while(ptr){
                temp.push_back(ptr->val);
                ptr = ptr->next;
            }
        }
        sort(temp.begin(),temp.end());
        ListNode *head = new ListNode();

        ListNode* ptr = head;
        for(int& num: temp){
            ptr->next = new ListNode(num);
            ptr = ptr->next;
        }
        return head->next;
    }
};