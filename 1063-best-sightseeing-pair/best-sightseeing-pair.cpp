class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        vector<int> dp(n);
        dp[0]=values[0];
        int res = 0;
        for(int i=1;i<n;i++){
            dp[i]=max(values[i]+i,dp[i-1]);
            res = max(res,dp[i-1]+values[i]-i);
        }
        return res;
    }
};