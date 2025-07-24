// Last updated: 7/24/2025, 8:23:38 AM
class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        unordered_set<int> ban;
        for(int& a: banned)
            ban.insert(a);
        int sum=0;
        int res=0;
        for(int i=1;i<=n;i++){
            if(ban.count(i))
                continue;
            maxSum -= i;
            if(maxSum<0)
                break;
            res++;
            // cout<<i<<" ";
        }
        return res;
    }
};