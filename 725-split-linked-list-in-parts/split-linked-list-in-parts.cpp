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
        int n = 0;
        ListNode* ptr = head;
        while (ptr) {
            n++;
            ptr = ptr->next;
        }
        vector<ListNode*> res;
        int numNodes = n / k;
        int rem = n%k;
        ptr = head;
        for (int i = 0; i < k; i++) {
            res.push_back(ptr);
            // cout<<ptr->val;
            int val;
            if(i<rem)
                val = numNodes + 1;
            else
                val = numNodes;
            // cout<<numNodes<<" ";
            for (int j = 1; j<val && ptr; j++) {
                cout<<val<<" ";
                ptr = ptr->next;
            }
            
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