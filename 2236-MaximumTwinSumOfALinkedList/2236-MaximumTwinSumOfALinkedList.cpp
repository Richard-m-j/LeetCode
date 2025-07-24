// Last updated: 7/24/2025, 8:24:56 AM
class Solution {
public:
    int pairSum(ListNode* head) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int max=INT_MIN;
        vector <int> dq;
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
            int sum = dq[i]+dq[n-i-1];
            if(sum>max)
                max=sum;
        }
        return max;
    }
};