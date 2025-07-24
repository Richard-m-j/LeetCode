// Last updated: 7/24/2025, 8:22:25 AM
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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> numSet;
        for(int& num:nums)
            numSet.insert(num);
        ListNode * dummy = new ListNode(0,head);
        ListNode* ptr = dummy;
        while(ptr->next){
            // cout<<ptr->val;

            if(numSet.find(ptr->next->val) != numSet.end())
                ptr->next = ptr->next->next;
            else
                ptr=ptr->next;
        }
        return dummy->next;
    }
};