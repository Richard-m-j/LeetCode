#pragma GCC optimize("fast")
static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();


class Solution {
public:
    int pairSum(ListNode* head) {
        
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