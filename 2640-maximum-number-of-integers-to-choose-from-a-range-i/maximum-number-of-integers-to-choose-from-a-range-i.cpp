class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> ban;
        for(int& a: banned)
            ban.insert(a);
        int sum=0;
        int res=0;
        for(int i=1;i<=n;i++){
            if(ban.count(i))
                continue;
            if(sum+i>maxSum)
                break;
            sum+=i;
            res++;
            // cout<<i<<" ";
        }
        return res;
    }
};