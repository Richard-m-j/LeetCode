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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int n = 0;
        ListNode* ptr = head;
        while (ptr) {
            n++;
            ptr = ptr->next;
        }
        vector<ListNode*> res;
        int numNodes = n / k;
        ptr = head;
        for (int i = 0; i < k; i++) {
            res.push_back(ptr);
            // cout<<ptr->val;
            int val = numNodes + (i<n%k);

            for (int j = 1; j<val && ptr; j++)
                // cout<<val<<" ";
                ptr = ptr->next;
            
            
            if(ptr){
                // cout<<ptr->val;
                ListNode* ptr1 = ptr->next;
                ptr->next = nullptr;
                ptr = ptr1;
            }
        }
        return res;
    }
};