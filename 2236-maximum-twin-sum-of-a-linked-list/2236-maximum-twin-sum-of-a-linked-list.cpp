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
    int pairSum(ListNode* head) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int max=INT_MIN;
        deque <int> dq;
        ListNode *ptr=head;
        int n{0};
        while(ptr)
        {
            dq.push_back(ptr->val);
            ptr=ptr->next;
            n++;
        }
        for(int i=0;i<n/2;i++)
        {
            int sum = dq.front()+dq.back();
            if(sum>max)
                max=sum;
            dq.pop_front();
            dq.pop_back();
        }
        return max;
    }
};